#ifndef BUTTON_UTILS_H
#define BUTTON_UTILS_H

#include <Arduino.h>

void setup_button(uint8_t pin);
bool buttonPressed(uint8_t pin);

#endif