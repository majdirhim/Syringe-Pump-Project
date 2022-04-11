#ifndef ACTIVEALARMSPRESENTER_HPP
#define ACTIVEALARMSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ActiveAlarmsView;

class ActiveAlarmsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ActiveAlarmsPresenter(ActiveAlarmsView& v);

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

    uint8_t getDisplayMode(void);

    virtual void AlarmOrEvent(void);

    uint8_t getActiveEvents(uint8_t);
    const char* getEventTitle(uint8_t);

    virtual ~ActiveAlarmsPresenter() {};

private:
    ActiveAlarmsPresenter();

    ActiveAlarmsView& view;
};

#endif // ACTIVEALARMSPRESENTER_HPP
