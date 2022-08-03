#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <string.h>



Model::Model() :
    modelListener(0),
    syringestatus(false),
    current_time({0, 0, 0}),
    drug(0),
    inputdestinsation(0),
    battery({100, PS_BATTERY }),
    perfusion_time({0, 0, 0}),
    User_parameters({ {0, 0}, {1000, 0}, {1000, 0}, {1, 0}, 0, {300, 0}, 0}),
    alarms({NO_ALARM , 0}),
    alarmpending(0),
    volume_left({0, 0}),
    time_left({0, 0, 0}),
    previouscallerid(0),
    purgepopup(0), 
    currentpressure(0),
    Pressure({400, 600, 800}),
	TempSensorData({0, 0, 0, 0}),
    InitParam({ 1, 50, 0, 0, {0, 0, 0}, PEDIATRICS}),
    init(0), 
    expectingPatientData(0),
    storedPatient(0),
    MotorResponse({{0, 0}, {0, 0}, 0, 0 }),
	expectingLogData(0),
	event(0),
	storedLog(0),
	Lock(0),
	Mute(0),
	screenlock(0),
	technicianpassword(9999)
{
}

void Model::tick()
{
    static int TickCounter = 0;

    TickCounter++;

    if (TickCounter % 60 == 0)
    {
        if (++current_time.seconds >= 60)
        {
            current_time.seconds = 0;
            if (++current_time.minutes >= 60)
            {
                current_time.minutes = 0;
                if (++current_time.hours >= 24)
                {
                    current_time.hours = 0;
                }
            }
        }
    }

#ifndef SIMULATOR
   // savedepartement(0)
    if ((init == 0) )
    		// && (osMessageQueueGet(SystemInitParam_handle, &InitParam, 0, 0) == osOK))
    {
    	init = 1;
    	current_time.hours = InitParam.startingtime.hours;
    	current_time.minutes = InitParam.startingtime.minutes;
    	current_time.seconds = InitParam.startingtime.seconds;
    	Patient.age = 0;
    	Patient.gender = 0;
    	Patient.height = 0;
    	Patient.weight = 0;
    	//osMessageQueuePut(InitAckQueue_handle, &init, 0, 0);
    }


	// int status = osMessageQueueGet(AlarmsToScreen_handle, &alarms, 0, 0);
	//if(status== osOK)
	//{
		User_parameters.mode = ALARM;
		if ((alarms.alarmSources > 0) && (alarms.alarmSources <= 17))
		{
			SaveMute(1);
			alarmsStates[alarms.alarmSources - 1] = alarms.status;
			alarmpending = alarms.status;
			if(alarms.status)
				AlarmOrEvent();
		}
	// }

	// status = osMessageQueueGet(EventstoScreenQueue_Handle, &event, 0, 0);
	// if(status== osOK)
	{
		if ((event > 0) && (event <= 15))
		{
			eventpending = 1;
			AlarmOrEvent();
		}
	}
	//if (osMessageQueueGet(BatteryStatus_handle, &battery, 0, 0) == osOK)
	{
	}
	// ------------------------ read current pressure
	//if (osMessageQueueGet(CurrentPressureDataQueue_handle, &currentpressure, 0, 0) == osOK)
	{
	}

	//if (osMessageQueueGet(ScreenDataQueue_Handle, &MotorResponse, 0, 0) == osOK)
	{
		TempSensorData.diameter = MotorResponse.Syringediameter;
		User_parameters.mode = MotorResponse.mode;
		calculateParametersLeft(MotorResponse);
	}
   // if ((expectingPatientData == 1) && (osMessageQueueGet(PatientData_handle, &Patient, 0, 0) == osOK))
    {
    	storedPatient = 1;
    	expectingPatientData = 0;
    }
   // if ((expectingLogData == 1) && (osMessageQueueGet(LogQueue_Handle, &logvector, 0, 0) == osOK))
    {
    	storedLog = 1;
    	expectingLogData = 0;
    }
#endif
}

bool Model::GetSyringeState()
{
    if (MotorResponse.Syringediameter < 2)
        return 0;
    else
        return 1;
}

uint16_t Model::GetSyringeDiameter(void)
{
        return MotorResponse.Syringediameter;
}

void Model::SaveCurrentTime(time_ps time)
{
    current_time = time;
#ifndef SIMULATOR
    //------------------------------------------------------------------------
    // osMessageQueuePut(TimeDataQueue_handle, &time, 0, 0);
#endif
}
time_ps Model::getcurrenttime()
{
    return current_time;
}

void Model::purgeactivate(uint8_t var)
{
    purgepopup = var;
}

uint8_t Model::purgeget(void)
{
    return purgepopup;
}

