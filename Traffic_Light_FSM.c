/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
/only the main function and init code included

/* USER CODE BEGIN Includes */
#include "main.h"
/* USER CODE END Includes */

/* USER CODE BEGIN PV */
typedef enum {
  RED_STATE,
  GREEN_STATE,
  ORANGE_STATE
} TrafficLightState;

TrafficLightState current_state = RED_STATE;
/* USER CODE END PV */

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  /* USER CODE BEGIN WHILE */
  while (1)
  {
    switch (current_state)
    {
      case RED_STATE:
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);   // Red ON
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13, GPIO_PIN_RESET); // Green, Orange OFF
        HAL_Delay(3000); // 3 seconds
        current_state = GREEN_STATE;
        break;

      case GREEN_STATE:
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);   // Green ON
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13 | GPIO_PIN_14, GPIO_PIN_RESET); // Orange, Red OFF
        HAL_Delay(3000); // 3 seconds
        current_state = ORANGE_STATE;
        break;

      case ORANGE_STATE:
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);   // Orange ON
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_14, GPIO_PIN_RESET); // Green, Red OFF
        HAL_Delay(1500); // 1.5 seconds
        current_state = RED_STATE;
        break;
    }
  }
  /* USER CODE END WHILE */
}
