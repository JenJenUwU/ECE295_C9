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
#include <stdbool.h>
#include <stdint.h>
#include "./Si5351.h"
#include "./twi.h"


bool setup_quadrature_outputs(uint32_t freq_hz);

int main(void)
{
	bool enabled = true;
	uint32_t output_frequency_hz = 10000000UL;

	// Initialize the I2C Bus
	twi_init();
	// Init PLL
	si5351_init();

	// Configure CLK0/CLK1 to output_frequency_hz with 90 degree phase offset
	if (!setup_quadrature_outputs(output_frequency_hz))
	{
		enabled = false;
	}

	// Reset PLL
	reset_pll();
	// Enable outputs
	enable_clocks(enabled);
	
	while(1)
	{

	}
}

bool setup_quadrature_outputs(uint32_t freq_hz)
{
    if (freq_hz == 0) return false;

    const uint32_t pll_freq_hz = 800000000UL;
    if ((pll_freq_hz % freq_hz) != 0) return false;

    const uint32_t div = pll_freq_hz / freq_hz;
    if (div < 4 || div > 2048) return false;

    if (div > 127) return false;

    setup_PLL(SI5351_PLL_A, 32, 0, 1);
    setup_clock(SI5351_PLL_A, SI5351_PORT0, div, 0, 1);
    setup_clock(SI5351_PLL_A, SI5351_PORT1, div, 0, 1);

    set_phase((word)div);

    return true;
}
