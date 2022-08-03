#include <gui/timeparam_screen/timeparamView.hpp>
#include <gui/timeparam_screen/timeparamPresenter.hpp>

timeparamPresenter::timeparamPresenter(timeparamView& v)
    : view(v)
{

}

void timeparamPresenter::activate()
{

}

void timeparamPresenter::deactivate()
{

}

void timeparamPresenter::AlarmOrEvent(void)
{
    view.AlarmOrEvent();
}
