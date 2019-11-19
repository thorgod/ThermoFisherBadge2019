// If you wanted to create your own.
// I used  http://en.radzio.dxp.pl/bitmap_converter/  LCDAssistant
// Width 128
// Height 32
// Vertical Byte Ort
// 8 pixels/byte
// Table name does not matter just copy hex in.

//Thermo Fisher Logo

const uint8_t img_a_bits[] PROGMEM = {
    0x00, 0x0E, 0x0E, 0x0E, 0x0E, 0xFE, 0xFE, 0xFE, 0x1E, 0x0E, 0x0E, 0x0E, 0x0E, 0x00, 0xFE, 0xFE,
    0xFE, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
    0x80, 0x80, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0x80, 0xC0, 0xC0, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0x80,
    0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x80, 0xC0,
    0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xFE, 0xFE, 0x0E, 0x0E,
    0x0E, 0x0E, 0x0E, 0x00, 0xC0, 0xCE, 0xCE, 0x0E, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
    0x80, 0x00, 0x00, 0xFE, 0xFE, 0xFE, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x80,
    0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0x80, 0xC0, 0xC0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
    0xFF, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x7F, 0xFF, 0xFF, 0xCD, 0x8C, 0x8C, 0xCD,
    0xCF, 0xCF, 0x0C, 0x00, 0xFF, 0xFF, 0xFF, 0x03, 0x01, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00,
    0x00, 0x01, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x7F, 0xFF, 0xFF,
    0xC1, 0x80, 0x80, 0xC1, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07,
    0x07, 0x03, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xC7, 0xCF, 0xCF, 0x8C, 0x9C, 0xF9, 0xF9,
    0xF9, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x7F, 0xFF,
    0xFF, 0x8C, 0x8C, 0x8C, 0xCF, 0xCF, 0xCF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x03, 0x01, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0x41, 0x41, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x01, 0x01,
    0x01, 0x00, 0x00, 0x00, 0x81, 0x41, 0x41, 0x41, 0x40, 0x40, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x00, 0xC0, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x41, 0x41, 0x41, 0x40,
    0x40, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0xC1, 0x81, 0x01, 0x00, 0x00, 0x00, 0xC1,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x40, 0x40, 0x40, 0xC1, 0x41, 0x41, 0x41, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0xC1, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0xC1,
    0x40, 0x40, 0x40, 0x41, 0x41, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0xC0, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x80, 0x40, 0x40, 0x41, 0x41, 0x41, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x42, 0x44, 0x44, 0x44, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1F, 0x20, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x44, 0x44, 0x44, 0x44,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x03, 0x04, 0x18, 0x20, 0x7F,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F,
    0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x31, 0x60, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00};

// AWS Logo

const uint8_t img_b_bits[] PROGMEM = {
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE3, 0xE3, 0x61, 0x71, 0x71,
0x71, 0x71, 0x61, 0x01, 0x03, 0x03, 0x0F, 0xFB, 0x81, 0x01, 0x01, 0x03, 0x1F, 0xFF, 0xFF, 0x0F,
0x03, 0x01, 0x01, 0x01, 0x0F, 0xFF, 0xFF, 0x3F, 0x03, 0x01, 0x01, 0x81, 0xF3, 0x07, 0x03, 0x03,
0x01, 0x31, 0x71, 0x71, 0x71, 0xF1, 0xE3, 0xE3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x83, 0x00, 0x00, 0x00, 0x18, 0x38,
0x3C, 0x38, 0x18, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFC, 0xE0, 0x00, 0x00, 0x01, 0x00, 0x00,
0xC0, 0xFE, 0xFE, 0xE0, 0x00, 0x00, 0x01, 0x00, 0x00, 0xE0, 0xFC, 0xFF, 0xFF, 0x1F, 0x1E, 0x3C,
0x3C, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x81, 0xC3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x8F, 0x0F, 0x1F, 0x1F, 0x3E, 0x3E, 0x7E, 0x7E,
0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE,
0xFE, 0x8E, 0x8E, 0x06, 0x46, 0x46, 0x87, 0x07, 0x07, 0x0F, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0,
0xF0, 0xE0, 0xE0, 0xC1, 0xC1, 0xC1, 0xC1, 0xC3, 0xC3, 0x83, 0x83, 0x83, 0x87, 0x87, 0x87, 0x87,
0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x83, 0x83, 0xC3, 0xC3, 0xC3, 0xC3, 0xC1, 0xE1, 0xE1,
0xE0, 0xF0, 0xF0, 0xF8, 0xFC, 0xEC, 0xE1, 0xE0, 0xF0, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
