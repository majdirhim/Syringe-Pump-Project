/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "adc.h"
#include "crc.h"
#include "dma2d.h"
#include "i2c.h"
#include "ltdc.h"
#include "quadspi.h"
#include "sdmmc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "app_touchgfx.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include "l6474.h"
#include "drv8825.h"
// #include "stdio.h" // used for Send function (sprintf) ( --- we will not be using it ---- )
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SCREWSTEP 1.5
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
//uint8_t END_CMD[3] = {0xFF , 0XFF , 0XFF}; // "End Command" for nextion display (we will not be using it)
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
void MX_FREERTOS_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/*L6474_Init_t gL6474InitParams =
  {
      1,                               /// Acceleration rate in step/s2. Range: (0..+inf).
      1,                               /// Deceleration rate in step/s2. Range: (0..+inf).
      1000,                              /// Maximum speed in step/s. Range: (30..10000].
      1000,                               ///Minimum speed in step/s. Range: [30..10000).
      250,                               ///Torque regulation current in mA. (TVAL register) Range: 31.25mA to 4000mA.
      750,                               ///Overcurrent threshold (OCD_TH register). Range: 375mA to 6000mA.
      L6474_CONFIG_OC_SD_ENABLE,         ///Overcurrent shutwdown (OC_SD field of CONFIG register).
      L6474_CONFIG_EN_TQREG_TVAL_USED,   /// Torque regulation method (EN_TQREG field of CONFIG register).
      L6474_STEP_SEL_1_16,               /// Step selection (STEP_SEL field of STEP_MODE register).
      L6474_SYNC_SEL_1_2,                /// Sync selection (SYNC_SEL field of STEP_MODE register).
      L6474_FAST_STEP_12us,              /// Fall time value (T_FAST field of T_FAST register). Range: 2us to 32us.
      L6474_TOFF_FAST_8us,               /// Maximum fast decay time (T_OFF field of T_FAST register). Range: 2us to 32us.
      3,                                 /// Minimum ON time in us (TON_MIN register). Range: 0.5us to 64us.
      21,                                /// Minimum OFF time in us (TOFF_MIN register). Range: 0.5us to 64us.
      L6474_CONFIG_TOFF_044us,           /// Target Swicthing Period (field TOFF of CONFIG register).
      L6474_CONFIG_SR_320V_us,           /// Slew rate (POW_SR field of CONFIG register).
      L6474_CONFIG_INT_16MHZ,            /// Clock setting (OSC_CLK_SEL field of CONFIG register).
      (L6474_ALARM_EN_OVERCURRENT      |
       L6474_ALARM_EN_THERMAL_SHUTDOWN |
       L6474_ALARM_EN_THERMAL_WARNING  |
       L6474_ALARM_EN_UNDERVOLTAGE     |
       L6474_ALARM_EN_SW_TURN_ON       |
       L6474_ALARM_EN_WRONG_NPERF_CMD)    /// Alarm (ALARM_EN register).
  };*/
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

/* Configure the peripherals common clocks */
  PeriphCommonClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI2_Init();
  MX_ADC3_Init();
  MX_I2C1_SMBUS_Init();
  MX_DMA2D_Init();
  MX_LTDC_Init();
  MX_CRC_Init();
  MX_TIM2_Init();
  MX_QUADSPI_Init();
  //MX_SDMMC1_SD_Init();
  MX_USART3_UART_Init();
  MX_ADC1_Init();
  MX_TouchGFX_Init();
  /* USER CODE BEGIN 2 */
  /*L6474_SetNbDevices(1);
  L6474_Init(NULL);*/
  // drv8825 structure creation
  	drv8825 drv;
  	// drv8825 structure initialization
  	drv8825_init(&drv, Dir_G_GPIO_Port, Dir_G_Pin,
  			En_G_GPIO_Port, En_G_Pin, &htim2, TIM_CHANNEL_1);
  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();  /* Call init function for freertos objects (in freertos.c) */
  MX_FREERTOS_Init();
  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);
  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
  /** Macro to configure the PLL clock source
  */
  __HAL_RCC_PLL_PLLSOURCE_CONFIG(RCC_PLLSOURCE_HSE);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief Peripherals Common Clock Configuration
  * @retval None
  */
void PeriphCommonClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Initializes the peripherals clock
  */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInitStruct.PLL2.PLL2M = 1;
  PeriphClkInitStruct.PLL2.PLL2N = 18;
  PeriphClkInitStruct.PLL2.PLL2P = 2;
  PeriphClkInitStruct.PLL2.PLL2Q = 2;
  PeriphClkInitStruct.PLL2.PLL2R = 2;
  PeriphClkInitStruct.PLL2.PLL2RGE = RCC_PLL2VCIRANGE_3;
  PeriphClkInitStruct.PLL2.PLL2VCOSEL = RCC_PLL2VCOMEDIUM;
  PeriphClkInitStruct.PLL2.PLL2FRACN = 6144;
  PeriphClkInitStruct.AdcClockSelection = RCC_ADCCLKSOURCE_PLL2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
