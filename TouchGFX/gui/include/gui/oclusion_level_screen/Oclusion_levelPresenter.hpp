#ifndef OCLUSION_LEVELPRESENTER_HPP
#define OCLUSION_LEVELPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Oclusion_levelView;

class Oclusion_levelPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Oclusion_levelPresenter(Oclusion_levelView& v);

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

    uint8_t GetdisplayMode(void)
    {
        return model->GetDisplayMode();
    }
    virtual void AlarmOrEvent(void);
    void saveinputdestination(int16_t var)
    {
        model->saveinputdestinsation(var);
    }

    int16_t getoclusionLow()
    {
        return model->getoclusionLow();
    }

    int16_t getoclusionMedium()
    {
        return model->getoclusionMedium();
    }

    int16_t getoclusionHigh()
    {
        return model->getoclusionHigh();
    }

    virtual ~Oclusion_levelPresenter() {};


private:
    Oclusion_levelPresenter();

    Oclusion_levelView& view;
};

#endif // OCLUSION_LEVELPRESENTER_HPP
