/**
* @file uart.h
* @author Alejandro López Rodríguez and Ana Maria Casanova López
* @date 06/06/2021
* @brief This file contains all the function prototypes for the uart.c file
*/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __UART_H__
#define __UART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

extern UART_HandleTypeDef huart2;
void USART2_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* __UART_H__ */
/* EOF */
