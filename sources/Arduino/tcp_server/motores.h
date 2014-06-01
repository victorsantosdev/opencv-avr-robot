/*
* motores.h
*
* Created on: Feb 19, 2014
* Author: victor
*/

#ifndef MOTORES_H_
#define MOTORES_H_
#include "avr/io.h"
#include "LS_ATmega328.h"
#include "LS_defines.h"
#include "Arduino.h"

#define MOTOR_SHIELD_DDR DDRD
#define MOTOR_SHIELD_PORT PORTD
#define MOTOR_SHIELD_PIN PIND
#define MOTOR_INA PD4 //left wheel
#define MOTOR_PWMA PD5
#define MOTOR_PWMB PD6
#define MOTOR_INB PD7 //right wheel

void goBack(int flag);

void goForward(int flag);

void goLeft(int flag);

void goRight(int flag);

void stopMove(void);

void turn(void);

#endif /* MOTORES_H_ */

