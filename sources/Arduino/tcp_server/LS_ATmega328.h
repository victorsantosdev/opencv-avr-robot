/* -----------------------------------------------------------------------------
 * File:			LS_ATmega328.h
 * Module:			ATmega328 basic interface
 * Author:			Leandro Schwarz
 * Version:			5.2
 * Last edition:	08/02/2013
 * -------------------------------------------------------------------------- */

#ifndef __LS_ATMEGA328_H
#define __LS_ATMEGA328_H 52

// -----------------------------------------------------------------------------
// Header files ----------------------------------------------------------------

#include <avr/io.h>
#include <stdio.h>
#include "LS_defines.h"

#if __LS_DEFINES_H < 89
#error Wrong definition file (LS_defines.h).
#endif

// -----------------------------------------------------------------------------
// Status Register -------------------------------------------------------------

#define GLOBAL_INTERRUPT_ENABLE()		set_bit(SREG,I)
#define GLOBAL_INTERRUPT_DISABLE()		clr_bit(SREG,I)

// -----------------------------------------------------------------------------
// EEPROM Data Memory ----------------------------------------------------------

uint8 eepromRead(uint16 address);
void eepromWrite(uint8 data, uint8 address);

// -----------------------------------------------------------------------------
// General purpose registers ---------------------------------------------------

#define GERAL_PURPOSE_REGISTER_2_READ(data)	data = GPIOR2
#define GERAL_PURPOSE_REGISTER_2_WRITE(data)	GPIOR2 = data
#define GERAL_PURPOSE_REGISTER_1_READ(data)	data = GPIOR1
#define GERAL_PURPOSE_REGISTER_1_WRITE(data)	GPIOR1 = data
#define GERAL_PURPOSE_REGISTER_0_READ(data)	data = GPIOR0
#define GERAL_PURPOSE_REGISTER_0_WRITE(data)	GPIOR0 = data

// -----------------------------------------------------------------------------
// I/O ports -------------------------------------------------------------------

#define PULL_UP_DISABLE()	set_bit(MCUCR,PUD)
#define PULL_UP_ENABLE()	clr_bit(MCUCR,PUD)

// -----------------------------------------------------------------------------
// External interrupts ---------------------------------------------------------

