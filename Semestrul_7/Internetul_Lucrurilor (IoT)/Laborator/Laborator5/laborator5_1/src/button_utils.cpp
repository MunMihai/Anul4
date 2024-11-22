#include "button_utils.h"

void setup_button(uint8_t pin){
  pinMode(pin, INPUT_PULLUP);
}

bool buttonPressed(uint8_t pin){
  if(digitalRead(pin) == LOW){
    while(digitalRead(pin) == LOW);
    return true;
  }
  return false;
}