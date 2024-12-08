/**
  ******************************************************************************
  * @file           : export_fuc.c
  * @brief          : 此文件定义了一些必要的功能函数，如一些处理系统错误的钩子函数、在
  *                   一些宏定义开启时所需要定义的函数（以确保能正确实现其功能）、断言
  *                   等等。中断回调函数不在此文件。
  ******************************************************************************
  * @attention			: 请不要在FreeRTOSConfig.h中引用此文件的头文件！一般来说只需要在
  *                   main.c中引用该文件的头文件，因为大多数函数不需要用户调用。			
  ******************************************************************************
  */


/* Includes -------------------------------------------------------------------*/

#include "export_fuc.h"

/* ----------------------------------------------------------------------------*/


/* Export variables -----------------------------------------------------------*/

#ifdef portGET_RUN_TIME_COUNTER_VALUE

uint32_t FreeRTOSRunTimeTicks;   /* 用于记录任务运行时间统计的变量*/

#endif
/* ----------------------------------------------------------------------------*/


/* RTOS Export Fuc ------------------------------------------------------------*/

/**
  * @brief 	堆栈溢出钩子函数
  * @param  xTask: 违规任务的句柄
  * @param  pcTaskName: 违规任务的名称 	
  * @note 	堆栈溢出检查会增加上下文切换的开销，因此建议只在开发或测试阶段使用此检查。
  */
#if(configCHECK_FOR_STACK_OVERFLOW == 1 || configCHECK_FOR_STACK_OVERFLOW == 2)

void vApplicationStackOverflowHook(TaskHandle_t xTask,char * pcTaskName )
{
	portDISABLE_INTERRUPTS();
	while(1);
}

#endif

/**
 * @brief 用于查看任务运行时间统计的定时器初始化函数
 * @note  仅用于开发阶段
 */

#ifdef portCONFIGURE_TIMER_FOR_RUN_TIME_STATS

void ConfigureTimeForRunTimeStats(void)
{
  //MX_TIM3_Init();
  //FreeRTOSRunTimeTicks = 0;
}

#endif

/* ----------------------------------------------------------------------------*/


/* System Export Fuc ----------------------------------------------------------*/

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
}

/**
  * @brief  System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
}
#endif /* USE_FULL_ASSERT */

/* ----------------------------------------------------------------------------*/
