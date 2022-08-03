#include <stdint.h>
#include <string.h>

#ifndef SW_COMMON_H_
#define SW_COMMON_H_

typedef enum {
	NO_ALARMS,
	LINE_OCCLUDED_HIGH,
	BATTERY_OVERCURRENT, 
	BATTERY_OVERHEAT,
	BATTERY_CHARGE_DEPLETED,
	BATTERY_CONTACT_FAILURE,                          
	BATTERTY_CHARGE_TIMEOUT,            
	MOTOR_THERMAL_OVERHEAT,              
	MOTOR_THERMAL_SHUTDOWN,            
	MOTOR_OVERCURRENT,                 
	MOTOR_UNDERVOLTAGE,               
	MOTOR_DRIVER_NOT_RESPONSDING,      
	POSTION_ERROR,
	SYRINGUE_NOT_DETECTED_ALARM,
	END_OF_TRAIL,
	SYRINGE_EMPTY
}Alarms;

#define NUMBER_OF_ALARMS 15

typedef enum {
	NO_ALERTS,
	LINE_OCCLUDED_MEDIUM = 16,
	BATTERY_NO_CHARGE_CURRENT,
	BATTERY_LOW_TEMPERATURE,
	BATTERY_LOW_CHARGE,
	INTERNAL_SOFTWARE_ERROR, // can only be deactivated by a maintenance personnel or after power down but error is stored in diagnostic message
	INFUSION_COMPLETE, // when pop up is closed 
	BOLUS_COMPLETE, // when pop up is closed
	KVO_STARTED, // should be deactivated when mode changes
	SYRINGE_NEAR_EMPTY, // Should be deactivated when volume changes or when syringe empty alarm activates
}Alerts;

#define NUMBER_OF_ALERTS 9

typedef enum {
	NO_NOTIFICATION,
	LINE_OCCLUDED_LOW = 25,
	COMPLETE_EDITING_INFO,
	PUMP_IS_IDLE,
	POWER_SOURCE_CHANGED
}Notifications;

#define NUMBER_OF_NOTIFICATIONS 4

typedef enum {
	NO_EVENTS,
	PERFUSION_STARTED = 29,
	PERFUSION_STOPPED,
	BOLUS_STARTED,
	BOLUS_STOPPED,
	KVO_STOPPED,
	PURGE_STARTED,
	PURGE_STOPPED
}DefaultEvents;

#define NUMBER_OF_DEFAULT_EVENTS 7

typedef enum {
	EVENT,
	NOTIFICATION,
	ALERT,
	ALARM
}EventTypes;

typedef enum {
	DEFAULT,
	DARK,
	CHILDREN
}DisplayModes;

typedef enum {
	OTHER,
	PEDIATRICS,
	EMERGENCY,
	NEONATAL,
	INTENSIVECARE,
	MATERNITY
}Departments;

typedef enum{
	AGE = 1,
	HEIGHT,
	WEIGHT,
	FLOWRATE,
	TOTALVOLUME,
	INFUSIONVOLUME,
	KVO,
	BOLUS,
	PRESSURE_L,
	PRESSURE_M,
	PRESSURE_H,
	TOTALVOLUME_MAIN,
	FLOWRATE_MAIN
}KeyboardUsers;

typedef enum {
	STOP_M,
	INFUSION_M,
	BOLUS_M,
	KVO_M,
	ALARM_M,
	PAUSE_M,
	AIVOC_M,
	TIVA_M,
	PURGE_M,
	INFUSION_STATION_M
}MotorModes;

typedef enum {
	NOTDETECTED,
	NOTCONFIGURED,
	VALID
}SyringeStates;

typedef enum {
	UNKNOWN,
	ML10 = 10,
	ML20 = 20,
	ML50 = 50
}VolumeIntervals;

typedef enum {
	NOT_CHARGING,
	CHARGING
}ChargingStates;

typedef enum {
	SECTOR,
	BATTERY
}PowerSources;

typedef enum {
	NO_THREAT,
	LOW_THREAT,
	MEDIUM_THREAT,
	HIGH_THREAT
}DrugThreatLevel;

typedef enum {
	NOTIFICATION_FLASH_PERIOD = 150,
	ALERT_FLASH_PERIOD = 50,
	ALARM_FLASH_PERIOD = 30
}FlashPeriods;

typedef struct{
	uint16_t BeforeComma;
	uint16_t AfterComma;
}SW_float;

typedef struct {
	uint8_t Hour;
	uint8_t Minute;
	uint8_t Second;
	uint8_t Day;
	uint8_t Month;
	uint16_t Year;
}SW_time;

typedef struct {
	uint8_t BatteryChargeLevel;
	uint8_t BatteryChargingState;
	uint8_t PowerSource;
	uint8_t TimeToEmpty;
}BatteryT;

typedef struct {
	uint8_t EventType;
	uint8_t EventSource;
	uint8_t EventState;
	uint8_t FlashPeriod;
}EventTypeT;

typedef struct {
    char Name[20];
    uint8_t Height;
	uint16_t Weight;
	uint8_t Age;
	uint8_t Gender;
}Patient_dataT;

typedef struct {
	uint16_t Id;
	uint8_t Sound;
	uint16_t password;
	uint8_t DisplayMode;
	SW_time Time;
	uint8_t Departement;
}System_init_paramT;

typedef struct {
	float Flowrate;
	float InfousionVolume;
	float TotalVolume;
	float KVORate;
	uint8_t Mode;
	float Bolus;
	uint8_t DataChanged;
} Infusion_paramT;

typedef struct {
	uint8_t CurrentMode;
	float VolumeLeft;
	float Rate;
}Motor_StatusT;

typedef struct {
	uint16_t HighThreshold;
	uint16_t MediumThreshold;
	uint16_t LowThreshold;
} Pressure_thresholdsT;

typedef struct {
	uint16_t Id;
	char Manufacturer[20];
	uint8_t VolumeInvterval;
	float diameter;
}SyringeT;

typedef struct {
	uint16_t Id;
	char Name[20];
	uint8_t ThreatLevel;
	float MinRate;
	float MaxRate;
}DrugT;

typedef struct {
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;
}time_ps;
typedef struct {
	char jsondata[500];
}Log;

#endif
