#include <Arduino.h>
#include "stdinout.h"
#define MAIN_LED_PIN 13
#define INTERMITENT_LED_PIN 12
#define SERIAL_LED_PIN 11
#define MAIN_BUTTON_PIN 8
#define INC_BUTTON_PIN 23
#define DEC_BUTTON_PIN 25

void task1();
void task2();
void task3();
void task4();
void idleTask();

byte ledState = LOW;
byte interLedState = LOW;
byte serialLedState = LOW;
bool btnPressed = false;
unsigned int currentTime = 0;
unsigned int prevTime_T1 = 0;
unsigned int prevTime_Idle = 0;
unsigned int delayTime = 1000;
unsigned int idleInterval = 2000;
unsigned int step = 100;
char command[10];

void setup()
{
  pinMode(MAIN_LED_PIN, OUTPUT);
  pinMode(INTERMITENT_LED_PIN, OUTPUT);
  pinMode(SERIAL_LED_PIN, OUTPUT);
  pinMode(MAIN_BUTTON_PIN, INPUT_PULLUP);
  pinMode(INC_BUTTON_PIN, INPUT);
  pinMode(DEC_BUTTON_PIN, INPUT);
  Serial.begin(115200);
}

void loop()
{
  currentTime = millis();
  task1();
  task2();
  task3();
  task4();
  idleTask();
}

void task1()
{
  if (digitalRead(MAIN_BUTTON_PIN) == LOW)
  {
    if (!btnPressed)
    {
      ledState = !ledState;
      digitalWrite(MAIN_LED_PIN, ledState);
      btnPressed = true;
    }
  }
  else
  {
    btnPressed = false;
  }
}

void task2()
{
  if (currentTime - prevTime_T1 > delayTime)
  {
    if (ledState == HIGH)
    {
      interLedState = LOW;
      digitalWrite(INTERMITENT_LED_PIN, interLedState);
    }
    else
    {
      digitalWrite(INTERMITENT_LED_PIN, interLedState =
                                            interLedState == LOW ? HIGH : LOW);
    }
    prevTime_T1 = currentTime;
  }
}

void task3()
{
  if (digitalRead(INC_BUTTON_PIN) == LOW)
  {
    delayTime += step;
    digitalWrite(INC_BUTTON_PIN, HIGH);
  }
  if (digitalRead(DEC_BUTTON_PIN) == LOW)
  {
    if (delayTime > 100)
    {
      delayTime -= step;
      digitalWrite(DEC_BUTTON_PIN, HIGH);
    }
  }
}

void task4()
{
  if (Serial.available())
  {
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = 0; // Remove the newline character

    if (strcasecmp(command, "led on") == 0)
    {
      serialLedState = HIGH;
      digitalWrite(SERIAL_LED_PIN, serialLedState);
    }
    else if (strcasecmp(command, "led off") == 0)
    {
      serialLedState = LOW;
      digitalWrite(SERIAL_LED_PIN, serialLedState);
    }
    else
    {
      printf("No such command available!\n");
    }
  }
}

void idleTask()
{
  if (currentTime - prevTime_Idle > idleInterval)
  {
    prevTime_Idle = currentTime;

    printf("LED-ul principal este: %s \n", ledState == HIGH ? "Aprins" : "Stins");
    printf("LED-ul intermitent  este: %s \n", interLedState == HIGH ? "Aprins" : "Stins");
    printf("Numărul de recurențe/timp în care LED-ul intermitent se va afla într-o stare: %d \n", delayTime);
    printf("Comanda de la terminal: %s\n", command);
    printf("LED-ul Serial este: %s \n", serialLedState == HIGH ? "Aprins" : "Stins");
  }
}
