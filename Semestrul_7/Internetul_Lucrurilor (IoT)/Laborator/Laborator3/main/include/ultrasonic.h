#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

#define PIN_TRIG 8
#define PIN_ECHO 7

void setup_ultrasonic();
int16_t get_distance_CM();
int16_t get_distance_inches();

#endif //ULTRASONIC_H