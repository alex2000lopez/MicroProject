/**
* @file button.c
* @Author Alejandro López Rodríguez and Ana Maria Casanova López
* @date 16/05/2021
* @brief Button handler
*/
//Initialize hardware
//Interrupts
//Única variable botón(?)

#include "button.h"
/**
* @brief Initialize the button hardware
* @param void
* @return void
*/
void Button_H_Init(void){//#include "stm32f4xx_hal_rcc.h"
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);	
}

/**
* @brief Interrupt button?
* @param void
* @return void
*/
void Button_Interrupt(void){}
	