/*
 * test.c
 *
 *  Created on: Sep 10, 2024
 *      Author: Admin
 */

#include "test.h"
int led_status = LED_OFF;
int counter = 0;
void init_test(){

}

void led_on(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
}

void led_off(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
}

void test_run(){
	if (led_status == 1){
			  led_on();
		  }
		  if (led_status == 0){
			  led_off();
		  }
		  counter ++;
		  if (counter == 3 && led_status == 1){
			  led_status = !led_status;
			  counter = 0;
		  }
		  if (counter == 2 && led_status == 0){
			  led_status = !led_status;
			  counter = 0;
		  }
}
