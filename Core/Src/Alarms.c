#include "Alarms.h"
#include "l6474.h"
extern osMessageQueueId_t AlarmsQHandle;


void Alarm_Action(uint8_t event){
	switch(event){
	case OVERPRESSURE :
		//pressure passed the high threshhold

		/*for prototyping only*/
		L6474_SetDirection(0, FORWARD);
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, SET);
		break;
	case BATTERY_OVERCURRENT :
		//High current detected in the battery
		SyringeStop();
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, SET);
		break;
	case BATTERY_OVERHEAT :
		//Battery temperature higher than 80°
		SyringeStop();
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, SET);
		break;
	case BATTERY_CHHARGE_DEPLETED :
		//Battery charge level is lower than 10min
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, SET);
		break;
	case BATTERY_CONTACT_FAILURE:
		//Power loss between smart battery connector and battery power > 3W
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, SET);
		break;
	case BATTERTY_CHARGE_TIMEOUT:
		//Battery not fully charged after 16 hour of charge
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, SET);
		break;
	case MOTOR_THERMAL_OVERHEAT :
		//Motor Driver Temperature higher than threshold
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, SET);
		break;
	case MOTOR_THERMAL_SHUTDOWN :
		//Motor Driver Can no longer function due to high heat
		break;
	case MOTOR_OVERCURRENT :
		//High current detected in the motor driver
		break;
	case MOTOR_UNDERVOLTAGE :
		//Motor driver voltage lower than threshold
		break;
	case MOTOR_DRIVER_NOT_RESPONSDING :
		//Motor Driver Ingnored 5 consecutive commands
		break;
	case POSTION_ERROR :
		//Motor real position is 10% different than theoretical position
		break;
	case SYRINGUE_NOT_DETECTED_ALARM:
		//Syringe no longer detected during infusion
		break;
	case END_OF_TRAIL :
		//the end trail sensor detected motor presence
		break;
	case SYRINGE_EMPTY:
		//syringe total volume has been injected
		break;

	}
	osMessageQueuePut(AlarmsQHandle, &event, 1, 10);
}


void Alerts_Action (uint8_t event){
	switch(event){
	case LINE_OCCLUDED_MEDIUM :
		//
		break;
	case BATTERY_UNDERCURRENT:
		//
		break;
	case BATTERY_UNDERHEAT:
		//
		break;
	case BATTERY_LOW_CHARGE:
		//
		break;
	case INTERNAL_ERROR:
		//
		break;
	case PERFUSION_COMPLETE:
		//
		break;
	case BOLUS_COMPLETE:
		//
		break;
	case KVO_STARTED:
		//
		break;
	case SYRINGE_NEAR_EMPTY:
		//
		break;
	}
	osMessageQueuePut(AlarmsQHandle, &event, 1, 10);
}


void Notifs_Action(uint8_t event){
	switch(event){
	case LINE_OCCLUDED_LOW :
		//
		break;
	case POWER_SOURCE_CHANGED :
		//
		break;
	}
	osMessageQueuePut(AlarmsQHandle, &event, 1, 10);
}


void Default_Event_Action(uint8_t event){
	switch(event){
	case PERFUSION_STARTED:
		//
		break;
	case PERFUSION_STOPPED:
		//
		break;
	case BOLUS_STARTED:
		//
		break;
	case BOLUS_STOPPED:
		//
		break;
	case KVO_STARTED:
		//
		break;
	case KVO_STOPPED:
		//
		break;
	case PURGE_STARTED:
		//
		break;
	case PURGE_STOPPED:
		//
		break;
	}
	osMessageQueuePut(AlarmsQHandle, &event, 1, 10);
}
