#include <Arduino.h>
#include "relay.h"
#include "lcd_utils.h"

#define RELAY_PIN 5
#define STEP_PIN 31
#define DIR_PIN 33

void serial_read();
void HandleSerialCommand(char command);
void runMotorStepper();
void changeDirection();

bool relayState = false;
char command;
bool motorState = 0;
bool dirState = 0;


void setup() {
  Serial.begin(15200);
  setup_relay(RELAY_PIN);
  initializeLcd(relayState);

  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  printf("Session starts:\n");
}

void loop() {
  if (Serial.available() > 0) {
    serial_read();

    HandleSerialCommand(command);
    resetLcd(relayState);
  }
  runMotorStepper();
}


void HandleSerialCommand(char command) {
  if (command == '1') {
    relayState = turnRelayOn(RELAY_PIN);
  } else if (command == '0') {
    relayState = turnRelayOff(RELAY_PIN);
    changeDirection();
  }
}

void serial_read() {
  scanf("%s", &command);
  if (command != '1' && command != '0') {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Comanda invalida! Folositi '1' pentru ON si '0' pentru OFF.\n");
  }
}

void runMotorStepper() {
  digitalWrite(STEP_PIN, motorState == HIGH ? LOW : HIGH);
  motorState = !motorState;
}

void changeDirection() {
  digitalWrite(DIR_PIN, dirState == HIGH ? LOW : HIGH);
  dirState = !dirState;
}