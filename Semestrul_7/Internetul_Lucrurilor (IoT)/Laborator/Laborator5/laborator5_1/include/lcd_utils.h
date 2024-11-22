#ifndef LCD_UTILS_H
#define LCD_UTILS_H

#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27
#define COLUMNS 16
#define ROWS   2

void initializeLcd();
void resetLcd(const char* temp, const char* setPoint);

#endif // LCD_UTILS_H