#ifndef MAINSCREEN_WITHSTARTVIEW_HPP
#define MAINSCREEN_WITHSTARTVIEW_HPP

#include <gui_generated/mainscreen_withstart_screen/mainScreen_WithSTARTViewBase.hpp>
#include <gui/mainscreen_withstart_screen/mainScreen_WithSTARTPresenter.hpp>



class mainScreen_WithSTARTView : public mainScreen_WithSTARTViewBase
{
public:
    mainScreen_WithSTARTView();
    virtual ~mainScreen_WithSTARTView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();

    virtual void gotoconfigue();

    virtual void backtomain1();


    virtual void startperfusion();
    virtual void changemode();
    virtual void stopperfusion();
    void pressuregauge();

    void gotoalarm();

    virtual void Namedrug(uint8_t drug1);

    virtual void ratevar();

    virtual void ratevarvolume();

    virtual void KVOSet();

    virtual void bolusSet();

    virtual void setVTBI();

    virtual void MuteF();

    char* getpatientname();

    virtual void outofpopup();

    virtual void purgeClicked();

    virtual void Closepurgepopup();

    virtual void writeinmain();

    void updatesyringestatus(void);

    void SetupDisplayMode(void);

    void displayalarmtext(uint8_t);

    virtual void outofeventpop();
    void gotoeveentpopup(void);
    void displayeventtext(void);

protected:
    bool status;
    time_ps currenttime;
    uint8_t drug;
    static char text[20];
    Unicode::UnicodeChar buffertext[20];
    uint16_t K;
    uint16_t chiffre;
    int16_t pressureLow;
    int16_t pressureMedium;
    int16_t pressureHigh;
    ps_float KVO;
    ps_float bolus;
    ps_float rate;
    ps_float volume;
    ps_float volumeVTBI;
    time_ps perfusiontime;
    battery_info battery;
    char* patientnamevar;
    alarm_info alarms;
    bool alarmborder;
    time_ps timeleft;
    ps_float volumeleft;
    int mode;
};

#endif // MAINSCREEN_WITHSTARTVIEW_HPP
