#include <Servo.h>  // Include the Servo library

const int startSensorPin = 2;    // Start sensor (touch to start movement)
const int servoPin = 10;          // Servo signal pin
const int startAngle = 50;       // Start angle for servo
const int endAngle = 150;        // End angle for servo
const int delayTime = 1000;      // Delay between movements in ms

Servo servoMotor;

int moveCount = 0;  // To track the number of movements (5 total)
bool movementStarted = false;  // Flag to check if movement has started

void setup() {
  pinMode(startSensorPin, INPUT);
  servoMotor.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  int startState = digitalRead(startSensorPin);

  // Start movement when the sensor is touched and we haven't moved 5 times yet
  if (startState == HIGH && moveCount < 5 && !movementStarted) {
    Serial.println("Arm is moving...");
    movementStarted = true;  // Mark that movement has started
    moveCount = 0;           // Reset moveCount when starting a new movement
    moveArm();               // Start moving the arm up to 5 times
  }

  // If 5 movements have been completed, stop the arm
  if (moveCount >= 5) {
    Serial.println("Arm movement completed.");
    servoMotor.write(startAngle);  // Return servo to start position
    delay(1000);  // Wait for 1 second
    movementStarted = false;  // Reset movement flag, ready for next trigger
  }

  delay(50);  // Small delay for stability
}

void moveArm() {
  // Move the arm 5 times back and forth
  while (moveCount < 5) {
    // Move the servo to the start position
    servoMotor.write(startAngle);
    delay(delayTime);  // Wait for the servo to reach the position

    // Move the servo to the end position
    servoMotor.write(endAngle);
    delay(delayTime);  // Wait for the servo to reach the position

    moveCount++;  // Increment the movement count after each movement
  }
}
