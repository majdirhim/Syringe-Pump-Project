/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "l6474.h"
#include "adc.h"
#include "usart.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
int tCelsius ; // cpu_temp
/* USER CODE END Variables */
/* Definitions for battery_manage */
osThreadId_t battery_manageHandle;
const osThreadAttr_t battery_manage_attributes = {
  .name = "battery_manage",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Stepper */
osThreadId_t StepperHandle;
const osThreadAttr_t Stepper_attributes = {
  .name = "Stepper",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityAboveNormal,
};
/* Definitions for Connectivity */
osThreadId_t ConnectivityHandle;
const osThreadAttr_t Connectivity_attributes = {
  .name = "Connectivity",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityAboveNormal,
};
/* Definitions for Sensors */
osThreadId_t SensorsHandle;
const osThreadAttr_t Sensors_attributes = {
  .name = "Sensors",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for IHM */
osThreadId_t IHMHandle;
const osThreadAttr_t IHM_attributes = {
  .name = "IHM",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal1,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
// stepper interrupts
void MyFlagInterruptHandler(void);
// cpu temp interrupts
void HAL_ADC_LevelOutOfWindowCallback(ADC_HandleTypeDef *hadc);
// returns the speed of Screws needed for a given flow_rate (mm/h) and syringe radius(mm)
uint8_t Screws_Speed_From_FlowRate(uint8_t flow_rate , uint8_t radius );
// returns the speed of Screws needed for a given fluid volume , time and radius
uint8_t Screws_Speed_From_Time_And_Volume(int time , uint8_t volume,uint8_t radius);
// returns the motor speed needed
uint8_t Motor_Speed(uint8_t screwstep,uint8_t screwspeed);
/* USER CODE END FunctionPrototypes */

void StartBatteryManage(void *argument);
void Stepper_motor(void *argument);
void Cloud_Connectivity(void *argument);
void Sensors_measurements(void *argument);
void Interface(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of battery_manage */
  battery_manageHandle = osThreadNew(StartBatteryManage, NULL, &battery_manage_attributes);

  /* creation of Stepper */
  StepperHandle = osThreadNew(Stepper_motor, NULL, &Stepper_attributes);

  /* creation of Connectivity */
  ConnectivityHandle = osThreadNew(Cloud_Connectivity, NULL, &Connectivity_attributes);

  /* creation of Sensors */
  SensorsHandle = osThreadNew(Sensors_measurements, NULL, &Sensors_attributes);

  /* creation of IHM */
  IHMHandle = osThreadNew(Interface, NULL, &IHM_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartBatteryManage */
/**
  * @brief  Function implementing the battery_manage thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartBatteryManage */
void StartBatteryManage(void *argument)
{
  /* USER CODE BEGIN StartBatteryManage */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartBatteryManage */
}

/* USER CODE BEGIN Header_Stepper_motor */
/**
* @brief Function implementing the Stepper thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Stepper_motor */
void Stepper_motor(void *argument)
{
  /* USER CODE BEGIN Stepper_motor */
	BSP_MotorControl_AttachFlagInterrupt(MyFlagInterruptHandler);
  /* Infinite loop */
  for(;;)
  {
	L6474_SetMaxSpeed(0, 1000);
	L6474_SetMinSpeed(0, 1000);
	L6474_Move(0, BACKWARD, 16000);
	L6474_WaitWhileActive(0);
	osDelay(1000);
	L6474_Move(0, FORWARD, 16000);
	L6474_WaitWhileActive(0);
	osDelay(1000);
  }
  /* USER CODE END Stepper_motor */
}

/* USER CODE BEGIN Header_Cloud_Connectivity */
/**
* @brief Function implementing the Connectivity thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Cloud_Connectivity */
void Cloud_Connectivity(void *argument)
{
  /* USER CODE BEGIN Cloud_Connectivity */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Cloud_Connectivity */
}

/* USER CODE BEGIN Header_Sensors_measurements */
/**
* @brief Function implementing the Sensors thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Sensors_measurements */
void Sensors_measurements(void *argument)
{
  /* USER CODE BEGIN Sensors_measurements */
	uint16_t readValue;
  /* Infinite loop */
  for(;;)
  {
	  HAL_ADC_Start(&hadc3); // temp
	  HAL_ADC_PollForConversion(&hadc3, 10000);
	  readValue = HAL_ADC_GetValue(&hadc3);
	  tCelsius = 357.558 - 0.187364 * readValue;
	  osDelay(1000);
  }
  /* USER CODE END Sensors_measurements */
}

/* USER CODE BEGIN Header_Interface */
/**
* @brief Function implementing the IHM thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Interface */
void Interface(void *argument)
{
  /* USER CODE BEGIN Interface */
  /* Infinite loop */
  for(;;)
  {
	  osDelay(1);
  }
  /* USER CODE END Interface */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
