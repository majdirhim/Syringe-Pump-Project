#ifndef KEYBOARDNBPRESENTER_HPP
#define KEYBOARDNBPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class KeyboardNbView;

class KeyboardNbPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    KeyboardNbPresenter(KeyboardNbView& v);

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

    virtual ~KeyboardNbPresenter() {};

    virtual void AlarmOrEvent(void);

    uint8_t getDisplayMode(void);

    uint8_t getKeyboardUser(void);

    void savePatientWeight(uint16_t);
    void savePatientHeight(uint8_t);
    void savePatientAge(uint8_t);

    void saveBolusRate(SW_float);
    void saveKVORate(SW_float);
    void saveInfusionVolume(SW_float);
    void saveTotalVolume(SW_float);
    void saveFlowaRate(SW_float);

    void savePressureThresholdLow(uint16_t);
    void savePressureThresholdMedium(uint16_t);
    void savePressureThresholdHigh(uint16_t);

private:
    KeyboardNbPresenter();

    KeyboardNbView& view;
};

#endif // KEYBOARDNBPRESENTER_HPP
