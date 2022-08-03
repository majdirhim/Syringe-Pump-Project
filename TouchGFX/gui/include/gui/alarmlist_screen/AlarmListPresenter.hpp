#ifndef ALARMLISTPRESENTER_HPP
#define ALARMLISTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class AlarmListView;

class AlarmListPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    AlarmListPresenter(AlarmListView& v);

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
    uint8_t getalarmvector(uint8_t);
    virtual ~AlarmListPresenter() {};

private:
    AlarmListPresenter();

    AlarmListView& view;
};

#endif // ALARMLISTPRESENTER_HPP
