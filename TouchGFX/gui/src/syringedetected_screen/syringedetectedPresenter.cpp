#include <gui/syringedetected_screen/syringedetectedView.hpp>
#include <gui/syringedetected_screen/syringedetectedPresenter.hpp>

syringedetectedPresenter::syringedetectedPresenter(syringedetectedView& v)
    : view(v)
{

}

void syringedetectedPresenter::activate()
{

}

void syringedetectedPresenter::deactivate()
{

}

void syringedetectedPresenter::AlarmOrEvent(void)
{
    view.AlarmOrEvent();
}
