#include <gui/manual_screen/ManualView.hpp>

ManualView::ManualView()
{

}

void ManualView::setupScreen()
{
	SetupDisplayMode();
    ManualViewBase::setupScreen();
}

void ManualView::tearDownScreen()
{
    ManualViewBase::tearDownScreen();
}

void ManualView::SetupDisplayMode(void)
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

void ManualView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}
