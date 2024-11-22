#include "lcd_utils.h"
#include <stdio.h>
LiquidCrystal_I2C lcd(I2C_ADDR, COLUMNS, ROWS);


void initializeLcd(){
  lcd.begin(16, 2);
  lcd.backlight();
  resetLcd("", "");
}

void resetLcd(const char* temp, const char* setPoint) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(temp);
  lcd.setCursor(0, 1);
  lcd.print(setPoint);
}