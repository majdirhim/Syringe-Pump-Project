#include <gui/lockscreen_screen/LockScreenView.hpp>
#include <gui/lockscreen_screen/LockScreenPresenter.hpp>

LockScreenPresenter::LockScreenPresenter(LockScreenView& v)
    : view(v)
{

}

void LockScreenPresenter::activate()
{

}

void LockScreenPresenter::deactivate()
{

}

void LockScreenPresenter::AlarmOrEvent(void)
{
    view.AlarmOrEvent();
}
