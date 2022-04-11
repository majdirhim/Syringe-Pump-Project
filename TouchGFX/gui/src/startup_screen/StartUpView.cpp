#include <gui/startup_screen/StartUpView.hpp>
#include "../../../Core/Inc/SW_common.h"

StartUpView::StartUpView()
{

}

void StartUpView::setupScreen()
{
	setupDisplayMode();
    StartUpViewBase::setupScreen();
}

void StartUpView::tearDownScreen()
{
    StartUpViewBase::tearDownScreen();
}

void StartUpView::setupDisplayMode(void)
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

void StartUpView::handleTickEvent(void)
{
    static int i = 0, state = 4;

    switch(state)
    {
        case 0:
        {
            i++;
            LoadingCercle.setArc(0, i);
            LoadingCercle.invalidate();
            if (i == 360)
            {
                state = 1;
            }
            break;
        }
        case 1:
        {
            i--;
            LoadingCercle.setArc(0, i);
            LoadingCercle.invalidate();
            if (i == 0)
            {
                state = 4;
            }
            break;
        }
        case 4:
        {
            i++;
            LoadingCercle.setArc(0, i);
            LoadingCercle.invalidate();
            if (i == 110)
            {
                state = 5;
            }
            break;
        }
        case 5:
        {
            LoadingCercle.setArc(0, 360);
            LoadingCercle.invalidate();
            state = 8;
            checkInitStatus();
            break;
        }
    }
}

void StartUpView::checkInitStatus(void)
{

    LoadingCercle.setVisible(false);
    textArea1.setVisible(false);
    LoadingCercle.invalidate();
    textArea1.invalidate();
	if(presenter->getInitStatus() == (uint8_t)true)
	{
		StartUpViewBase::initSuccess(true);
	}
	else
	{
		InitErrorPopUp.setVisible(true);
		InitErrorPopUp.invalidate();
	}
}
