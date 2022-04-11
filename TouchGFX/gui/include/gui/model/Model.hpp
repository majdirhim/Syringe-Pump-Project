#ifndef MODEL_HPP
#define MODEL_HPP

#include <stdint.h>
#include <string>
#include "../../../Core/Inc/SW_common.h"
#include "../../../Core/Inc/Runtime_language.h"
#include <touchgfx/Texts.hpp>

enum {
    FIRST_CALL,
    CALLER_FLOWRATE,
    CALLER_VOLUME,
    CALLER_TIME
};


class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    /*======================= Model Listener Functions ======================================*/
    void AlarmOrEvent(void);
    void batteryUpdated(void);
    void currentTimeUpdated(void);
    void syringeUpdated(void);
    void motorStatusUpdated(void);
    /*====================== Alarms And Event =============================================*/
    uint8_t getActiveEvents(uint8_t);
    const char* getEventTitle(uint8_t);
    EventTypeT getLatestEvent();
    uint8_t getPendingEventStatus();
    void savePendingEventStatus(void);
    void saveMuteStatus(void);
    /*====================== Initialisation =============================================*/
    uint8_t getInitStatus(void);
    uint8_t getDisplayMode(void);
    void saveDisplayMode(uint8_t);
    /*====================== Patient ====================================================*/
    Patient_dataT getPatient(void);
    void savePatientWeight(uint16_t);
    void savePatientHeight(uint8_t);
    void savePatientName(char *);
    void savePatientAge(uint8_t);
    void savePatientGender(uint8_t);
    void requestLastPatientData(void);
    void RequestPatientSearch(char *);
    uint8_t getPatientDataRequestState(void);
    /*====================== Perfusion Parameters =================================================*/
    void saveFlowaRate(SW_float);
    SW_float getFlowRate(void);
    void saveTotalVolume(SW_float);
    SW_float getTotalVolume(void);
    void saveInfusionVolume(SW_float);
    SW_float getInfusionVolume(void);
    void saveKVORate(SW_float);
    SW_float getKVORate(void);
    void saveBolusRate(SW_float);
    SW_float getBolusRate(void);
    uint8_t getMode(void);
    void saveMode(uint8_t);
    SW_time getInfusionTIme();
    void saveInfusionTime(SW_time);
    void calculateThirdParameter(uint8_t);
    void saveInfusionData(void);
    SW_float getVolumeLeft();
    SW_time getTimeLeft();
    void calculateTimeLeft();
    Infusion_paramT getInfusionParameters();
    /*====================== Pressure ===========================================================*/
    Pressure_thresholdsT getPressureThresholds();
    void savePressureThresholdLow(uint16_t);
    void savePressureThresholdMedium(uint16_t);
    void savePressureThresholdHigh(uint16_t);
    float getCurrentPressure();
    /*====================== Syringe ===========================================================*/
    SyringeT getSyringe();
    void saveSyringe(SyringeT);
    uint8_t getSyringeState();
    /*====================== Time ===========================================================*/
    SW_time getCurrentTime(void);
    /*====================== Battery ===========================================================*/
    BatteryT getBattery();
    /*====================== Drug ===========================================================*/
    DrugT getDrug();
    void saveDrug(DrugT);
    /*====================== MISC ==============================================================*/
    uint8_t getKeyboardUser(void);
    void saveKeyboardUser(uint8_t);

