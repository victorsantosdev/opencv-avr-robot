/*
 * sensorIR.cpp
 *
 *  Created on: Dec 30, 2013
 *      Author: victor
 */

/* O sensor IR utiliza o canal 0 do ADC PORTC0 como porta de leitura */

#include "sensorIR.h"

/* Number of samples I read from ADC to give some result*/
#define N_SAMPLES 8
#define N_SHIFTS  3		//to avoid divisions I take 8 samples and I do three shifts left to divide result by 8 or 2^3

/*************************************************************************
Function: obstacleAlarm
Purpose:  just a beep function used when I found some obstacle
 **************************************************************************/
//void obstacleAlarm(void) {
//	uint8_t i = 0;
//	for(i=0; i <= 30; i++)
//	{
//		ALARM_PORT |= _BV(ALARM_BIT);
//		mydelay_us(75);
//		ALARM_PORT &= ~_BV(ALARM_BIT);
//		mydelay_us(75);
//	}
//}

/*************************************************************************
Function: ir_convertToDistance
Purpose:  returns the distance of IR sensor in centimeters
 **************************************************************************/
int ir_convertToDistance(int adc_value) {
	int distance;
	distance = (6787/(adc_value -3)) - 4;
	return distance;
}


/*************************************************************************
Function: verificaObstaculoIR
Purpose:  returns 1 if obstacle found using IR sensor
 **************************************************************************/
uint8_t verificaObstaculoIR(void)
{
	int result_tmp = 0;
	//uint8_t result_final = 0;
	int result_media = 0;
	uint8_t i = 0;
	//const int n_samples = 5;
	int distance_cm = 0;

	result_tmp = 0;

	for (i = N_SAMPLES; i > 0; i--) {
		ADC_START_CONVERSION();
		ADC_WAIT_CONVERSION_FINISH();
		result_tmp += ADC; 			//read the entire ADC
		//mydelay_us(25); 			//time of each samples in 1MHz ADC frequency
		//printf("leitura_ADC: %d\n", ADC );
	}

	result_media = (result_tmp >> N_SHIFTS); //I just get a average of read samples to avoid false positives
	//printf("leitura_ADC: %d\n", result_media );

	distance_cm = ir_convertToDistance(result_media);

//	if (result_media > 500) {
//		result_final = 1;
//	}
//
//	if (result_media <= 500) {
//		result_final = 0;
//	}
	result_media = 0;

	//return result_final;
	return distance_cm;
}


