#ifndef SETTINGS__SCREENVIEW_HPP
#define SETTINGS__SCREENVIEW_HPP

#include <gui_generated/settings__screen_screen/Settings__screenViewBase.hpp>
#include <gui/settings__screen_screen/Settings__screenPresenter.hpp>

class Settings__screenView : public Settings__screenViewBase
{
public:
    Settings__screenView();
    virtual ~Settings__screenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void Btnon_off(bool onoff);
    virtual void state_test();
    virtual void goto_autodiagnosic();
    virtual void handleTickEvent();
    virtual void afterTransition();
    virtual void gotosound();
    virtual void soundtomain();
    virtual void goto_Displaymode();
    virtual void set_setting();
    virtual void goto_Language();
    virtual void displaychildren();
    virtual void displaydark();
    virtual void displaydefault();
    virtual void AlarmOrEvent(void);
    virtual void gotomaintenance();
    virtual void gototimeanddate();
    virtual void gotohistory();
    void SetupDisplayMode(void);

protected:
    static const uint16_t DURATION = 300;
    uint16_t Counter;
    int tickCount;
    time_ps timesetting;
    uint8_t Displaymode;
};

#endif // SETTINGS__SCREENVIEW_HPP
