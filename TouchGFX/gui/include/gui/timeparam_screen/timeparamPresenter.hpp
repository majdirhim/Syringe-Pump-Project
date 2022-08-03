#ifndef TIMEPARAMPRESENTER_HPP
#define TIMEPARAMPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class timeparamView;

class timeparamPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    timeparamPresenter(timeparamView& v);

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

    void savePerfusiontime(time_ps H)
    {
        model->savePerfusiontime(H);
    }

    virtual ~timeparamPresenter() {};
    uint8_t GetdisplayMode(void)
    {
        return model->GetDisplayMode();
    }
    virtual void AlarmOrEvent(void);

private:
    timeparamPresenter();

    timeparamView& view;
};

#endif // TIMEPARAMPRESENTER_HPP
