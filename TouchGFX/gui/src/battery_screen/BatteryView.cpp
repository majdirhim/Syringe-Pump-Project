#include <gui/battery_screen/BatteryView.hpp>

BatteryView::BatteryView()
{

}

void BatteryView::setupScreen()
{
	SetupDisplayMode();
    BatteryViewBase::setupScreen();
}

void BatteryView::tearDownScreen()
{
    BatteryViewBase::tearDownScreen();
}

void BatteryView::SetupDisplayMode(void)
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

void BatteryView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}
