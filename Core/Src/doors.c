// Necesitamos variable piso y llamada al ascensor

#include "doors.h"
#include "timer.h"
#define dooropen_pulse 0
#define doorclosed_pulse 5
extern TIM_HandleTypeDef htim1;
/**
* @brief Initialize the doors (servo) hardware
* @param void
* @return void
*/

void Doors_H_Init(void){
	Timer1_Init();
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
}

void Door_open(uint32_t floor){
	if(floor==0){
	//TIM1->CCR1 = dooropen_pulse;
	}
	else if(floor==1){
	//TIM1->CCR2 = dooropen_pulse;
	}
	
}

void Door_close(uint32_t floor){
	if(floor==0){
	//TIM1->CCR1 = doorclosed_pulse;
	}
	else if(floor==1){
	//TIM1->CCR2 = doorclosed_pulse;
	}	
}
