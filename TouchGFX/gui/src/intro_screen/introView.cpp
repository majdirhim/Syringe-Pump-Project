#include <gui/intro_screen/introView.hpp>

introView::introView()
{

}

void introView::setupScreen()
{
    SetupDisplayMode();
    introViewBase::setupScreen();
}

void introView::tearDownScreen()
{
    introViewBase::tearDownScreen();
}
void introView::systemparaminit()
{
    presenter->purgeactivate(1);
}

void introView::SetupDisplayMode(void)
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

void introView::initsystem(void)
{
	int state = 0;
	while(presenter->init() != 1)
	{
		if(state == 0)
		{
			backend.setVisible(1);
			BackendBlack.setVisible(0);
			BackendChildren.setVisible(0);
			state = 1;
		}
		else if(state == 1)
		{
			backend.setVisible(0);
			BackendBlack.setVisible(1);
			BackendChildren.setVisible(0);
			state = 2;
		}
		else if(state == 2)
		{
			backend.setVisible(0);
			BackendBlack.setVisible(0);
			BackendChildren.setVisible(2);
			state = 0;
		}
		backend.invalidate();
		BackendBlack.invalidate();
		BackendChildren.invalidate();
	}
		static_cast<FrontendApplication*>(Application::getInstance())->gotostartupScreenNoTransition();
}
