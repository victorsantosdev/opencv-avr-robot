/* -----------------------------------------------------------------------------
 * File:			LS_defines.h
 * Module:			Definifitions file for the Library Source Project
 * Author:			Leandro Schwarz
 * Version:			9.0
 * Last edition:	08/02/2013
 * ---------------------------------------------------------------------------*/

#ifndef __LS_DEFINES_H
#define __LS_DEFINES_H 90

// -----------------------------------------------------------------------------
// Basic definitions -----------------------------------------------------------

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#ifndef MCU_32_BITS
#ifndef MCU_8_BITS
#define MCU_8_BITS
#endif
#endif

// -----------------------------------------------------------------------------
// Header files ----------------------------------------------------------------
//#define __DELAY_BACKWARD_COMPATIBLE__  //teste, sem isto apresentava problemas de compilação na função _delay_us
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>

// -----------------------------------------------------------------------------
// Constant definitions --------------------------------------------------------

#define FALSE	0
#define TRUE	1
#define HIGH	1
#define LOW		0

#define ADC0			0
#define ADC1			1
#define ADC2			2
#define ADC3			3
#define ADC4			4
#define ADC5			5
#define ADC6			6
#define ADC7			7
#define ADC_TEMP		8
#define ADC_INTERNAL	14
#define ADC_GND			15

#define ADC_PRESCALLER_OFF	0
#define ADC_PRESCALLER_2	1
#define ADC_PRESCALLER_4	2
#define ADC_PRESCALLER_8	3
#define ADC_PRESCALLER_16	4
#define ADC_PRESCALLER_32	5
#define ADC_PRESCALLER_64	6
#define ADC_PRESCALLER_128	7

#define ADC_REF_AREF		0
#define ADC_REF_AVCC		1
#define ADC_REF_INTERNAL	3

// -----------------------------------------------------------------------------
// Bit handling macro functions ------------------------------------------------

#define set_bit(address,bit) (address |= (1 << bit))
#define clr_bit(address,bit) (address &= ~(1 << bit))
#define tst_bit(address,bit) ((address >> bit) & 1)
#define cpl_bit(address,bit) (address ^= (1 << bit))

// -----------------------------------------------------------------------------
// New data types --------------------------------------------------------------

#ifdef MCU_32_BITS
typedef char int8;
typedef short int int16;
typedef int int32;
typedef long long int64;
typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
#else
typedef char int8;
typedef int int16;
typedef long int int32;
typedef long long int64;
typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long int uint32;
typedef unsigned long long uint64;
#endif

typedef struct adcConfiguration_t {
    uint8 reference : 2;
    uint8 channel : 4;
    uint8 leftAdjust : 1;
    uint8 enable : 1;
    uint8 autoTrigger : 1;
    uint8 interruptEnable : 1;
    uint8 prescaller : 3;
    uint8 triggerSource : 3;
    uint8 digitalDisabled : 6;
    uint8 analogComparator : 1;
    uint8 unusedBits : 1;
} adcConfiguration_t;

// -----------------------------------------------------------------------------
// Keypad configuration --------------------------------------------------------

#define KEYPAD_CONFIGURATION_4X4		// User selectable
//#define KEYPAD_CONFIGURATION_4X3		// User selectable
//#define KEYPAD_CONFIGURATION_5X3		// User selectable

#define KEYPAD_LINES_DDR		DDRD	// User configurable
#define KEYPAD_LINES_PORT		PORTD	// User configurable
#define KEYPAD_LINES_PIN		PIND	// User configurable
#define KEYPAD_LINE_FIRST		PD0	// User configurable
#define KEYPAD_COLUMNS_DDR		DDRD	// User configurable
#define KEYPAD_COLUMNS_PORT		PORTD	// User configurable
#define KEYPAD_COLUMN_FIRST		PD4	// User configurable
#define KEYPAD_DEBOUNCE_TIME		10	// User configurable

// -----------------------------------------------------------------------------
// Keypad ADC configuration ----------------------------------------------------

#define KEYPAD_ADC_CONFIGURATION_4X4		// User selectable
//#define KEYPAD_ADC_CONFIGURATION_4X3		// User selectable
//#define KEYPAD_ADC_CONFIGURATION_5X3		// User selectable

//#define KEYPAD_ADC_PRESCALLER_OFF			// User selectable
//#define KEYPAD_ADC_PRESCALLER_2			// User selectable
//#define KEYPAD_ADC_PRESCALLER_4			// User selectable
//#define KEYPAD_ADC_PRESCALLER_8			// User selectable
//#define KEYPAD_ADC_PRESCALLER_16			// User selectable
//#define KEYPAD_ADC_PRESCALLER_32			// User selectable
//#define KEYPAD_ADC_PRESCALLER_64			// User selectable
#define KEYPAD_ADC_PRESCALLER_128			// User selectable

