#include <gui/druglibrary_screen/DrugLibraryView.hpp>

DrugLibraryView::DrugLibraryView()
{

}

void DrugLibraryView::setupScreen()
{
	SetupDisplayMode();
    DrugLibraryViewBase::setupScreen();
}

void DrugLibraryView::tearDownScreen()
{
    DrugLibraryViewBase::tearDownScreen();
}

void DrugLibraryView::SetupDisplayMode(void)
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

void DrugLibraryView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}
