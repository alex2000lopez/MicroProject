/**
* @file doors.c
* @author Alejandro López Rodríguez and Ana Maria Casanova López
* @date 06/06/2021
* @brief Door Functions
*/

/* Includes ------------------------------------------------------------------*/

#include "doors.h"
#include "timer.h"


/**
* @brief Initialize PWM Channels 1&2 of TIM1 
* @param void
* @return void
*/
void initDoorsPWM(void){

		HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1); /* Initialize TIM1 Channel 1 -> Left Servo */
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2); /* Initialize TIM1 Channel 2 -> Right Servo */
	
}

/**
* @brief Modify the servo angle by setting the value of the CCRx register 
* @param uint16_t Servo, uint8_t angle
* @return void
*/
void Servo_PWM_Angle(uint16_t Servo, uint8_t angle){
	
	uint32_t Pulse = 0;
	
	/* Calculate the Pulse value given a duty cycle percentage */
	if(angle > 180) Pulse = 224;
	else if(angle < 0) Pulse = 74;
	else Pulse = (uint32_t)(angle * (5/6.0) + 74);  /* (5/6.0) = (224-74)/180 */
	
	/* Update the PWM duty cycle by modifying the CCRx value */
	if(Servo == Servo1_Pin) /* Orange LED */
		TIM1->CCR1 = Pulse; 
	else if(Servo == Servo2_Pin) /* Red LED */
		TIM1->CCR2 = Pulse;
	
}

/**
* @brief Set servo angle to open position
* @param void
* @return void
*/
void OpenDoors(void){
	
	Servo_PWM_Angle(Servo1_Pin, 90);
	Servo_PWM_Angle(Servo2_Pin, 90);
}

/**
* @brief Set servo angle to closed position
* @param void
* @return void
*/
void CloseDoors(void){

	Servo_PWM_Angle(Servo1_Pin, 180);
	Servo_PWM_Angle(Servo2_Pin, 0);
}

/**
* @brief Initialize the door hardware and set the initial angle to "Open"
* @param void
* @return void
*/
void Doors_Init(){

	initDoorsPWM();
	OpenDoors();

}

/* EOF */
