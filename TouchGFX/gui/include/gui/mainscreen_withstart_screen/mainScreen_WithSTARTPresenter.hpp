#ifndef MAINSCREEN_WITHSTARTPRESENTER_HPP
#define MAINSCREEN_WITHSTARTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class mainScreen_WithSTARTView;

class mainScreen_WithSTARTPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    mainScreen_WithSTARTPresenter(mainScreen_WithSTARTView& v);

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

    virtual ~mainScreen_WithSTARTPresenter() {};

	void saveCurrentTime(time_ps hour)
    {
        model->SaveCurrentTime(hour);
    }
	time_ps getCurrentTime()
    {
        return model->getcurrenttime();
    }

    void saveinputdestinsation(int16_t var)
    {
        model->saveinputdestinsation(var);
    }
    int16_t getinputdestinsation()
    {
        return model->getinputdestinsation();
    }

    bool getstatus()
    {
        return model->GetSyringeState();
    }

    void savedrug(int8_t drug)
    {
        model->savedrug(drug);
    }
    int8_t getdrug()
    {
        return model->getdrug();
    }

    void saverate(ps_float rate)
    {
        model->saverate(rate);
    }
    ps_float getrate()
    {
        return model->getrate();
    }

    void savevolume(ps_float volume)
    {
        model->savevolume(volume);
    }
    ps_float getvolume()
    {
        return model->getvolume();
    }

    int16_t getpressureLow()
    {
        return model->getoclusionLow();
    }
    int16_t getpressureMedium()
    {
        return model->getoclusionMedium();
    }
    int16_t getpressureHigh()
    {
        return model->getoclusionHigh();
    }
    int16_t getcurrentpressure()
    {
        return model->getcurrentpressure();
    }

    ps_float getinfusionvolume()
    {
        return model->getinfusionvolume();
    }

    ps_float getKVO()
    {
        return model->getKVO();
    }
    void saveKVO(ps_float bolus)
    {
        model->saveKVO(bolus);
    }

    ps_float getbolus()
    {
        return model->getbolus();
    }
    void savebolus(ps_float bolus)
    {
        model->savebolus(bolus);
    }

    int getPerfusionmode(void)
    {
        return model->getPerfusionmode();
    }
    void savePerfusionmode(int var)
    {
        model->savePerfusionmode(var);
    }

    time_ps getPerfusiontime()
    {
        return model->getPerfusiontime();
    }

    battery_info getbatteryinfo()
    {
        return model->getbatteryinfo();
    }

    char * getpatientname(void)
    {
        return model->getpatientname();
    }

    ps_float getvolumeleft()
    {
        return model->getvolumeleft();
    }

    time_ps gettimeleft()
    {
        return model->gettimeleft();
    }

    bool getalarmpending(void)
    {
        return model->getalarmpending();
    }
    void savealarmpending(bool var)
    {
        return model->savealarmpending(var);
    }

    alarm_info getalarminfo(void)
    {
        return model->getalarminfo();
    }

    uint8_t purgeget()
    {
        return model->purgeget();
    }

    void savepurge(uint8_t var)
    {
        model->purgeactivate(var);
    }

    uint8_t GetdisplayMode(void)
    {
        return model->GetDisplayMode();
    }

    uint8_t GetLock(void)
    {
        return model->GetLock();
    }

    void SaveLock(uint8_t state)
    {
        return model->SaveLock(state);
    }

    void SaveMute(uint8_t state)
    {
        return model->SaveMute(state);
    }

    uint8_t GetMute(void)
    {
        return model->GetMute();
    }

    uint8_t geteventpending(void)
    {
        return model->Geteventpending();
    }
    void saveeventpending(uint8_t var)
    {
        return model->Saveeventpending(var);
    }

    uint8_t geteventinfo(void)
    {
        return model->Getevent();
    }


private:
    mainScreen_WithSTARTPresenter();

    mainScreen_WithSTARTView& view;
};

#endif // MAINSCREEN_WITHSTARTPRESENTER_HPP
