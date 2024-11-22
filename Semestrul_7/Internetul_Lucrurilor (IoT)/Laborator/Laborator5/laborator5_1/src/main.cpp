#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include "lcd_utils.h"
#include "serial_utils.h"
#include "relay.h"
#include "button_utils.h"
#include "NTC.h"

#define RELAY_PIN 13
#define INC_BUTTON_PIN 31
#define DEC_BUTTON_PIN 41
#define HYSTERESIS 2.0
#define MAX_TEMPERATURE 80
#define MIN_TEMPERATURE -24

bool isPressed = false;
double temperature = 0;
double lastTempValue = temperature;
double setPoint = 17.0;
double step = 1;
bool relayState = false;
bool lastRelayState = relayState;

void Task_to_SetPoint(void * param);
void Task_to_ControlRelay(void * param);
void Task_to_ReadTemperature(void * param);
void Task_to_PrintOnLcd(void * param);
void Task_to_SendtoPlotter(void * param);

void SetPoint();
void ControlRelay();
void ReadTemperature();
void PrintOnLcd();

SemaphoreHandle_t lcdSemaphore;
SemaphoreHandle_t serialSemaphore;



void setup() {
  setup_button(INC_BUTTON_PIN);
  setup_button(DEC_BUTTON_PIN);
  setup_relay(RELAY_PIN);
  initializeLcd();
  initializeSerial(115200);

  lcdSemaphore = xSemaphoreCreateBinary();
  serialSemaphore = xSemaphoreCreateBinary();

  xTaskCreate(Task_to_SetPoint, "Set the desired temperature", 1000, NULL, 1, NULL);
  xTaskCreate(Task_to_ControlRelay, "Control relay on or off", 1000, NULL, 1, NULL);
  xTaskCreate(Task_to_ReadTemperature, "Read room temperature in Celsius", 1000, NULL, 1, NULL);
  xTaskCreate(Task_to_PrintOnLcd, "Idle task to print values on LCD", 1000, NULL, 1, NULL);
  xTaskCreate(Task_to_SendtoPlotter, "Idle task to print values on Serial", 1000, NULL, 1, NULL);
}

void loop() {
  // SetPoint();
  // ControlRelay();
  // ReadTemperature();
  // PrintOnLcd();
  // delay(2000);
  // Serial.println(isPressed);
  // isPressed = false;
}


void Task_to_SetPoint(void * param) {
  while (true) {
    SetPoint();
    if (isPressed) {
      isPressed = false;
      xSemaphoreGive(lcdSemaphore);
    }
    vTaskDelay(200 / portTICK_PERIOD_MS );
  }
}

void Task_to_ControlRelay(void * param) {
  while (true) {
    ControlRelay();
    if(lastRelayState != relayState){
      xSemaphoreGive(serialSemaphore);
      lastRelayState = relayState;
    }
    vTaskDelay(500 / portTICK_PERIOD_MS );
  }
}
void Task_to_ReadTemperature(void * param) {
  while (true) {
    ReadTemperature();
    if (temperature != lastTempValue) {
      lastTempValue = temperature;
      xSemaphoreGive(lcdSemaphore);
    }
    vTaskDelay(200 / portTICK_PERIOD_MS );
  }
}
void Task_to_PrintOnLcd(void * param) {
  while (1) {
    if (xSemaphoreTake(lcdSemaphore, portMAX_DELAY) == pdTRUE) {
      PrintOnLcd();
    }
  }
}

void Task_to_SendtoPlotter(void * param) {
  char buffer[10];
  while (1) {
    if (xSemaphoreTake(serialSemaphore, portMAX_DELAY) == pdTRUE) {
      dtostrf(temperature, 5, 2, buffer);
      printf("Temperature: %s °C |", buffer);
      dtostrf(setPoint, 5, 2, buffer);
      printf("Set Point: %s °C |", buffer);
      printf("Relay is %s", relayState == HIGH ? "On" : "Off");
      printf("\n");
    }
  }
}

void SetPoint() {
  if ((isPressed = buttonPressed(INC_BUTTON_PIN))) {
    if (setPoint < MAX_TEMPERATURE) {
      setPoint += step;
    }
  }
  else if ((isPressed = buttonPressed(DEC_BUTTON_PIN))) {
    if (setPoint > MIN_TEMPERATURE) {
      setPoint -= step;
    }
  }
}

void ControlRelay() {
  if (setPoint >= temperature + HYSTERESIS) {
    relayState = turnRelayOff(RELAY_PIN);
  }
  else if (setPoint <= temperature - HYSTERESIS) {
    relayState = turnRelayOn(RELAY_PIN);
  }
}

void ReadTemperature() {
  temperature = get_temperature_directly();
}


void PrintOnLcd() {
  String message1 = "Curent: " + String(temperature, 2);
  String message2 = "SetPoint: " + String(setPoint, 2);

  resetLcd(message1.c_str(), message2.c_str());
}