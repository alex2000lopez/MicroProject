/**
* @file led.c
* @author Alejandro López Rodríguez and Ana Maria Casanova López
* @date 06/06/2021
* @brief Led Functions
*/

/* Includes ------------------------------------------------------------------*/

#include "led.h"
#include "timer.h"


/**
* @brief Configure the floor LEDs
* @param void
* @return void
*/
void initLEDGPIO(void){

	/* Enable GPIOD clock */
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
	/* Configuration Struct */
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	/* Configure GPIO pins : PD12 PD15 (LD4 LD6) */
  GPIO_InitStruct.Pin = LD4_Pin|LD6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}


/**
* @brief Initialize TIM4 PWMs 
* @param None
* @return None
*/
void initLEDsPWM(void){
	
	/* Initialize TIM4 Channel 2 -> Orange LED */
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
		
}

/**
* @brief Control the duty cycle of the TIM4 PWM signal
* @param uint16_t LED, uint8_t value
* @return None
*/
void LED_PWM_Percent(uint16_t LED, uint8_t value){
	
	uint32_t Pulse = 0;
	
	/* Calculate the Pulse value given a duty cycle percentage */
	if(value > 100) Pulse = 9999;
	else if(value == 0) Pulse = 0;
	else Pulse = (uint32_t)(value * 100 - 1);
	
	/* Update the PWM duty cycle by modifying the CCRx value */
	if(LED == LD3_Pin) /* Orange LED */
		TIM4->CCR2 = Pulse; 
	else if(LED == LD5_Pin) /* Red LED */
		TIM4->CCR3 = Pulse;
	
}

/**
* @brief Set TIM4 PWM duty cycle to 0 -> Turn off red and orange LEDs 
* @param None
* @return None
*/
void TurnOffLEDPWM(void){
	
	LED_PWM_Percent(LD3_Pin, 0);
	LED_PWM_Percent(LD5_Pin, 0);

}

/**
* @brief Turn OFF green and blue LEDs to indicate that the lift is moving
* @param None
* @return None
*/
void Moving(void){
	
	HAL_GPIO_WritePin(GPIOD,LD6_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD,LD4_Pin,GPIO_PIN_RESET);
}


/**
* @brief Turn ON blue LED to indicate that the lift is in the ground floor
* @param None
* @return None
*/
void GroundFloor(void){
	
	HAL_GPIO_WritePin(GPIOD,LD6_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,LD4_Pin,GPIO_PIN_RESET);
}

/**
* @brief Turn ON green LED to indicate that the lift is in the first floor
* @param None
* @return None
*/
void FirstFloor(void){
	
	HAL_GPIO_WritePin(GPIOD,LD6_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD,LD4_Pin,GPIO_PIN_SET);
}


/**
* @brief Initialize the LED hardware
* @param None
* @return None
*/
void LED_Init(void){
	
	GroundFloor();
	initLEDsPWM();
	initLEDGPIO();
	
}
