#ifndef ACTIVEALARMSVIEW_HPP
#define ACTIVEALARMSVIEW_HPP

#include <gui_generated/activealarms_screen/ActiveAlarmsViewBase.hpp>
#include <gui/activealarms_screen/ActiveAlarmsPresenter.hpp>
#include <gui/containers/ActiveAlarms.hpp>

class ActiveAlarmsView : public ActiveAlarmsViewBase
{
public:
    ActiveAlarmsView();
    virtual ~ActiveAlarmsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void AlarmOrEvent();
    void setupDisplayMode();

    virtual void handleTickEvent();

protected:
    static const uint8_t numberOfListElements = NUMBER_OF_ALARMS + NUMBER_OF_ALERTS + 1;
    ActiveAlarms ListElements[numberOfListElements];
    uint8_t AlarmState;
    touchgfx::Unicode::UnicodeChar Description[50];
    uint8_t AlarmStates[NUMBER_OF_ALARMS + NUMBER_OF_ALERTS + 1] = { 0 };
    uint8_t Deleter[50] = { 0 };

};

#endif // ACTIVEALARMSVIEW_HPP
