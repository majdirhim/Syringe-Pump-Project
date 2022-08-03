#include <gui/maintenance_screen/MaintenanceView.hpp>

MaintenanceView::MaintenanceView()
{

}

void MaintenanceView::setupScreen()
{
	SetupDisplayMode();
    MaintenanceViewBase::setupScreen();
}

void MaintenanceView::tearDownScreen()
{
    MaintenanceViewBase::tearDownScreen();
}

void MaintenanceView::SetupDisplayMode(void)
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

void MaintenanceView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}
