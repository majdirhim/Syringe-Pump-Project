#ifndef SETTINGS_TIME_DATEPRESENTER_HPP
#define SETTINGS_TIME_DATEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Settings_Time_DateView;

class Settings_Time_DatePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Settings_Time_DatePresenter(Settings_Time_DateView& v);

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

    virtual ~Settings_Time_DatePresenter() {};
    
    void SaveCurrentTime(time_ps hour)
    {
        model->SaveCurrentTime(hour);
    }
    time_ps GetCurrentTime()
    {
        return model->getcurrenttime();
    }

   private:
    Settings_Time_DatePresenter();

    Settings_Time_DateView& view;
};

#endif // SETTINGS_TIME_DATEPRESENTER_HPP
