#include <gui/screenkeyboard_screen/ScreenKeyboardView.hpp>
#include <gui/screenkeyboard_screen/ScreenKeyboardPresenter.hpp>

ScreenKeyboardPresenter::ScreenKeyboardPresenter(ScreenKeyboardView& v)
    : view(v)
{

}

void ScreenKeyboardPresenter::activate()
{

}

void ScreenKeyboardPresenter::deactivate()
{

}

void ScreenKeyboardPresenter::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}
