/**
* @file SysTick_Handler.c
* @author Alejandro López Rodríguez and Ana Maria Casanova López
* @date 06/06/2021
* @brief SysTick Handler. This function, along with other interrupt handlers is 
* defined at stm32f4xx_it.c. In order to address it, we have created this file.
* This file is not included on the project
*/

/**
* @brief Increases a variable each ms and if the lift is moving, updates the
* stepper output according to the direction of the movememt
* @param void
* @return void
*/
void SysTick_Handler(void)
{
  HAL_IncTick();

	if(liftIsMoving() && DirUP)
		(step_index == 7)? step_index = 0 : step_index++;
	else if(liftIsMoving() && DirDOWN)
		(step_index == 0)? step_index = 7 : step_index--;
		
		GPIOB->ODR &= ~(0xF << 12);
		GPIOB->ODR |= step_positions[step_index] << 12;	
}