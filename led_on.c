/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Joe
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
int main(void)
{
	uint32_t *pClkctrlreg = (uint32_t*)0x40023830;
	uint32_t *pPORTDModereg = (uint32_t*)0x40020C00;
	uint32_t *pPORTDoutreg = (uint32_t*)0x40020C14;


	// 1. enable the clock peripheral GPIOD in AHB1ENR

	//uint32_t temp = *pClkctrlreg;//read operaration
	//temp = temp |0x08; //modify
	//*pClkctrlreg = temp;//reassign

	*pClkctrlreg |= 0x08;

	// 2. configure mode of register to high ( pin 12 -> high)( 24 and 15 bit -> 01)

	//clear 24 and 25 bit

	*pPORTDModereg &= 0xFCFFFFFF;

	// set 24 bit
	*pPORTDModereg |= 0X01000000;

	// configure output register to 1 that is bit 12 to 1
	*pPORTDoutreg |= 0x1000;

	 while(1);
}
