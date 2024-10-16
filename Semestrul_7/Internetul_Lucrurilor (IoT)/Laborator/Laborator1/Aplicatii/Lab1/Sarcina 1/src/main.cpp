#include <Arduino.h>
#define LED_PIN 13
#define BUTTON_PIN 8

byte buttonState = LOW;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);

  buttonState == LOW ? digitalWrite(LED_PIN, LOW) :
              digitalWrite(LED_PIN, HIGH);  
}