// INT0
#define INT0_ACTIVATE()				set_bit(EIMSK,INT0)
#define INT0_CLEAR_REQUEST()		set_bit(EIFR,INTF0)
#define INT0_DDR_CONFIGURE()		clr_bit(DDRD,PD2)
#define INT0_DEACTIVATE()			clr_bit(EIMSK,INT0)
#define INT0_PULL_UP_DISABLE()		clr_bit(PORTD,PD2)
#define INT0_PULL_UP_ENABLE()		set_bit(PORTD,PD2)
#define INT0_SENSE_LOW_LEVEL()		do{clr_bit(EICRA,ISC01);clr_bit(EICRA,ISC00);}while(0)
#define INT0_SENSE_ANY_EDGE()		do{clr_bit(EICRA,ISC01);set_bit(EICRA,ISC00);}while(0)
#define INT0_SENSE_FALLING_EDGE()	do{set_bit(EICRA,ISC01);clr_bit(EICRA,ISC00);}while(0)
#define INT0_SENSE_RISING_EDGE()	do{set_bit(EICRA,ISC01);set_bit(EICRA,ISC00);}while(0)
// INT1
#define INT1_ACTIVATE()				set_bit(EIMSK,INT1)
#define INT1_CLEAR_REQUEST()		set_bit(EIFR,INTF1)
#define INT1_DDR_CONFIGURE()		clr_bit(DDRD,PD3)
#define INT1_DEACTIVATE()			clr_bit(EIMSK,INT1)
#define INT1_PULL_UP_DISABLE()		clr_bit(PORTD,PD3)
#define INT1_PULL_UP_ENABLE()		set_bit(PORTD,PD3)
#define INT1_SENSE_LOW_LEVEL()		do{clr_bit(EICRA,ISC11);clr_bit(EICRA,ISC10);}while(0)
#define INT1_SENSE_ANY_EDGE()		do{clr_bit(EICRA,ISC11);set_bit(EICRA,ISC10);}while(0)
#define INT1_SENSE_FALLING_EDGE()	do{set_bit(EICRA,ISC11);clr_bit(EICRA,ISC10);}while(0)
#define INT1_SENSE_RISING_EDGE()	do{set_bit(EICRA,ISC11);set_bit(EICRA,ISC10);}while(0)
// PCINT7-0
#define PCINT7_0_DISABLE()			clr_bit(PCICR,PCIE0)
#define PCINT7_0_ENABLE()			set_bit(PCICR,PCIE0)
#define PCINT7_0_CLEAR_REQUEST()	set_bit(PCIFR,PCIF0)
#define PCINT0_ACTIVATE()			set_bit(PCMSK0,PCINT0)
#define PCINT0_DEACTIVATE()			clr_bit(PCMSK0,PCINT0)
#define PCINT0_DDR_CONFIGURE()		clr_bit(DDRB,PB0)
#define PCINT0_PULL_UP_DISABLE()	clr_bit(PORTB,PB0)
#define PCINT0_PULL_UP_ENABLE()		set_bit(PORTB,PB0)
#define PCINT1_ACTIVATE()			set_bit(PCMSK0,PCINT1)
#define PCINT1_DEACTIVATE()			clr_bit(PCMSK0,PCINT1)
#define PCINT1_DDR_CONFIGURE()		clr_bit(DDRB,PB1)
#define PCINT1_PULL_UP_DISABLE()	clr_bit(PORTB,PB1)
#define PCINT1_PULL_UP_ENABLE()		set_bit(PORTB,PB1)
#define PCINT2_ACTIVATE()			set_bit(PCMSK0,PCINT2)
#define PCINT2_DEACTIVATE()			clr_bit(PCMSK0,PCINT2)
#define PCINT2_DDR_CONFIGURE()		clr_bit(DDRB,PB2)
#define PCINT2_PULL_UP_DISABLE()	clr_bit(PORTB,PB2)
#define PCINT2_PULL_UP_ENABLE()		set_bit(PORTB,PB2)
#define PCINT3_ACTIVATE()			set_bit(PCMSK0,PCINT3)
#define PCINT3_DEACTIVATE()			clr_bit(PCMSK0,PCINT3)
#define PCINT3_DDR_CONFIGURE()		clr_bit(DDRB,PB3)
#define PCINT3_PULL_UP_DISABLE()	clr_bit(PORTB,PB3)
#define PCINT3_PULL_UP_ENABLE()		set_bit(PORTB,PB3)
#define PCINT4_ACTIVATE()			set_bit(PCMSK0,PCINT4)
#define PCINT4_DEACTIVATE()			clr_bit(PCMSK0,PCINT4)
#define PCINT4_DDR_CONFIGURE()		clr_bit(DDRB,PB4)
#define PCINT4_PULL_UP_DISABLE()	clr_bit(PORTB,PB4)
#define PCINT4_PULL_UP_ENABLE()		set_bit(PORTB,PB4)
#define PCINT5_ACTIVATE()			set_bit(PCMSK0,PCINT5)
#define PCINT5_DEACTIVATE()			clr_bit(PCMSK0,PCINT5)
#define PCINT5_DDR_CONFIGURE()		clr_bit(DDRB,PB5)
#define PCINT5_PULL_UP_DISABLE()	clr_bit(PORTB,PB5)
#define PCINT5_PULL_UP_ENABLE()		set_bit(PORTB,PB5)
#define PCINT6_ACTIVATE()			set_bit(PCMSK0,PCINT6)
#define PCINT6_DEACTIVATE()			clr_bit(PCMSK0,PCINT6)
#define PCINT6_DDR_CONFIGURE()		clr_bit(DDRB,PB6)
#define PCINT6_PULL_UP_DISABLE()	clr_bit(PORTB,PB6)
#define PCINT6_PULL_UP_ENABLE()		set_bit(PORTB,PB6)
#define PCINT7_ACTIVATE()			set_bit(PCMSK0,PCINT7)
#define PCINT7_DEACTIVATE()			clr_bit(PCMSK0,PCINT7)
#define PCINT7_DDR_CONFIGURE()		clr_bit(DDRB,PB7)
#define PCINT7_PULL_UP_DISABLE()	clr_bit(PORTB,PB7)
#define PCINT7_PULL_UP_ENABLE()		set_bit(PORTB,PB7)
// PCINT14-8
#define PCINT14_8_DISABLE()			clr_bit(PCICR,PCIE1)
#define PCINT14_8_ENABLE()			set_bit(PCICR,PCIE1)
#define PCINT14_8_CLEAR_REQUEST()	set_bit(PCIFR,PCIF1)
#define PCINT8_ACTIVATE()			set_bit(PCMSK1,PCINT8)
#define PCINT8_DEACTIVATE()			clr_bit(PCMSK1,PCINT8)
#define PCINT8_DDR_CONFIGURE()		clr_bit(DDRC,PC0)
#define PCINT8_PULL_UP_DISABLE()	clr_bit(PORTC,PC0)
#define PCINT8_PULL_UP_ENABLE()		set_bit(PORTC,PC0)
#define PCINT9_ACTIVATE()			set_bit(PCMSK1,PCINT9)
#define PCINT9_DEACTIVATE()			clr_bit(PCMSK1,PCINT9)
#define PCINT9_DDR_CONFIGURE()		clr_bit(DDRC,PC1)
#define PCINT9_PULL_UP_DISABLE()	clr_bit(PORTC,PC1)
#define PCINT9_PULL_UP_ENABLE()		set_bit(PORTC,PC1)
#define PCINT10_ACTIVATE()			set_bit(PCMSK1,PCINT10)
#define PCINT10_DEACTIVATE()		clr_bit(PCMSK1,PCINT10)
#define PCINT10_DDR_CONFIGURE()		clr_bit(DDRC,PC2)
#define PCINT10_PULL_UP_DISABLE()	clr_bit(PORTC,PC2)
#define PCINT10_PULL_UP_ENABLE()	set_bit(PORTC,PC2)
#define PCINT11_ACTIVATE()			set_bit(PCMSK1,PCINT11)
#define PCINT11_DEACTIVATE()		clr_bit(PCMSK1,PCINT11)
#define PCINT11_DDR_CONFIGURE()		clr_bit(DDRC,PC3)
#define PCINT11_PULL_UP_DISABLE()	clr_bit(PORTC,PC3)
#define PCINT11_PULL_UP_ENABLE()	set_bit(PORTC,PC3)
#define PCINT12_ACTIVATE()			set_bit(PCMSK1,PCINT12)
#define PCINT12_DEACTIVATE()		clr_bit(PCMSK1,PCINT12)
#define PCINT12_DDR_CONFIGURE()		clr_bit(DDRC,PC4)
#define PCINT12_PULL_UP_DISABLE()	clr_bit(PORTC,PC4)
#define PCINT12_PULL_UP_ENABLE()	set_bit(PORTC,PC4)
#define PCINT13_ACTIVATE()			set_bit(PCMSK1,PCINT13)
#define PCINT13_DEACTIVATE()		clr_bit(PCMSK1,PCINT13)
#define PCINT13_DDR_CONFIGURE()		clr_bit(DDRC,PC5)
#define PCINT13_PULL_UP_DISABLE()	clr_bit(PORTC,PC5)
#define PCINT13_PULL_UP_ENABLE()	set_bit(PORTC,PC5)
#define PCINT14_ACTIVATE()			set_bit(PCMSK1,PCINT14)
#define PCINT14_DEACTIVATE()		clr_bit(PCMSK1,PCINT14)
#define PCINT14_DDR_CONFIGURE()		clr_bit(DDRC,PC6)
#define PCINT14_PULL_UP_DISABLE()	clr_bit(PORTC,PC6)
#define PCINT14_PULL_UP_ENABLE()	set_bit(PORTC,PC6)
// PCINT14-8
#define PCINT23_16_DISABLE()		clr_bit(PCICR,PCIE2)
#define PCINT23_16_ENABLE()			set_bit(PCICR,PCIE2)
#define PCINT23_16_CLEAR_REQUEST()	set_bit(PCIFR,PCIF2)
#define PCINT16_ACTIVATE()			set_bit(PCMSK2,PCINT16)
#define PCINT16_DEACTIVATE()		clr_bit(PCMSK2,PCINT16)
#define PCINT16_DDR_CONFIGURE()		clr_bit(DDRD,PD0)
#define PCINT16_PULL_UP_DISABLE()	clr_bit(PORTD,PD0)
#define PCINT16_PULL_UP_ENABLE()	set_bit(PORTD,PD0)
#define PCINT17_ACTIVATE()			set_bit(PCMSK2,PCINT17)
#define PCINT17_DEACTIVATE()		clr_bit(PCMSK2,PCINT17)
#define PCINT17_DDR_CONFIGURE()		clr_bit(DDRD,PD1)
#define PCINT17_PULL_UP_DISABLE()	clr_bit(PORTD,PD1)
#define PCINT17_PULL_UP_ENABLE()	set_bit(PORTD,PD1)
#define PCINT18_ACTIVATE()			set_bit(PCMSK2,PCINT18)
#define PCINT18_DEACTIVATE()		clr_bit(PCMSK2,PCINT18)
#define PCINT18_DDR_CONFIGURE()		clr_bit(DDRD,PD2)
#define PCINT18_PULL_UP_DISABLE()	clr_bit(PORTD,PD2)
#define PCINT18_PULL_UP_ENABLE()	set_bit(PORTD,PD2)
#define PCINT19_ACTIVATE()			set_bit(PCMSK2,PCINT19)
#define PCINT19_DEACTIVATE()		clr_bit(PCMSK2,PCINT19)
#define PCINT19_DDR_CONFIGURE()		clr_bit(DDRD,PD3)
#define PCINT19_PULL_UP_DISABLE()	clr_bit(PORTD,PD3)
#define PCINT19_PULL_UP_ENABLE()	set_bit(PORTD,PD3)
#define PCINT20_ACTIVATE()			set_bit(PCMSK2,PCINT20)
#define PCINT20_DEACTIVATE()		clr_bit(PCMSK2,PCINT20)
#define PCINT20_DDR_CONFIGURE()		clr_bit(DDRD,PD4)
#define PCINT20_PULL_UP_DISABLE()	clr_bit(PORTD,PD4)
#define PCINT20_PULL_UP_ENABLE()	set_bit(PORTD,PD4)
#define PCINT21_ACTIVATE()			set_bit(PCMSK2,PCINT21)
#define PCINT21_DEACTIVATE()		clr_bit(PCMSK2,PCINT21)
#define PCINT21_DDR_CONFIGURE()		clr_bit(DDRD,PD5)
#define PCINT21_PULL_UP_DISABLE()	clr_bit(PORTD,PD5)
#define PCINT21_PULL_UP_ENABLE()	set_bit(PORTD,PD5)
#define PCINT22_ACTIVATE()			set_bit(PCMSK2,PCINT22)
#define PCINT22_DEACTIVATE()		clr_bit(PCMSK2,PCINT22)
#define PCINT22_DDR_CONFIGURE()		clr_bit(DDRD,PD6)
#define PCINT22_PULL_UP_DISABLE()	clr_bit(PORTD,PD6)
#define PCINT22_PULL_UP_ENABLE()	set_bit(PORTD,PD6)
#define PCINT23_ACTIVATE()			set_bit(PCMSK2,PCINT23)
#define PCINT23_DEACTIVATE()		clr_bit(PCMSK2,PCINT23)
#define PCINT23_DDR_CONFIGURE()		clr_bit(DDRD,PD7)
#define PCINT23_PULL_UP_DISABLE()	clr_bit(PORTD,PD7)
#define PCINT23_PULL_UP_ENABLE()	set_bit(PORTD,PD7)

