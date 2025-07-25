/**
  ******************************************************************************
  * @file    main.c
  * @author Joe
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/

#include "main.h"

/*
	uint32_t *pClkCtrlReg =   (uint32_t*)0x40023830;
	uint32_t *pPortDModeReg = (uint32_t*)0x40020C00;
	uint32_t *pPortDOutReg =  (uint32_t*)0x40020C14; */

int main(void)
{
	RCC_AHB1ENR_t volatile *const pClkCtrlReg   = (RCC_AHB1ENR_t*) 0x40023830;
	GPIOx_MODE_t  volatile *const pPortDModeReg = (GPIOx_MODE_t*) 0x40020C00;
	GPIOx_ODR_t   volatile *const pPortDOutReg  = (GPIOx_ODR_t*) 0x40020C14;

	//1. enable the clock for GPOID peripheral in the AHB1ENR (SET the 3rd bit position)
	pClkCtrlReg->gpiod_en = 1;


	//2. configure the mode of the IO pin as output
	pPortDModeReg->pin_12 = 1;

	while(1)
	{
		//Set 12th bit of the output data register to make I/O pin-12 as HIGH
		pPortDOutReg->pin_12  = 1;

		//introduce small human observable delay
		//This loop executes for 300K times
		for(uint32_t i=0 ; i < 300000 ; i++ );

		//Reset 12th bit of the output data register to make I/O pin-12 as LOW
		pPortDOutReg->pin_12  = 0;

		for(uint32_t i=0 ; i < 300000 ; i++ );
	}


	for(;;);
}
