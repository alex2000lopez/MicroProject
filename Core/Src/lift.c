/**
* @file lift.c
* @Author Alejandro López Rodríguez and Ana Maria Casanova López
* @date 16/05/2021
* @brief Lift implementation
*/
#include "main.h"
#include "lift.h"
#include "button.h"
#include "doors.h"
#include "floor.h"
#include "led.h"
#include "motor.h"
#include "timer.h"


/**
* @brief Initialize the lift
* @param void
* @return void
*/
void lift_Init(void){
	Button_H_Init();
	Doors_H_Init();
	floor_Init();
	Led_H_Init();
	motor_H_Init();
	Timers_Init();

}
/**
* @brief Control the lift to go up
* @return void
*/
void liftUp(void){}
/**
* @brief Control the lift to go down
* @return void
*/
void liftDown(void){}
/**
* @brief Retrieve wether the lift is moving or stopped
* @return 1 if it is moving, 0 if it is stopped
*/
uint32_t liftIsMoving(void){}
/**
* @brief Retrieve the floor where the lift is
* @return 0 ground floor, 1 first floor, -1 moving
*/
int32_t liftFloor(void){}
	