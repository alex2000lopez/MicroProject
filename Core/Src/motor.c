/**
* @file motor.c
* @Author Alejandro López Rodríguez and Ana Maria Casanova López
* @date 16/05/2021
* @brief Motor handler
*/

#include "motor.h"

UART_HandleTypeDef huart2;

/**
* @brief Initialize motor hardware
* @return void
*/
void motor_H_Init(void){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	__HAL_RCC_GPIOB_CLK_ENABLE();
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);
	GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	/*UART*/
	huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&huart2);
}

//Stop
/**
* @brief motor stop
* @return void
*/
void motorStop(void){}

//Spinning clockwise
/**
* @brief motor spinning clockwise
* @return void
*/
void motorSpinClock(void){}

//Spinning counter-clockwise
/**
* @brief motor spinning counter-clockwise
* @return void
*/
void motorSpinCClock(void){}
	