#ifndef ACTIVEALARMS_HPP
#define ACTIVEALARMS_HPP

#include <gui_generated/containers/ActiveAlarmsBase.hpp>

class ActiveAlarms : public ActiveAlarmsBase
{
public:
    ActiveAlarms();
    virtual ~ActiveAlarms() {}
    void setUpTitle();
    void setUpAlarm(uint8_t, touchgfx::Unicode::UnicodeChar*, uint8_t);
    void setUpColor(colortype Color);
    virtual void initialize();
protected:
};

#endif // ACTIVEALARMS_HPP
