#include <gui/startup_screen/startupView.hpp>
#include <gui/startup_screen/startupPresenter.hpp>

startupPresenter::startupPresenter(startupView& v)
    : view(v)
{

}

void startupPresenter::activate()
{

}

void startupPresenter::deactivate()
{

}

void startupPresenter::AlarmOrEvent(void)
 {
        view.AlarmOrEvent();
}

