/**
* @file led.c
* @Author Alejandro López Rodríguez and Ana Maria Casanova López
* @date 16/05/2021
* @brief Led handler
*/

#include "main.h"
#include "tim.h"


//LED on
/**
* @brief Led On
* @param LED_GPIO
* @return None
*/
void Led_on(int LED_GPIO){}

//LED off
/**
* @brief Led Off
* @param LED_GPIO
* @return None
*/
void Led_off(int LED_GPIO){}

//Toggle LED with spec on and off time
/**
* @brief Led toggle
* @param int LED_GPIO, float t_on, float t_off
* @return None
*/
void Led_toggle(int LED_GPIO, float t_on, float t_off){}

	
void LedOrange_pwm_OnValue_percent(uint16_t value){
	int Pulse;
	switch(value){
		case 25: Pulse=10000/25;
			break;
		case 75: Pulse=10000/75;
			break;
		case 0: Pulse=0;
			break;
		default: Pulse=0;
	}
    TIM_OC_InitTypeDef sConfigOC;
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = Pulse;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);  
}
void LedRed_pwm_OnValue_percent(uint16_t value){
	int Pulse;
	switch(value){
		case 25: Pulse=10000/25;
			break;
		case 75: Pulse=10000/75;
			break;
		case 0: Pulse=0;
			break;
		default: Pulse=0;
	}
    TIM_OC_InitTypeDef sConfigOC;
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = Pulse;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);  
}


/**
* @brief Initialize led hardware
* @param None
* @return None
*/
void Led_H_Init(void){
	//Initialize PWM
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
//Initially, on ground floor (BLUE ON) no motor up/down (RED and ORANGE OFF)
	HAL_GPIO_WritePin(GPIOD,LD6_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,LD4_Pin,GPIO_PIN_RESET);
	LedOrange_pwm_OnValue_percent(0);
	LedRed_pwm_OnValue_percent(0);
}
