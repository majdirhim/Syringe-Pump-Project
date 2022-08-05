#ifndef MODEL_HPP
#define MODEL_HPP
#include <touchgfx/hal/types.hpp>
#include <touchgfx/Utils.hpp>
#include "../../../Core/Inc/SW_common.h"
#ifndef SIMULATOR
#include "../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os.h"

extern osMessageQueueId_t PerfusuinParametersDataQueue_handle;
// temporary
extern osMessageQueueId_t MotorSensorDataQueue_Handle;

extern osMessageQueueId_t LogQHandle;
extern osMessageQueueId_t patientQHandle;
extern osMessageQueueId_t InfusionQHandle;

extern osMessageQueueId_t SystemInitParam_handle;
extern osMessageQueueId_t PatientData_handle;
extern osMessageQueueId_t ScreenDataQueue_Handle;
extern osMessageQueueId_t AlarmsToScreen_handle;
extern osMessageQueueId_t BatteryStatus_handle;
extern osMessageQueueId_t PatientDataRequest_handle;
extern osMessageQueueId_t EventstoScreenQueue_Handle;
extern osMessageQueueId_t LogQueue_Handle;
extern osMessageQueueId_t LogRequestQueue_Handle;
extern osMessageQueueId_t PatientNameQueue_handle;
extern osMessageQueueId_t PressureQueue_handle;
extern osMessageQueueId_t DrugDataQueue_handle;
extern osMessageQueueId_t SoundDataQueue_handle;
extern osMessageQueueId_t TimeDataQueue_handle;
extern osMessageQueueId_t CurrentPressureDataQueue_handle;
extern osMessageQueueId_t MuteRequestQueue_handle;
extern osMessageQueueId_t InitAckQueue_handle;
extern Log data;
#endif





class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    bool GetSyringeState();

    uint16_t GetSyringeDiameter(void);

    void SaveCurrentTime(time_ps time);
    time_ps getcurrenttime();

    void savedrug(int8_t savedrug);
    int8_t getdrug();

    void saveinputdestinsation(int16_t savevar);
    int16_t getinputdestinsation();

    void saverate(ps_float saverate);
    ps_float getrate();

    void savevolume(ps_float savevolume);
    ps_float getvolume();

    void saveinfusionvolume(ps_float savevolume);
    ps_float getinfusionvolume();

    void saveoclusionLow(int16_t pressure);
    int16_t getoclusionLow();

    void saveoclusionMedium(int16_t pressure);
    int16_t getoclusionMedium();

    void saveoclusionHigh(int16_t pressure);
    int16_t getoclusionHigh();

    uint16_t getcurrentpressure();

    void saveKVO(ps_float kvo);
    ps_float getKVO();

    void savebolus(ps_float bolus);
    ps_float getbolus();

    void datachanged(void);

    // void saveMode(uint8_t);

    void purgeactivate(uint8_t);
    uint8_t purgeget(void);

    void savePerfusiontime(time_ps h);
    time_ps getPerfusiontime();

    void calculateParametersLeft(retun_parameters);

    void savePerfusionmode(int mode);
    int getPerfusionmode(void);

    void saveDiameter(uint16_t diameter);
    void savePosition(uint32_t position);
    void saveEnd(uint8_t end);
    void saveStart(uint8_t start);

    void savegender(uint8_t value);
    uint8_t getgender();

    void savepatientname(char*, uint8_t len);
    char* getpatientname(void);

    void savepatientheight(uint16_t);
    uint16_t getpatientheight(void);

    void savepatientweight(uint16_t);
    uint16_t getpatientweight(void);

    void savepatientage(uint8_t);
    uint8_t getpatientage(void);

    battery_info getbatteryinfo(void);
    void batteryinfoready(void);
    
    void AlarmOrEvent(void);

    alarm_info getalarminfo(void);
    bool getalarmpending();
    void savealarmpending(bool);

    ps_float getvolumeleft(void);

    time_ps gettimeleft(void);

    uint8_t GetDisplayMode(void);
     void   SaveDisplayMode(uint8_t);

     uint8_t getsound(void);
     void   savesound(uint8_t);

     uint16_t getpassword(void);
     void   savepassword(uint16_t);

     void RequeststoredData(void);
     uint8_t PatientDataRequestAnswer(void);

     uint8_t GetAlarmVector(uint8_t);

    void calculateparameters(int callerid);

    void  SavePatient(void);

    void SaveMute(uint8_t);
    uint8_t GetMute(void);

    void SaveLock(uint8_t);
    uint8_t GetLock(void);

    uint8_t Geteventpending(void);
    void Saveeventpending(uint8_t event);
    uint8_t Getevent(void);
    logT  GetLogVector(uint8_t index);
    void RequeststorelogdData(uint8_t);
    uint8_t LogDataRequestAnswer(void);

    uint8_t getscreenlock(void);
    void savescreenlock(uint8_t screen);

    uint8_t getdepartement(void);
    void savedepartement(uint8_t screen);

    uint16_t getpwdtech(void);
    void savepwdtech(uint16_t screen);

    uint8_t getinit(void);

    ps_float getinfusionvolumeleft(void);

    void toLog(char str[30]);

    void tick();
protected:
    ModelListener* modelListener;
    bool syringestatus;
    int syringe_diameter;
    time_ps current_time;
    int8_t drug;
    int16_t inputdestinsation;
    battery_info battery;
    time_ps perfusion_time;
    perfusionFV_parameters User_parameters;
    alarm_info alarms;
    bool alarmpending;
    ps_float volume_left;
    time_ps time_left;
    int previouscallerid;
    uint8_t purgepopup;
    uint16_t currentpressure;
    patient_dataT Patient;
    pressure_dataT Pressure;
    motor_sensor_dataT TempSensorData;
    System_init_paramT InitParam;
    uint8_t init;
    uint8_t expectingPatientData;
    uint8_t storedPatient;
    uint8_t alarmsStates[17];
    retun_parameters MotorResponse;
    uint8_t expectingLogData;
    logT logvector[32];
    uint8_t event;
    uint8_t eventpending;
    uint8_t storedLog;
    uint8_t Lock;
    uint8_t Mute;
    perfusionFV_parameters PerfusionParameters;
    uint8_t screenlock;
    uint16_t technicianpassword;
    ps_float infusion_volume_left;
};

#endif // MODEL_HPP
