#include <gui/containers/popup_Time_Date.hpp>

popup_Time_Date::popup_Time_Date()
{

}

void popup_Time_Date::initialize()
{
    popup_Time_DateBase::initialize();
}


void popup_Time_Date::buttonhourupclicked()
{
    hour = (hour + 1) % 24; // Keep new value in range 0..23
    Unicode::snprintf(textaearHourBuffer, TEXTAEARHOUR_SIZE, "%02d", hour);
    textaearHour.invalidate();
}

void popup_Time_Date::buttonhourdownclicked()
{
    hour = (hour + 24 - 1) % 24; // Keep new value in range 0..23
    Unicode::snprintf(textaearHourBuffer, TEXTAEARHOUR_SIZE, "%02d", hour);
    textaearHour.invalidate();
}

void popup_Time_Date::buttonminuteupclicked()
{
    minute = (minute + 1) % 60; // Keep new value in range 0..59
    Unicode::snprintf(textAreaminuteBuffer, TEXTAREAMINUTE_SIZE, "%02d", minute);
    textAreaminute.invalidate();
}

void popup_Time_Date::buttonminutedownclicked()
{
    minute = (minute + 60 - 1) % 60; // Keep new value in range 0..59
    Unicode::snprintf(textAreaminuteBuffer, TEXTAREAMINUTE_SIZE, "%02d", minute);
    textAreaminute.invalidate();
}


void popup_Time_Date::saveclock()
{
  //  Presenter->b :;

}