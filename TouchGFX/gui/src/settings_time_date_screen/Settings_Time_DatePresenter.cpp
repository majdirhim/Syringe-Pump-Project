#include <gui/settings_time_date_screen/Settings_Time_DateView.hpp>
#include <gui/settings_time_date_screen/Settings_Time_DatePresenter.hpp>

Settings_Time_DatePresenter::Settings_Time_DatePresenter(Settings_Time_DateView& v)
    : view(v)
{

}

void Settings_Time_DatePresenter::activate()
{

}

void Settings_Time_DatePresenter::deactivate()
{

}

void Settings_Time_DatePresenter::AlarmOrEvent(void)
{
    view.AlarmOrEvent();
}
