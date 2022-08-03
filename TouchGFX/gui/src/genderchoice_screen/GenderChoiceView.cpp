#include <gui/genderchoice_screen/genderchoiceView.hpp>

genderchoiceView::genderchoiceView()
{

}

void genderchoiceView::setupScreen()
{
	SetupDisplayMode();
    genderchoiceViewBase::setupScreen();
}

void genderchoiceView::tearDownScreen()
{
    genderchoiceViewBase::tearDownScreen();
}

void genderchoiceView::gendersave(int8_t value)
{
    presenter->savegender(value);
}

void genderchoiceView::SetupDisplayMode(void)
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

void genderchoiceView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}
