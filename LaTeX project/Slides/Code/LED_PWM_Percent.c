void LED_PWM_Percent(uint16_t LED, uint8_t value){
	uint32_t Pulse = 0;
	/* Calculate the Pulse value given a duty cycle percentage */
	if(value > 100) Pulse = 9999;
	else if(value == 0) Pulse = 0;
	else Pulse = (uint32_t)(value * 100 - 1);
	/* Update the PWM duty cycle by modifying the CCRx value */
	if(LED == LD3_Pin) /* Orange LED */
		TIM4->CCR2 = Pulse; 
	else if(LED == LD5_Pin) /* Red LED */
		TIM4->CCR3 = Pulse;
}