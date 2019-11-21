
// This is a custom tiny OLED written for Thermo Fisher Badge.
// Based on 
// Based on the following sources.
// https://github.com/jjshortcut/PockeTetris/
// https://github.com/MichMich/Electrocard
// https://github.com/richardkchapman/TinyOLED
// https://github.com/datacute/Tiny4kOLED
// https://github.com/datacute/TinyOLED-Fonts

#include <Arduino.h>
// The custom font file is the only additional file you should need to compile this game
#include "font8x16.h"
// Standard Arduino headers
#include <TinyOLED.h>


void tinyOLED::ssd1306_char_f8x16(uint8_t x, uint8_t y, const char ch[])
{
    uint8_t c, j = 0;

    while (ch[j] != '\0')
    {
        c = ch[j] - 32; // to space
        if (c > 0)
            c = c - 12; // to dash
        if (c > 15)
            c = c - 7;
        if (c > 40)
            c = c - 6;
        if (c > 4)
            c = c - 10;
        ssd1306_setpos(x, y);
        ssd1306_send_data_start();
        for (uint8_t lxn = 0; lxn < 8; lxn++)
        {

            ssd1306_send_uint8_t(pgm_read_byte(&ssd1306xled_font8x16atari[c * 16 + lxn]));
        }
        ssd1306_send_data_stop();
        ssd1306_setpos(x, y + 1);

        ssd1306_send_data_start();
        for (uint8_t lxn = 8; lxn < 16; lxn++)
        {
            ssd1306_send_uint8_t(pgm_read_byte(&ssd1306xled_font8x16atari[c * 16 + lxn]));
        }
        ssd1306_send_data_stop();

        x += 8;
        j++;
    }
}

void tinyOLED::ssd1306_index_8x16(uint8_t x, uint8_t y, const uint8_t ch[])
{
    uint8_t j = 0;

    while (j < 16)
    {
        ssd1306_setpos(x, y);
        ssd1306_send_data_start();
        for (uint8_t lxn = 0; lxn < 8; lxn++)
        {

            ssd1306_send_uint8_t(pgm_read_byte(&ssd1306xled_font8x16atari[ch[j] * 16 + lxn]));
        }
        ssd1306_send_data_stop();
        ssd1306_setpos(x, y + 1);

        ssd1306_send_data_start();
        for (uint8_t lxn = 8; lxn < 16; lxn++)
        {
            ssd1306_send_uint8_t(pgm_read_byte(&ssd1306xled_font8x16atari[ch[j] * 16 + lxn]));
        }
        ssd1306_send_data_stop();

        x += 8;
        j++;
    }
}

void tinyOLED::draw_bmp(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, const uint8_t *bitmap)
{
    for (uint8_t y = y0; y < y1; y++)
    {
        ssd1306_setpos(x0, y);
        ssd1306_send_data_start();
        for (uint8_t x = x0; x < x1; x++)
        {
            ssd1306_send_uint8_t(pgm_read_byte(bitmap++));
        }
        ssd1306_send_data_stop();
    }
}

// Screen control functions
void tinyOLED::ssd1306_init(void)
{
    DDRB |= (1 << SSD1306_SDA); // Set port as output
    DDRB |= (1 << SSD1306_SCL); // Set port as output

    for (uint8_t i = 0; i < sizeof(init_sequence); i++)
    {
        ssd1306_send_command(pgm_read_byte(&init_sequence[i]));
    }
}

void tinyOLED::ssd1306_xfer_start(void)
{
    DIGITAL_WRITE_HIGH(SSD1306_SCL); // Set to HIGH
    DIGITAL_WRITE_HIGH(SSD1306_SDA); // Set to HIGH
    DIGITAL_WRITE_LOW(SSD1306_SDA);  // Set to LOW
    DIGITAL_WRITE_LOW(SSD1306_SCL);  // Set to LOW
}

void tinyOLED::ssd1306_xfer_stop(void)
{
    DIGITAL_WRITE_LOW(SSD1306_SCL);  // Set to LOW
    DIGITAL_WRITE_LOW(SSD1306_SDA);  // Set to LOW
    DIGITAL_WRITE_HIGH(SSD1306_SCL); // Set to HIGH
    DIGITAL_WRITE_HIGH(SSD1306_SDA); // Set to HIGH
}

void tinyOLED::ssd1306_send_uint8_t(uint8_t byte)
{
    uint8_t i;
    for (i = 0; i < 8; i++)
    {
        if ((byte << i) & 0x80)
            DIGITAL_WRITE_HIGH(SSD1306_SDA);
        else
            DIGITAL_WRITE_LOW(SSD1306_SDA);

        DIGITAL_WRITE_HIGH(SSD1306_SCL);
        DIGITAL_WRITE_LOW(SSD1306_SCL);
    }
    DIGITAL_WRITE_HIGH(SSD1306_SDA);
    DIGITAL_WRITE_HIGH(SSD1306_SCL);
    DIGITAL_WRITE_LOW(SSD1306_SCL);
}

void tinyOLED::ssd1306_send_command(uint8_t command)
{
    ssd1306_xfer_start();
    ssd1306_send_uint8_t(SSD1306_SA); // Slave address, SA0=0
    ssd1306_send_uint8_t(0x00);       // write command
    ssd1306_send_uint8_t(command);
    ssd1306_xfer_stop();
}

void tinyOLED::ssd1306_send_data_start(void)
{
    ssd1306_xfer_start();
    ssd1306_send_uint8_t(SSD1306_SA);
    ssd1306_send_uint8_t(0x40); //write data
}

void tinyOLED::ssd1306_send_data_stop(void)
{
    ssd1306_xfer_stop();
}

void tinyOLED::ssd1306_setpos(uint8_t x, uint8_t y)
{
    if (y > 7)
        return;
    ssd1306_xfer_start();
    ssd1306_send_uint8_t(SSD1306_SA); //Slave address,SA0=0
    ssd1306_send_uint8_t(0x00);       //write command

    ssd1306_send_uint8_t(0xb0 + y);
    ssd1306_send_uint8_t(((x & 0xf0) >> 4) | 0x10); // |0x10
    ssd1306_send_uint8_t((x & 0x0f) | 0x01);        // |0x01

    ssd1306_xfer_stop();
}

void tinyOLED::ssd1306_fillscreen(uint8_t fill_Data)
{
    uint8_t m, n;
    for (m = 0; m < 8; m++)
    {
        ssd1306_send_command(0xb0 + m); //page0-page1
        ssd1306_send_command(0x00);     //low column start address
        ssd1306_send_command(0x10);     //high column start address
        ssd1306_send_data_start();
        for (n = 0; n < 128; n++)
        {
            ssd1306_send_uint8_t(fill_Data);
        }
        ssd1306_send_data_stop();
    }
}