#ifndef LOGSCREENPRESENTER_HPP
#define LOGSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class LogScreenView;

class LogScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    LogScreenPresenter(LogScreenView& v);

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
    logT getlogvector(uint8_t index);
    void RequeststorelogdData(uint8_t direction);
    uint8_t LogDataRequestAnswer(void);
    virtual ~LogScreenPresenter() {};

private:
    LogScreenPresenter();

    LogScreenView& view;
};

#endif // LOGSCREENPRESENTER_HPP
