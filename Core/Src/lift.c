/**
* @file lift.c
* @author Alejandro López Rodríguez and Ana Maria Casanova López
* @date 06/06/2021
* @brief Lift Functions
*/

/* Includes ------------------------------------------------------------------*/

#include "main.h"
#include "timer.h"
#include "button.h"
#include "led.h"
#include "doors.h"
#include "motor.h"

#include "uart.h"
#include "string.h"


/**
* @brief Main Init -> Initialize the lift by calling the required sub-functions
* @param void
* @return void
*/
void lift_Init(void){

	LED_Init();
	Doors_Init();
	Button_Init();
	Motor_Init();
	
	unsigned char mssg[] = "Initialization Complete :) \r\n\n";
	HAL_UART_Transmit(&huart2, mssg, sizeof(mssg)/sizeof(mssg[0]),0xffff);
	
}

/**
* @brief Retrieve whether the lift is moving or stopped
* @param void
* @return 1 if it is moving, 0 if it is stopped
*/
uint32_t liftIsMoving(void){

	if(current_floor == MOVING) return 1;
	else return 0;
}

/**
* @brief Retrieve the floor where the lift is
* @param void
* @return 0 ground floor, 1 first floor, -1 moving
*/
int32_t liftFloor(void){

	if(liftIsMoving() == 0x00){
		if(current_floor == GROUND_FLOOR) return 0;
		else if(current_floor == FIRST_FLOOR) return 1;
	}
	return -1;
}


/**
* @brief Control the lift to go up and indicate it via the UART
*	@param void
* @return void
*/
void liftUp(void){

	CloseDoors();
	
	DirUP = true;    
	DirDOWN = false;
	
	LED_PWM_Percent(LD3_Pin, 25);
	LED_PWM_Percent(LD5_Pin, 50);
	
	current_floor = MOVING;
	Moving();			

	unsigned char mssg[]="Lift moving UP \r\n";
	HAL_UART_Transmit(&huart2,mssg,sizeof(mssg)/sizeof(mssg[0]),0xffff);
	
	htim3.Instance->SR &= ~0x01;		/* Clear the UIF flag from the SR (Status register) */
	HAL_TIM_Base_Start_IT(&htim3);  /* Start TIM3 (5s) */
	
}

/**
* @brief Control the lift to go down and indicate it via the UART
* @param void
* @return void
*/
void liftDown(void){
	
	CloseDoors();
	
	DirUP = false;    
	DirDOWN = true;
	
	LED_PWM_Percent(LD3_Pin, 75);
	LED_PWM_Percent(LD5_Pin, 50);
	
	current_floor = MOVING;
	Moving();			

	unsigned char mssg[]="Lift moving DOWN \r\n";
	HAL_UART_Transmit(&huart2,mssg,sizeof(mssg)/sizeof(mssg[0]),0xffff);
	
	htim3.Instance->SR &= ~0x01;   /* Clear the UIF flag from the SR (Status register) */
	HAL_TIM_Base_Start_IT(&htim3); /* Start TIM3 (5s) */
	
}

/**
* @brief Stop the lift, open the doors and send the current floor via UART
* @param void
* @return None
*/
void liftStop(void){

		TurnOffLEDPWM();									/* Turn off the LEDs */
			
		/* Update current floor */
		if(DirUP){
			current_floor = FIRST_FLOOR;
			FirstFloor();
		}
		else if(DirDOWN){ 
			current_floor = GROUND_FLOOR;
			GroundFloor();
		}
		
		unsigned char ground_floor_mssg[] = "Floor: Ground Floor \r\n\n";
		unsigned char first_floor_mssg[] = "Floor: First Floor \r\n\n";
				
		if(liftFloor() == 0){
			HAL_UART_Transmit(&huart2, ground_floor_mssg, sizeof(ground_floor_mssg)/sizeof(ground_floor_mssg[0]),0xffff);
		}
		else if(liftFloor() == 1){
			HAL_UART_Transmit(&huart2, first_floor_mssg, sizeof(first_floor_mssg)/sizeof(first_floor_mssg[0]),0xffff);
		}
			
		OpenDoors();	
		
		htim3.Instance->SR &= ~0x01;   /* Clear the UIF flag from the SR (Status register) */
		EXTI->PR |= 0x0001; 					 /*Clear the EXTI0 Pending Register */
				
		HAL_NVIC_EnableIRQ(TIM3_IRQn);		/* Enable the TIM3 interrupt */
		HAL_NVIC_EnableIRQ(EXTI0_IRQn);	 	/* Enable the EXTI interrupt */
}
/* EOF */
