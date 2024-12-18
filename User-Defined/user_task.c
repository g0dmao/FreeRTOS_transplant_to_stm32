/**
  ******************************************************************************
  * @file           : user_task.c
  * @brief          : 用户的所有任务函数
  ******************************************************************************
  * @attention		: 无
  *						
  ******************************************************************************
  */


/* Include -------------------------------------------------------------------*/

#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "list.h"

/* ---------------------------------------------------------------------------*/


/* Global variables ----------------------------------------------------------*/

/* ---------------------------------------------------------------------------*/


/* Task Config ---------------------------------------------------------------*/

#define TASK_START_STACK_SIZE (512/4)			/* task_start */
#define TASK_START_TASK_PRIO 1
TaskHandle_t task_start_Handler = NULL;
void task_start(void);


#define TASK_1_STACK_SIZE (512/4)					/* task1 */
#define TASK_1_PRIO 2
TaskHandle_t task_1_Handler = NULL;				
void task_1(void);

#define TASK_2_STACK_SIZE (512/4)					/* task2 */
#define TASK_2_PRIO 4
TaskHandle_t task_2_Handler = NULL;				
void task_2(void);

#define TASK_LOG_STACK_SIZE (512/4)				/* task_log */
#define TASK_LOG_PRIO 3
#define BUFFER_SIZE 100
TaskHandle_t task_log_Handler = NULL;				
void task_log(void);



/* ---------------------------------------------------------------------------*/


/* Start RTOS in main --------------------------------------------------------*/

void start_RTOS(void)
{
	BaseType_t OK = xTaskCreate(  (TaskFunction_t)                task_start,
                                (const char *)                  "task_start",
                                (configSTACK_DEPTH_TYPE)        TASK_START_STACK_SIZE,
                                (void *)                        NULL,
                                (UBaseType_t)                   TASK_START_TASK_PRIO,
                                (TaskHandle_t *)                &task_start_Handler
														 );
	
  if(OK == pdPASS)
  {
    vTaskStartScheduler();
  }
  else
  {
    while(1);
  }
}

/* ---------------------------------------------------------------------------*/


/* Task Definition -----------------------------------------------------------*/

void task_start(void)
{
	
   taskENTER_CRITICAL();               /* 进入临界区 */
   xTaskCreate( (TaskFunction_t)                task_1,
                (const char *)                  "task_1",
                (configSTACK_DEPTH_TYPE)        TASK_1_STACK_SIZE,
                (void *)                        NULL,
                (UBaseType_t)                   TASK_1_PRIO,
                (TaskHandle_t *)                &task_1_Handler
                );
   xTaskCreate( (TaskFunction_t)                task_2,
                (const char *)                  "task_2",
                (configSTACK_DEPTH_TYPE)        TASK_2_STACK_SIZE,
                (void *)                        NULL,
                (UBaseType_t)                   TASK_2_PRIO,
                (TaskHandle_t *)                &task_2_Handler
                );
   xTaskCreate( (TaskFunction_t)                task_log,
                (const char *)                  "task_log",
                (configSTACK_DEPTH_TYPE)        TASK_LOG_STACK_SIZE,
                (void *)                        NULL,
                (UBaseType_t)                   TASK_LOG_PRIO,
                (TaskHandle_t *)                &task_log_Handler
                );

             
   vTaskDelete(NULL);						/* 任务自删除 */
   taskEXIT_CRITICAL();         /* 退出临界区 */
}

void task_1(void)              
{
   while(1)
   {
      
   }
   
}

void task_2(void)                
{
   while(1)
	 {
	 
	 }
}

/**
 * @brief 任务运行信息
 * @note  仅用于调试时使用。你可能会查看一些任务运行时间，任务剩余堆栈大小等等，以便于你更好的配置任务
 */
void task_log(void)                   
{
   
   
}

/* ---------------------------------------------------------------------------*/


/* 中断回调--------------------------------------------------------------------*/

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) /* 此中断必须配置,使用另一个定时器作为系统心跳时钟，而内核时钟作为RTOS的心跳时钟 */
{

  if (htim->Instance == TIM4) {
    HAL_IncTick();
  }
}

