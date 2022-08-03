#include <gui/containers/Alarmlist.hpp>

Alarmlist::Alarmlist()
{

}

void Alarmlist::initialize()
{
    AlarmlistBase::initialize();
}

void Alarmlist::configAlarmSource(const char * text)
{
    Unicode::snprintf(alarmsourceBuffer, ALARMSOURCE_SIZE, text);
}

void Alarmlist::configAlarmState(uint8_t state)
{
    switch (state)
    {
    case 1 :
        Unicode::snprintf(CurrentstateBuffer, CURRENTSTATE_SIZE, "Active");
        Currentstate.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
        break;
    case 0 :
    default :
        Unicode::snprintf(CurrentstateBuffer, CURRENTSTATE_SIZE, "Inactive");
        Currentstate.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
        break;
    }
}

void Alarmlist::setuplist(const char* text, uint8_t state)
{
    configAlarmSource(text);
    configAlarmState(state);
    invalidate();
}

void Alarmlist::setuptile()
{
    Unicode::snprintf(alarmsourceBuffer, ALARMSOURCE_SIZE, "Alarm Sources");
    Unicode::snprintf(CurrentstateBuffer, CURRENTSTATE_SIZE, "State");
    invalidate();
}

void Alarmlist::setuptitle()
{
    Unicode::snprintf(alarmsourceBuffer, ALARMSOURCE_SIZE, "Log");
    Unicode::snprintf(CurrentstateBuffer, CURRENTSTATE_SIZE, "TimeStamp");
    invalidate();
}

void Alarmlist::setuptime(time_ps time)
{
    Unicode::snprintf(CurrentstateBuffer, CURRENTSTATE_SIZE, "%dh:%dmin", time.hours, time.minutes);
    invalidate();
}

void Alarmlist::setuplog(const char* text, time_ps time)
{
    configAlarmSource(text);
    setuptime(time);
    invalidate();
}

void Alarmlist::setupcolor(colortype color)
{
	alarmsource.setColor(color);
	alarmsource.invalidate();
}


