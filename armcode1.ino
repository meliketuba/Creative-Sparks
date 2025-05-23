/* This is the code for cinderella's arm that is washing the floor. It repeatedly moves back and forth after sponge is placed on hand and for the whole time until trigger is placed to stop it */
#include <Servo.h>  // Include the Servo library

Servo servoMotor;  // Create a Servo object to control the servo motor

int servoPin = 9;  // Pin where the servo is connected
int startAngle = 50;  // Start position of the servo (0 degrees)
int endAngle = 150;  // End position of the servo (180 degrees)
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