// -----------------------------------------------------------------------------
// Timer/counter 0 -------------------------------------------------------------

// Clock prescaler selection
#define TIMER0_CLOCK_DISABLE()					do{clr_bit(TCCR0B,CS02);clr_bit(TCCR0B,CS01);clr_bit(TCCR0B,CS00);}while(0)
#define TIMER0_CLOCK_PRESCALER_OFF()			do{clr_bit(TCCR0B,CS02);clr_bit(TCCR0B,CS01);set_bit(TCCR0B,CS00);}while(0)
#define TIMER0_CLOCK_PRESCALER_8()				do{clr_bit(TCCR0B,CS02);set_bit(TCCR0B,CS01);clr_bit(TCCR0B,CS00);}while(0)
#define TIMER0_CLOCK_PRESCALER_64()				do{clr_bit(TCCR0B,CS02);set_bit(TCCR0B,CS01);set_bit(TCCR0B,CS00);}while(0)
#define TIMER0_CLOCK_PRESCALER_256()			do{set_bit(TCCR0B,CS02);clr_bit(TCCR0B,CS01);clr_bit(TCCR0B,CS00);}while(0)
#define TIMER0_CLOCK_PRESCALER_1024()			do{set_bit(TCCR0B,CS02);clr_bit(TCCR0B,CS01);set_bit(TCCR0B,CS00);}while(0)
#define TIMER0_CLOCK_T0_FALLING_EDGE()			do{set_bit(TCCR0B,CS02);set_bit(TCCR0B,CS01);clr_bit(TCCR0B,CS00);}while(0)
#define TIMER0_CLOCK_T0_RISING_EDGE()			do{set_bit(TCCR0B,CS02);set_bit(TCCR0B,CS01);set_bit(TCCR0B,CS00);}while(0)
// Operation mode selection
#define TIMER0_NORMAL_MODE()					do{clr_bit(TCCR0B,WGM02);clr_bit(TCCR0A,WGM01);clr_bit(TCCR0A,WGM00);}while(0)
#define TIMER0_CTC_MODE()						do{clr_bit(TCCR0B,WGM02);set_bit(TCCR0A,WGM01);clr_bit(TCCR0A,WGM00);}while(0)
#define TIMER0_FAST_PWM_MAX_MODE()				do{clr_bit(TCCR0B,WGM02);set_bit(TCCR0A,WGM01);set_bit(TCCR0A,WGM00);}while(0)
#define TIMER0_FAST_PWM_OCR0A_MODE()			do{set_bit(TCCR0B,WGM02);set_bit(TCCR0A,WGM01);set_bit(TCCR0A,WGM00);}while(0)
#define TIMER0_PHASE_CORRECT_MAX_PWM_MODE()		do{clr_bit(TCCR0B,WGM02);clr_bit(TCCR0A,WGM01);set_bit(TCCR0A,WGM00);}while(0)
#define TIMER0_PHASE_CORRECT_OCR0A_PWM_MODE()	do{set_bit(TCCR0B,WGM02);clr_bit(TCCR0A,WGM01);set_bit(TCCR0A,WGM00);}while(0)
// Output compare A behavior
#define TIMER0_OC0A_OFF()						do{clr_bit(TCCR0A,COM0A1);clr_bit(TCCR0A,COM0A0);}while(0)
#define TIMER0_OC0A_TOGGLE_ON_COMPARE()			do{clr_bit(TCCR0A,COM0A1);set_bit(TCCR0A,COM0A0);}while(0)
#define TIMER0_OC0A_CLEAR_ON_COMPARE()			do{set_bit(TCCR0A,COM0A1);clr_bit(TCCR0A,COM0A0);}while(0)
#define TIMER0_OC0A_SET_ON_COMPARE()			do{set_bit(TCCR0A,COM0A1);set_bit(TCCR0A,COM0A0);}while(0)
#define TIMER0_OC0A_NON_INVERTED_MODE()			do{set_bit(TCCR0A,COM0A1);clr_bit(TCCR0A,COM0A0);}while(0)
#define TIMER0_OC0A_INVERTED_MODE()				do{set_bit(TCCR0A,COM0A1);set_bit(TCCR0A,COM0A0);}while(0)
// Output compare B behavior
#define TIMER0_OC0B_OFF()						do{clr_bit(TCCR0A,COM0B1);clr_bit(TCCR0A,COM0B0);}while(0)
#define TIMER0_OC0B_TOGGLE_ON_COMPARE()			do{clr_bit(TCCR0A,COM0B1);set_bit(TCCR0A,COM0B0);}while(0)
#define TIMER0_OC0B_CLEAR_ON_COMPARE()			do{set_bit(TCCR0A,COM0B1);clr_bit(TCCR0A,COM0B0);}while(0)
#define TIMER0_OC0B_SET_ON_COMPARE()			do{set_bit(TCCR0A,COM0B1);set_bit(TCCR0A,COM0B0);}while(0)
#define TIMER0_OC0B_NON_INVERTED_MODE()			do{set_bit(TCCR0A,COM0B1);clr_bit(TCCR0A,COM0B0);}while(0)
#define TIMER0_OC0B_INVERTED_MODE()				do{set_bit(TCCR0A,COM0B1);set_bit(TCCR0A,COM0B0);}while(0)
// Timer overflow interruption configuration
#define TIMER0_ACTIVATE_OVF_INTERRUPT()			set_bit(TIMSK0,TOIE0)
#define TIMER0_DEACTIVATE_OVF_INTERRUPT()		clr_bit(TIMSK0,TOIE0)
#define TIMER0_CLEAR_OVF_REQUEST()				set_bit(TIFR0,TOV0)
// Output compare A interruption configuration
#define TIMER0_ACTIVATE_COMPARE_A_INTERRUPT()	set_bit(TIMSK0,OCIE0A)
#define TIMER0_DEACTIVATE_COMPARE_A_INTERRUPT()	clr_bit(TIMSK0,OCIE0A)
#define TIMER0_CLEAR_COMPARE_A_REQUEST()		set_bit(TIFR0,OCF0A)
// Output compare B interruption configuration
#define TIMER0_ACTIVATE_COMPARE_B_INTERRUPT()	set_bit(TIMSK0,OCIE0B)
#define TIMER0_DEACTIVATE_COMPARE_B_INTERRUPT()	clr_bit(TIMSK0,OCIE0B)
#define TIMER0_CLEAR_COMPARE_B_REQUEST()		set_bit(TIFR0,OCF0B)
// Force output compare
#define TIMER0_FORCE_COMPARE_A()				set_bit(TCCR0B,FOC0A)
#define TIMER0_FORCE_COMPARE_B()				set_bit(TCCR0B,FOC0B)
// Timer value
#define TIMER0_COUNTER_CONFIGURE(value)			TCNT0 = value
#define TIMER0_COMPARE_A_CONFIGURE(value)		OCR0A = value
#define TIMER0_COMPARE_B_CONFIGURE(value)		OCR0B = value

