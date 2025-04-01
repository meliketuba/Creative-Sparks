#include <Servo.h>  // Include the Servo library

Servo servoMotor;  // Create a Servo object to control the servo motor

int servoPin = 9;  // Pin where the servo is connected
int startAngle = 0;  // Start position of the servo (0 degrees)
int endAngle = 180;  // End position of the servo (180 degrees)
int delayTime = 1000;  // Delay between movements in milliseconds (1 second)

void setup() {
  servoMotor.attach(servoPin);  // Attach the servo to the specified pin
}

void loop() {
  // Move the servo to the start position
  servoMotor.write(startAngle);  
  delay(delayTime);  // Wait for a short time (for the servo to reach the position)

  // Move the servo to the end position
  servoMotor.write(endAngle);
  delay(delayTime);  // Wait for a short time (for the servo to reach the position)
}