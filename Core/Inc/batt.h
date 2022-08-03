/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BATT_H
#define __BATT_H

#ifdef __cplusplus
 extern "C" {
#endif

#define BATTADDR 0x0B



#include "main.h"

 /***** enums *****/

 typedef enum {
	   ManufacturerAccess = 0x00,
	   RemainingCapacityAlarm = 0x01,
	   RemainingTimeAlarm = 0x02,
	   BatteryMode = 0x03,
	   AtRate = 0x04,
	   AtRateTimeToFull = 0x05,
	   AtRateTimeToEmpty = 0x06,
	   AtRateOK = 0x07,
	   Temperature = 0x08,
	   Voltage = 0x09,
	   Current = 0x0a,
	   AverageCurrent = 0x0b,
	   MaxError = 0x0c,
	   RelativeStateOfCharge = 0x0d,
	   AbsoluteStateOfCharge = 0x0e,
	   RemainingCapacity = 0x0f,
	   FullChargeCapacity = 0x10,
	   RunTimeToEmpty = 0x11,
	   AverageTimeToEmpty = 0x12,
	   AverageTimeToFull = 0x13,
	   ChargingCurrent = 0x14,
	   ChargingVoltage = 0x15,
	   BatteryStatus = 0x16,
	   CycleCount = 0x17,
	   DesignCapacity = 0x18,
	   DesignVoltage = 0x19,
	   SpecificationInfo = 0x1a,
	   ManufactureDate = 0x1b,
	   SerialNumber = 0x1c,
	   // 0x1d-0x1f reserved
	   ManufacturerName = 0x20,
	   DeviceName = 0x21,
	   CellChemistry = 0x22,
	   ManufacturerData = 0x23,
 }SBSCommand;

 typedef enum {
	   Initialized     = 0x0080,
	   Discharging     = 0x0040,
	   FullyCharged    = 0x0020,
	   FullyDischarged = 0x0010,
 }BatteryStates;

 typedef enum {
	   OverCharged       = 0x8000,
	   TerminateCharge   = 0x4000,
	   OverTemp          = 0x1000,
	   RemainingCap 	 = 0x0200,
	   RemainingTime     = 0x0100,
	   Mask
 }BatteryStatusAlarm ;

 typedef enum {
	   OK                 = 0x0,
	   Busy               = 0x1,
	   ReservedCommand    = 0x2,
	   UnsupportedCommand = 0x3,
	   AccessDenied       = 0x4,
	   OverflowUnderflow  = 0x5,
	   BadSize            = 0x6,
	   UnknownError       = 0x7,
 }BatteryStatusError ;


 /**** functions *****/

 // mV
  uint16_t voltage();
  // mA
  uint16_t current() ;
  // mAh
  uint16_t fullChargeCapacity() ;
  // mAh
  uint16_t designCapacity() ;
  // percent
  uint16_t relativeStateOfCharge() ;
  // bit flags, use above enums to interpret
  uint16_t batteryStatus() ;
  // number
  uint16_t serialNumber() ;
  //time in minutes to empty
  uint16_t runtimetoempty();
  // Celsius
  float temperature() ;

 //uint16_t readWord(SBSCommand command); /** static in .c file **/
#ifdef __cplusplus
  }
#endif

#endif /* #ifndef __BATT_H*/

