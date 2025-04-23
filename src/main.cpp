#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#include "freeRTOS_scheduler.h"

void setup() {
  freeRTOS_scheduler_setup(NULL); // Initialize FreeRTOS and start the tasks
}

void loop() 
{

}