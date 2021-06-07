unsigned char mssg[]="Initialization complete\n";
HAL_UART_Transmit(&huart2,mssg,sizeof(mssg)/sizeof(mssg[0]),0xffff);