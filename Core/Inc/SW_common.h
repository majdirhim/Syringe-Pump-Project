#include <stdint.h>
#include <string.h>

#ifndef SW_COMMON_H_
#define SW_COMMON_H_

typedef enum {
	NO_ALARM,
    BATTERY_OVERCURRENT,                     // LE COURENT DE LA BATTERIE EST SUPERIEUR A AL LIMITE
    BATTERY_CHHARGE_DEPLETED,               // LE NIVEAU DE CHARGE DE LA BATTERIE IN INFERIEUR A 10 MIN
    BATTERY_OVERHEAT,                      // TEMPERATURE > 80°C
    BATTERY_UNDERHEAT,                    // TEMPERATURE < -20°C
    BATTERY_LOW_CHARGE,                   // LE NIVEAU DE CHARGE DE LA BATTERIE EST INFERIEUR A 2H
    BATTERY_CONTACT_FAILURE,              // PERTE DE PUISSANCE ENTRE LE CONNECTEUR ET LA BATTERIE, ET LA PUISSANCE DE LA BATTERIE> 3W
    BATTERY_UNDERCURRENT,                // LE COURANT DE LA BATTERIE < 10mA LORS DE CHARGE
    BATTERTY_CHARGE_TIMEOUT,              // LA BATTERIE N'EST PAS COMPLETEMENT CHARGEE APRES 16H DE CHARGE
    MOTOR_THERMAL_OVERHEAT,              // TEMPERATURE ELEVE DETECTE DANS LA DRIVER
    MOTOR_THERMAL_SHUTDOWN,             // LE DRIVER A ARRETE SON FONCTIONNEMENT DUE A UNE TEMPERATURE ELEVE
    MOTOR_OVERCURRENT,                 // LE COURENT DU MOTEUR EST SUPERIEUR A AL LIMITE
    MOTOR_UNDERVOLTAGE,               // L'ALIMENTATION DU MOTEUR N'EST PAS ADEQUAT
    MOTOR_DRIVER_NOT_RESPONSDING,    // LE DRIVER REFUSE LES COMMANDE ERREUR DE COMMUNICATION
    OVERPRESSURE,                   // DETECTION D'UNE PRESSION ELEVE AU NIVEAU DE LA SYRINGUE
	LINE_OCCLUDED_MEDIUM,
	LINE_OCCLUDED_LOW,
    INTERNAL_ERROR,        // DETECTION D'UNE  soft ERREUR INTERNE /**DANS LA SYRINGUE**/
	POSTION_ERROR,
	SYRINGUE_NOT_DETECTED_ALARM
}alarm_sources;

typedef struct {
    alarm_sources alarmSources;
    uint8_t status;
}alarm_info;

typedef enum {
	CONTINUE_MOTOR,
	STOP_MOTOR,
	BACKWARD_MOTOR
}MotorAlarmBehavior;

typedef enum {
	NO_EVENT,
    PERFUSION_STARTED=20,
    PERFUSION_STOPPED,
    PERFUSION_COMPLETE,
    BOLUS_STARTED,
    BOLUS_STOPPED,
    BOLUS_COMPLETE,
	KVO_STARTED,
	KVO_STOPPED,
	PURGE_STARTED,
	PURGE_COMPLETE,
	PURGE_STOPPED,
    SYRINGE_NEAR_EMPTY,
    SYRINGE_EMPTY,
	END_OF_TRAIL,
    POWER_SOURCE_CHANGED,
}events;

typedef struct {
	events event;
    uint8_t notification;
}event_info;

typedef struct {
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
}time_ps;

typedef struct {
	uint8_t source;
    time_ps timestamp;
    uint8_t types;
}logT;


typedef enum power_source{
    PS_SECTOR,
    PS_BATTERY
}power_sources;

typedef struct battery_info {
    int charge_level;
    int TimeToEmpty;
    power_sources power_source;
} battery_info;

