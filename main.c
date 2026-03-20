#ifndef F_CPU
#define F_CPU 1000000UL 
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "oled.h"

int main(void) {
    // 1. Initialize Peripherals
    oled_spi_init();
    oled_init();
    oled_clear();

    // 2. Configure Inputs
    DDRA &= ~(1 << PA6); // TXEN Switch
    DDRD &= ~((1 << PD5) | (1 << PD6) | (1 << PD7)); // Encoder & Button Pins
    DDRE &= ~(1 << PE5); // PC/User
    

    // 3. Static UI Elements
    oled_write_string(0, "SYSTEM STATUS");
    oled_write_string(1, "-------------");

    // 4. State Tracking Variables
    uint8_t last_a_state = (PIND & (1 << PD5)) >> PD5; 
    uint8_t current_a_state;
    uint8_t current_b_state; 
    int16_t encoder_count = 0;
    char oled_buffer[16];

    // Initialize button/switch states to force an initial draw
    uint8_t last_btn_state = 2; 
    uint8_t last_txen_state = 2; 
    uint8_t last_mode_state = 2; // Initialize to force first draw
    while(1) {
        // --- TXEN Switch (PA6) ---
        uint8_t current_txen = (PINA & (1 << PA6)) >> PA6;
        if (current_txen != last_txen_state) {
            if (current_txen) {
                oled_write_string(2, "TXEN: ENABLED "); 
            } else {
                oled_write_string(2, "TXEN: DISABLED"); 
            }
            last_txen_state = current_txen;
        }
        // --- PC/USER Mode Switch (PE5) ---
        uint8_t current_mode = (PINE & (1 << PE5)) >> PE5;
        if (current_mode != last_mode_state) {
            if (current_mode) {
                oled_write_string(3, "MODE: USER    "); // Logic High state
            } else {
                oled_write_string(3, "MODE: PC      "); // Logic Low state
            }
            last_mode_state = current_mode;
        }

        // --- Rotary Encoder Knob ---
        // Channel A is still on PD5
        current_a_state = (PIND & (1 << PD5)) >> PD5;

        // Trigger ONLY on the falling edge of Channel A (1 dropping to 0)
        if ((current_a_state != last_a_state) && (current_a_state == 0)) {
            
            // Channel B is now looking at PD7!
            current_b_state = (PIND & (1 << PD7)) >> PD7;
            
            // Check direction
            if (current_b_state == 1) {
                encoder_count++; 
            } else {
                encoder_count--; 
            }
            
            sprintf(oled_buffer, "COUNT: %-6d", encoder_count);
            oled_write_string(4, oled_buffer);
        }
        last_a_state = current_a_state; 

        // --- Rotary Encoder Button ---
        // The button is now looking at PD6!
        uint8_t current_btn = (PIND & (1 << PD6)) >> PD6;
        if (current_btn != last_btn_state) {
            if (current_btn == 0) { // Pin goes LOW when pressed to GND
                oled_write_string(6, "BTN: PRESSED  ");
            } else {
                oled_write_string(6, "BTN: RELEASED ");
            }
            last_btn_state = current_btn;
        }
    }
}