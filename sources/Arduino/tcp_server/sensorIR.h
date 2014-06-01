/*
* sensorIR.h
*
* Created on: Dec 30, 2013
* Author: victor
*/


#ifndef SENSORIR_H_
#define SENSORIR_H_

#include <util/delay.h>
#include "template.h"
#include "LS_ATmega328.h"
#include "myDelay.h"
#include "stdio.h"

#define SENSOR_IR_DDR DDRC
#define SENSOR_IR_PORT PORTC
#define SENSOR_IR_PIN PINC
#define SENSOR_IR_BIT PC2 //tive problemas usando o pc0 em conjunto com o ethernet shield
#define ALARM_DDR_RED DDRB
#define ALARM_DDR_GREEN DDRC
#define ALARM_PORT_RED PORTB
#define ALARM_PORT_GREEN PORTC
#define ALARM_BIT_RED PB0
#define ALARM_BIT_GREEN PC3

uint8_t verificaObstaculoIR(void);
void obstacleAlarm(void);
int ir_convertToDistance(int adc_value);
#endif /* SENSORIR_H_ */
