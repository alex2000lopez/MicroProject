/**
* @file led.h
* @author Alejandro López Rodríguez and Ana Maria Casanova López
* @date 06/06/2021
* @brief This file contains all the function prototypes for the led.c file
*/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LED_H__
#define __LED_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

void initLEDGPIO(void);
void initLEDsPWM(void);

extern void LED_PWM_Percent(uint16_t LED, uint8_t value);
extern void TurnOffLEDPWM(void);

extern void Moving(void);
extern void GroundFloor(void);
extern void FirstFloor(void);

extern void LED_Init(void);

#ifdef __cplusplus
}
#endif
#endif /*__ LED_H__ */

/* EOF */
