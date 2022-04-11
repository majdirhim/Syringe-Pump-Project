#include <gui/home_screen/HomeView.hpp>
#include "../../../Core/Inc/SW_common.h"

HomeView::HomeView()
{

}

void HomeView::setupScreen()
{
	setupDisplayMode();
    HomeViewBase::setupScreen();
}

void HomeView::tearDownScreen()
{
    HomeViewBase::tearDownScreen();
}

void HomeView::setupDisplayMode(void)
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

