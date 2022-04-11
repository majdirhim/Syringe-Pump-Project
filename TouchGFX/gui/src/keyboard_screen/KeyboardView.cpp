#include <gui/keyboard_screen/KeyboardView.hpp>

extern Unicode::UnicodeChar keyboardBuffer[2][18];
extern uint8_t KeyboardSource;

KeyboardView::KeyboardView()
{
   keyboard.setPosition(80, 0, 320, 240);
   add(keyboard);
}

void KeyboardView::setupScreen()
{
	setupDisplayMode();
    KeyboardViewBase::setupScreen();
}

void KeyboardView::tearDownScreen()
{
    KeyboardViewBase::tearDownScreen();
}

void KeyboardView::getBuffer()
{
    Unicode::UnicodeChar* buff = keyboard.getBuffer();
    if (!KeyboardSource)
    {
        Unicode::strncpy(keyboardBuffer[0], buff, Unicode::strlen(buff) + 1);
        static_cast<FrontendApplication*>(Application::getInstance())->gotoNewPatientScreenWipeTransitionNorth();
    }
    else
    {
        Unicode::strncpy(keyboardBuffer[1], buff, Unicode::strlen(buff) + 1);
        static_cast<FrontendApplication*>(Application::getInstance())->gotoPatientDatabaseScreenWipeTransitionNorth();
    }
}

void KeyboardView::setupDisplayMode(void)
{
    if (presenter->getDisplayMode() == DARK)
    {
    	DefaultBackground.setVisible(false);
    	DarkBackground.setVisible(true);
    	ChildrenBackground.setVisible(false);
    }
    else if (presenter->getDisplayMode() == CHILDREN)
    {
    	DefaultBackground.setVisible(false);
    	DarkBackground.setVisible(false);
    	ChildrenBackground.setVisible(true);
    }
    else
    {
    	DefaultBackground.setVisible(true);
    	DarkBackground.setVisible(false);
    	ChildrenBackground.setVisible(false);
    }
}

void KeyboardView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotoMainScreenNoTransition();
}
