#ifndef F_CPU
#define F_CPU 1000000UL // Match your actual clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "oled.h"

int main(void) {
    // 1. Initialize Peripherals
    oled_spi_init();
    oled_init();
    oled_clear();
    // 2. Configure PA6 (TXEN Switch) as Input
    DDRA &= ~(1 << PA6); 

    // 3. Static UI Elements (Write once)
    oled_write_string(0, "SYSTEM STATUS");
    oled_write_string(1, "-------------");

    while(1) {
        // Read PA6: If high (pull-up), switch is ON. If low, switch is OFF.
        if (PINA & (1 << PA6)) {
            oled_write_string(4, "TXEN: ENABLED "); 
        } else {
            oled_write_string(4, "TXEN: DISABLED"); 
        }
        
        _delay_ms(100); // 10Hz refresh is plenty for a switch
    }
}