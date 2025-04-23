// ultrasonic_sensor.h
#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include <Arduino.h>
#include "config.h"
#include "own_stdio.h"
#include <Arduino_FreeRTOS.h>
#include <semphr.h>

// Add these declarations
extern SemaphoreHandle_t echoSemaphore;
void echoISR();
void startTriggerSequence();

// Function Prototypes
void setupUltrasonicSensor();
int getDistanceCm();

#endif // !ULTRASONIC_SENSOR_H