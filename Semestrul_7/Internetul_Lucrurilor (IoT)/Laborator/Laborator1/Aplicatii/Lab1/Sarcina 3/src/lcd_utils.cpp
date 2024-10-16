#include "lcd_utils.h"


void initializeLcd() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Guess the CODE!");

  String message = "4 digits";
  lcd.setCursor(4, 1);
  for(int i = 0; i < message.length(); i++){
    lcd.write(message[i]);
    delay(100);
  }

  delay(2000);
  resetLcd();
}

void resetLcd() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter code:");
  lcd.setCursor(5, 1);
  lcd.print("[____]");
}

