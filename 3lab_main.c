/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#include "main.h"
#include "stm32f3xx.h"


void SystemClock_Config(void);

#define ON 1
#define OFF 0

int main(void)
{
	RCC -> AHBENR |= RCC_AHBENR_GPIODEN;

	GPIOD -> MODER |= GPIO_MODER_MODER1_0;
	GPIOD -> MODER &=~ GPIO_MODER_MODER1_1;

	GPIOD -> MODER |= GPIO_MODER_MODER2_0;
	GPIOD -> MODER &=~ GPIO_MODER_MODER2_1;

	GPIOD -> MODER |= GPIO_MODER_MODER3_0;
	GPIOD -> MODER &=~ GPIO_MODER_MODER3_1;

	GPIOD -> MODER |= GPIO_MODER_MODER4_0;
	GPIOD -> MODER &=~ GPIO_MODER_MODER4_1;


  while (1)
  {

	  GPIOD -> BSRR = 1<<1;
	  for(int z =0; z<=1000; z++);
	  GPIOD -> BSRR = 1<<2;
	  for(int z =0; z<=1000; z++);
	  GPIOD -> BSRR = 1<<(1+16);
	  for(int z =0; z<=1000; z++);
	  GPIOD -> BSRR = 1<<3;
	  for(int z =0; z<=1000; z++);
	  GPIOD -> BSRR = 1<<(2+16);
	  for(int z =0; z<=1000; z++);
	  GPIOD -> BSRR = 1<<4;
	  for(int z =0; z<=1000; z++);
	  GPIOD -> BSRR = 1<<(3+16);
	  for(int z =0; z<=1000; z++);
	  GPIOD -> BSRR = 1<<(4+16);
	  for(int z =0; z<=1000; z++);

  }
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
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
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

