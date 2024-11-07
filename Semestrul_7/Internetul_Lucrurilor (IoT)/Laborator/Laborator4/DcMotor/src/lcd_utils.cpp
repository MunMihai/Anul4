#include "lcd_utils.h"
#include <stdio.h>
LiquidCrystal_I2C lcd(I2C_ADDR, COLUMNS, ROWS);


void initializeLcd(){
  lcd.begin(16, 2);
  lcd.backlight();
  resetLcd(0, "--");
}

void resetLcd(uint8_t speed, const char* direction) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Motor Speed:");
  lcd.setCursor(13, 0);
  lcd.print(direction);
  lcd.setCursor(4, 1);
  lcd.print(speed);
}