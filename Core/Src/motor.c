/**
* @file motor.c
* @author Alejandro López Rodríguez and Ana Maria Casanova López
* @date 06/06/2021
* @brief Motor Functions
*/

/* Includes ------------------------------------------------------------------*/

#include "motor.h"

/**
* @brief Initialize the motor hardware
* @param void
* @return None
*/
void Motor_Init(void){

	/* Enable GPIOB clock */
	__HAL_RCC_GPIOB_CLK_ENABLE();
	
	/* Configuration Struct */
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
  /*Configure GPIO pins : PB12 PB13 PB14 PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

}

/* EOF */
