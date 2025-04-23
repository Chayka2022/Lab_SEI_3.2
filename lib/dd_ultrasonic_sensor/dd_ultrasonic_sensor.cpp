#include "dd_ultrasonic_sensor.h"

static volatile long duration_us;
static volatile int distance_cm;

void setupUltrasonicSensor() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT); 
  digitalWrite(TRIG_PIN, LOW);
}

int getDistanceCm() {

  //printf("[DEBUG] Triggering ultrasonic sensor...\n\r"); // Debug print  

  // Trigger the sensor by sending a short pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2); // Short low pulse to ensure clean high pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10); // Trigger pulse
  digitalWrite(TRIG_PIN, LOW);

  // Read the echo pulse duration
  // pulseIn is blocking, but usually short enough not to starve other tasks significantly
  // For highly time-critical applications, interrupt-based reading might be preferred.
  duration_us = pulseIn(ECHO_PIN, HIGH);

  //printf("[DEBUG] Duration: %ld us\n\r", duration_us); // Debug print

  // Calculate the distance
  // Speed of sound = 343 m/s = 0.0343 cm/us
  // Distance = (Speed * Time) / 2 (for round trip)
  distance_cm = duration_us * 0.0343 / 2;

  //printf("[DEBUG] Distance: %d cm\n\r", distance_cm); // Debug print

  return distance_cm;
}
