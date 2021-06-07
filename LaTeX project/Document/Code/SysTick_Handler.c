void SysTick_Handler(void){
  HAL_IncTick();
	
  if(liftIsMoving() && DirUP)
	(step_index == 7)? step_index = 0 : step_index++;
  else if(liftIsMoving() && DirDOWN)
	(step_index == 0)? step_index = 7 : step_index--;
		
  GPIOB->ODR &= ~(0xF << 12);
  GPIOB->ODR |= step_positions[step_index] << 12;	
}