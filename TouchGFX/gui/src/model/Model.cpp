#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#ifndef SIMULATOR
#include <cmsis_os.h> // FreeRtos V2
extern osMessageQueueId_t InfusionQHandle;
#endif

Model::Model() : modelListener(0),
LatestEventReceived({ 0, 0, 0, ALARM_FLASH_PERIOD }),
PendingEventStatus(0),
InitStatus(true),
InitialisationParameters({ 0, 0, 0, DEFAULT, {0, 0, 0, 0, 0, 0},OTHER }),
PatientDataArrivedAck(0),
WaitingForPatientData(0),
PerfusionParameters({0.0, 0.0, 0.0, 0.1, 0, 300.0, 0}),
PressureThresholds({ 400, 600, 800 }),
CurrentPressure(0),
SyringeState(VALID),
CurrentTime(InitialisationParameters.Time),
Battery({50, SECTOR, CHARGING}),
KeyboardUser(0)
{

}

void Model::tick()
{
	/*
	* check rtos queues periodically for battery update, syringe update, alarm update, current time.
	*/
	if (0)
	{
		AlarmOrEvent();
	}

	if (0)
	{
		batteryUpdated();
	}

	if (0)
	{
		currentTimeUpdated();
	}

	if (0)
	{
		syringeUpdated();
	}

	if (0)
	{
		PerfusionParameters.Mode = MotorStatus.CurrentMode;
		calculateTimeLeft();
		motorStatusUpdated();
	}
}
/*===========================Model Listener==========================*/
void Model::AlarmOrEvent(void)
{
    if (modelListener != 0)
    {
        modelListener->AlarmOrEvent();
    }
}

void Model::batteryUpdated(void)
{
	if (modelListener != 0)
	{
		modelListener->AlarmOrEvent();
	}
}

void Model::currentTimeUpdated(void)
{
	if (modelListener != 0)
	{
		modelListener->currentTimeUpdated();
	}
}

void Model::syringeUpdated(void)
{
	if (modelListener != 0)
	{
		modelListener->syringeUpdated();
	}
}

void Model::motorStatusUpdated(void)
{
	if (modelListener != 0)
	{
		modelListener->motorStatusUpdated();
	}
}
/*==========================Alarms And Event===========================*/
uint8_t Model::getActiveEvents(uint8_t index)
{
	return EventStates[index - 1];
}

const char* Model::getEventTitle(uint8_t index)
{
	if (touchgfx::Texts::getLanguage() == 1)
	{
		return EventListFrench[index - 1];
	}
	else 
	{
		return EventListEnglish[index - 1];
	}
}

EventTypeT Model::getLatestEvent()
{
	return LatestEventReceived;
}

uint8_t Model::getPendingEventStatus()
{
	return PendingEventStatus;
}

void Model::savePendingEventStatus(void)
{
	PendingEventStatus = 0;
#ifndef SIMULATOR
	// RTOS
#endif
}

void Model::saveMuteStatus(void)
{
	if (MuteStatus)
		MuteStatus = 0;
	else
		MuteStatus = 1;
#ifndef SIMULATOR
	// RTOS
#endif
}

/*=========================INIT PARAMETERS==============================*/
uint8_t Model::getDisplayMode(void)
{
	return InitialisationParameters.DisplayMode;
}

void Model::saveDisplayMode(uint8_t value)
{
	InitialisationParameters.DisplayMode = value;
#ifndef SIMULATOR
	// RTOS
#endif
}

uint8_t Model::getInitStatus(void)
{
	return InitStatus;
}

/*========================PATIENT==========================================*/
Patient_dataT Model::getPatient(void)
{
	return Patient;
}

void Model::savePatientWeight(uint16_t value)
{
	Patient.Weight = value;
}

void Model::savePatientHeight(uint8_t value)
{
	Patient.Height = value;
}

void Model::savePatientName(char * Value)
{
	strncpy(Patient.Name, (const char*)Value, strlen(Value));
#ifndef SIMULATOR
	// RTOS
#endif
}

void Model::savePatientAge(uint8_t value)
{
	Patient.Age = value;
}

void Model::savePatientGender(uint8_t value)
{
	Patient.Gender = value;
}

void Model::requestLastPatientData(void)
{
	WaitingForPatientData = 1;
	PatientDataArrivedAck = 0;
#ifndef SIMULATOR
	// RTOS
#endif
}

void Model::RequestPatientSearch(char * Name)
{
	WaitingForPatientData = 1;
	PatientDataArrivedAck = 0;
#ifndef SIMULATOR
	// RTOS
#endif
}

uint8_t Model::getPatientDataRequestState(void)
{
	return PatientDataArrivedAck;
}

