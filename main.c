/*
 * Si5351_SkeletonCode.c
 * This project contains the skeleton code to get started with the 
 * Si5351 PLL chip
 *
 * Created: 2023-02-28 4:39:21 PM
 * Author : StewartPearson
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "./Si5351.h"
#include "./twi.h"


int main(void)
{
	bool enabled = true;

	// Initialize the I2C Bus
	twi_init();
	// Init PLL
	si5351_init();

	// Configure PLLA to 800 MHz from 25 MHz crystal: 25 MHz * 32
	setup_PLL(SI5351_PLL_A, 32, 0, 1);
	// Configure CLK0 to 10 MHz: 800 MHz / 80
	setup_clock(SI5351_PLL_A, SI5351_PORT0, 80, 0, 1);

	// Reset PLL
	reset_pll();
	// Enable outputs
	enable_clocks(enabled);
	
	while(1)
	{

	}
}

