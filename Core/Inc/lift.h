/**
* @file lift.h
* @author Alejandro López Rodríguez and Ana Maria Casanova López
* @date 06/06/2021
* @brief This file contains all the function prototypes for the lift.c file
*/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LIFT_H__
#define __LIFT_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* USER CODE BEGIN Includes */

extern void lift_Init(void);
extern void liftUp(void);
extern void liftDown(void);
extern void liftStop(void);

extern uint32_t liftIsMoving(void);
extern int32_t liftFloor(void);


#ifdef __cplusplus
}
#endif
#endif /*__ LIFT_H__ */

/* EOF */
