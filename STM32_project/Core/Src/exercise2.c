/*
 * exercise2.c
 *
 *  Created on: Sep 10, 2024
 *      Author: Admin
 */

#include "exercise2.h"

int led_status = RED;
int counter  = RED;

void init_exercise2(){

}

void led_green_on(){
	HAL_GPIO_WritePin(LED11_GREEN_GPIO_Port, LED11_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED12_YELLOW_GPIO_Port, LED12_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, RESET);
}

void led_yellow_on(){
	HAL_GPIO_WritePin(LED11_GREEN_GPIO_Port, LED11_GREEN_Pin, RESET);
	HAL_GPIO_WritePin(LED12_YELLOW_GPIO_Port, LED12_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, RESET);
}

void led_red_on(){
	HAL_GPIO_WritePin(LED11_GREEN_GPIO_Port, LED11_GREEN_Pin, RESET);
	HAL_GPIO_WritePin(LED12_YELLOW_GPIO_Port, LED12_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, SET);
}

void exercise2_run(){
	if (led_status == RED){
		led_red_on();
		if(counter <= 0){
			led_green_on();
			led_status = GREEN;
			counter = GREEN;
		}
	}

	if (led_status == GREEN){
		led_green_on();
		if(counter <= 0){
			led_yellow_on();
			led_status = YELLOW;
			counter = YELLOW;
		}
	}

	if (led_status == YELLOW){
		led_yellow_on();
		if (counter <= 0){
			led_red_on();
			led_status = RED;
			counter = RED;
		}
	}
	counter--;
}
