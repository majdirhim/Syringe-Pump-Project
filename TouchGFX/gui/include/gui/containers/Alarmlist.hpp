#ifndef ALARMLIST_HPP
#define ALARMLIST_HPP

#include <gui_generated/containers/AlarmlistBase.hpp>

class Alarmlist : public AlarmlistBase
{
public:
    Alarmlist();
    virtual ~Alarmlist() {}

    void configAlarmSource(const char*);
    void configAlarmState(uint8_t state);
    void setuptile();
    void setuplist(const char*, uint8_t);
    void setuptitle();
    void setuptime(time_ps time);
    void setuplog(const char* text, time_ps time);
    void setupcolor(colortype color);


    virtual void initialize();
protected:
};

#endif // ALARMLIST_HPP
