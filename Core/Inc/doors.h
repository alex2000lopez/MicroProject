/**
* @file doors.h
* @author Alejandro López Rodríguez and Ana Maria Casanova López
* @date 06/06/2021
* @brief This file contains all the function prototypes for the doors.c file
*/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DOORS_H__
#define __DOORS_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

extern void initDoorsPWM(void);
extern void Servo_PWM_Angle(uint16_t Servo, uint8_t angle);

extern void OpenDoors(void);
extern void CloseDoors(void);

extern void Doors_Init(void);


#ifdef __cplusplus
}
#endif
#endif /*__ DOORS_H__ */

/* EOF */
