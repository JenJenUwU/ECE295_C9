#ifndef OLED_H
#define OLED_H

#include <avr/io.h>
#include <stdint.h>

// Hardware Pin Mapping
#define OLED_RST  PB2
#define OLED_DC   PB1
#define OLED_CS   PB4
#define OLED_PORT PORTB
#define OLED_DDR  DDRB

// Function Prototypes
void oled_spi_init(void);
void oled_write(uint8_t byte, uint8_t is_data);
void oled_init(void);
void oled_set_cursor(uint8_t row, uint8_t col);
void oled_write_char(char c);
void oled_write_string(uint8_t row, const char *str);
void oled_clear(void);

#endif // OLED_H