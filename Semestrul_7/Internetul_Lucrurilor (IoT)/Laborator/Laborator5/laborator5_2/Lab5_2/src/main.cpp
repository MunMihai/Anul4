#include <Arduino.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <PID_v1.h>
#define ENCODER_CLK 3
#define ENCODER_DT 4
#define POT_PIN A4
#define STEP_PIN 6
#define DIR_PIN 5
LiquidCrystal_I2C lcd(0x27, 16, 2);
// Variables for PID control
double setPoint = 0, input = 0, output = 0; // Setpoint, input, and output for PID
double Kp = 2.0, Ki = 5.0, Kd = 1.0; // PID coefficients (proportional, integral, derivative)
PID myPID(&input, &output, &setPoint, Kp, Ki, Kd, DIRECT); // PID object in DIRECT mode
volatile long encoderCount = 0; // Counter for encoder rotations
int lastStateDT; // Last state of the encoder DT pin
unsigned long lastEncoderUpdate = 0; // Timestamp for encoder debouncing
unsigned long previousMillis = 0; // Timestamp for PID updates
unsigned long lastStepTime = 0; // Timestamp for motor step timing
double minSpeed = 0; // Minimum speed based on potentiometer value
void setup() {
// Configure pins as input or output
pinMode(ENCODER_CLK, INPUT);
pinMode(ENCODER_DT, INPUT);
pinMode(STEP_PIN, OUTPUT);
pinMode(DIR_PIN, OUTPUT);
// Initialize the LCD
lcd.begin(16, 2);
lcd.backlight();
// Attach interrupt for the encoder
attachInterrupt(digitalPinToInterrupt(ENCODER_CLK), updateEncoder, CHANGE);
// Initialize the PID controller
myPID.SetMode(AUTOMATIC);
myPID.SetOutputLimits(0, 255); // Limit PID output to 0-255
lastStateDT = digitalRead(ENCODER_DT); // Read the initial state of the encoder DT pin
}
void loop() {
readPotentiometer(); // Read the potentiometer value
updatePID(); // Update the PID controller
controlMotor(); // Control the motor based on PID output
updateLCD(); // Update the LCD display
}
void readPotentiometer() {
// Read the potentiometer value and map it to a speed range (0-100)
int potValue = analogRead(POT_PIN);
minSpeed = map(potValue, 0, 1023, 0, 100);
setPoint = constrain(minSpeed, 0, 100); // Ensure the setpoint is within valid range
}
void updatePID() {
// Update the PID controller every 100 ms
unsigned long currentMillis = millis();
if (currentMillis - previousMillis >= 100) {
previousMillis = currentMillis;
myPID.Compute(); // Compute the new PID output
}
}
void controlMotor() {
if (input > setPoint) { // If the actual speed is greater than the setpoint
digitalWrite(DIR_PIN, HIGH); // Set motor direction
// Generate step pulses based on the PID output
unsigned long currentMicros = micros();
int delayTime = map(abs(output), 0, 255, 2000, 100); // Map output to delay time
if (currentMicros - lastStepTime >= delayTime) {
lastStepTime = currentMicros;
digitalWrite(STEP_PIN, !digitalRead(STEP_PIN)); // Toggle step pin
}
} else {
digitalWrite(STEP_PIN, LOW); // Stop motor steps
}
}
void updateLCD() {
static double lastSetPoint = -1; // Last setpoint value displayed
static double lastInput = -1; // Last input value displayed
// Update the LCD only if values have changed
if (setPoint != lastSetPoint || input != lastInput) {
lastSetPoint = setPoint;
lastInput = input;
lcd.setCursor(0, 0);
lcd.print("SetPt: ");
lcd.print(setPoint);
lcd.print(" "); // Clear extra characters
lcd.setCursor(0, 1);
lcd.print("Speed: ");
lcd.print(input);
lcd.print(" "); // Clear extra characters
}
}
void updateEncoder() {
// Handle encoder rotation with debouncing
unsigned long currentMicros = micros();
if (currentMicros - lastEncoderUpdate >= 500) { // 500 µs debounce time
int currentStateDT = digitalRead(ENCODER_DT);
if (currentStateDT != lastStateDT) { // If the state has changed
if (digitalRead(ENCODER_DT) != digitalRead(ENCODER_CLK)) {
input += 1; // Increase speed
} else {
input -= 1; // Decrease speed
}
}
lastStateDT = currentStateDT; // Update the last state
lastEncoderUpdate = currentMicros; // Update the last timestamp
}
}