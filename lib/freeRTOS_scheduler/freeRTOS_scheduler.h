#ifndef FREERTOS_SCHEDULER_H
#define FREERTOS_SCHEDULER_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h> // Must include the FreeRTOS library for Arduino
#include "config.h" // Include config for pin definitions
#include "own_stdio.h"
#include "dd_ultrasonic_sensor.h"
#include "dd_servo.h"
#include "semphr.h"

void freeRTOS_scheduler_setup(void *pvParameters);
void freeRTOS_scheduler_loop(void *pvParameters);
void currentAngleDistanceDislay(void *pvParameters);
void sweepAndMeasureTask(void *pvParameters);

#endif // !FREERTOS_SCHEDULER_H