#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>

bool turnRelayOn(short pin);
bool turnRelayOff(short pin);
void setup_relay(short pin);

#endif