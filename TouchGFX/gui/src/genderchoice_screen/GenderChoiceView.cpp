#include <gui/genderchoice_screen/GenderChoiceView.hpp>

GenderChoiceView::GenderChoiceView()
{

}

void GenderChoiceView::setupScreen()
{
	setupDisplayMode();
    GenderChoiceViewBase::setupScreen();
}

void GenderChoiceView::tearDownScreen()
{
    GenderChoiceViewBase::tearDownScreen();
}

void GenderChoiceView::setupDisplayMode(void)
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

void GenderChoiceView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotoMainScreenNoTransition();
}

void GenderChoiceView::ChooseGender(uint8_t value)
{
	presenter->savePatientGender(value);
	GenderChoiceViewBase::ChooseGender(value);
}