// -----------------------------------------------------------------------------
// Timer/counter 1 -------------------------------------------------------------

// Clock prescaler selection
#define TIMER1_CLOCK_DISABLE()							do{clr_bit(TCCR1B,CS12);clr_bit(TCCR1B,CS11);clr_bit(TCCR1B,CS10);}while(0)
#define TIMER1_CLOCK_PRESCALER_OFF()					do{clr_bit(TCCR1B,CS12);clr_bit(TCCR1B,CS11);set_bit(TCCR1B,CS10);}while(0)
#define TIMER1_CLOCK_PRESCALER_8()						do{clr_bit(TCCR1B,CS12);set_bit(TCCR1B,CS11);clr_bit(TCCR1B,CS10);}while(0)
#define TIMER1_CLOCK_PRESCALER_64()						do{clr_bit(TCCR1B,CS12);set_bit(TCCR1B,CS11);set_bit(TCCR1B,CS10);}while(0)
#define TIMER1_CLOCK_PRESCALER_256()					do{set_bit(TCCR1B,CS12);clr_bit(TCCR1B,CS11);clr_bit(TCCR1B,CS10);}while(0)
#define TIMER1_CLOCK_PRESCALER_1024()					do{set_bit(TCCR1B,CS12);clr_bit(TCCR1B,CS11);set_bit(TCCR1B,CS10);}while(0)
#define TIMER1_CLOCK_T1_FALLING_EDGE()					do{set_bit(TCCR1B,CS12);set_bit(TCCR1B,CS11);clr_bit(TCCR1B,CS10);}while(0)
#define TIMER1_CLOCK_T1_RISING_EDGE()					do{set_bit(TCCR1B,CS12);set_bit(TCCR1B,CS11);set_bit(TCCR1B,CS10);}while(0)
// Operation mode selection
#define TIMER1_NORMAL_MODE()							do{clr_bit(TCCR1B,WGM13);clr_bit(TCCR1B,WGM12);clr_bit(TCCR1A,WGM11);clr_bit(TCCR1A,WGM10);}while(0)
#define TIMER1_PHASE_CORRECT_8_BITS_PWM_MODE()			do{clr_bit(TCCR1B,WGM13);clr_bit(TCCR1B,WGM12);clr_bit(TCCR1A,WGM11);set_bit(TCCR1A,WGM10);}while(0)
#define TIMER1_PHASE_CORRECT_9_BITS_PWM_MODE()			do{clr_bit(TCCR1B,WGM13);clr_bit(TCCR1B,WGM12);set_bit(TCCR1A,WGM11);clr_bit(TCCR1A,WGM10);}while(0)
#define TIMER1_PHASE_CORRECT_10_BITS_PWM_MODE()			do{clr_bit(TCCR1B,WGM13);clr_bit(TCCR1B,WGM12);set_bit(TCCR1A,WGM11);set_bit(TCCR1A,WGM10);}while(0)
#define TIMER1_CTC_MODE()								do{clr_bit(TCCR1B,WGM13);set_bit(TCCR1B,WGM12);clr_bit(TCCR1A,WGM11);clr_bit(TCCR1A,WGM10);}while(0)
#define TIMER1_FAST_PWM_MODE_8_BITS()					do{clr_bit(TCCR1B,WGM13);set_bit(TCCR1B,WGM12);clr_bit(TCCR1A,WGM11);set_bit(TCCR1A,WGM10);}while(0)
#define TIMER1_FAST_PWM_MODE_9_BITS()					do{clr_bit(TCCR1B,WGM13);set_bit(TCCR1B,WGM12);set_bit(TCCR1A,WGM11);clr_bit(TCCR1A,WGM10);}while(0)
#define TIMER1_FAST_PWM_MODE_10_BITS()					do{clr_bit(TCCR1B,WGM13);set_bit(TCCR1B,WGM12);set_bit(TCCR1A,WGM11);set_bit(TCCR1A,WGM10);}while(0)
#define TIMER1_PHASE_FREQUENCY_CORRECT_ICR1_PWM_MODE()	do{set_bit(TCCR1B,WGM13);clr_bit(TCCR1B,WGM12);clr_bit(TCCR1A,WGM11);clr_bit(TCCR1A,WGM10);}while(0)
#define TIMER1_PHASE_FREQUENCY_CORRECT_OCR1A_PWM_MODE()	do{set_bit(TCCR1B,WGM13);clr_bit(TCCR1B,WGM12);clr_bit(TCCR1A,WGM11);set_bit(TCCR1A,WGM10);}while(0)
#define TIMER1_PHASE_CORRECT_ICR1_PWM_MODE()			do{set_bit(TCCR1B,WGM13);clr_bit(TCCR1B,WGM12);set_bit(TCCR1A,WGM11);clr_bit(TCCR1A,WGM10);}while(0)
#define TIMER1_PHASE_CORRECT_OCR1A_PWM_MODE()			do{set_bit(TCCR1B,WGM13);clr_bit(TCCR1B,WGM12);set_bit(TCCR1A,WGM11);set_bit(TCCR1A,WGM10);}while(0)
#define TIMER1_CTC_ICR1_MODE()							do{set_bit(TCCR1B,WGM13);set_bit(TCCR1B,WGM12);clr_bit(TCCR1A,WGM11);clr_bit(TCCR1A,WGM10);}while(0)
#define TIMER1_FAST_ICR1_PWM_MODE()						do{set_bit(TCCR1B,WGM13);set_bit(TCCR1B,WGM12);set_bit(TCCR1A,WGM11);clr_bit(TCCR1A,WGM10);}while(0)
#define TIMER1_FAST_OCR1A_PWM_MODE()					do{set_bit(TCCR1B,WGM13);set_bit(TCCR1B,WGM12);set_bit(TCCR1A,WGM11);set_bit(TCCR1A,WGM10);}while(0)
// Output compare A behavior
#define TIMER1_OC1A_OFF()								do{clr_bit(TCCR1A,COM1A1);clr_bit(TCCR1A,COM1A0);}while(0)
#define TIMER1_OC1A_TOGGLE_ON_COMPARE()					do{clr_bit(TCCR1A,COM1A1);set_bit(TCCR1A,COM1A0);}while(0)
#define TIMER1_OC1A_CLEAR_ON_COMPARE()					do{set_bit(TCCR1A,COM1A1);clr_bit(TCCR1A,COM1A0);}while(0)
#define TIMER1_OC1A_SET_ON_COMPARE()					do{set_bit(TCCR1A,COM1A1);set_bit(TCCR1A,COM1A0);}while(0)
#define TIMER1_OC1A_NON_INVERTED_MODE()					do{set_bit(TCCR1A,COM1A1);clr_bit(TCCR1A,COM1A0);}while(0)
#define TIMER1_OC1A_INVERTED_MODE()						do{set_bit(TCCR1A,COM1A1);set_bit(TCCR1A,COM1A0);}while(0)
// Output compare B behavior
#define TIMER1_OC1B_OFF()								do{clr_bit(TCCR1A,COM1B1);clr_bit(TCCR1A,COM1B0);}while(0)
#define TIMER1_OC1B_TOGGLE_ON_COMPARE()					do{clr_bit(TCCR1A,COM1B1);set_bit(TCCR1A,COM1B0);}while(0)
#define TIMER1_OC1B_CLEAR_ON_COMPARE()					do{set_bit(TCCR1A,COM1B1);clr_bit(TCCR1A,COM1B0);}while(0)
#define TIMER1_OC1B_SET_ON_COMPARE()					do{set_bit(TCCR1A,COM1B1);set_bit(TCCR1A,COM1B0);}while(0)
#define TIMER1_OC1B_NON_INVERTED_MODE()					do{set_bit(TCCR1A,COM1B1);clr_bit(TCCR1A,COM1B0);}while(0)
#define TIMER1_OC1B_INVERTED_MODE()						do{set_bit(TCCR1A,COM1B1);set_bit(TCCR1A,COM1B0);}while(0)
// Timer overflow interruption configuration
#define TIMER1_ACTIVATE_OVF_INTERRUPT()					set_bit(TIMSK1,TOIE1)
#define TIMER1_DEACTIVATE_OVF_INTERRUPT()				clr_bit(TIMSK1,TOIE1)
#define TIMER1_CLEAR_OVF_REQUEST()						set_bit(TIFR1,TOV1)
// Output compare A interruption configuration
#define TIMER1_ACTIVATE_COMPARE_A_INTERRUPT()			set_bit(TIMSK1,OCIE1A)
#define TIMER1_DEACTIVATE_COMPARE_A_INTERRUPT()			clr_bit(TIMSK1,OCIE1A)
#define TIMER1_CLEAR_COMPARE_A_REQUEST()				set_bit(TIFR1,OCF1A)
// Output compare B interruption configuration
#define TIMER1_ACTIVATE_COMPARE_B_INTERRUPT()			set_bit(TIMSK1,OCIE1B)
#define TIMER1_DEACTIVATE_COMPARE_B_INTERRUPT()			clr_bit(TIMSK1,OCIE1B)
#define TIMER1_CLEAR_COMPARE_B_REQUEST()				set_bit(TIFR1,OCF1B)
// Force output compare
#define TIMER1_FORCE_COMPARE_A()						set_bit(TCCR1C,FOC0A)
#define TIMER1_FORCE_COMPARE_B()						set_bit(TCCR1C,FOC0B)
// Timer value
#define TIMER1_COUNTER_CONFIGURE(value)					TCNT1 = value
#define TIMER1_COMPARE_A_CONFIGURE(value)				OCR1A = value
#define TIMER1_COMPARE_B_CONFIGURE(value)				OCR1B = value

