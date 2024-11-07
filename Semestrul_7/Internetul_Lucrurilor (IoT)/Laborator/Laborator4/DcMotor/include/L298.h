#ifndef DC_MOTOR_UTILS_H
#define DC_MOTOR_UTILS_H

#include <Arduino.h>

//MotorPins
#define IN1 5
#define IN2 6
#define ENA 7 // for speed control

void initializeDcMotor();
void stopSpinning();
void spinRight(uint8_t);
void spinLeft(uint8_t);

#endif // LCD_UTILS_H