void Model::savedrug(int8_t savedrug)
{
    drug = savedrug;
#ifndef SIMULATOR
     // osMessageQueuePut(DrugDataQueue_handle, &drug, 0, 0);
#endif
}
int8_t Model::getdrug()
{
    return drug;
}

void Model::saveinputdestinsation(int16_t savevar)
{
    inputdestinsation = savevar;
}
int16_t Model::getinputdestinsation()
{
    return inputdestinsation;
}

void Model::saverate(ps_float saverate)
{
    User_parameters.flowrate = saverate;
    calculateparameters(1);
    datachanged();
}
ps_float Model::getrate()
{
    return User_parameters.flowrate;
}



void Model::savevolume(ps_float savevolume)
{
    User_parameters.total_volume = savevolume;
    if((User_parameters.infusion_volume.value == 0) && (User_parameters.infusion_volume.scale == 0))
    	User_parameters.infusion_volume = savevolume;
    if((User_parameters.infusion_volume.value > savevolume.value))
    	User_parameters.infusion_volume = savevolume;
    volume_left = savevolume;
    calculateparameters(2);
    datachanged();
}
ps_float Model::getvolume()
{
    return User_parameters.total_volume;
}

void Model::saveinfusionvolume(ps_float savevolume)
{
    User_parameters.infusion_volume = savevolume;
    if (User_parameters.total_volume.value < savevolume.value)
        User_parameters.total_volume.value = savevolume.value;
    calculateparameters(2);
    datachanged();
}
ps_float Model::getinfusionvolume()
{
    return User_parameters.infusion_volume;
}

void Model::saveoclusionLow(int16_t pressure)
{
    Pressure.low = pressure;
#ifndef SIMULATOR
   // osMessageQueuePut(PressureQueue_handle, &Pressure, 0, 0);
#endif

}
int16_t Model::getoclusionLow()
{
    return Pressure.low;
}

void Model::saveoclusionMedium(int16_t pressure)
{
    Pressure.medium = pressure;
#ifndef SIMULATOR
   // osMessageQueuePut(PressureQueue_handle, &Pressure, 0, 0);
#endif
}
int16_t Model::getoclusionMedium()
{
    return Pressure.medium;
}

void Model::saveoclusionHigh(int16_t pressure)
{
    Pressure.high = pressure;
#ifndef SIMULATOR
   //osMessageQueuePut(PressureQueue_handle, &Pressure, 0, 0);
#endif
}
int16_t Model::getoclusionHigh()
{
    return Pressure.high;
}

uint16_t Model::getcurrentpressure()
{
    return currentpressure;
}
void Model::savebolus(ps_float Bolus)
{
    User_parameters.bolus = Bolus;
    datachanged();
}
ps_float Model::getbolus()
{
    return User_parameters.bolus;
}

void Model::saveKVO(ps_float KVO)
{
    User_parameters.kvo_rate = KVO;
    datachanged();
}
ps_float Model::getKVO()
{
    return User_parameters.kvo_rate;
}

void Model::savePerfusionmode(int mode)
{
    User_parameters.mode = mode;
    datachanged();
}
int Model::getPerfusionmode(void)
{
    return User_parameters.mode;
}

void Model::saveDiameter(uint16_t diameter)
{
	TempSensorData.diameter = diameter;
#ifdef SIMULATOR
    MotorResponse.Syringediameter = diameter;
#endif
#ifndef SIMULATOR
	//osMessageQueuePut(MotorSensorDataQueue_Handle, &TempSensorData, 0, 0);
#endif
}
void Model::savePosition(uint32_t position)
{
	TempSensorData.position = position;
#ifndef SIMULATOR
	//osMessageQueuePut(MotorSensorDataQueue_Handle, &TempSensorData, 0, 0);
#endif
}
void Model::saveEnd(uint8_t end)
{
	TempSensorData.end = end;
#ifndef SIMULATOR
	//osMessageQueuePut(MotorSensorDataQueue_Handle, &TempSensorData, 0, 0);
#endif
}
void Model::saveStart(uint8_t start)
{
	TempSensorData.start = start;
#ifndef SIMULATOR
	//osMessageQueuePut(MotorSensorDataQueue_Handle, &TempSensorData, 0, 0);
#endif
}

void Model::savegender(uint8_t value)
{
    Patient.gender = value;
}
uint8_t Model::getgender()
{
    return Patient.gender;
}

void Model::savepatientage(uint8_t value)
{
    Patient.age = value;
}
uint8_t Model::getpatientage(void)
{
    return Patient.age;
}

void Model::savepatientname(char* value, uint8_t len)
{
	memset(Patient.name, 0, 18);
    strncpy(Patient.name, value, len);
#ifndef SIMULATOR
    //osMessageQueuePut(PatientNameQueue_handle, &Patient.name, 0, 0);
#endif

}
char* Model::getpatientname(void)
{
    return Patient.name;
}