// -----------------------------------------------------------------------------
// Timer/counter 2-------------------------------------------------------------

// Clock prescaler selection
#define TIMER2_CLOCK_DISABLE()					do{clr_bit(TCCR2B,CS22);clr_bit(TCCR2B,CS21);clr_bit(TCCR2B,CS20);}while(0)
#define TIMER2_CLOCK_PRESCALER_OFF()			do{clr_bit(TCCR2B,CS22);clr_bit(TCCR2B,CS21);set_bit(TCCR2B,CS20);}while(0)
#define TIMER2_CLOCK_PRESCALER_8()				do{clr_bit(TCCR2B,CS22);set_bit(TCCR2B,CS21);clr_bit(TCCR2B,CS20);}while(0)
#define TIMER2_CLOCK_PRESCALER_32()				do{clr_bit(TCCR2B,CS22);set_bit(TCCR2B,CS21);set_bit(TCCR2B,CS20);}while(0)
#define TIMER2_CLOCK_PRESCALER_64()				do{set_bit(TCCR2B,CS22);clr_bit(TCCR2B,CS21);clr_bit(TCCR2B,CS20);}while(0)
#define TIMER2_CLOCK_PRESCALER_128()			do{set_bit(TCCR2B,CS22);clr_bit(TCCR2B,CS21);set_bit(TCCR2B,CS20);}while(0)
#define TIMER2_CLOCK_PRESCALER_256()			do{set_bit(TCCR2B,CS22);set_bit(TCCR2B,CS21);clr_bit(TCCR2B,CS20);}while(0)
#define TIMER2_CLOCK_PRESCALER_1024()			do{set_bit(TCCR2B,CS22);set_bit(TCCR2B,CS21);set_bit(TCCR2B,CS20);}while(0)
// Operation mode selection
#define TIMER2_NORMAL_MODE()					do{clr_bit(TCCR2B,WGM22);clr_bit(TCCR2A,WGM21);clr_bit(TCCR2A,WGM20);}while(0)
#define TIMER2_CTC_MODE()						do{clr_bit(TCCR2B,WGM22);set_bit(TCCR2A,WGM21);clr_bit(TCCR2A,WGM20);}while(0)
#define TIMER2_FAST_PWM_MAX_MODE()				do{clr_bit(TCCR2B,WGM22);set_bit(TCCR2A,WGM21);set_bit(TCCR2A,WGM20);}while(0)
#define TIMER2_FAST_PWM_OCR0A_MODE()			do{set_bit(TCCR2B,WGM22);set_bit(TCCR2A,WGM21);set_bit(TCCR2A,WGM20);}while(0)
#define TIMER2_PHASE_CORRECT_MAX_PWM_MODE()		do{clr_bit(TCCR2B,WGM22);clr_bit(TCCR2A,WGM21);set_bit(TCCR2A,WGM20);}while(0)
#define TIMER2_PHASE_CORRECT_OCR0A_PWM_MODE()	do{set_bit(TCCR2B,WGM22);clr_bit(TCCR2A,WGM21);set_bit(TCCR2A,WGM20);}while(0)
// Output compare A behavior
#define TIMER2_OC2A_OFF()						do{clr_bit(TCCR2A,COM2A1);clr_bit(TCCR2A,COM0A0);}while(0)
#define TIMER2_OC2A_TOGGLE_ON_COMPARE()			do{clr_bit(TCCR2A,COM2A1);set_bit(TCCR2A,COM0A0);}while(0)
#define TIMER2_OC2A_CLEAR_ON_COMPARE()			do{set_bit(TCCR2A,COM2A1);clr_bit(TCCR2A,COM0A0);}while(0)
#define TIMER2_OC2A_SET_ON_COMPARE()			do{set_bit(TCCR2A,COM2A1);set_bit(TCCR2A,COM0A0);}while(0)
#define TIMER2_OC2A_NON_INVERTED_MODE()			do{set_bit(TCCR2A,COM2A1);clr_bit(TCCR2A,COM0A0);}while(0)
#define TIMER2_OC2A_INVERTED_MODE()				do{set_bit(TCCR2A,COM2A1);set_bit(TCCR2A,COM0A0);}while(0)
// Output compare B behavior
#define TIMER2_OC2B_OFF()						do{clr_bit(TCCR2A,COM2B1);clr_bit(TCCR2A,COM2B0);}while(0)
#define TIMER2_OC2B_TOGGLE_ON_COMPARE()			do{clr_bit(TCCR2A,COM2B1);set_bit(TCCR2A,COM2B0);}while(0)
#define TIMER2_OC2B_CLEAR_ON_COMPARE()			do{set_bit(TCCR2A,COM2B1);clr_bit(TCCR2A,COM2B0);}while(0)
#define TIMER2_OC2B_SET_ON_COMPARE()			do{set_bit(TCCR2A,COM2B1);set_bit(TCCR2A,COM2B0);}while(0)
#define TIMER2_OC2B_NON_INVERTED_MODE()			do{set_bit(TCCR2A,COM2B1);clr_bit(TCCR2A,COM2B0);}while(0)
#define TIMER2_OC2B_INVERTED_MODE()				do{set_bit(TCCR2A,COM2B1);set_bit(TCCR2A,COM2B0);}while(0)
// Timer overflow interruption configuration
#define TIMER2_ACTIVATE_OVF_INTERRUPT()			set_bit(TIMSK2,TOIE2)
#define TIMER2_DEACTIVATE_OVF_INTERRUPT()		clr_bit(TIMSK2,TOIE2)
#define TIMER2_CLEAR_OVF_REQUEST()				set_bit(TIFR2,TOV2)
// Output compare A interruption configuration
#define TIMER2_ACTIVATE_COMPARE_A_INTERRUPT()	set_bit(TIMSK2,OCIE2A)
#define TIMER2_DEACTIVATE_COMPARE_A_INTERRUPT()	clr_bit(TIMSK2,OCIE2A)
#define TIMER2_CLEAR_COMPARE_A_REQUEST()		set_bit(TIFR2,OCF2A)
// Output compare B interruption configuration
#define TIMER2_ACTIVATE_COMPARE_B_INTERRUPT()	set_bit(TIMSK2,OCIE2B)
#define TIMER2_DEACTIVATE_COMPARE_B_INTERRUPT()	clr_bit(TIMSK2,OCIE2B)
#define TIMER2_CLEAR_COMPARE_B_REQUEST()		set_bit(TIFR2,OCF2B)
// Force output compare
#define TIMER2_FORCE_COMPARE_A()				set_bit(TCCR2B,FOC2A)
#define TIMER2_FORCE_COMPARE_B()				set_bit(TCCR2B,FOC2B)
// Timer value
#define TIMER2_COUNTER_CONFIGURE(value)			TCNT2 = value
#define TIMER2_COMPARE_A_CONFIGURE(value)		OCR2A = value
#define TIMER2_COMPARE_B_CONFIGURE(value)		OCR2B = value
// Input capture
// TODO
// TODO
// TODO
// TODO
// Assyncronous mode
// TODO
// TODO
// TODO
// TODO

