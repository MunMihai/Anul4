#define LED_PIN 12
#define BUTTON_PIN 8
#define LED_ON_STATE HIGH
#define LED_OFF_STATE LOW

typedef struct{
  unsigned long Out;
  unsigned long Time;
  unsigned long Next[2];
} SType;

SType FSM[2] = {
  {0, 10, { LED_OFF_STATE, LED_ON_STATE }},
  {1, 10, { LED_ON_STATE, LED_OFF_STATE }}
};

int FSM_State = LED_OFF_STATE;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  FSM_State = LED_OFF_STATE;
}

void loop() {
  int output = FSM[FSM_State].Out;
  digitalWrite(LED_PIN, output);

  delay(FSM[FSM_State].Time * 10);

  if(digitalRead(BUTTON_PIN) == LOW){
    while(digitalRead(BUTTON_PIN) == LOW);
    int input = digitalRead(BUTTON_PIN);
    FSM_State = FSM[FSM_State].Next[input];
  }
}

