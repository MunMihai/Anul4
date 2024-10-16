#ifndef LCD_UTILS_H
#define LCD_UTILS_H

#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

#define I2C_ADDR    0x27
#define LCD_COLUMNS 16
#define LCD_LINES   2

extern LiquidCrystal_I2C lcd;

void initializeLcd();
void resetLcd();

#endif // LCD_UTILS_H