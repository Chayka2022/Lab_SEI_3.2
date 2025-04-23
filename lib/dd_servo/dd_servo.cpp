// servo_control.cpp
#include <Servo.h>
#include "dd_servo.h"
#include "config.h" // Include config for pin definitions

// Create a servo object
Servo myServo;

void setupServo() {
  myServo.attach(SERVO_PIN); // Attaches the servo on the defined pin
}

void setServoAngle(int angle) {
  // Constrain angle to valid limits if needed, though the task logic does this
  // angle = constrain(angle, 0, 180); // Example constraint
  myServo.write(angle);
}