#include <gui/settings_time_date_screen/Settings_Time_DateView.hpp>

Settings_Time_DateView::Settings_Time_DateView()
{

}

void Settings_Time_DateView::setupScreen()
{
	SetupDisplayMode();
    Settings_Time_DateViewBase::setupScreen();

    timeinput = presenter->GetCurrentTime();

    Unicode::snprintf(textaearHourBuffer, TEXTAEARHOUR_SIZE, "%02d", timeinput.hours);
    Unicode::snprintf(textAreaminuteBuffer, TEXTAREAMINUTE_SIZE, "%02d", timeinput.minutes);
}

void Settings_Time_DateView::tearDownScreen()
{
    Settings_Time_DateViewBase::tearDownScreen();
}

void Settings_Time_DateView::buttonhourupclicked()
{
    timeinput.hours = (timeinput.hours + 1) % 24; // Keep new value in range 0..23
    Unicode::snprintf(textaearHourBuffer, TEXTAEARHOUR_SIZE, "%02d", timeinput.hours);
    textaearHour.invalidate();
}

void Settings_Time_DateView::buttonhourdownclicked()
{
    timeinput.hours = (timeinput.hours + 24 - 1) % 24; // Keep new value in range 0..23
    Unicode::snprintf(textaearHourBuffer, TEXTAEARHOUR_SIZE, "%02d", timeinput.hours);
    textaearHour.invalidate();
}

void Settings_Time_DateView::buttonminuteupclicked()
{
    timeinput.minutes = (timeinput.minutes + 1) % 60; // Keep new value in range 0..59
    Unicode::snprintf(textAreaminuteBuffer, TEXTAREAMINUTE_SIZE, "%02d", timeinput.minutes);
    textAreaminute.invalidate();
}

void Settings_Time_DateView::buttonminutedownclicked()
{
    timeinput.minutes = (timeinput.minutes + 60 - 1) % 60; // Keep new value in range 0..59
    Unicode::snprintf(textAreaminuteBuffer, TEXTAREAMINUTE_SIZE, "%02d", timeinput.minutes);
    textAreaminute.invalidate();
}

void Settings_Time_DateView::SetupDisplayMode(void)
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

void Settings_Time_DateView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}
