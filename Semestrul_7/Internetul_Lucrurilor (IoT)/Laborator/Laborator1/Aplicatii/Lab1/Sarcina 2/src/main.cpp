#include <Arduino.h>
#include "stdinout.h"

#define LED_PIN 13

void processCommand();
void handleLEDCommand();
void handleUnknownCommand();
void setLEDState(bool val);

char command[10];

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  printf("All staff is ready. Try \"led on\" or \"led off\" commands:\n");
}

void loop() {
  if (Serial.available()) {
    processCommand();
  }
}

void processCommand() {
  fgets(command, sizeof(command), stdin);
  command[strcspn(command, "\n")] = 0;     // Remove the newline character
  printf("Received command: %s\n", command);

  handleLEDCommand();
}

void handleLEDCommand() {
  if (strcasecmp(command, "led on") == 0) {
    setLEDState(true);
  }
  else if (strcasecmp(command, "led off") == 0) {
    setLEDState(false);
  }
  else {
    handleUnknownCommand();
  }
}

void handleUnknownCommand() {
  printf("No such command available!\n");
}

void setLEDState(bool val) {
  digitalWrite(LED_PIN, val ? HIGH : LOW);
  printf("LED is %s\n", val ? "ON" : "OFF");
}

