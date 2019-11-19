
// This is a custom tiny OLED written for Thermo Fisher Badge.
// Based on 
// Based on the following sources.
// https://github.com/jjshortcut/PockeTetris/
// https://github.com/MichMich/Electrocard
// https://github.com/richardkchapman/TinyOLED
// https://github.com/datacute/Tiny4kOLED
// https://github.com/datacute/TinyOLED-Fonts

#include <Arduino.h>
#include <avr/pgmspace.h>
#define SSD1306XLED_H
#define SSD1306_SCL PORTB2 // SCL, Pin 4 on SSD1306 Board - for webbogles board
#define SSD1306_SDA PORTB0 // SDA, Pin 3 on SSD1306 Board - for webbogles board
#define SSD1306_SA 0x78    // Slave address
#define DIGITAL_WRITE_HIGH(PORT) PORTB |= (1 << PORT)
#define DIGITAL_WRITE_LOW(PORT) PORTB &= ~(1 << PORT)

const uint8_t init_sequence[] PROGMEM = {
    // Initialization Sequence
    0xAE,       // Display OFF (sleep mode)
    0x20, 0b10, // Set Memory Addressing Mode
    // 00=Horizontal Addressing Mode; 01=Vertical Addressing Mode;
    // 10=Page Addressing Mode (RESET); 11=Invalid
    0xB0,       // Set Page Start Address for Page Addressing Mode, 0-7
    0xC8,       // Set COM Output Scan Direction
    0x00,       // ---set low column address
    0x10,       // ---set high column address
    0x40,       // --set start line address
    0x81, 0x3F, // Set contrast control register
    0xA1,       // Set Segment Re-map. A0=address mapped; A1=address 127 mapped.
    0xA6,       // Set display mode. A6=Normal; A7=Inverse
    0xA8, 0x1F, // Set multiplex ratio(1 to 64)
    0xA4,       // Output RAM to Display
    // 0xA4=Output follows RAM content; 0xA5,Output ignores RAM content
    0xD3, 0x00, // Set display offset. 00 = no offset
    0xD5,       // --set display clock divide ratio/oscillator frequency
    0xF0,       // --set divide ratio
    0xD9, 0x22, // Set pre-charge period
    0xDA, 0x02, // Set com pins hardware configuration
    0xDB,       // --set vcomh
    0x20,       // 0x20,0.77xVcc
    0x8D, 0x14, // Set DC-DC enable
    0xAF        // Display ON in normal mode

};

class tinyOLED
{
public:
    void draw_bmp(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, const uint8_t *bitmap);
    void ssd1306_setpos(uint8_t x, uint8_t y);
    void ssd1306_fillscreen(uint8_t fill_Data);
    void ssd1306_send_data_stop();
    void ssd1306_send_data_start();
    void ssd1306_send_command(uint8_t command);
    void ssd1306_send_uint8_t(uint8_t byte);
    void ssd1306_xfer_stop();
    void ssd1306_xfer_start();
    void ssd1306_init();
    void ssd1306_char_f8x8(uint8_t x, uint8_t y, const char ch[]);
    void charTest(uint8_t x, uint8_t y, const uint8_t ch[]);
};

extern tinyOLED TinyOLED;
