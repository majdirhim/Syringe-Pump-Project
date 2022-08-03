#include <gui/logscreen_screen/LogScreenView.hpp>

LogScreenView::LogScreenView()
{

}

void LogScreenView::setupScreen()
{
	SetupDisplayMode();
    LogScreenViewBase::setupScreen();
}

void LogScreenView::tearDownScreen()
{
    LogScreenViewBase::tearDownScreen();
}

void LogScreenView::SetupDisplayMode(void)
{
	if (presenter->GetdisplayMode() == 1)
	{
		Backend.setVisible(0);
		BackendBlack.setVisible(1);
		BackendChildren.setVisible(0);
	}
	else if (presenter->GetdisplayMode() == 2)
	{
		Backend.setVisible(0);
		BackendBlack.setVisible(0);
		BackendChildren.setVisible(2);
	}
	else
	{
		Backend.setVisible(1);
		BackendBlack.setVisible(0);
		BackendChildren.setVisible(0);
	}
}

void LogScreenView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}

void LogScreenView::RequestData()
{
	presenter->RequeststorelogdData(0);
}
void LogScreenView::testdata()
{
	if(presenter->LogDataRequestAnswer() == 0)
	{
        WaitAnimation.stopAnimation();
        WaitAnimation.setVisible(0);
        nodata.setVisible(1);
        WaitAnimation.invalidate();
        nodata.invalidate();
	}
	else
	{
		WaitPopUp.setVisible(0);
		WaitPopUp.invalidate();
	    listElements[0].setuptitle();
	    list.add(listElements[0]);
	    for (uint8_t i = 1; i < 33; ++i)
	    {
	    	logvector = presenter->getlogvector(i - 1);
	    	while(((logvector.source <= 0) || (logvector.source > 17)) && (i < 33))
	    	{
				listElements[i].setuplog(" ", {0, 0, 0});
				list.add(listElements[i]);
	    		i++;
	    		logvector = presenter->getlogvector(i - 1);
	    	}
	    	if(i < 33)
	    	{
				if(logvector.types == 1)
				{
					listElements[i].setuplog(alarmSources[logvector.source - 1], logvector.timestamp);
					listElements[i].setupcolor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
					list.add(listElements[i]);
				}
				if(logvector.types == 0)
				{
					listElements[i].setuplog(eventSources[logvector.source - 1], logvector.timestamp);
					listElements[i].setupcolor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
					list.add(listElements[i]);
				}
	    	}
	    	list.invalidate();
	    }
	}
}

void LogScreenView::RequestForward()
{
    nodata.setVisible(0);
	WaitAnimation.startAnimation(0, 1);
    WaitAnimation.invalidate();
    nodata.invalidate();
	presenter->RequeststorelogdData(2);
}
void LogScreenView::RequestBack()
{
    nodata.setVisible(0);
    WaitAnimation.startAnimation(0, 1);
    WaitAnimation.invalidate();
    nodata.invalidate();
	presenter->RequeststorelogdData(1);
}

void LogScreenView::testdataafteInit()
{
	if(presenter->LogDataRequestAnswer() == 0)
	{
        WaitAnimation.stopAnimation();
        WaitAnimation.setVisible(0);
        nodata.setVisible(1);
        WaitAnimation.invalidate();
        nodata.invalidate();
	}
	else
	{
		WaitPopUp.setVisible(0);
		WaitPopUp.invalidate();
	    for (uint8_t i = 1; i < 33; ++i)
	    {
	    	logvector = presenter->getlogvector(i - 1);
	    	while(((logvector.source <= 0) || (logvector.source > 17)) && (i < 33))
	    	{
	    		listElements[i].setuplog(" ", {0, 0, 0});
	    		i++;
	    		logvector = presenter->getlogvector(i - 1);
	    	}
	    	if(i < 33)
	    	{
				if(logvector.types == 1)
				{
					listElements[i].setuplog(alarmSources[logvector.source - 1], logvector.timestamp);
					listElements[i].setupcolor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
				}
				if(logvector.types == 0)
				{
					listElements[i].setuplog(eventSources[logvector.source - 1], logvector.timestamp);
					listElements[i].setupcolor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
				}
	    	}
	    	list.invalidate();
	    }
	}
}