enum infusion_modes {
    STOP,
    INFUSION,
    BOLUS,
	PURGE,
	ALARM,
	KVO,
	PAUSE,
    IVOC,
    TIVA
};

typedef struct {
    int value;
    int scale;
} ps_float;


typedef struct {
    ps_float flowrate;
    ps_float infusion_volume;
    ps_float total_volume;
    ps_float kvo_rate;
    uint8_t mode;
    ps_float bolus;
    uint8_t changed;
} perfusionFV_parameters;

typedef struct {
    ps_float VolumeLeft;
    ps_float InfusionVolumeLeft;
    uint16_t Syringediameter;
    uint8_t mode;
} retun_parameters;

typedef struct {
    char name[20];
    uint8_t height;
	uint16_t weight;
	uint8_t age;
	uint8_t gender;
}patient_dataT;

typedef struct {
    uint16_t low;
    uint16_t medium;
    uint16_t high;
}pressure_dataT;

typedef struct {
    uint8_t start;
    uint8_t end;
    uint16_t diameter;
    int32_t position;
}motor_sensor_dataT;

enum departements
{
	PEDIATRICS,
	EMERGENCY,
	NEONATAL,
	INTENSIVE_CARE,
	MATERNITY,
	OTHERS
};

enum DisplayMode
{
	DEFAULTDISPLAY,
	BLACKDISPLAY,
	CHILDRENDISPLAY,
};
typedef struct {
    uint16_t Id;
    uint8_t sound;
    uint16_t password;
    uint8_t displayMode;
    time_ps startingtime;
    uint8_t departement;
}System_init_paramT;


typedef struct {
	uint16_t Id;
	char Name[20];
	uint8_t ThreatLevel;
	float MinRate;
	float MaxRate;
}DrugT;

typedef struct {
	char jsondata[500];
}Log;


