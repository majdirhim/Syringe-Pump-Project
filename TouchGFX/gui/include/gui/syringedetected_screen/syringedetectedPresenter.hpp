#ifndef SYRINGEDETECTEDPRESENTER_HPP
#define SYRINGEDETECTEDPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class syringedetectedView;

class syringedetectedPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    syringedetectedPresenter(syringedetectedView& v);

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
    ps_float getVolume(void)
    {
        return model->getvolume();
    }
    ps_float getVolumeleft(void)
    {
        return model->getvolumeleft();
    }
    uint16_t GetSyringeDiameter(void)
    {
        return model->GetSyringeDiameter();
    }
    virtual void AlarmOrEvent(void);
    virtual ~syringedetectedPresenter() {};

private:
    syringedetectedPresenter();

    syringedetectedView& view;
};

#endif // SYRINGEDETECTEDPRESENTER_HPP
