# embedded-C using STM32F407 Discovery Board

Day1: Hello world
-> Compiled and run the Hello World program for STM32 Target Board and viewed the results on SWV console and verified the results.

Day2: Sizeof operation
-> Compiled and run the program for finding the size of each datatype using sizeof operator. 
---sizeof()

Day3: LedOn - turning the led LD4 to ON state on STM32F407 Discovery board
-> Compiled and run the program for turning the Led on using memory addresses and bit wise operation. 
->Step 1 :enable the clock peripheral GPIOD in AHB1ENR
->Step 2 :configure mode of register to high ( pin 12 -> high)( 24 and 15 bit -> 01) ie. 	clear 24 and 25 bit and then set 24th bit.
->Step 3 :configure output register to 1 that is bit 12 to 1
