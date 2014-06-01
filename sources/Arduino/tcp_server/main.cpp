#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <pt.h>
#include <motores.h>
#include <string.h>
#include <sensorIR.h>
#include "ByteBuffer.h"

#define WITH_CARE 1
#define NO_CARE 0

//only detected as obstacle if distance is below 25cm, below 10cm the sensor starts misreading
#define IR_OBSTACLE_THRESHOLD 20
#define IR_OBSTACLE_UPPER_THRESHOLD 30

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress serverIP(10, 0, 1, 101);
int serverPort = 80;
ByteBuffer charBuffer; //i myself modded this library to achieve my demands

#ifdef debug
// buffers for receiving and sending data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,
#endif

// An EthernetUDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

char obstacle_flag = 0;
int IR_obstaculo = 0;
char received = 0;
char autonomous_flag = 0;

/*********************************************
 * variáveis de temporizacao
 */
unsigned long interval_ethernet = 50;  // the time we need to wait
unsigned long previousEth = 0; // millis() returns an unsigned long.
char count_eth = 0;

unsigned long interval_adc = 60;  // the time we need to wait
unsigned long previousADC = 0; // millis() returns an unsigned long.
char count_adc = 0;

unsigned long interval_motores = 100;  // the time we need to wait
unsigned long previousMotores = 0; // millis() returns an unsigned long.

char ciclosClock_motor = 0;
static char count_motor = 0;

/*************************************************************************
 Function: timer0_init
 Purpose: used to generate PWM to the motor wheels
 **************************************************************************/
void timer0_init(void) {
    MOTOR_SHIELD_DDR |= _BV(
            MOTOR_PWMA) | _BV(MOTOR_PWMB) | _BV(MOTOR_INA) | _BV(MOTOR_INB);
    TIMER0_PHASE_CORRECT_MAX_PWM_MODE();
    TIMER0_OC0A_CLEAR_ON_COMPARE();
    TIMER0_OC0B_CLEAR_ON_COMPARE();
    TIMER0_CLOCK_PRESCALER_OFF();
    TIMER0_COMPARE_A_CONFIGURE(0);
    TIMER0_COMPARE_B_CONFIGURE(0);
}

/*************************************************************************
 Function: ADC_init
 Purpose: set up the ADC to be used in IR sensor
 **************************************************************************/
void ADC_init(void) {
    SENSOR_IR_DDR &= ~_BV(SENSOR_IR_BIT);
    //ADC in 10bits : used in IR sensor routine : without shift left or right
    ADC_REFERENCE_AREF(); //ADC reference in 5V
    ADC_CLOCK_PRESCALER_128();
    /* the original ADC frequency of this project was 125KHz (Prescaler = 128), thus, I changed it to sample faster, in 1MHz (Prescaler16)
     * I have some loss in precision, working in 10 bits with a frequency bigger than 200KHz, but in this case this do not matters
     * */
    ADC_ENABLE();
    ADC_SELECT_CHANNEL_2();
    ADC_DIGITAL_INPUT_2_DISABLE();
    ADC_START_CONVERSION(); //I discard the first sample, which takes 25 clock cycles
    ADC_WAIT_CONVERSION_FINISH();
}

void debug_init(int pin) {
    DDRC |= _BV(pin);
    PORTC = 0;
}

void set_debug(int pin) {
    PORTC |= (1 << pin);
}

void clear_debug(int pin) {
    PORTC &= ~(1 << pin);
}

void setup() {

    // Open serial communications and wait for port to open:
    Serial.begin(9600);
    ADC_init();
    timer0_init();
    debug_init(PC3);
    debug_init(PC4);
    // Initialize the buffer with a capacity for 256 bytes
    charBuffer.init(256);
    // start the Ethernet connection and the server:
    Ethernet.begin(mac, serverIP);
    Udp.begin(serverPort);

    Serial.println("arduino server is at ");
    Serial.println(Ethernet.localIP());

}

