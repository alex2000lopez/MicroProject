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

	
void LedOrange_pwm_OnValue_percent(uint8_t value){
	
	uint32_t Pulse = 0;
	
	if(value > 100) Pulse = 10000;
	else Pulse = (uint32_t)value * 100;
	
	TIM4->CCR2 = Pulse;
}
void LedRed_pwm_OnValue_percent(uint8_t value){
	
	uint32_t Pulse = 0;
	
	if(value > 100) Pulse = 10000;
	else Pulse = (uint32_t)value * 100;

  TIM4->CCR3 = Pulse;
}


/**
* @brief Initialize TIM4 PWMs 
* @param None
* @return None
*/
void initPWM(void){
	
    TIM_OC_InitTypeDef TIM4CH2;
    TIM4CH2.OCMode = TIM_OCMODE_PWM1;
    TIM4CH2.Pulse = 0;
    TIM4CH2.OCPolarity = TIM_OCPOLARITY_HIGH;
    TIM4CH2.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim4, &TIM4CH2, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
	
    TIM_OC_InitTypeDef TIM4CH3;
    TIM4CH3.OCMode = TIM_OCMODE_PWM1;
    TIM4CH3.Pulse = 0;
    TIM4CH3.OCPolarity = TIM_OCPOLARITY_HIGH;
    TIM4CH3.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim4, &TIM4CH3, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
		
}

/**
* @brief Initialize led hardware
* @param None
* @return None
*/
void Led_H_Init(void){
	
	//Initialize PWM
	//HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
	//HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
	initPWM();
	
	//Initially, on ground floor (BLUE ON) no motor up/down (RED and ORANGE OFF)
	HAL_GPIO_WritePin(GPIOD,LD6_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,LD4_Pin,GPIO_PIN_RESET);
	
	LedOrange_pwm_OnValue_percent(75);
	LedRed_pwm_OnValue_percent(25);
}
