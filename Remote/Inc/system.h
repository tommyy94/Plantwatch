#pragma once

/* System headers */

/* Device vendor headers */
#include "MKL25Z4.h"

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "event_groups.h"

/* User headers */
#include "comm.h"
#include "adc.h"
#include "tpm.h"
#include "dma.h"
#include "nrf24l01.h"


/* Global defines */
#define MAX_QUEUE_SIZE          (32UL)

/* Task priorities */
#define ANALOGTASKPRIORITY      (4UL)
#define FRAMETASKPRIORITY       (5UL)
#define COMMTASKPRIORITY        (7UL)
#define MOTORTASKPRIORITY       (6UL)
#define STARTUPTASKPRIORITY     (10UL)

/* Task sizes */
#define ANALOGTASKSIZE          (2048UL)    
#define FRAMETASKSIZE           (1024UL)    
#define COMMTASKSIZE            (2048UL)    
#define MOTORTASKSIZE           (1024UL)    
#define STARTUPTASKSIZE         (4096UL)

    
/* Global variables */
extern QueueHandle_t xCommQueue;
extern QueueHandle_t xAnalogQueue;
extern QueueHandle_t xMotorQueue;
extern EventGroupHandle_t xMotorEventGroup;
extern SemaphoreHandle_t xCommSemaphore;
    

/* Global function prototypes */
void vStartupTask(void *const pvMotorTimers);
void vApplicationIdleHook(void);
void vAssertCalled(const uint32_t ulLine, char *const pcFile);
