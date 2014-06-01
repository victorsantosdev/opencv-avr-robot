/*
* myDelay.h
*
* Created on: Feb 2, 2014
* Author: victor
*/

#ifndef MYDELAY_H_
#define MYDELAY_H_

#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>

void mydelay_ms(uint16_t count);

void mydelay_us(uint16_t count);

#endif /* MYDELAY_H_ */
