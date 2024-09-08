/*
 * exercise2.c
 *
 *  Created on: Sep 8, 2024
 *      Author: Thuyen
 */
#include "exercise2.h"

int led_status = 0;


void init_exercise2(){

}

void led_green_on(){
	HAL_GPIO_WritePin(LED11_GREEN_GPIO_Port, LED11_GREEN_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED12_YELLOW_GPIO_Port, LED11_GREEN_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED11_GREEN_GPIO_Port, LED1_RED_Pin, GPIO_PIN_SET);
}

void led_yellow_on(){
	HAL_GPIO_WritePin(LED11_GREEN_GPIO_Port, LED11_GREEN_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED12_YELLOW_GPIO_Port, LED11_GREEN_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED11_GREEN_GPIO_Port, LED1_RED_Pin, GPIO_PIN_SET);
}

void led_yellow_on(){
	HAL_GPIO_WritePin(LED11_GREEN_GPIO_Port, LED11_GREEN_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED12_YELLOW_GPIO_Port, LED11_GREEN_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED11_GREEN_GPIO_Port, LED1_RED_Pin, GPIO_PIN_RESET);
}

void exercise2_run(){

}
