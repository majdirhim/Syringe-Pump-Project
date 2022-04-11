#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>

class MainView : public MainViewBase
{
public:
    MainView();
    virtual ~MainView() {}

    virtual void setupScreen();
    virtual void tearDownScreen();
    void setupScreenElement();
    virtual void handleTickEvent();
    virtual void InitKeyboard(uint8_t value);
    virtual void reactToClick(AbstractDataGraph::GraphClickEvent value);
    virtual void CloseAlarmPopUp();
    virtual void MuteSound();
    virtual void batteryUpdated(void);
    virtual void currentTimeUpdated(void);
    virtual void syringeUpdated(void);
    virtual void motorStatusUpdated(void);
    virtual void ChangeMotorMode(uint8_t value);
    uint8_t checkBeforeInfusion();
    uint8_t checkBeforeInfusionStation();
    uint8_t checkBeforeStop();
    uint8_t checkBeforePurge();
    uint8_t checkBeforePause();
    uint8_t checkBeforeBolus();
    uint8_t checkSyringe();
    uint8_t checkDrug();
    uint8_t checkVolume();

    
protected:
    uint8_t ColorState = 0, CurrentMode = 0, Counter = 0, RequestedMode = 0, DrugCheckPass = 0;
    uint16_t /*temp*/ PressureVector[4] = {120, 450, 680, 930}, low = 400, medium = 600, high = 800;
    uint8_t /*temp*/ i = 0;
};

#endif // MAINVIEW_HPP