/*============================PERFUSION===================================*/
void Model::saveFlowaRate(SW_float value)
{
	float temp = (float)value.BeforeComma;
	temp = temp + (float)value.AfterComma / 10.0;
	PerfusionParameters.Flowrate = temp;
	calculateThirdParameter(CALLER_FLOWRATE);
	saveInfusionData();
}

SW_float Model::getFlowRate(void)
{
	SW_float temp;
	temp.BeforeComma = (uint16_t)PerfusionParameters.Flowrate;
	temp.AfterComma = (PerfusionParameters.Flowrate - (uint16_t)PerfusionParameters.Flowrate) * 10;
	return temp;
}

void Model::saveTotalVolume(SW_float value)
{
	float temp = (float)value.BeforeComma;
	temp = temp + (float)value.AfterComma / 10.0;
	if (temp != 0)
	{
		PerfusionParameters.TotalVolume = temp;
		MotorStatus.VolumeLeft = temp;
		if (PerfusionParameters.InfousionVolume == 0.0)
			saveInfusionVolume(value);

		saveInfusionData();
	}
}

SW_float Model::getTotalVolume(void)
{
	SW_float temp;
	temp.BeforeComma = (uint16_t)PerfusionParameters.TotalVolume;
	temp.AfterComma = (PerfusionParameters.TotalVolume - (uint16_t)PerfusionParameters.TotalVolume) * 10;
	return temp;
}

void Model::saveInfusionVolume(SW_float value)
{
	float temp = (float)value.BeforeComma;
	temp = temp + (float)value.AfterComma / 10.0;
	if (temp != 0)
	{
		PerfusionParameters.InfousionVolume = temp;
		if (PerfusionParameters.TotalVolume == 0.0)
			saveTotalVolume(value);
		calculateThirdParameter(CALLER_VOLUME);
		saveInfusionData();
	}
}

SW_float Model::getInfusionVolume(void)
{
	SW_float temp;
	temp.BeforeComma = (uint16_t)PerfusionParameters.InfousionVolume;
	temp.AfterComma = (PerfusionParameters.InfousionVolume - (uint16_t)PerfusionParameters.InfousionVolume) * 10;
	return temp;
}

void Model::saveKVORate(SW_float value)
{
	float temp = (float)value.BeforeComma;
	temp = temp + (float)value.AfterComma / 10.0;
	PerfusionParameters.KVORate = temp;
	saveInfusionData();
}

SW_float Model::getKVORate(void)
{
	SW_float temp;
	temp.BeforeComma = (uint16_t)PerfusionParameters.KVORate;
	temp.AfterComma = (PerfusionParameters.KVORate - (uint16_t)PerfusionParameters.KVORate) * 10;
	return temp;
}

void Model::saveBolusRate(SW_float value)
{
	float temp = (float)value.BeforeComma;
	temp = temp + (float)value.AfterComma / 10.0;
	PerfusionParameters.Bolus = temp;
	saveInfusionData();
}

SW_float Model::getBolusRate(void)
{
	SW_float temp;
	temp.BeforeComma = (uint16_t)PerfusionParameters.Bolus;
	temp.AfterComma = (PerfusionParameters.Bolus - (uint16_t)PerfusionParameters.Bolus) * 10;
	return temp;
}

uint8_t Model::getMode(void)
{
	return PerfusionParameters.Mode;
}

void Model::saveMode(uint8_t value)
{
	PerfusionParameters.Mode = value;
	saveInfusionData();
}

SW_time Model::getInfusionTIme()
{
	return InfusionTIme;
}

void Model::saveInfusionTime(SW_time Time)
{
	InfusionTIme = Time;
	Timeleft = Time;
	calculateThirdParameter(CALLER_TIME);
	saveInfusionData();
}

