#ifndef KEYBOARDNBPRESENTER_HPP
#define KEYBOARDNBPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class KeyboardNBView;

class KeyboardNBPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    KeyboardNBPresenter(KeyboardNBView& v);

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

    virtual ~KeyboardNBPresenter() {};
    uint8_t GetdisplayMode(void)
    {
        return model->GetDisplayMode();
    }
    virtual void AlarmOrEvent(void);
    void saveinputdestinsation(int16_t var)
    {
        model->saveinputdestinsation(var);
    }
    int16_t getinputdestinsation()
    {
        return model->getinputdestinsation();
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

    void saveoclusionHigh(int16_t pressure)
    {
        model->saveoclusionHigh(pressure);
    }
    int16_t getoclusionHigh()
    {
        return model->getoclusionHigh();
    }
    void saveoclusionMedium(int16_t pressure)
    {
        model->saveoclusionMedium(pressure);
    }
    int16_t getoclusionMedium()
    {
        return model->getoclusionMedium();
    }
    void saveoclusionLow(int16_t pressure)
    {
        model->saveoclusionLow(pressure);
    }
    int16_t getoclusionLow()
    {
        return model->getoclusionLow();
    }

    void saveKVO(ps_float kvo)
    {
        model->saveKVO(kvo);
    }

    void savebolus(ps_float bolus)
    {
        model->savebolus(bolus);
    }

    void saveposition(uint32_t bolus)
    {
        model->savePosition(bolus);
    }

    void savediameter(uint16_t bolus)
    {
        model->saveDiameter(bolus);
    }

    void savedinfusionvolume(ps_float volume)
    {
        model->saveinfusionvolume(volume);
    }

private:
    KeyboardNBPresenter();

    KeyboardNBView& view;
};

#endif // KEYBOARDNBPRESENTER_HPP
