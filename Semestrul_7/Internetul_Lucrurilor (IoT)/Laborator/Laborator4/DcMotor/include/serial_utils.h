#ifndef SERIAL_UTILS_H
#define SERIAL_UTILS_H

#include <Arduino.h>

void initializeSerial(int64_t baud);
int16_t getNumericValue();

#endif // SERIAL_UTILS_H