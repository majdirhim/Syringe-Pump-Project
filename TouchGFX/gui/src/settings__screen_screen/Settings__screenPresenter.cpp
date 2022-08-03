#include <gui/settings__screen_screen/Settings__screenView.hpp>
#include <gui/settings__screen_screen/Settings__screenPresenter.hpp>

Settings__screenPresenter::Settings__screenPresenter(Settings__screenView& v)
    : view(v)
{

}

void Settings__screenPresenter::activate()
{

}

void Settings__screenPresenter::deactivate()
{

}

void Settings__screenPresenter::AlarmOrEvent(void)
{
    view.AlarmOrEvent();
}
