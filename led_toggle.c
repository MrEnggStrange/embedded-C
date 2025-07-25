
#include<stdint.h>

int main(void)
{
	uint32_t *pClkCtrlReg =   (uint32_t*)0x40023830;
	uint32_t *pPortDModeReg = (uint32_t*)0x40020C00;
	uint32_t *pPortDOutReg =  (uint32_t*)0x40020C14;

	//1. enable the clock for GPOID peripheral in the AHB1ENR (SET the 3rd bit position)
	*pClkCtrlReg |= ( 1 << 3);

	//2. configure the mode of the IO pin as output
	//a. clear the 24th and 25th bit positions (CLEAR)
	*pPortDModeReg &= ~( 3 << 24);
	//b. make 24th bit position as 1 (SET)
	*pPortDModeReg |= ( 1 << 24);

	while(1)
	{
		//3.SET 12th bit of the output data register to make I/O pin-12 as HIGH
		*pPortDOutReg |= ( 1 << 12);

		//introduce small human observable delay. this delay was decided based on trial and error method
		//This loop executes for 10K times
		for(uint32_t i=0 ; i < 300000 ; i++ );

		//Tun OFF the LED
		*pPortDOutReg &= ~( 1 << 12);

		for(uint32_t i=0 ; i < 300000 ; i++ );
	}

}
