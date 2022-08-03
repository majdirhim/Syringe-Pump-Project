#include <gui/screenselectdrug_screen/ScreenselectdrugView.hpp>
#include <gui/screenselectdrug_screen/ScreenselectdrugPresenter.hpp>

ScreenselectdrugPresenter::ScreenselectdrugPresenter(ScreenselectdrugView& v)
    : view(v)
{

}

void ScreenselectdrugPresenter::activate()
{

}

void ScreenselectdrugPresenter::deactivate()
{

}

void ScreenselectdrugPresenter::AlarmOrEvent(void)
{
    view.AlarmOrEvent();
}