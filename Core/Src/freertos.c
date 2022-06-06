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
#include "tim.h"
#include "adc.h"
#include "usart.h"
#include "SW_common.h"
#include "stdio.h"
//#include "drv8825.h"
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

//drv8825* drv;

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
  .stack_size = 256 * 4,
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
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for IHM */
osThreadId_t IHMHandle;
const osThreadAttr_t IHM_attributes = {
  .name = "IHM",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal1,
};
/* Definitions for DataStorage */
osThreadId_t DataStorageHandle;
const osThreadAttr_t DataStorage_attributes = {
  .name = "DataStorage",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityBelowNormal,
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
void SyringeMove(uint16_t FlowRate , uint8_t radius);
// mapping values
uint16_t map(uint16_t x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max);
// return number of seconds to finish the injection
int Time_Needed(uint8_t flow_rate, uint8_t volume_to_inject);
// calculate volume left
float calculate_volume_left(uint16_t traveled_steps ,float flowrate ,float volume_to_inject );
// stepper position
uint16_t position();
//stop syringe
void SyringeStop();
/* USER CODE END FunctionPrototypes */

void StartBatteryManage(void *argument);
void Stepper_motor(void *argument);
void Cloud_Connectivity(void *argument);
void Sensors_measurements(void *argument);
void Interface(void *argument);
void StartDataStorage(void *argument);

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
  RadiusQHandle = osMessageQueueNew (2, sizeof(uint8_t), &RadiusQ_attributes);

  /* creation of VolumeLeftQ */
  VolumeLeftQHandle = osMessageQueueNew (8, sizeof(float), &VolumeLeftQ_attributes);

  /* creation of ModeQ */
  ModeQHandle = osMessageQueueNew (8, sizeof(uint8_t), &ModeQ_attributes);

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

  /* creation of DataStorage */
  DataStorageHandle = osThreadNew(StartDataStorage, NULL, &DataStorage_attributes);

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

	// drv8825 structure initialization
	//drv8825_init(&drv, Dir_G_GPIO_Port, Dir_G_Pin,En_G_GPIO_Port, En_G_Pin, &htim2, TIM_CHANNEL_1);
	float Flowrate=50 , radius=17.7,volume_to_inject=50 ;
	int timeneeded=0;
	uint8_t mode=0;
	uint16_t laststep;

  /* Infinite loop */
  for(;;)
  {
	  SyringeMove(Flowrate,radius);
	  timeneeded= Time_Needed(Flowrate, volume_to_inject);
	  int speedd = L6474_GetCurrentSpeed(0);
	  laststep = timeneeded*L6474_GetMaxSpeed(0);
	  osMessageQueuePut(LastStepQHandle, &laststep, 1, 100);
	if(osMessageQueueGet(FlowRateQHandle,&Flowrate , 10U, 100)==osOK && osMessageQueueGet(VolumeQHandle,&volume_to_inject , 10U, 100)==osOK ){
		SyringeMove(Flowrate,radius);
		timeneeded= Time_Needed(Flowrate, volume_to_inject);
		laststep = timeneeded*L6474_GetCurrentSpeed(0);
		osMessageQueuePut(LastStepQHandle, &laststep, 1, 100);
	}
	// ***** 0 => StopMode , 8=> PauseMode *******
	if(osMessageQueueGet(ModeQHandle, &mode, 10U, 10U)==osOK && (mode==0 || mode == 8)){
		SyringeStop();
	}

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
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, RESET); // UART clock
	float Flowrate=0 , Timeleft=0, Volumeleft=0;
	char flowbuff[10], timebuff[10] , volumebuff[10];

	/********** UNIQUE ID ***********/
	uint32_t (*unique_id_1) = (uint32_t*)(0x1FF1E800); // BASE address (reference manual stm32h743)
	uint32_t (*unique_id_2) = (uint32_t*)(0x1FF1E804); // BASE address + 0x04 offset
	uint32_t (*unique_id_3) = (uint32_t*)(0x1FF1E808); // BASE address + 0x08 offset
	char Id[85];
	int n =sprintf(Id,"%lu%lu%lu",*unique_id_1,*unique_id_2,*unique_id_3);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, SET);
	HAL_UART_Transmit(&huart3,Id ,n , 100);
	osDelay(10);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, RESET);
  /* Infinite loop */
	// ***** f==> flowrate t==> timeleft v==>volumeleft *****
  for(;;)
  {
    if(osMessageQueueGet(FlowRateQHandle,&Flowrate , 1U, 100U)==osOK){
    	int nflow =sprintf((uint8_t *)flowbuff,"f%.3f",Flowrate);
    	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, SET);
    	HAL_UART_Transmit(&huart3, (uint8_t *)flowbuff, nflow, 10);
    	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, RESET);
    }
    if(osMessageQueueGet(TimeQHandle,&Timeleft , 1U, 100U)==osOK){
        	int ntime =sprintf((uint8_t *)timebuff,"t%f",Timeleft);
        	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, SET);
        	HAL_UART_Transmit(&huart3, (uint8_t *)timebuff, ntime, 10);
        	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, RESET);
        }
    if(osMessageQueueGet(VolumeLeftQHandle,&Volumeleft , 1, 100U)==osOK){
            	int nvol =sprintf((uint8_t *)volumebuff,"v%.3f",Volumeleft);
            	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, SET);
            	HAL_UART_Transmit(&huart3, (uint8_t *)volumebuff, nvol, 10);
            	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, RESET);
            }
    osDelay(100);

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
	float volumeleft=0 , timeleft=0 ;
	uint16_t  laststep=0, traveled_steps=0 ;
	float Flowrate=0,volume_to_inject=0 ;
	HAL_ADC_Start_IT(&hadc3);
  /* Infinite loop */
  for(;;)
  {
	osMessageQueueGet(FlowRateQHandle,&Flowrate , 1U, 100);
	osMessageQueueGet(VolumeQHandle,&volume_to_inject , 1U, 100);
	osMessageQueueGet(LastStepQHandle, &laststep, 1U, 100);
	if(Flowrate!=0 && volume_to_inject!=0 && laststep!=0){
		traveled_steps= position();
		volumeleft=calculate_volume_left(traveled_steps,Flowrate,volume_to_inject); //mm^3
		timeleft=volumeleft/Flowrate; // seconds
		osMessageQueuePut(VolumeLeftQHandle,  &volumeleft, 1, 100);
		osMessageQueuePut(TimeQHandle,  &timeleft, 1, 100);
		if(traveled_steps>=laststep || volumeleft<=0 || timeleft <=0)
			osMessageQueuePut(ModeQHandle,0, 10U, 100U); // ***** 0 => StopMode , 8=> PauseMode ******
	 }

	  osDelay(10);
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
	float flow = 100 , vol = 50;
  /* Infinite loop */
  for(;;)
  {
	  // ***** 0 => StopMode , 8=> PauseMode *******
	 // osMessageQueuePut(FlowRateQHandle,&flow , 1U, 100U);
	  //osMessageQueuePut(VolumeQHandle,&vol , 1U, 100U);
	 /* if(osMessageQueueGet(InfusionQHandle,&msgPerfusionParameters,10U,100)==osOK && msgPerfusionParameters.Mode!=0
			  &&  msgPerfusionParameters.Mode!=8  ){
		  osMessageQueuePut(FlowRateQHandle,&msgPerfusionParameters.Flowrate , 1U, 100U);
		  osMessageQueuePut(VolumeQHandle,&msgPerfusionParameters.InfousionVolume , 1U, 100U);
	  }else{
		  osMessageQueuePut(ModeQHandle,&msgPerfusionParameters.Mode , 10U, 100U);
	  }*/

	  osDelay(1000);
  }
  /* USER CODE END Interface */
}

/* USER CODE BEGIN Header_StartDataStorage */
/**
* @brief Function implementing the DataStorage thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartDataStorage */
void StartDataStorage(void *argument)
{
  /* USER CODE BEGIN StartDataStorage */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDataStorage */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