void loop() {

    if ((unsigned long) (millis() - previousEth) >= interval_ethernet) { //entra a cada 50ms
        previousEth = millis();
        if(count_eth == 0) { //espera completar um ciclo de todas as funções chamadas
            int packetSize = Udp.parsePacket();
            count_eth = 2;
            Serial.println("entrou eth");
            received = 0;
            if (packetSize) {
                set_debug(PC3);

#ifdef debug
                Serial.println("entrou eth RX ");
                Serial.print("Received packet of size ");
                Serial.println(packetSize);
                Serial.print("From ");
                IPAddress remote = Udp.remoteIP();
                for (int i =0; i < 4; i++)
                {
                    Serial.print(remote[i], DEC);
                    if (i < 3)
                    {
                        Serial.print(".");
                    }
                }
                Serial.print(", port ");
                Serial.println(Udp.remotePort());

                Serial.println("Contents:");
                Serial.println(packetBuffer);
#endif
                received = Udp.read();
                charBuffer.put(received);

#ifdef debug
                Serial.println("\rchar recebido:");
                Serial.write(received);
#endif

                /////////////////////////////
                clear_debug(PC3);
            }
        } else {
            count_eth--;
            Serial.println("entrou eth NADA");
            if (charBuffer.getSize() > 5) charBuffer.clear();
            if( charBuffer.getSize() > 0 )
                received = charBuffer.get();
            Serial.println("received:");
            Serial.println(received);

        }
    }
#ifdef debug
    Serial.println("client disconnected");
#endif
    /****************FIM ROTINA ETHERNET ***************************************************/


    if ((unsigned long) (millis() - previousADC) >= interval_adc) { //entra a cada 60ms
        previousADC = millis();
        set_debug(PC4);
        if (count_adc == 0) {
            count_adc = 1;
            /*testa obstaculo IR*/
            Serial.println("entrou adc OBSTACULO ");

            IR_obstaculo = 0;
            IR_obstaculo = verificaObstaculoIR();
#ifdef debug
            Serial.println("distancia_ir");
            Serial.println(IR_obstaculo);
            Serial.println("\r");
#endif
            if (IR_obstaculo > IR_OBSTACLE_THRESHOLD)
                obstacle_flag = 0;
            else if (IR_obstaculo > IR_OBSTACLE_THRESHOLD
                    && IR_obstaculo < IR_OBSTACLE_UPPER_THRESHOLD)
                obstacle_flag = 1;
            else if (IR_obstaculo <= IR_OBSTACLE_THRESHOLD)
                obstacle_flag = 2;
            clear_debug(PC4);
        } else {
            count_adc=0;
            Serial.println("entrou adc NADA ");

        }
    }

    /***************** FIM ROTINA ADC********************************/

    if ((unsigned long) (millis() - previousMotores) >= interval_motores) { //entra a cada 100ms
        previousMotores = millis();

        if (ciclosClock_motor == 2) { //duas bordas de subida depois de acionar o motor (200ms depois de acionar o motor)
            Serial.println("motor stop ");
            stopMove();
            ciclosClock_motor = 0;
        }
        if (count_motor == 0) {
            Serial.println("motor ANDA ");

            if (obstacle_flag == 0 || obstacle_flag == 1) {
                count_motor = 1;
                /*move motores*/
                switch (received) {
                case 'u':
                    goForward(obstacle_flag);
                    break;
                case 'd':
                    goBack(obstacle_flag);
                    break;
                case 'l':
                    goLeft(obstacle_flag);
                    break;
                case 'r':
                    goRight(obstacle_flag);
                    break;
                default:
                    received = 0;
                    stopMove();
                    break;
                }
            } else {
                if (received == 'd') {
                    goBack(WITH_CARE);
                } else {
                    stopMove();
                }
            }
        } else {
            ciclosClock_motor++;
            count_motor = 0;
            Serial.println("ciclosClock_motor++ ");
        }

    }
    // _delay_ms(500);
}

int main(void) {

    init();
    setup();

    while (true) {
        loop();
    }
}
