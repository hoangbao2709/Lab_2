/*
 * updateClockBuffer.c
 *
 *  Created on: Oct 1, 2024
 *      Author: PC
 */

#include "updateClockBuffer.h"

int hour = 15;
int minute = 8;
int second = 50;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};
int counter = 0;
int bit = 0;

void update7SEG(int index){
	switch (index){
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, 1);
		display7SEG(hour / 10);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, 1);
		display7SEG(hour % 10);
		break;
	case 2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, 0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, 1);
		display7SEG(minute / 10);
		break;
	case 3:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, 0);
		display7SEG(minute % 10);
		break;
	default :
		break;
	}
}

void updateClockBuffer (){
	if(counter == 0){
		if(bit == 0){
			HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, 0);
			bit = 1;
		}
		else{
			HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, 1);
			bit = 0;
		}
	}
	if(counter++ == 1){
		counter = 0;
	}
	update7SEG(index_led++);
	if(index_led == 4){
		index_led = 0;
	}
}
