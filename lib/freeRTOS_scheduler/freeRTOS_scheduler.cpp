#include "freeRTOS_scheduler.h"

static volatile int distance;
static volatile int currentAngle;

void freeRTOS_scheduler_setup(void *pvParameters) 
{
  own_stdio_setup(SERIAL_BAUD_RATE);
  
  setupServo();
  setupUltrasonicSensor();

  xTaskCreate(
    sweepAndMeasureTask,  
    "SweepMeasureTask",       
    SWEEP_TASK_STACK_SIZE,
    NULL,                 
    SWEEP_TASK_PRIORITY,  
    NULL                  
  );
}

void sweepAndMeasureTask(void *pvParameters) 
{
    for (;;) 
    {
      for (currentAngle = MIN_ANGLE; currentAngle <= MAX_ANGLE; currentAngle++) {
        setServoAngle(currentAngle);
  
        vTaskDelay(pdMS_TO_TICKS(SWEEP_STEP_DELAY_MS));

        //printf("[DEBUG] delay: %d\n\r", pdMS_TO_TICKS(SWEEP_STEP_DELAY_MS));
  
        distance = getDistanceCm();
  
        currentAngleDistanceDislay(NULL);
      }
  
      for (currentAngle = MAX_ANGLE; currentAngle > MIN_ANGLE; currentAngle--) 
      {
        setServoAngle(currentAngle);
  
        vTaskDelay(pdMS_TO_TICKS(SWEEP_STEP_DELAY_MS));

        //printf("[DEBUG] delay: %d\n\r", pdMS_TO_TICKS(SWEEP_STEP_DELAY_MS));
  
        distance = getDistanceCm(); // Measure the distance
  
        currentAngleDistanceDislay(NULL);
      }
       
    }
}

void currentAngleDistanceDislay(void *pvParameters) 
{
  printf("%d", currentAngle);
  printf(",");
  printf("%d", distance);
  printf(".");
}

void vApplicationIdleHook() 
{
    //printf("[IDLE] distance: %d\n\r", distance);
    //printf("[IDLE] currentAngle: %d\n\r", currentAngle);
    //vTaskDelay(pdMS_TO_TICKS(IDLE_TASK_SLEEP_TIME_MS));
}