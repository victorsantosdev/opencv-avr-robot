/*
* myDelay.c
*
* Created on: Feb 2, 2014
* Author: victor
*/

#include "myDelay.h"

 void mydelay_ms(uint16_t count) {
  while(count--) {
    _delay_ms(1);
  }
}

void mydelay_us(uint16_t count) {
  while(count--) {
    _delay_us(1);
  }
}
