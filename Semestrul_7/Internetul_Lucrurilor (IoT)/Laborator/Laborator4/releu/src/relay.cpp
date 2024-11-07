#include "relay.h"

void setup_relay(short pin){
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}


bool turnRelayOn(short pin) {
  digitalWrite(pin, HIGH);
  printf("Relay ON\n");
  return true;
}

bool turnRelayOff(short pin) {
  digitalWrite(pin, LOW);
  printf("Relay OFF\n");
  return false;
}