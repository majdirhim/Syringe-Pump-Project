#include <gui/screenkeyboard_screen/ScreenKeyboardView.hpp>


extern Unicode::UnicodeChar keyboardBuffer[2][18]; // add
extern uint8_t keyboardSelection; // add


ScreenKeyboardView::ScreenKeyboardView()
{
    keyboard.setPosition(80, 16, 320, 240); // add
    add(keyboard); // add
}

void ScreenKeyboardView::setupScreen()
{
	SetupDisplayMode();
    ScreenKeyboardViewBase::setupScreen();
}

void ScreenKeyboardView::tearDownScreen()
{
    ScreenKeyboardViewBase::tearDownScreen();
}

void ScreenKeyboardView::getBuffer() // add
{
    Unicode::UnicodeChar* buff = keyboard.getBuffer();
    Unicode::strncpy(keyboardBuffer[keyboardSelection], buff, Unicode::strlen(buff) + 1);
}

void ScreenKeyboardView::SetupDisplayMode(void)
{
	if (presenter->GetdisplayMode() == 1)
	{
		backend.setVisible(0);
		BackendBlack.setVisible(1);
		BackendChildren.setVisible(0);
	}
	else if (presenter->GetdisplayMode() == 2)
	{
		backend.setVisible(0);
		BackendBlack.setVisible(0);
		BackendChildren.setVisible(2);
	}
	else
	{
		backend.setVisible(1);
		BackendBlack.setVisible(0);
		BackendChildren.setVisible(0);
	}
}

void ScreenKeyboardView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}