// -----------------------------------------------------------------------------
// Serial Peripheral Interface -------------------------------------------------


#define SPI_PORT                        PORTB
#define SPI_DDR				DDRB
#define SPI_CE                          PB0
#define SPI_SS                          PB2  //chip select ou CSN
#define SPI_MOSI			PB3
#define SPI_MISO			PB4
#define SPI_SCK				PB5
#define SPI_CLOCK_PRESCALER_2		4
#define SPI_CLOCK_PRESCALER_4		0
#define SPI_CLOCK_PRESCALER_8		5
#define SPI_CLOCK_PRESCALER_16		1
#define SPI_CLOCK_PRESCALER_32		6
#define SPI_CLOCK_PRESCALER_64		2
#define SPI_CLOCK_PRESCALER_128		3
#define SPI_ENABLE()			set_bit(SPCR,SPE)
#define SPI_DISABLE()			clr_bit(SPCR,SPE)
#define SPI_INTERRUPT_ENABLE()		set_bit(SPCR,SPIE)
#define SPI_INTERRUPT_DISABLE()		clr_bit(SPCR,SPIE)
#define SPI_MSB_FIRST()			clr_bit(SPCR,DORD)
#define SPI_LSB_FIRST()			set_bit(SPCR,DORD)
#define SPI_SCK_IDLE_LOW()		clr_bit(SPCR,CPOL)
#define SPI_SCK_IDLE_HIGH()		set_bit(SPCR,CPOL)
#define SPI_SAMPLE_LEADING_EDGE()	clr_bit(SPCR,CPHA)
#define SPI_SAMPLE_TRAILING_EDGE()	set_bit(SPCR,CPHA)