void Model::savepatientheight(uint16_t value)
{
    Patient.height = value;
}
uint16_t Model::getpatientheight(void)
{
    return Patient.height;
}

void Model::savepatientweight(uint16_t value)
{
    Patient.weight = value;
}
uint16_t Model::getpatientweight(void)
{
    return Patient.weight;
}
void Model::savePerfusiontime(time_ps h)
{
    perfusion_time = h;
    time_left = h;
    calculateparameters(3);
}
time_ps Model::getPerfusiontime()
{
    return perfusion_time;
}

battery_info Model::getbatteryinfo(void)
{
    return battery;
}
void Model::batteryinfoready(void)
{
    if (modelListener != 0)
    {
        modelListener->batterystateready();
    }
}

void Model::AlarmOrEvent(void)
{
    if (modelListener != 0)
    {
        modelListener->AlarmOrEvent();
    }
}
alarm_info Model::getalarminfo(void)
{
    return alarms;
}
bool Model::getalarmpending(void)
{
    return alarmpending;
}
void Model::savealarmpending(bool var)
{
    alarmpending = var;
}

ps_float Model::getvolumeleft(void)
{
    return volume_left;
}

ps_float Model::getinfusionvolumeleft(void)
{
    return infusion_volume_left;
}

time_ps Model::gettimeleft(void)
{
    return time_left;
}

uint8_t Model::GetDisplayMode(void)
{
    return InitParam.displayMode;
}
void  Model::SaveDisplayMode(uint8_t mode)
{
    InitParam.displayMode = mode;
#ifndef SIMULATOR
    //osMessageQueuePut(SystemInitParam_handle, &InitParam, 0, 0);
#endif
}

uint8_t Model::getsound(void)
{
    return InitParam.sound;
}
void   Model::savesound(uint8_t sound)
{
    InitParam.sound = sound;
#ifndef SIMULATOR
    //osMessageQueuePut(SystemInitParam_handle, &InitParam, 0, 0);
   // --------------------------------------------------------------------------------
   // osMessageQueuePut(SoundDataQueue_handle, &sound, 0, 0);
#endif
}

uint16_t Model::getpassword(void)
{
    return InitParam.password;
}
void   Model::savepassword(uint16_t pwd)
{
    InitParam.password = pwd;
#ifndef SIMULATOR
   // osMessageQueuePut(SystemInitParam_handle, &InitParam, 0, 0);
#endif
}

void Model::calculateparameters(int callerid)
{
    touchgfx_printf("callerid = %d previous caller id = %d\n", callerid, previouscallerid);
    float temp = 0;
    switch(callerid)
    {
    case 1 :
        if (previouscallerid == 2)
        {
            temp = (((float)User_parameters.infusion_volume.value + (((float)User_parameters.infusion_volume.scale / 10))) / ((float)User_parameters.flowrate.value + ((float)User_parameters.flowrate.scale / 10)));
            perfusion_time.hours = (int)temp;
            perfusion_time.minutes = (temp - (int)temp) * 60;
            perfusion_time.seconds = (((temp - (int)temp) * 60) - perfusion_time.minutes) * 60;
            touchgfx_printf("%f %d %d", temp, perfusion_time.hours, perfusion_time.minutes);
            time_left = perfusion_time;
        }
        else if ((previouscallerid == 3) || (previouscallerid == 1))
        {
            temp = ((float)perfusion_time.hours + ((float)perfusion_time.minutes / 60)) * ((float)User_parameters.flowrate.value + ((float)User_parameters.flowrate.scale / 10));
            User_parameters.infusion_volume.value = (int)temp;
            User_parameters.infusion_volume.scale = (temp - (int)temp) * 10;
            saveinfusionvolume(User_parameters.infusion_volume);
            touchgfx_printf("%f %d %d", temp, User_parameters.infusion_volume.value, User_parameters.infusion_volume.scale);
            volume_left = User_parameters.infusion_volume;
        }

        break;
    case 2 :
        if ((previouscallerid == 1) || (previouscallerid == 2))
        {
            temp = (((float)User_parameters.infusion_volume.value + (((float)User_parameters.infusion_volume.scale / 10))) / ((float)User_parameters.flowrate.value + ((float)User_parameters.flowrate.scale / 10)));
            perfusion_time.hours = (int)temp;
            perfusion_time.minutes = (temp - (int)temp) * 60;
            perfusion_time.seconds = (((temp - (int)temp) * 60) - perfusion_time.minutes) * 60;
            touchgfx_printf("%f %d %d", temp, perfusion_time.hours, perfusion_time.minutes);
            time_left = perfusion_time;
        }
        else if (previouscallerid == 3)
        {
            temp = (((float)User_parameters.infusion_volume.value + (((float)User_parameters.infusion_volume.scale / 10))) / ((float)perfusion_time.hours + ((float)perfusion_time.minutes / 60)));
            User_parameters.flowrate.value = (int)temp;
            User_parameters.flowrate.scale = (temp - (int)temp) * 10;
        }
        break;
    case 3 :
        if ((previouscallerid == 1) || (previouscallerid == 3))
        {
            temp = ((float)perfusion_time.hours + ((float)perfusion_time.minutes / 60)) * ((float)User_parameters.flowrate.value + ((float)User_parameters.flowrate.scale / 10));
            User_parameters.infusion_volume.value = (int)temp;
            User_parameters.infusion_volume.scale = (temp - (int)temp) * 10;
            saveinfusionvolume(User_parameters.infusion_volume);
            volume_left = User_parameters.infusion_volume;
            touchgfx_printf("%f %d %d", temp, User_parameters.infusion_volume.value, User_parameters.infusion_volume.scale);
        }
        else if (previouscallerid == 2)
        {
            temp = (((float)User_parameters.infusion_volume.value + (((float)User_parameters.infusion_volume.scale / 10))) / ((float)perfusion_time.hours + ((float)perfusion_time.minutes / 60)));
            User_parameters.flowrate.value = (int)temp;
            User_parameters.flowrate.scale = (temp - (int)temp) * 10;
        }
        break;
    default :
        break;
    }
    previouscallerid = callerid;
}


