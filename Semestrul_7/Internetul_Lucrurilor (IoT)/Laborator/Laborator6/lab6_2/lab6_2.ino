#define NORTH_PIN 9
#define EAST_PIN 2
#define EAST_RED_PIN 3
#define EAST_YELLOW_PIN 4
#define EAST_GREEN_PIN 5
#define NORTH_RED_PIN 6
#define NORTH_YELLOW_PIN 7
#define NORTH_GREEN_PIN 8
#define goN 0   // 0b00
#define waitN 1 // 0b01
#define goE 2   // 0b10
#define waitE 3 // 0b11

int GetInput();
void SetOutput(int out);

typedef struct State {
  unsigned long Out;
  unsigned long Time;
  unsigned long Next[4]; // next state for inputs 0,1,2,3
} SType;

SType FSM[4] {
  {0b100001, 300, {  goN,  waitN, goN,   waitN  }},
  {0b010010, 50,  {  goE,  goE,   goE,   goE    }},
  {0b001100, 300, {  goE,  goE,   waitE,  waitE  }},
  {0b010010, 50,  {  goN,  goN,   goN,   goN    }}
};

int FSM_State = goN;


void setup() {
  Serial.begin(115200);
  // Init Button
  pinMode(NORTH_PIN, INPUT);
  pinMode(EAST_PIN, INPUT);

  // Init LED
  pinMode(EAST_RED_PIN, OUTPUT);
  pinMode(EAST_YELLOW_PIN, OUTPUT);
  pinMode(EAST_GREEN_PIN, OUTPUT);
  pinMode(NORTH_RED_PIN, OUTPUT);
  pinMode(NORTH_YELLOW_PIN, OUTPUT);
  pinMode(NORTH_GREEN_PIN, OUTPUT);

  // Init Initial State
  FSM_State = goN;
}

// The loop function is called in an endless loop
void loop() {
  // 1. Output Based on current state
  int output = FSM[FSM_State].Out;
  SetOutput(output);
  Serial.print("output: ");
  Serial.println(output);

  // 2. wait for time relevant to state
  delay(FSM[FSM_State].Time * 10);

  // 3. Get Input
  int input = GetInput();
  Serial.print("input: ");
  Serial.println(input);

  // 4. Change state based on input and current state
  FSM_State = FSM[FSM_State].Next[input];
}


int GetInput() {
  int northButton = digitalRead(NORTH_PIN);
  int eastButton = digitalRead(EAST_PIN);

  if (northButton && eastButton)
    return 0b11;
  else if (northButton)
    return 0b10;
  else if (eastButton)
    return 0b01;
  else
    return 0b00;

}
void SetOutput(int out) {
  int ledState;
  ledState = (out & (1 << 5)) ? HIGH : LOW;
  digitalWrite(EAST_RED_PIN, ledState);
  ledState = (out & (1 << 4)) ? HIGH : LOW;
  digitalWrite(EAST_YELLOW_PIN, ledState);
  ledState = (out & (1 << 3)) ? HIGH : LOW;
  digitalWrite(EAST_GREEN_PIN, ledState);
  ledState = (out & (1 << 2)) ? HIGH : LOW;
  digitalWrite(NORTH_RED_PIN, ledState);
  ledState = (out & (1 << 1)) ? HIGH : LOW;
  digitalWrite(NORTH_YELLOW_PIN, ledState);
  ledState = (out & (1 << 0)) ? HIGH : LOW;
  digitalWrite(NORTH_GREEN_PIN, ledState);
}