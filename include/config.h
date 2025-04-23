// config.h
#ifndef CONFIG_H
#define CONFIG_H

// Pin Definitions
#define TRIG_PIN 10
#define ECHO_PIN 2
#define SERVO_PIN 12

// Servo Configuration
#define MIN_ANGLE 15
#define MAX_ANGLE 165
#define SWEEP_STEP_DELAY_MS 60 // Delay between servo steps in milliseconds

// Idle Task Configuration
#define IDLE_TASK_SLEEP_TIME_MS 1000 // Sleep time for idle task in milliseconds

// Serial Communication
#define SERIAL_BAUD_RATE 115200 // Baud rate for serial communication

// FreeRTOS Task Configuration
#define SWEEP_TASK_STACK_SIZE 512 // Stack size in words (adjust if needed)
#define SWEEP_TASK_PRIORITY   1   // Task priority (1 is low)

#endif // CONFIG_H