//#define KEYPAD_ADC_REFERENCE_AREF			// User selectable
#define KEYPAD_ADC_REFERENCE_AVCC			// User selectable
//#define KEYPAD_ADC_REFERENCE_INTERNAL		// User selectable

#define KEYPAD_ADC_DEBOUNCE_TIME	10		// User configurable
#define KEYPAD_ADC_CHANNEL				0
#define KEYPAD_R_C0_GND					(int)1200	// Value in ohms
#define KEYPAD_R_C1_C0					(int)820	// Value in ohms
#define KEYPAD_R_C2_C1					(int)680	// Value in ohms
#define KEYPAD_R_C3_C2					(int)1000	// Value in ohms
#define KEYPAD_R_L1_L0					(int)15000	// Value in ohms
#define KEYPAD_R_L2_L1					(int)3300	// Value in ohms
#define KEYPAD_R_L3_L2					(int)1000	// Value in ohms
#define KEYPAD_R_VCC_L3					(int)180	// Value in ohms

// -----------------------------------------------------------------------------
// LCD configuration -----------------------------------------------------------

#define LCD_4_BITS_MODE				// User selectable
//#define LCD_8_BITS_MODE			// User selectable
//#define LCD_USE_BUSY_FLAG			// User selectable
#define LCD_5X8_FONT				// User selectable
//#define LCD_5X10_FONT				// User selectable
//#define LCD_8X1				// User selectable
//#define LCD_8X2				// User selectable
//#define LCD_12X2				// User selectable
//#define LCD_16X1				// User selectable
#define LCD_16X2				// User selectable
//#define LCD_16X4				// User selectable
//#define LCD_20X1				// User selectable
//#define LCD_20X2				// User selectable
//#define LCD_20X4				// User selectable
//#define LCD_24X2				// User selectable
//#define LCD_40X2				// User selectable
//#define LCD_40X4				// User selectable

#define LCD_DATA_DDR		DDRB		// User configurable
#define LCD_DATA_PIN		PINB		// User configurable
#define LCD_DATA_PORT		PORTB		// User configurable
#define LCD_DATA_D4			PB0		// User configurable
#define LCD_CONTROL_DDR		DDRB		// User configurable
#define LCD_CONTROL_PORT	PORTB		// User configurable
#define LCD_CONTROL_PIN		PINB		// User configurable
#define LCD_CONTROL_E		PB4		// User configurable
#define LCD_CONTROL_RS		PB5		// User configurable
#define LCD_CONTROL_RW		PB5		// User configurable

// -----------------------------------------------------------------------------
// MMA7260 Accelerometer Configuration -----------------------------------------

#define MMA7260_SLEEP_CONTROL_DDR	DDRC	// User configurable
#define MMA7260_SLEEP_CONTROL_PORT	PORTC	// User configurable
#define MMA7260_SLEEP			PC3	// User configurable
#define MMA7260_SENSE_CONTROL_DDR	DDRD	// User configurable
#define MMA7260_SENSE_CONTROL_PORT	PORTD	// User configurable
#define MMA7260_SENSE_0			PD3	// User configurable
#define MMA7260_SENSE_1			PD4	// User configurable

// -----------------------------------------------------------------------------
// MMA7361 accelerometer configuration -----------------------------------------

#define MMA7361_SUPPLY_VOLTAGE_33				// User selectable
//#define MMA7361_SUPPLY_VOLTAGE_50				// User selectable

#define MMA7361_CALIBRATION_SAMPLES		10		// User configurable => 1 to 63
#define MMA7361_ACQUISITION_SAMPLES		3		// User configurable => 1 to 63

#define MMA7361_CONTROL_DDR				DDRD	// User configurable
#define MMA7361_CONTROL_PORT			PORTD	// User configurable
#define MMA7361_CONTROL_PIN				PIND	// User configurable
#define MMA7361_SLEEP					PD4		// User configurable
#define MMA7361_G_SELECT				PD2		// User configurable
#define MMA7361_SELF_TEST				PD3		// User configurable
#define MMA7361_0_G_DETECT				PD7		// User configurable
#define MMA7361_X_AXIS					ADC0	// User configurable
#define MMA7361_Y_AXIS					ADC1	// User configurable
#define MMA7361_Z_AXIS					ADC2	// User configurable

// -----------------------------------------------------------------------------
// USART configuration ---------------------------------------------------------

#define USART_BAUD_RATE							9600	// User configurable
#define USART_RECEIVER_BUFFER_SIZE				50UL	// User configurable

// -----------------------------------------------------------------------------
// I2C configuration -----------------------------------------------------------

#define I2C_BUFFER_SIZE		4		// User configurable
#define I2C_BAUD_RATE		90000UL		// User configurable

#endif
