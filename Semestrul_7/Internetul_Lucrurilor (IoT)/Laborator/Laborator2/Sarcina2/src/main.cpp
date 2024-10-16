#include "stdinout.h"
// #include <Arduino_FreeRTOS.h>

#define MAIN_LED_PIN 13
#define INTERMITENT_LED_PIN 12
#define SERIAL_LED_PIN 11
#define MAIN_BUTTON_PIN 8
#define INC_BUTTON_PIN 23
#define DEC_BUTTON_PIN 25

void task1(void * param);
void task2(void * param);
void task3(void * param);
void task4(void * param);
void idleTask(void * param);

byte ledState = LOW;
byte interLedState = LOW;
byte serialLedState = LOW;
bool btnPressed = false;

unsigned int delayTime = 1000;
unsigned int step = 100;
char command[10];

void setup(){
  pinMode(MAIN_LED_PIN, OUTPUT);
  pinMode(INTERMITENT_LED_PIN, OUTPUT);
  pinMode(SERIAL_LED_PIN, OUTPUT);
  pinMode(MAIN_BUTTON_PIN, INPUT_PULLUP);
  pinMode(INC_BUTTON_PIN, INPUT_PULLUP);
  pinMode(DEC_BUTTON_PIN, INPUT_PULLUP);
  
  Serial.begin(9600);

  xTaskCreate(
    task1, // function name
    "Task 1", // description(task name)
    1000, // stack size
    NULL, // task parameters
    1, // task priority 
    NULL // task handle
  );
  xTaskCreate(task2, "Task 2", 1000, NULL, 1, NULL);
  xTaskCreate(task3, "Task 3", 1000, NULL, 1, NULL);
  xTaskCreate(task4, "Task 4", 1000, NULL, 1, NULL);
  xTaskCreate(idleTask, "IDLE Task", 1000, NULL, 1, NULL);
}

void loop(){

}

void task1(void * param){
  while(1){
    if(digitalRead(MAIN_BUTTON_PIN) == LOW){
      while(digitalRead(MAIN_BUTTON_PIN) == LOW);
      ledState = !ledState;
      digitalWrite(MAIN_LED_PIN, ledState);
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS );
  }
}



void task2(void * param)
{
  while(1){
    if (ledState ^ serialLedState )
    {
      interLedState = LOW;
      digitalWrite(INTERMITENT_LED_PIN, interLedState);
    }
    else
    {
      interLedState = (interLedState == LOW) ? HIGH : LOW ;
      digitalWrite(INTERMITENT_LED_PIN, interLedState);
    }  
    vTaskDelay(delayTime / portTICK_PERIOD_MS );
  }
}

void task3(void * param){
  while(1){
    if(digitalRead(INC_BUTTON_PIN) == LOW){
      while(digitalRead(INC_BUTTON_PIN) == LOW);
      delayTime += step;
      digitalWrite(INC_BUTTON_PIN, HIGH);
    }
    if(digitalRead(DEC_BUTTON_PIN) == LOW){
      if(delayTime > 100){
        while(digitalRead(DEC_BUTTON_PIN) == LOW);
        delayTime -= step;
        digitalWrite(DEC_BUTTON_PIN, HIGH);
      }
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS );
  }
}


void task4(void * param) {
  while(1){
    if(Serial.available()){
      fgets(command, sizeof(command), stdin);
      command[strcspn(command, "\n")] = 0;    
      printf("Received command: %s\n", command);

      if (strcasecmp(command, "led on") == 0) {
        serialLedState = HIGH;
        digitalWrite(SERIAL_LED_PIN, serialLedState);
      }
      else if (strcasecmp(command, "led off") == 0) {
        serialLedState = LOW;
        digitalWrite(SERIAL_LED_PIN, serialLedState);
      }
      else {
        printf("No such command available!\n");
      }
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS );
  }
}

void idleTask(void * param)
{
  while(1){
    printf("LED-ul principal este: %s \n", ledState == HIGH ? "Aprins" : "Stins" );
    printf("LED-ul intermitent  este: %s \n", interLedState == HIGH ? "Aprins" : "Stins" );
    printf("LED-ul serial  este: %s \n", serialLedState == HIGH ? "Aprins" : "Stins" );
    printf("Numărul de recurențe/timp în care LED-ul intermitent se va afla într-o stare: %d \n", delayTime );
    vTaskDelay(2000 / portTICK_PERIOD_MS );
  }
}


