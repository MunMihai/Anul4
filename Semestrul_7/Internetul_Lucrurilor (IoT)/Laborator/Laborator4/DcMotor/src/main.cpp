#include "lcd_utils.h"
#include "serial_utils.h"
#include "L298.h"

int16_t getSpeed();
void setSpeed(int16_t speed);


void setup() {
  initializeSerial(11500);
  initializeLcd();
  initializeDcMotor();
}

void loop() {
  int16_t speed = 0;
  char buffer[20];

  printf("Enter SPEED: ");
  speed = getSpeed();
  
  dtostrf(speed, 5, 2, buffer);
  printf("%s\n", buffer);

  setSpeed(speed);
}

int16_t getSpeed() {
  bool valid = false;
  int16_t speed;

  while (!valid) {
    speed = getNumericValue();
    if (speed < -255 || speed > 255) {
      valid = false;
      printf("Value out of range. Please enter a value between -255 and 255.\n");
    } else {
      valid = true;
    }
  }
  return speed;
}

void setSpeed(int16_t speed) {
  if (speed < 0) {
    spinLeft(abs(speed));
  }
  else if (speed > 0) {
    spinRight(abs(speed));
  }
  else {
    stopSpinning();
  }
}

