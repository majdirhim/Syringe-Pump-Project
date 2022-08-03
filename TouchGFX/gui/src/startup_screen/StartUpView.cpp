#include <gui/startup_screen/startupView.hpp>

startupView::startupView()
{

}

void startupView::setupScreen()
{
    SetupDisplayMode();
    startupViewBase::setupScreen();
}

void startupView::tearDownScreen()
{
    startupViewBase::tearDownScreen();
}

void startupView::SetupDisplayMode(void)
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

void startupView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}
