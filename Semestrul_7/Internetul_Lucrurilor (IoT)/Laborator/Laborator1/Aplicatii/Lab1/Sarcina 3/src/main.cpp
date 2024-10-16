#include <Arduino.h>
#include "lcd_utils.h"
#include "keypad_utils.h"

#define GREEN_LED_PIN 8
#define RED_LED_PIN  12


LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);
Keypad keypad = Keypad(makeKeymap(KEYPAD_KEYS), ROW_PINS, COL_PINS, ROWS, COLS);

const uint8_t CODE_LENGTH = 4;
const String CORRECT_CODE = "1234";

void displayResults(uint8_t ledPin, const String &message);
void determineResult(const String &enteredCode, String &message, uint8_t &ledPin);

void setup() {
  Serial.begin(9600);
  initializeLcd();
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
}

void loop() {
  String enteredCode = getEnteredCode(CODE_LENGTH);

  String message;
  uint8_t ledPin;

  determineResult(enteredCode, message, ledPin);

  displayResults(ledPin, message);
  resetLcd();
}

void displayResults(uint8_t ledPin, const String &message) {
  lcd.setCursor(0, 1);
  delay(500);
  lcd.print(message);
  digitalWrite(ledPin, HIGH);
  delay(2000);
  digitalWrite(ledPin, LOW);
}

void determineResult(const String &enteredCode, String &message, uint8_t &ledPin) {
  if (enteredCode == CORRECT_CODE) {
    message = "You are right!";
    ledPin = GREEN_LED_PIN;
  } else {
    message = "You are wrong!";
    ledPin = RED_LED_PIN;
  }
}