protected:
    ModelListener* modelListener;
    uint8_t EventStates[NUMBER_OF_ALARMS + NUMBER_OF_ALERTS] = { 0 };
    EventTypeT LatestEventReceived;
    uint8_t PendingEventStatus;
    uint8_t MuteStatus = 0;
    uint8_t InitStatus;
    System_init_paramT InitialisationParameters;
    Patient_dataT Patient = { "", 0, 0, 0, 0 };
    uint8_t PatientDataArrivedAck;
    uint8_t WaitingForPatientData;
    Infusion_paramT PerfusionParameters;
    SW_time InfusionTIme = { 0, 0, 0, 0, 0, 0 };
    uint8_t PreviousCaller = FIRST_CALL;
    Motor_StatusT MotorStatus;
    SW_time Timeleft;
    Pressure_thresholdsT PressureThresholds;
    float CurrentPressure;
    uint8_t SyringeState;
    SyringeT Syringe = { 0, "", ML50, 0 };
    SW_time CurrentTime;
    BatteryT Battery;
    DrugT Drug = { 0, "", NO_THREAT, 0.0, 0.0 };
    uint8_t KeyboardUser;

    const char * EventListEnglish[NUMBER_OF_ALARMS + NUMBER_OF_ALERTS + NUMBER_OF_NOTIFICATIONS + NUMBER_OF_DEFAULT_EVENTS] = {
        LINE_OCCLUDED_TITLE_ENGLISH_HIGH,
        BATTERY_OVERCURRENT_TITLE_ENGLISH,
        BATTERY_OVERHEAT_TITLE_ENGLISH,
        BATTERY_CHARGE_DEPLETED_TITLE_ENGLISH,
        BATTERY_CONTACT_FAILURE_TITLE_ENGLISH,
        BATTERTY_CHARGE_TIMEOUT_TITLE_ENGLISH,
        MOTOR_THERMAL_OVERHEAT_TITLE_ENGLISH,
        MOTOR_THERMAL_SHUTDOWN_TITLE_ENGLISH,
        MOTOR_OVERCURRENT_TITLE_ENGLISH,
        MOTOR_UNDERVOLTAGE_TITLE_ENGLISH,
        MOTOR_DRIVER_NOT_RESPONSDING_TITLE_ENGLISH,
        POSTION_ERROR_TITLE_ENGLISH,
        SYRINGUE_NOT_DETECTED_ALARM_TITLE_ENGLISH,
        SYRINGE_EMPTY_TITLE_ENGLISH,
        END_OF_TRAIL_TITLE_ENGLISH,
        LINE_OCCLUDED_TITLE_ENGLISH_MEDIUM,
        BATTERY_NO_CHARGING_CURRENT_TITLE_ENGLISH,
        BATTERY_LOW_TEMPERATURE_TITLE_ENGLISH,
        BATTERY_LOW_CHARGE_TITLE_ENGLISH,
        INTERNAL_SOFTWARE_ERROR_TITLE_ENGLISH,
        INFUSION_COMPLETE_TITLE_ENGLISH,
        BOLUS_COMPLETE_TITLE_ENGLISH,
        KVO_STARTED_TITLE_ENGLISH,
        SYRINGE_NEAR_EMPTY_TITLE_ENGLISH,
        LINE_OCCLUDED_TITLE_ENGLISH_LOW,
        COMPLETE_EDITING_INFO_TITLE_ENGLISH,
        PUMP_IS_IDLE_TITLE_ENGLISH,
        PERFUSION_STARTED_TITLE_ENGLISH,
        PERFUSION_STOPPED_TITLE_ENGLISH,
        BOLUS_STARTED_TITLE_ENGLISH,
        BOLUS_STOPPED_TITLE_ENGLISH,
        KVO_STOPPED_TITLE_ENGLISH,
        PURGE_STARTED_TITLE_ENGLISH,
        PURGE_STOPPED_TITLE_ENGLISH
    };

    const char* EventListFrench[NUMBER_OF_ALARMS + NUMBER_OF_ALERTS + NUMBER_OF_NOTIFICATIONS + NUMBER_OF_DEFAULT_EVENTS] = {
        LINE_OCCLUDED_TITLE_FRENCH_HIGH,
        BATTERY_OVERCURRENT_TITLE_FRENCH,
        BATTERY_OVERHEAT_TITLE_FRENCH,
        BATTERY_CHARGE_DEPLETED_TITLE_FRENCH,
        BATTERY_CONTACT_FAILURE_TITLE_FRENCH,
        BATTERTY_CHARGE_TIMEOUT_TITLE_FRENCH,
        MOTOR_THERMAL_OVERHEAT_TITLE_FRENCH,
        MOTOR_THERMAL_SHUTDOWN_TITLE_FRENCH,
        MOTOR_OVERCURRENT_TITLE_FRENCH,
        MOTOR_UNDERVOLTAGE_TITLE_FRENCH,
        MOTOR_DRIVER_NOT_RESPONSDING_TITLE_FRENCH,
        POSTION_ERROR_TITLE_FRENCH,
        SYRINGUE_NOT_DETECTED_ALARM_TITLE_FRENCH,
        SYRINGE_EMPTY_TITLE_FRENCH,
        END_OF_TRAIL_TITLE_FRENCH,
        LINE_OCCLUDED_TITLE_FRENCH_MEDIUM,
        BATTERY_NO_CHARGING_CURRENT_TITLE_FRENCH,
        BATTERY_LOW_TEMPERATURE_TITLE_FRENCH,
        BATTERY_LOW_CHARGE_TITLE_FRENCH,
        INTERNAL_SOFTWARE_ERROR_TITLE_FRENCH,
        INFUSION_COMPLETE_TITLE_FRENCH,
        BOLUS_COMPLETE_TITLE_FRENCH,
        KVO_STARTED_TITLE_FRENCH,
        SYRINGE_NEAR_EMPTY_TITLE_FRENCH,
        LINE_OCCLUDED_TITLE_FRENCH_LOW,
        COMPLETE_EDITING_INFO_TITLE_FRENCH,
        PUMP_IS_IDLE_TITLE_FRENCH,
        PERFUSION_STARTED_TITLE_FRENCH,
        PERFUSION_STOPPED_TITLE_FRENCH,
        BOLUS_STARTED_TITLE_FRENCH,
        BOLUS_STOPPED_TITLE_FRENCH,
        KVO_STOPPED_TITLE_FRENCH,
        PURGE_STARTED_TITLE_FRENCH,
        PURGE_STOPPED_TITLE_FRENCH
    };
};

#endif // MODEL_HPP
