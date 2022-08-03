#include <gui/alarmlist_screen/AlarmListView.hpp>

AlarmListView::AlarmListView()
{

}

void AlarmListView::setupScreen()
{
    SetupDisplayMode();
    listElements[0].setuptile();
    list.add(listElements[0]);
    int j = 1;
    for (uint8_t i = 0; i < 17; ++i)
    {
    	alarmvector = presenter->getalarmvector(i);
    	if((alarmvector) == 1)
    	{
    		alarmsState[i] = 1;
    		listElements[j].setuplist(alarmSources[i], (alarmvector));
    		list.add(listElements[j]);
    		j++;
    	}
    }
    AlarmListViewBase::setupScreen();
}

void AlarmListView::tearDownScreen()
{
    AlarmListViewBase::tearDownScreen();
}

void AlarmListView::SetupDisplayMode(void)
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

void AlarmListView::AlarmOrEvent(void)
{
    static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}


void AlarmListView::handleTickEvent()
{
    int j = 1;
    for (uint8_t i = 0; i < 17; ++i)
    {
    	alarmvector = presenter->getalarmvector(i);
    	if((alarmsState[i]) == 1)
    	{
    		listElements[j].setuplist(alarmSources[i], (alarmvector));
    		j++;
    	}
    	list.invalidate();
    }
}
