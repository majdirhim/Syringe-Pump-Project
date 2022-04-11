#include <gui/activealarms_screen/ActiveAlarmsView.hpp>

ActiveAlarmsView::ActiveAlarmsView()
{

}

void ActiveAlarmsView::setupScreen()
{
    setupDisplayMode();
    ListElements[0].setUpTitle();
    MyList.add(ListElements[0]);
    for (uint8_t i = 1; i < NUMBER_OF_ALARMS + NUMBER_OF_ALERTS + 1; ++i)
    {
        AlarmState = presenter->getActiveEvents(i);
        if ((AlarmState))
        {
            AlarmStates[i] = 1;
            touchgfx::Unicode::fromUTF8((const uint8_t *)presenter->getEventTitle(i), Description, strlen(presenter->getEventTitle(i)));
            ListElements[i].setUpAlarm(i, Description, 1);
            MyList.add(ListElements[i]);
        }
        memset(Description, 0, 49);
    }
    MyList.invalidate();
    ActiveAlarmsViewBase::setupScreen();
}

void ActiveAlarmsView::tearDownScreen()
{
    ActiveAlarmsViewBase::tearDownScreen();
}

void ActiveAlarmsView::AlarmOrEvent()
{
    static_cast<FrontendApplication*>(Application::getInstance())->gotoMainScreenNoTransition();
}

void ActiveAlarmsView::setupDisplayMode(void)
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

void ActiveAlarmsView::handleTickEvent()
{
    for (uint8_t i = 1; i < NUMBER_OF_ALARMS + NUMBER_OF_ALERTS + 1; ++i)
    {
        AlarmState = presenter->getActiveEvents(i);
        if ((!AlarmState)&&(AlarmStates[i] == 1))
        {
            touchgfx::Unicode::fromUTF8((const uint8_t*)presenter->getEventTitle(i), Description, strlen(presenter->getEventTitle(i)));
            ListElements[i].setUpAlarm(i, Description, 0);
        }
        else if ((AlarmState) && (AlarmStates[i] == 1))
        {
            touchgfx::Unicode::fromUTF8((const uint8_t*)presenter->getEventTitle(i), Description, strlen(presenter->getEventTitle(i)));
            ListElements[i].setUpAlarm(i, Description, 1);
        }
        else if ((AlarmState) && (AlarmStates[i] == 0))
        {
            AlarmStates[i] = 1;
            touchgfx::Unicode::fromUTF8((const uint8_t*)presenter->getEventTitle(i), Description, strlen(presenter->getEventTitle(i)));
            ListElements[i].setUpAlarm(i, Description, 1);
            MyList.add(ListElements[i]);
        }
        memset(Description, 0, 49);
    }
    MyList.invalidate();
}