void Model::datachanged(void)
{
#ifndef SIMULATOR
	//osMessageQueuePut(PerfusuinParametersDataQueue_handle, &User_parameters, 0, 0);
#endif
}

void Model::RequeststoredData(void)
{
#ifndef SIMULATOR
    expectingPatientData = 1;
    //osMessageQueuePut(PatientDataRequest_handle, &expectingPatientData, 0, 0);
    storedPatient = 0;
#endif
}

uint8_t Model::PatientDataRequestAnswer(void)
{
    return storedPatient;
}

void Model::calculateParametersLeft(retun_parameters param)
{
	volume_left = param.VolumeLeft;
	infusion_volume_left = param.InfusionVolumeLeft;
    float temp = (((float)infusion_volume_left.value + (((float)infusion_volume_left.scale / 10))) / ((float)User_parameters.flowrate.value + ((float)User_parameters.flowrate.scale / 10)));
    time_left.hours = (int)temp;
    time_left.minutes = (temp - (int)temp) * 60;
    time_left.seconds = (((temp - (int)temp) * 60) - time_left.minutes) * 60;
}

uint8_t  Model::GetAlarmVector(uint8_t index)
{
	return alarmsStates[index];
}

void  Model::SavePatient(void)
{
#ifndef SIMULATOR
    //osMessageQueuePut(PatientData_handle, &Patient, 0, 0);
    expectingPatientData = 0;
#endif
}

void Model::SaveMute(uint8_t state)
{
	Mute = state;
#ifndef SIMULATOR
    //osMessageQueuePut(MuteRequestQueue_handle, &Mute, 0, 0);
#endif
}

uint8_t Model::GetMute(void)
{
	return Mute;
}

void Model::SaveLock(uint8_t state)
{
	Lock = state;
}

uint8_t Model::GetLock(void)
{
	return Lock;
}

uint8_t Model::Geteventpending(void)
{
	return eventpending;
}

void Model::Saveeventpending(uint8_t event)
{
	eventpending = event;
}

uint8_t Model::Getevent(void)
{
	return event;
}


logT  Model::GetLogVector(uint8_t index)
{
	return logvector[index];
}

void Model::RequeststorelogdData(uint8_t direction)
{
#ifndef SIMULATOR
    expectingLogData = 1;

    // osMessageQueuePut(LogRequestQueue_Handle, &direction, 0, 0);
    storedLog = 0;
#endif
}

uint8_t Model::LogDataRequestAnswer(void)
{
    return storedLog;
}


uint8_t Model::getscreenlock(void)
{
	return screenlock;
}

void Model::savescreenlock(uint8_t screen)
{
	screenlock = screen;
}

uint8_t Model::getdepartement(void)
{
	return InitParam.departement;
}

void Model::savedepartement(uint8_t screen)
{
	InitParam.departement = screen;
#ifndef SIMULATOR
    // osMessageQueuePut(SystemInitParam_handle, &InitParam, 0, 0);
#endif
}
uint16_t Model::getpwdtech(void)
{
	return technicianpassword;
}

void Model::savepwdtech(uint16_t screen)
{
	technicianpassword = screen;
}

uint8_t Model::getinit(void)
{
	return init;
}
