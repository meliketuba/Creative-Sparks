#include <Servo.h>

Servo myServo;

const int touchPin = 2;   // Copper tape input pin
const int servoPin = 6;   // Servo control pin

void setup() {
  pinMode(touchPin, INPUT);       // Set touch pin as input
  myServo.attach(servoPin);       // Attach servo to pin 6
  myServo.write(0);               // Start in "up" position
  Serial.begin(9600);             // Optional: for debugging
}

void loop() {
  int touchState = digitalRead(touchPin);

  if (touchState == HIGH) {
    Serial.println("Touched! Moving servo...");
    myServo.write(90);    // Move to "down" position
    delay(2000);          // Hold down for 2 seconds... not sure if this is needed, we need to make circuit and test to make sure we include what we need.
}
