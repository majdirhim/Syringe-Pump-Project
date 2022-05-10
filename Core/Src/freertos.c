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
#include "SW_common.h"
#include "drv8825.h"
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
drv8825* drv;
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
  .priority = (osPriority_t) osPriorityHigh,
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
/* Definitions for InfusionQ */
osMessageQueueId_t InfusionQHandle;
const osMessageQueueAttr_t InfusionQ_attributes = {
  .name = "InfusionQ"
};
/* Definitions for VolumeQ */
osMessageQueueId_t VolumeQHandle;
const osMessageQueueAttr_t VolumeQ_attributes = {
  .name = "VolumeQ"
};
/* Definitions for FlowRateQ */
osMessageQueueId_t FlowRateQHandle;
const osMessageQueueAttr_t FlowRateQ_attributes = {
  .name = "FlowRateQ"
};
/* Definitions for TimeQ */
osMessageQueueId_t TimeQHandle;
const osMessageQueueAttr_t TimeQ_attributes = {
  .name = "TimeQ"
};
/* Definitions for LastStepQ */
osMessageQueueId_t LastStepQHandle;
const osMessageQueueAttr_t LastStepQ_attributes = {
  .name = "LastStepQ"
};
/* Definitions for RadiusQ */
osMessageQueueId_t RadiusQHandle;
const osMessageQueueAttr_t RadiusQ_attributes = {
  .name = "RadiusQ"
};
/* Definitions for VolumeLeftQ */
osMessageQueueId_t VolumeLeftQHandle;
const osMessageQueueAttr_t VolumeLeftQ_attributes = {
  .name = "VolumeLeftQ"
};
/* Definitions for ModeQ */
osMessageQueueId_t ModeQHandle;
const osMessageQueueAttr_t ModeQ_attributes = {
  .name = "ModeQ"
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
//Move the Syringe
void SyringeMove(drv8825* drv8825 , uint8_t FlowRate , uint8_t radius,int timeneeded);
// mapping values
uint16_t map(uint16_t x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max);
// return number of seconds to finish the injection
int Time_Needed(uint8_t flow_rate, uint8_t volume_to_inject);
// calculate volume left
uint8_t calculate_volume_left(int laststep , uint8_t flowrate ,uint8_t volume_to_inject );
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

  /* Create the queue(s) */
  /* creation of InfusionQ */
  InfusionQHandle = osMessageQueueNew (16, sizeof(Infusion_paramT), &InfusionQ_attributes);

  /* creation of VolumeQ */
  VolumeQHandle = osMessageQueueNew (8, sizeof(float), &VolumeQ_attributes);

  /* creation of FlowRateQ */
  FlowRateQHandle = osMessageQueueNew (8, sizeof(float), &FlowRateQ_attributes);

  /* creation of TimeQ */
  TimeQHandle = osMessageQueueNew (8, sizeof(float), &TimeQ_attributes);

  /* creation of LastStepQ */
  LastStepQHandle = osMessageQueueNew (2, sizeof(uint16_t), &LastStepQ_attributes);

  /* creation of RadiusQ */
  RadiusQHandle = osMessageQueueNew (8, sizeof(uint8_t), &RadiusQ_attributes);

  /* creation of VolumeLeftQ */
  VolumeLeftQHandle = osMessageQueueNew (8, sizeof(float), &VolumeLeftQ_attributes);

  /* creation of ModeQ */
  ModeQHandle = osMessageQueueNew (4, sizeof(uint8_t), &ModeQ_attributes);

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
	//BSP_MotorControl_AttachFlagInterrupt(MyFlagInterruptHandler);
	// drv8825 structure creation

	 // drv8825 structure initialization
	 //drv8825_init(&drv, Dir_G_GPIO_Port, Dir_G_Pin,En_G_GPIO_Port, En_G_Pin, &htim2, TIM_CHANNEL_1);
	float Flowrate , radius ,volume_to_inject ;
	int timeneeded;
	uint8_t mode=0;
	uint16_t laststep;

  /* Infinite loop */
  for(;;)
  {
	if(osMessageQueueGet(FlowRateQHandle,&Flowrate , 2, 100)==osOK && osMessageQueueGet(VolumeQHandle,&volume_to_inject , 2, 100)==osOK ){
		timeneeded= Time_Needed(Flowrate, volume_to_inject);
		laststep = timeneeded*drv8825_getSpeedPPS(drv);
		osMessageQueuePut(LastStepQHandle, &laststep, 1, 100);
	}
	// ***** 0 => StopMode , 8=> PauseMode *******
	if(osMessageQueueGet(ModeQHandle, &mode, 10, 10)==osOK && (mode==0 || mode == 8)){
		SyringeStop(drv);
	}
	SyringeMove(drv,Flowrate,radius,timeneeded);
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
	float volumeleft , timeleft ;
	uint16_t  laststep ;
	float Flowrate,volume_to_inject ;
	HAL_ADC_Start_IT(&hadc3);
  /* Infinite loop */
  for(;;)
  {
	 osMessageQueueGet(FlowRateQHandle,&Flowrate , 1, 100);
	 osMessageQueueGet(VolumeQHandle,&volume_to_inject , 1, 100);
	 osMessageQueueGet(LastStepQHandle, &laststep, 1, 100);
	 if(Flowrate!=0 && laststep!=0){
		 volumeleft=calculate_volume_left(laststep,Flowrate,volume_to_inject);
		 timeleft=volumeleft/Flowrate;
		 osMessageQueuePut(VolumeLeftQHandle,  &volumeleft, 1, 100);
		 osMessageQueuePut(TimeQHandle,  &timeleft, 1, 100);
	 }

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
	Infusion_paramT msgPerfusionParameters;
  /* Infinite loop */
  for(;;)
  {
	  // ***** 0 => StopMode , 8=> PauseMode *******
	  if(osMessageQueueGet(InfusionQHandle,&msgPerfusionParameters,10,100)==osOK && msgPerfusionParameters.Mode!=0
			  &&  msgPerfusionParameters.Mode!=8  ){
		  osMessageQueuePut(FlowRateQHandle,&msgPerfusionParameters.Flowrate , 1, 100);
		  osMessageQueuePut(VolumeQHandle,&msgPerfusionParameters.InfousionVolume , 1, 100);
	  }else{
		  osMessageQueuePut(ModeQHandle,&msgPerfusionParameters.Mode , 10, 100);
	  }

	  osDelay(1);
  }
  /* USER CODE END Interface */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
