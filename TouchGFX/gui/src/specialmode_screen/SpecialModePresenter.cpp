#include <gui/specialmode_screen/SpecialModeView.hpp>
#include <gui/specialmode_screen/SpecialModePresenter.hpp>

SpecialModePresenter::SpecialModePresenter(SpecialModeView& v)
    : view(v)
{

}

void SpecialModePresenter::activate()
{

}

void SpecialModePresenter::deactivate()
{

}

void SpecialModePresenter::AlarmOrEvent(void)
 {
        view.AlarmOrEvent();
}

