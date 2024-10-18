#include "ultrasonic.h"

int16_t duration = 0;

void set_trig_time(int16_t micro_seconds);  

void setup_ultrasonic(){
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void get_duration(){
  set_trig_time(10);
  duration = pulseIn(PIN_ECHO, HIGH);
}

int16_t get_distance_CM(){
  get_duration();
  return duration / 58;
}

int16_t get_distance_inches(){
  get_duration();
  return duration / 148;
}

void set_trig_time(int16_t micro_seconds){
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(micro_seconds);
  digitalWrite(PIN_TRIG, LOW);
}