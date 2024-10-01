/*
 * update7SEG.c
 *
 *  Created on: Oct 1, 2024
 *      Author: PC
 */


#include "update7SEG.h"

int led_buffer [4] = {1, 2, 3, 4};

void update7SEG ( int index ){
	switch (index){
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, 1);
		break ;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, 1);
		break ;
	case 2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, 0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, 1);
		break ;
	case 3:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, 0);
		break ;
	default :
		break ;
	}
	display7SEG(led_buffer[index]);
}