#define oclusion_text_english "Oclusion"
#define oclusion_action_english "please fix unclog the perfusion tube, and the\nperfusion will resume automatically."
#define oclusion_description_english "Sensors have detected a high pressure in\nthe perfusion tube, systems shutting down."
#define oclusion_text_frensh "Oclusion"
#define oclusion_action_frensh "please fix unclog the perfusion tube, and the\nperfusion will resume automatically."
#define oclusion_description_frensh "Sensors have detected a high pressure in\nthe perfusion tube, systems shutting down."
#define battovc_text_english "battovc"
#define battovc_action_english ""
#define battovc_description_english ""
#define battovc_text_frensh "battovc"
#define battovc_action_frensh ""
#define battovc_description_frensh ""
#define battunc_text_english "battunc"
#define battunc_action_english ""
#define battunc_description_english ""
#define battunc_text_frensh "battunc"
#define battunc_action_frensh ""
#define battunc_description_frensh ""
#define battovh_text_english "battovh"
#define battovh_action_english ""
#define battovh_description_english ""
#define battovh_text_frensh "battovh"
#define battovh_action_frensh ""
#define battovh_description_frensh ""
#define battunh_text_english "battunh"
#define battunh_action_english ""
#define battunh_description_english ""
#define battunh_text_frensh "battunh"
#define battunh_action_frensh ""
#define battunh_description_frensh ""
#define battlov_text_english "battlov"
#define battlov_action_english ""
#define battlov_description_english ""
#define battlov_text_frensh "battlov"
#define battlov_action_frensh ""
#define battlov_description_frensh ""
#define battcxpld_text_english "battcdpld"
#define battcdpld_action_english ""
#define battcdpld_description_english ""
#define battcdpld_text_frensh "battcdpld"
#define battcdpld_action_frensh ""
#define battcdpld_description_frensh ""
#define batttmout_text_english "batttmout"
#define batttmout_action_english ""
#define batttmout_description_english ""
#define batttmout_text_frensh "batttmout"
#define batttmout_action_frensh ""
#define batttmout_description_frensh ""
#define motorovh_text_english "motorovh"
#define motorovh_action_english ""
#define motorovh_description_english ""
#define motorovh_text_frensh "motorovh"
#define motorovh_action_frensh ""
#define motorovh_description_frensh ""
#define battcontactfai_text_english "battcontactfai"
#define battcontactfai_action_english ""
#define battcontactfai_description_english ""
#define battcontactfai_text_frensh "battcontactfai"
#define battcontactfai_action_frensh ""
#define battcontactfai_description_frensh ""
#define motorthermalshut_text_english "motorthermalshut"
#define motorthermalshut_action_english ""
#define motorthermalshut_description_english ""
#define motorthermalshut_text_frensh "motorthermalshut"
#define motorthermalshut_action_frensh ""
#define motorthermalshut_description_frensh ""
#define motorovc_text_english "motorovc"
#define motorovc_action_english ""
#define motorovc_description_english ""
#define motorovc_text_frensh "motorovc"
#define motorovc_action_frensh ""
#define motorovc_description_frensh ""
#define motorundv_text_english "motorundv"
#define motorundv_action_english ""
#define motorundv_description_english ""
#define motorundv_text_frensh "motorundv"
#define motorundv_action_frensh ""
#define motorundv_description_frensh ""
#define motornotresp_text_english "motornotresp"
#define motornotresp_action_english ""
#define motornotresp_description_english ""
#define motornotresp_text_frensh "motornotresp"
#define motornotresp_action_frensh ""
#define motornotresp_description_frensh ""
#define internalerror_text_english "internalerror"
#define internalerror_action_english ""
#define internalerror_description_english ""
#define internalerror_text_frensh "internalerror"
#define internalerror_action_frensh ""
#define internalerror_description_frensh ""
#define poserror_text_english "poserror"
#define poserror_action_english ""
#define poserror_description_english ""
#define poserror_text_frensh "poserror"
#define poserror_action_frensh ""
#define poserror_description_frensh ""
#define syringeerror_text_english "syringeerror"
#define syringeerror_action_english ""
#define syringeerror_description_english ""
#define syringeerror_text_frensh "syringeerror"
#define syringeerror_action_frensh ""
#define syringeerror_description_frensh ""
#define perfustart_text_english "perfustart"
#define perfustart_text_frensh "perfustart"
#define perfustop_text_english "perfustop"
#define perfustop_text_frensh "perfustop"
#define bolusstop_text_english "bolusstop"
#define bolusstop_text_frensh "bolusstop"
#define bolusstart_text_english "bolusstart"
#define bolusstart_text_frensh "bolusstart"
#define kvostart_text_english "kvostart"
#define kvostart_text_frensh "kvostart"
#define kvostop_text_english "kvostop"
#define kvostop_text_frensh "kvostop"
#define purgestop_text_english "purgestop"
#define purgestop_text_frensh "purgestop"
#define purgestart_text_english "purgestart"
#define purgestart_text_frensh "purgestart"
#define syringenearempty_text_english "syringenearempty"
#define syringenearempty_text_frensh "syringenearempty"
#define syringeempty_text_english "syringeempty"
#define syringeempty_text_frensh "syringeempty"
#define endoftrail_text_english "endoftrail"
#define endoftrail_text_frensh "endoftrail"
#define powersourcechange_text_english "powersourcechange"
#define powersourcechange_text_frensh "powersourcechange"
#define boluscomplete_text_english "boluscomplete"
#define boluscomplete_text_frensh "boluscomplete"
#define kvocomplete_text_english "kvocomplete"
#define kvocomplete_text_frensh "kvocomplete"
#define purgecomplete_text_english "purgecomplete"
#define purgecomplete_text_frensh "purgecomplete"
#define perfusioncomplete_text_english "perfusioncomplete"
#define perfusioncomplete_text_frensh "perfusioncomplete"

#endif