/*//stepper driver interrupt
void MyFlagInterruptHandler(void)
{
   Get the value of the status register via the L6474 command GET_STATUS
  uint16_t statusRegister =L6474_CmdGetStatus(0);

   Check HIZ flag: if set, power brigdes are disabled
  if ((statusRegister & L6474_STATUS_HIZ) == L6474_STATUS_HIZ)
  {
    // HIZ state
    // Action to be customized
  }

   Check direction bit
  if ((statusRegister & L6474_STATUS_DIR) == L6474_STATUS_DIR)
  {
    // Forward direction is set
    // Action to be customized
  }
  else
  {
    // Backward direction is set
    // Action to be customized
  }

   Check NOTPERF_CMD flag: if set, the command received by SPI can't be performed
   This often occures when a command is sent to the L6474
   while it is in HIZ state
  if ((statusRegister & L6474_STATUS_NOTPERF_CMD) == L6474_STATUS_NOTPERF_CMD)
  {
      // Command received by SPI can't be performed
     // Action to be customized
  }

   Check WRONG_CMD flag: if set, the command does not exist
  if ((statusRegister & L6474_STATUS_WRONG_CMD) == L6474_STATUS_WRONG_CMD)
  {
     //command received by SPI does not exist
     // Action to be customized
  }

   Check UVLO flag: if not set, there is an undervoltage lock-out
  if ((statusRegister & L6474_STATUS_UVLO) == 0)
  {
     //undervoltage lock-out
     // Action to be customized
  }

   Check TH_WRN flag: if not set, the thermal warning threshold is reached
  if ((statusRegister & L6474_STATUS_TH_WRN) == 0)
  {
    //thermal warning threshold is reached
    // Action to be customized
  }

   Check TH_SHD flag: if not set, the thermal shut down threshold is reached
  if ((statusRegister & L6474_STATUS_TH_SD) == 0)
  {
    //thermal shut down threshold is reached
    // Action to be customized

  }

   Check OCD  flag: if not set, there is an overcurrent detection
  if ((statusRegister & L6474_STATUS_OCD) == 0)
  {
    //overcurrent detection
    // Action to be customized
  }

}*/
// cpu temp interrupt
void HAL_ADC_LevelOutOfWindowCallback(ADC_HandleTypeDef *hadc){
	// do something in case of analog watchdog interrupts
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
	HAL_ADC_Stop_IT(&hadc3);
}

// returns the speed of Screws (m/s) needed for a given flow_rate (mm^3/h) and syringe radius(mm)
float Screws_Speed_From_FlowRate(float flow_rate , uint8_t radius ){
	radius = radius*0.001;
	uint8_t section = radius*radius*3.14159;
	flow_rate = (flow_rate * 0.001) / 3600;
	return flow_rate/section;
}
// returns the speed of Screws needed for a given fluid volume(m^3) , time(seconds) and radius
float Screws_Speed_From_Time_And_Volume(float time , float volume,uint8_t radius){
	return Screws_Speed_From_FlowRate(volume/time,radius) ;
}
// returns the motor speed needed (rps)
float Motor_Speed(float screwspeed){
	return screwspeed / (SCREWSTEP*0.001);
}
//return number of seconds to finish the injection
float Time_Needed(float flow_rate, float volume_to_inject){
	flow_rate = flow_rate  / 3600;
	return (volume_to_inject/flow_rate);
}

void SyringeMove(drv8825* drv8825 ,uint16_t FlowRate , uint8_t radius,int timeneeded){
	float screwspeed , motorspeed;
	int pps;
	screwspeed = Screws_Speed_From_FlowRate(FlowRate,radius);
	motorspeed = Motor_Speed(screwspeed);
	/*pps=motorspeed*200;
	L6474_SetMaxSpeed(0,pps);
	L6474_SetMinSpeed(0, pps);
	L6474_Move(0, FORWARD,pps*timeneeded);*/
	drv8825_setSpeedRPM(drv8825, motorspeed*60);
	drv8825_setEn(drv8825, EN_START);
}

uint16_t map(uint16_t x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
float calculate_volume_left(drv8825* drv8825 ,int laststep , float flowrate ,float volume_to_inject ){
	uint16_t readValue,traveled_steps ;
	uint8_t injectedVolume;
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 100);
	readValue = HAL_ADC_GetValue(&hadc1);
	traveled_steps=map(readValue, 0, 65535,0 ,laststep );
	injectedVolume = (traveled_steps / drv8825_getSpeedPPS(drv8825))*flowrate;
	return (volume_to_inject-injectedVolume);
}
/* USER CODE END 4 */

 /**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM3 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM3) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
