/*
 * exercise3.c
 *
 *  Created on: Sep 11, 2024
 *      Author: Admin
 */

#include "exercise3.h"
int led_status_1 = GREEN1;
int led_status_2 = RED2;
int counter1 = time_GREEN;
int counter2 = time_RED;

void init_exercise3(){

}

void led_green_on_1(){
	HAL_GPIO_WritePin(LED11_GREEN_GPIO_Port, LED11_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED12_YELLOW_GPIO_Port, LED12_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, RESET);

	HAL_GPIO_WritePin(LED7_GREEN_GPIO_Port, LED7_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED6_YELLOW_GPIO_Port, LED6_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED5_RED_GPIO_Port, LED5_RED_Pin, RESET);
}

void led_green_on_2(){
	HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED3_YELLOW_GPIO_Port, LED3_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED4_RED_GPIO_Port, LED4_RED_Pin, RESET);

	HAL_GPIO_WritePin(LED10_GREEN_GPIO_Port, LED10_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED9_YELLOW_GPIO_Port, LED9_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED8_RED_GPIO_Port, LED8_RED_Pin, RESET);
}

void led_yellow_on_1(){
	HAL_GPIO_WritePin(LED11_GREEN_GPIO_Port, LED11_GREEN_Pin, RESET);
	HAL_GPIO_WritePin(LED12_YELLOW_GPIO_Port, LED12_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, RESET);

	HAL_GPIO_WritePin(LED7_GREEN_GPIO_Port, LED7_GREEN_Pin, RESET);
	HAL_GPIO_WritePin(LED6_YELLOW_GPIO_Port, LED6_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED5_RED_GPIO_Port, LED5_RED_Pin, RESET);
}

void led_yellow_on_2(){
	HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, RESET);
	HAL_GPIO_WritePin(LED3_YELLOW_GPIO_Port, LED3_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED4_RED_GPIO_Port, LED4_RED_Pin, RESET);

	HAL_GPIO_WritePin(LED10_GREEN_GPIO_Port, LED10_GREEN_Pin, RESET);
	HAL_GPIO_WritePin(LED9_YELLOW_GPIO_Port, LED9_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED8_RED_GPIO_Port, LED8_RED_Pin, RESET);
}

void led_red_on_1(){
	HAL_GPIO_WritePin(LED11_GREEN_GPIO_Port, LED11_GREEN_Pin, RESET);
	HAL_GPIO_WritePin(LED12_YELLOW_GPIO_Port, LED12_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED1_RED_GPIO_Port, LED1_RED_Pin, SET);

	HAL_GPIO_WritePin(LED7_GREEN_GPIO_Port, LED7_GREEN_Pin, RESET);
	HAL_GPIO_WritePin(LED6_YELLOW_GPIO_Port, LED6_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED5_RED_GPIO_Port, LED5_RED_Pin, SET);
}

void led_red_on_2(){
	HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, RESET);
	HAL_GPIO_WritePin(LED3_YELLOW_GPIO_Port, LED3_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED4_RED_GPIO_Port, LED4_RED_Pin, SET);

	HAL_GPIO_WritePin(LED10_GREEN_GPIO_Port, LED10_GREEN_Pin, RESET);
	HAL_GPIO_WritePin(LED9_YELLOW_GPIO_Port, LED9_YELLOW_Pin, RESET);
	HAL_GPIO_WritePin(LED8_RED_GPIO_Port, LED8_RED_Pin, SET);
}

void exercise3_run() {
    if (led_status_1 == RED1) {
        led_red_on_1();
        if (counter1 <= 0) {
            led_green_on_1();
            led_status_1 = GREEN1;
            counter1 = time_GREEN;
        }

        if (counter2 <= 0) {
            led_yellow_on_2();
            led_status_2 = YELLOW2;
            counter2 = time_YELLOW;
        }
    }

    if (led_status_1 == YELLOW1) {
        led_yellow_on_1();
        if (counter1 <= 0) {
            led_red_on_1();
            led_green_on_2();
            led_status_1 = RED1;
            led_status_2 = GREEN2;
            counter1 = time_RED;
            counter2 = time_GREEN;
        }
    }

    if (led_status_1 == GREEN1) {
        led_green_on_1();
        if (counter1 <= 0) {
            led_yellow_on_1();
            led_status_1 = YELLOW1;
            counter1 = time_YELLOW;
        }
    }

    if (led_status_2 == RED2) {
        led_red_on_2();
        if (counter2 <= 0) {
            led_green_on_2();
            led_status_2 = GREEN2;
            counter2 = time_GREEN;
        }

        if (counter1 <= 0 && led_status_1 != YELLOW1) { // Sync with led_status_1
            led_yellow_on_1();
            led_status_1 = YELLOW1;
            counter1 = time_YELLOW;
        }
    }

    if (led_status_2 == YELLOW2) {
        led_yellow_on_2();
        if (counter2 <= 0) {
            led_red_on_2();
            led_green_on_1();
            led_status_2 = RED2;
            led_status_1 = GREEN1;
            counter2 = time_RED;
            counter1 = time_GREEN;
        }
    }

    if (led_status_2 == GREEN2) {
        led_green_on_2();
        if (counter2 <= 0) {
            led_yellow_on_2();
            led_status_2 = YELLOW2;
            counter2 = time_YELLOW;
        }
    }

    // Decrement counters
    if (counter1 > 0) {
        counter1--;
    }

    if (counter2 > 0) {
        counter2--;
    }
}
