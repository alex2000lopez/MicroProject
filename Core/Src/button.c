/**
* @file button.c
* @author Alejandro López Rodríguez and Ana Maria Casanova López
* @date 06/06/2021
* @brief Button Functions
*/

/* Includes ------------------------------------------------------------------*/

#include "button.h"

/**
* @brief Initialize the button hardware
* @param void
* @return void
*/
void Button_Init(void){

	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	/* Enable GPIOA clock */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	/*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}
	
/* EOF */
