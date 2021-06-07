/**
* @file timer.h
* @author Alejandro López Rodríguez and Ana Maria Casanova López
* @date 06/06/2021
* @brief This file contains all the function prototypes for the timer.c file
*/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TIMER_H__
#define __TIMER_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

void TIM1_Init(void);
void TIM3_Init(void);
void TIM4_Init(void);

//void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);


#ifdef __cplusplus
}
#endif

#endif /* __TIMER_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
