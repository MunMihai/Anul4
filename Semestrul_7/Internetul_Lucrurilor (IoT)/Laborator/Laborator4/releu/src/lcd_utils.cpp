#include "lcd_utils.h"
#include <stdio.h>
LiquidCrystal_I2C lcd(I2C_ADDR, COLUMNS, ROWS);


void initializeLcd(bool relayState){
  lcd.begin(16, 2);
  lcd.backlight();
  resetLcd(relayState);
}

void resetLcd(bool relayState) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Relay Status:");
  lcd.setCursor(0, 1);
  if (relayState) {
    lcd.print("ON");
  } else {
    lcd.print("OFF");
  }
}