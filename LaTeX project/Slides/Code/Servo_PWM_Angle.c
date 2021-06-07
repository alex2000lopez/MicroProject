void Servo_PWM_Angle(uint16_t Servo, uint8_t angle){
	uint32_t Pulse = 0;
	/* Calculate the Pulse value given a duty cycle percentage */
	if(angle > 180) Pulse = 224;
	else Pulse = (uint32_t)(angle * (5.0/6.0) + 74);
	/* Update the PWM duty cycle by modifying the CCRx value */
	if(Servo == Servo1_Pin) /* Orange LED */
		TIM1->CCR1 = Pulse; 
	else if(Servo == Servo2_Pin) /* Red LED */
		TIM1->CCR2 = Pulse;
}
