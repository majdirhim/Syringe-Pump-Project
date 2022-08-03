#include <gui/keyboardnb_screen/KeyboardNBView.hpp>
#include <gui/keyboardnb_screen/KeyboardNBPresenter.hpp>

KeyboardNBPresenter::KeyboardNBPresenter(KeyboardNBView& v)
    : view(v)
{

}

void KeyboardNBPresenter::activate()
{

}

void KeyboardNBPresenter::deactivate()
{

}

void KeyboardNBPresenter::AlarmOrEvent(void)
{
    view.AlarmOrEvent();
}
