#include <gui/keyboard_screen/KeyboardView.hpp>
#include <gui/keyboard_screen/KeyboardPresenter.hpp>

KeyboardPresenter::KeyboardPresenter(KeyboardView& v)
    : view(v)
{

}

void KeyboardPresenter::activate()
{

}

void KeyboardPresenter::deactivate()
{

}

uint8_t KeyboardPresenter::getDisplayMode()
{
	return model->getDisplayMode();
}

void KeyboardPresenter::AlarmOrEvent(void)
{
        view.AlarmOrEvent();
}
