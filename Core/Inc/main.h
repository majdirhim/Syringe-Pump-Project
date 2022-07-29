/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Alarms.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void MyFlagInterruptHandler(void);// stepper motor driver flags handler ( under_voltage / thermal warning ...)
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DISP_Pin GPIO_PIN_8
#define DISP_GPIO_Port GPIOI
#define Detect_SD_Pin GPIO_PIN_13
#define Detect_SD_GPIO_Port GPIOC
#define RST_Pin GPIO_PIN_6
#define RST_GPIO_Port GPIOF
#define SCL_Pin GPIO_PIN_7
#define SCL_GPIO_Port GPIOF
#define SDA_Pin GPIO_PIN_8
#define SDA_GPIO_Port GPIOF
#define STBY_RST_Pin GPIO_PIN_0
#define STBY_RST_GPIO_Port GPIOA
#define FLAG_PIN_Pin GPIO_PIN_4
#define FLAG_PIN_GPIO_Port GPIOH
#define FLAG_PIN_EXTI_IRQn EXTI4_IRQn
#define LED_RED_Pin GPIO_PIN_11
#define LED_RED_GPIO_Port GPIOF
#define LED_GREEN_Pin GPIO_PIN_12
#define LED_GREEN_GPIO_Port GPIOF
#define LED_YELLOW_Pin GPIO_PIN_13
#define LED_YELLOW_GPIO_Port GPIOF
#define BUZZER_Pin GPIO_PIN_14
#define BUZZER_GPIO_Port GPIOF
#define CS_Pin GPIO_PIN_12
#define CS_GPIO_Port GPIOB
#define DIR_1_Pin GPIO_PIN_3
#define DIR_1_GPIO_Port GPIOI
#define INT_Pin GPIO_PIN_7
#define INT_GPIO_Port GPIOD
#define LED2_Pin GPIO_PIN_7
#define LED2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
