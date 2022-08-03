#include <gui/specialmode_screen/SpecialModeView.hpp>

SpecialModeView::SpecialModeView()
{

}

void SpecialModeView::setupScreen()
{
    SetupDisplayMode();
    SpecialModeViewBase::setupScreen();
}

void SpecialModeView::tearDownScreen()
{
    SpecialModeViewBase::tearDownScreen();
}

void SpecialModeView::SetupDisplayMode(void)
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

void SpecialModeView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}