void spiMasterInit(uint8 clockPrescaller);
uint8_t spi_transfer(uint8_t data);
void spiSlaveInit(void);
uint8 spiSlaveReceive(void);

//Funcoes vindas do exemplo de funcionamento do nRF24L01
// Write data using SPI
void spi_write_data(uint8_t * dataout, uint8_t len);

// Read data using SPI
uint8_t spi_read_data(uint8_t * datain, uint8_t len);


// -----------------------------------------------------------------------------
// Analog/Digital Converter ----------------------------------------------------

#define ADC_REFERENCE_AREF()			do{clr_bit(ADMUX,REFS1);clr_bit(ADMUX,REFS0);}while(0)
#define ADC_REFERENCE_AVCC()			do{clr_bit(ADMUX,REFS1);set_bit(ADMUX,REFS0);}while(0)
#define ADC_REFERENCE_INTERNAL()		do{set_bit(ADMUX,REFS1);set_bit(ADMUX,REFS0);}while(0)

#define ADC_RESULT_LEFT_ADJUST()		set_bit(ADMUX,ADLAR)
#define ADC_RESULT_RIGHT_ADJUST()		clr_bit(ADMUX,ADLAR)
#define ADC_SELECT_CHANNEL_0()			do{clr_bit(ADMUX,MUX3);clr_bit(ADMUX,MUX2);clr_bit(ADMUX,MUX1);clr_bit(ADMUX,MUX0);}while(0)
#define ADC_SELECT_CHANNEL_1()			do{clr_bit(ADMUX,MUX3);clr_bit(ADMUX,MUX2);clr_bit(ADMUX,MUX1);set_bit(ADMUX,MUX0);}while(0)
#define ADC_SELECT_CHANNEL_2()			do{clr_bit(ADMUX,MUX3);clr_bit(ADMUX,MUX2);set_bit(ADMUX,MUX1);clr_bit(ADMUX,MUX0);}while(0)
#define ADC_SELECT_CHANNEL_3()			do{clr_bit(ADMUX,MUX3);clr_bit(ADMUX,MUX2);set_bit(ADMUX,MUX1);set_bit(ADMUX,MUX0);}while(0)
#define ADC_SELECT_CHANNEL_4()			do{clr_bit(ADMUX,MUX3);set_bit(ADMUX,MUX2);clr_bit(ADMUX,MUX1);clr_bit(ADMUX,MUX0);}while(0)
#define ADC_SELECT_CHANNEL_5()			do{clr_bit(ADMUX,MUX3);set_bit(ADMUX,MUX2);clr_bit(ADMUX,MUX1);set_bit(ADMUX,MUX0);}while(0)
#define ADC_SELECT_CHANNEL_6()			do{clr_bit(ADMUX,MUX3);set_bit(ADMUX,MUX2);set_bit(ADMUX,MUX1);clr_bit(ADMUX,MUX0);}while(0)
#define ADC_SELECT_CHANNEL_7()			do{clr_bit(ADMUX,MUX3);set_bit(ADMUX,MUX2);set_bit(ADMUX,MUX1);set_bit(ADMUX,MUX0);}while(0)
#define ADC_SELECT_CHANNEL_TEMPERATURE()	do{set_bit(ADMUX,MUX3);clr_bit(ADMUX,MUX2);clr_bit(ADMUX,MUX1);clr_bit(ADMUX,MUX0);}while(0)
#define ADC_SELECT_CHANNEL_REFERENCE()		do{set_bit(ADMUX,MUX3);set_bit(ADMUX,MUX2);set_bit(ADMUX,MUX1);clr_bit(ADMUX,MUX0);}while(0)
#define ADC_SELECT_CHANNEL_GROUND()		do{set_bit(ADMUX,MUX3);set_bit(ADMUX,MUX2);set_bit(ADMUX,MUX1);set_bit(ADMUX,MUX0);}while(0)
#define ADC_SELECT_CHANNEL(channel)		ADMUX = ((ADMUX & 0xF0) | channel)
#define ADC_ENABLE()				set_bit(ADCSRA,ADEN)
#define ADC_DISABLE()				clr_bit(ADCSRA,ADEN)
#define ADC_START_CONVERSION()			set_bit(ADCSRA,ADSC)
#define ADC_WAIT_CONVERSION_FINISH()     while (tst_bit(ADCSRA, ADSC));
#define ADC_ATIVATE()				set_bit(ADCSRA,ADIE)
#define ADC_DEACTIVATE()			clr_bit(ADCSRA,ADIE)
#define ADC_ENABLE_AUTOMATIC_MODE()		set_bit(ADCSRA,ADATE)
#define ADC_DISABLE_AUTOMATIC_MODE()		clr_bit(ADCSRA,ADATE)
#define ADC_TRIGGER_CONTINUOUS()		do{clr_bit(ADCSRB,ADTS2);clr_bit(ADCSRB,ADTS1);clr_bit(ADCSRB,ADTS0);}while(0)
#define ADC_TRIGGER_COMPARATOR()		do{clr_bit(ADCSRB,ADTS2);clr_bit(ADCSRB,ADTS1);set_bit(ADCSRB,ADTS0);}while(0)
#define ADC_TRIGGER_INT_0()			do{clr_bit(ADCSRB,ADTS2);set_bit(ADCSRB,ADTS1);clr_bit(ADCSRB,ADTS0);}while(0)
#define ADC_TRIGGER_TIMER_0_COMPARATOR()	do{clr_bit(ADCSRB,ADTS2);set_bit(ADCSRB,ADTS1);set_bit(ADCSRB,ADTS0);}while(0)
#define ADC_TRIGGER_TIMER_0_OVERFLOW()		do{set_bit(ADCSRB,ADTS2);clr_bit(ADCSRB,ADTS1);clr_bit(ADCSRB,ADTS0);}while(0)
#define ADC_TRIGGER_TIMER_1_COMPARATOR()	do{set_bit(ADCSRB,ADTS2);clr_bit(ADCSRB,ADTS1);set_bit(ADCSRB,ADTS0);}while(0)
#define ADC_TRIGGER_TIMER_1_OVERFLOW()		do{set_bit(ADCSRB,ADTS2);set_bit(ADCSRB,ADTS1);clr_bit(ADCSRB,ADTS0);}while(0)
#define ADC_TRIGGER_TIMER_1_EVENT()		do{set_bit(ADCSRB,ADTS2);set_bit(ADCSRB,ADTS1);set_bit(ADCSRB,ADTS0);}while(0)
#define ADC_CLOCK_PRESCALER_OFF()		do{clr_bit(ADCSRA,ADPS2);clr_bit(ADCSRA,ADPS1);clr_bit(ADCSRA,ADPS0);}while(0)
#define ADC_CLOCK_PRESCALER_2()			do{clr_bit(ADCSRA,ADPS2);clr_bit(ADCSRA,ADPS1);set_bit(ADCSRA,ADPS0);}while(0)
#define ADC_CLOCK_PRESCALER_4()			do{clr_bit(ADCSRA,ADPS2);set_bit(ADCSRA,ADPS1);clr_bit(ADCSRA,ADPS0);}while(0)
#define ADC_CLOCK_PRESCALER_8()			do{clr_bit(ADCSRA,ADPS2);set_bit(ADCSRA,ADPS1);set_bit(ADCSRA,ADPS0);}while(0)
#define ADC_CLOCK_PRESCALER_16()		do{set_bit(ADCSRA,ADPS2);clr_bit(ADCSRA,ADPS1);clr_bit(ADCSRA,ADPS0);}while(0)
#define ADC_CLOCK_PRESCALER_32()		do{set_bit(ADCSRA,ADPS2);clr_bit(ADCSRA,ADPS1);set_bit(ADCSRA,ADPS0);}while(0)
#define ADC_CLOCK_PRESCALER_64()		do{set_bit(ADCSRA,ADPS2);set_bit(ADCSRA,ADPS1);clr_bit(ADCSRA,ADPS0);}while(0)
#define ADC_CLOCK_PRESCALER_128()		do{set_bit(ADCSRA,ADPS2);set_bit(ADCSRA,ADPS1);set_bit(ADCSRA,ADPS0);}while(0)
#define ADC_DIGITAL_INPUT_0_DISABLE()		set_bit(DIDR0,ADC0D)
#define ADC_DIGITAL_INPUT_0_ENABLE()		clr_bit(DIDR0,ADC0D)
#define ADC_DIGITAL_INPUT_1_DISABLE()		set_bit(DIDR0,ADC1D)
#define ADC_DIGITAL_INPUT_1_ENABLE()		clr_bit(DIDR0,ADC1D)
#define ADC_DIGITAL_INPUT_2_DISABLE()		set_bit(DIDR0,ADC2D)
#define ADC_DIGITAL_INPUT_2_ENABLE()		clr_bit(DIDR0,ADC2D)
#define ADC_DIGITAL_INPUT_3_DISABLE()		set_bit(DIDR0,ADC3D)
#define ADC_DIGITAL_INPUT_3_ENABLE()		clr_bit(DIDR0,ADC3D)
#define ADC_DIGITAL_INPUT_4_DISABLE()		set_bit(DIDR0,ADC4D)
#define ADC_DIGITAL_INPUT_4_ENABLE()		clr_bit(DIDR0,ADC4D)
#define ADC_DIGITAL_INPUT_5_DISABLE()		set_bit(DIDR0,ADC5D)
#define ADC_DIGITAL_INPUT_5_ENABLE()		clr_bit(DIDR0,ADC5D)

adcConfiguration_t adcGetConfiguration(void);
void adcLoadConfiguration(adcConfiguration_t config);
void adcStartConversion(void);
void adcSelectChannel(uint8 channel);
void adcWaitConversionFinish(void);

//debug functions
void lcd_debug(char * frase);


#endif