void Model::calculateThirdParameter(uint8_t caller)
{
	float temp = 0;
	if (PreviousCaller != FIRST_CALL)
	{
		switch (caller)
		{
		case CALLER_FLOWRATE:
			switch (PreviousCaller)
			{
			case CALLER_VOLUME:
				if (PerfusionParameters.Flowrate != 0)
					temp = PerfusionParameters.InfousionVolume / PerfusionParameters.Flowrate;
				else
					temp = 0;
				InfusionTIme.Hour = (int)temp;
				InfusionTIme.Minute = (temp - (int)temp) * 60;
				InfusionTIme.Second = (((temp - (int)temp) * 60) - InfusionTIme.Minute) * 60;
				break;
			case CALLER_TIME:
				PerfusionParameters.InfousionVolume = ((float)InfusionTIme.Hour + ((float)InfusionTIme.Minute / 60)) * PerfusionParameters.Flowrate;
				if (PerfusionParameters.TotalVolume == 0.0)
				{
					PerfusionParameters.TotalVolume = PerfusionParameters.InfousionVolume;
					MotorStatus.VolumeLeft = PerfusionParameters.InfousionVolume;
				}
				break;
			}
			break;
		case CALLER_VOLUME:
			switch (PreviousCaller)
			{
			case CALLER_FLOWRATE:
				if (PerfusionParameters.Flowrate != 0)
					temp = PerfusionParameters.InfousionVolume / PerfusionParameters.Flowrate;
				else
					temp = 0;
				InfusionTIme.Hour = (int)temp;
				InfusionTIme.Minute = (temp - (int)temp) * 60;
				InfusionTIme.Second = (((temp - (int)temp) * 60) - InfusionTIme.Minute) * 60;
				break;
			case CALLER_TIME:
				if ((InfusionTIme.Hour != 0) && (InfusionTIme.Minute != 0))
					PerfusionParameters.Flowrate = (PerfusionParameters.InfousionVolume) / ((float)InfusionTIme.Hour + ((float)InfusionTIme.Minute / 60));
				else
					PerfusionParameters.Flowrate = 0.0;
				break;
			}
			break;
		case CALLER_TIME:
			switch (PreviousCaller)
			{
			case CALLER_VOLUME:
				if ((InfusionTIme.Hour != 0) && (InfusionTIme.Minute != 0))
					PerfusionParameters.Flowrate = (PerfusionParameters.InfousionVolume) / ((float)InfusionTIme.Hour + ((float)InfusionTIme.Minute / 60));
				else
					PerfusionParameters.Flowrate = 0.0;
				break;
			case CALLER_FLOWRATE:
				PerfusionParameters.InfousionVolume = ((float)InfusionTIme.Hour + ((float)InfusionTIme.Minute / 60)) * PerfusionParameters.Flowrate;
				if (PerfusionParameters.TotalVolume == 0.0)
				{
					PerfusionParameters.TotalVolume = PerfusionParameters.InfousionVolume;
					MotorStatus.VolumeLeft = PerfusionParameters.InfousionVolume;
				}
				break;
			}
			break;
		}
	}
	if(PreviousCaller != caller)
		PreviousCaller = caller;
}

void Model::saveInfusionData(void)
{
#ifndef SIMULATOR
	// RTOS
	if(PerfusionParameters.Flowrate!=0 || (PerfusionParameters.InfousionVolume!=0 )){
		osMessageQueuePut(InfusionQHandle,&PerfusionParameters,1,100);
	}
#endif
}

SW_float Model::getVolumeLeft()
{
	SW_float temp;
	temp.BeforeComma = (uint16_t)MotorStatus.VolumeLeft;
	temp.AfterComma = (MotorStatus.VolumeLeft - (uint16_t)MotorStatus.VolumeLeft) * 10;
	return temp;
}

SW_time Model::getTimeLeft()
{
	return Timeleft;
}

void Model::calculateTimeLeft()
{
	float temp = MotorStatus.VolumeLeft / MotorStatus.Rate;
	Timeleft.Hour = (int)temp;
	Timeleft.Minute = (temp - (int)temp) * 60;
	Timeleft.Second = (((temp - (int)temp) * 60) - Timeleft.Minute) * 60;
}

Infusion_paramT Model::getInfusionParameters()
{
	return PerfusionParameters;
}

/*=========================================== Pressure ======================================*/
Pressure_thresholdsT Model::getPressureThresholds()
{
	return PressureThresholds;
}
void Model::savePressureThresholdLow(uint16_t value)
{
	PressureThresholds.LowThreshold = value;
#ifndef SIMULATOR
	// RTOS
#endif
}
void Model::savePressureThresholdMedium(uint16_t value)
{
	PressureThresholds.MediumThreshold = value;
#ifndef SIMULATOR
	// RTOS
#endif
}
void Model::savePressureThresholdHigh(uint16_t value)
{
	PressureThresholds.HighThreshold = value;
#ifndef SIMULATOR
	// RTOS
#endif
}

float Model::getCurrentPressure()
{
	return CurrentPressure;
}

/*========================= MISC =========================================*/
void Model::saveKeyboardUser(uint8_t user)
{
	KeyboardUser = user;
}

uint8_t Model::getKeyboardUser(void)
{
	return KeyboardUser;
}

/*========================= Syringe =========================================*/
SyringeT Model::getSyringe()
{
	return Syringe;
}

void Model::saveSyringe(SyringeT value)
{
	Syringe = value;
#ifndef SIMULATOR
	// RTOS
#endif
}

uint8_t Model::getSyringeState()
{
	return SyringeState;
}

/*========================= Current Time =========================================*/
SW_time Model::getCurrentTime(void)
{
	return CurrentTime;
}

/*========================= Battery =========================================*/
BatteryT Model::getBattery()
{
	return Battery;
}

/*========================= Drug =========================================*/
DrugT Model::getDrug()
{
	return Drug;
}

void Model::saveDrug(DrugT value)
{
	Drug = value;
#ifndef SIMULATOR
	// RTOS Maybe
#endif
}
