/*
 * exercise1.c
 *
 *  Created on: Sep 10, 2024
 *      Author: Admin
 */

#include "exercise1.h"

int led_status = LED_ON;

void led_on(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
}

void led_off(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
}

void exercise1_run(){
	switch(led_status){
	case LED_ON:
		led_off();
		led_status = LED_OFF;
		break;
	case LED_OFF:
		led_on();
		led_status = LED_ON;
		break;
	default:
		break;
	}
}
