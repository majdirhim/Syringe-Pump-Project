#ifndef SETTINGS_TIME_DATEVIEW_HPP
#define SETTINGS_TIME_DATEVIEW_HPP

#include <gui_generated/settings_time_date_screen/Settings_Time_DateViewBase.hpp>
#include <gui/settings_time_date_screen/Settings_Time_DatePresenter.hpp>

class Settings_Time_DateView : public Settings_Time_DateViewBase
{
public:
    Settings_Time_DateView();
    virtual ~Settings_Time_DateView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void buttonhourupclicked();
    virtual void buttonhourdownclicked();
    virtual void buttonminuteupclicked();
    virtual void buttonminutedownclicked();
    void SetupDisplayMode(void);
    virtual void AlarmOrEvent(void);
    virtual void saveclock()
    {
        // presenter->savecurrentTime(timeinput);
    }
protected:
    time_ps timeinput;
};

#endif // SETTINGS_TIME_DATEVIEW_HPP

