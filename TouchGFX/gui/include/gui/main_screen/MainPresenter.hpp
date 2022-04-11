#ifndef MAINPRESENTER_HPP
#define MAINPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MainView;

class MainPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MainPresenter(MainView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~MainPresenter() {};

    virtual void batteryUpdated(void);

    virtual void currentTimeUpdated(void);

    virtual void syringeUpdated(void);

    virtual void motorStatusUpdated(void);

    /*====================================== Perfusion Paramaters ========================================*/
    SW_float getFlowRate(void);
    SW_float getTotalVolume(void);
    SW_float getInfusionVolume(void);
    SW_float getKVORate(void);
    SW_float getBolusRate(void);
    uint8_t getMode(void);
    SW_time getInfusionTIme();
    void saveMode(uint8_t);
    SW_float getVolumeLeft();
    SW_time getTimeLeft();
    Infusion_paramT getInfusionParameters();
    void saveTotalVolume(SW_float);
    
    /*========================================== Syringe =========================================*/
    uint8_t getSyringeState();
    SyringeT getSyringe();

    /*========================================== patient =========================================*/
    char * getPatientName(void);

    /*========================================== time =========================================*/
    SW_time getCurrentTime(void);

    /*========================================== Battery =========================================*/
    BatteryT getBattery();

    /*========================================== Current Pressure =========================================*/
    float getCurrentPressure();

    /*========================================== Init Parameters =========================================*/
    uint8_t getDisplayMode(void);

    /*========================================== Drug =========================================*/
    DrugT getDrug();

    /*========================================== MISC =========================================*/
    void saveKeyboardUser(uint8_t);

    /*========================================== Event =========================================*/
    const char* getEventTitle(uint8_t);
    EventTypeT getLatestEvent();
    uint8_t getPendingEventStatus();
    void savePendingEventStatus(void);
    void saveMuteStatus(void);

private:
    MainPresenter();

    MainView& view;
};

#endif // MAINPRESENTER_HPP
