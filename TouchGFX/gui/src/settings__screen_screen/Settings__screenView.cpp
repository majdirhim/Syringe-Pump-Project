#include <gui/settings__screen_screen/Settings__screenView.hpp>

Settings__screenView::Settings__screenView()
{

}

void Settings__screenView::setupScreen()
{
    SetupDisplayMode();

    timesetting = presenter->GetCurrentTime();

    Unicode::snprintf(textclockBuffer1, TEXTCLOCKBUFFER1_SIZE, "%02d", timesetting.hours);
    Unicode::snprintf(textclockBuffer2, TEXTCLOCKBUFFER2_SIZE, "%02d", timesetting.minutes);
    Unicode::snprintf(textclocksecBuffer, TEXTCLOCKSEC_SIZE, "%02d", timesetting.seconds);
    Settings__screenViewBase::setupScreen();
}

void Settings__screenView::tearDownScreen()
{
	
    presenter->SaveCurrentTime(timesetting);

    Settings__screenViewBase::tearDownScreen();
}

void Settings__screenView::Btnon_off(bool onoff)
{
    btn_Auto_Diagnostic.setTouchable(onoff);
    btn_Departement.setTouchable(onoff);
    btn_Display_mode.setTouchable(onoff);
    btn_history.setTouchable(onoff);
    btn_Drug_Library.setTouchable(onoff);
    btn_Language.setTouchable(onoff);
    btn_Manual.setTouchable(onoff);
    btn_Sound.setTouchable(onoff);
    btn_Time_Date.setTouchable(onoff);
    btn_Back.setTouchable(onoff);
}

void Settings__screenView::state_test()
{
    if (popup_auto_diagnostic1.isVisible())
        Btnon_off(false);
    else
        Btnon_off(true);
}

void Settings__screenView::goto_autodiagnosic()
{
    popup_auto_diagnostic1.setVisible(true);
    container_setting.setVisible(false);
    container_Display_mode.setVisible(false);
    container_Language.setVisible(false);
    container_sound.setVisible(false);
    container_setting.invalidate();
    container_Display_mode.invalidate();
    container_Language.invalidate();
    container_sound.invalidate();
    popup_auto_diagnostic1.invalidate();
    state_test();
    handleTickEvent();
    state_test();
}

void Settings__screenView::handleTickEvent()
{
  
    if (popup_auto_diagnostic1.isVisible())
    {
        if (Counter > 0)
        {
            Counter--;
            if (Counter == 0)
            {
                application().gotoSettings__screenScreenNoTransition();
            }
        }
    }
     
    
    tickCount++;
   
    if (tickCount % 60 == 0)
    {
    	if(++timesetting.seconds >= 60 )
    	{
            timesetting.seconds = 0;
    		if(++timesetting.minutes >= 60)
    		{
                timesetting.minutes = 0;
    			if(++timesetting.hours >= 24)
    			{
                    timesetting.hours = 0;
				}
			}
		}
        Unicode::snprintf(textclockBuffer1, TEXTCLOCKBUFFER1_SIZE, "%02d", timesetting.hours);
        Unicode::snprintf(textclockBuffer2,TEXTCLOCKBUFFER2_SIZE, "%02d", timesetting.minutes);
        Unicode::snprintf(textclocksecBuffer,TEXTCLOCKSEC_SIZE, "%02d", timesetting.seconds);
        textclock.invalidate();
        textclocksec.invalidate();
    }    
}


void Settings__screenView::afterTransition()
{
    Counter = DURATION;
}

void Settings__screenView::gotosound()
{
    container_setting.setVisible(false);
    popup_auto_diagnostic1.setVisible(false);
    container_Display_mode.setVisible(false);
    container_Language.setVisible(false);
    container_sound.setVisible(true);
    container_setting.setTouchable(false);
    popup_auto_diagnostic1.setTouchable(false);
    container_Display_mode.setTouchable(false);
    container_Language.setTouchable(false);
    container_sound.setTouchable(true);
    container_setting.invalidate();
    popup_auto_diagnostic1.invalidate();
    container_Display_mode.invalidate();
    container_Language.invalidate();
    container_sound.invalidate();
    slider1_1.setValue(presenter->getsound());
}

void Settings__screenView::soundtomain()
{
    presenter->savesound(slider1_1.getValue());
    container_setting.setVisible(true);
    popup_auto_diagnostic1.setVisible(false);
    container_Display_mode.setVisible(false);
    container_Language.setVisible(false);
    container_sound.setVisible(false);

    container_setting.setTouchable(true);
    popup_auto_diagnostic1.setTouchable(false);
    container_Display_mode.setTouchable(false);
    container_Language.setTouchable(false);
    container_sound.setTouchable(false);

    container_setting.invalidate();
    popup_auto_diagnostic1.invalidate();
    container_Display_mode.invalidate();
    container_Language.invalidate();
    container_sound.invalidate();
}

void Settings__screenView::goto_Displaymode()
{
    container_setting.setVisible(false);
    popup_auto_diagnostic1.setVisible(false);
    container_Display_mode.setVisible(true);
    container_Language.setVisible(false);
    container_sound.setVisible(false);
    DisplayDark.setVisible(true);
    DisplayChildren.setVisible(true);
    DisplayDefault.setVisible(true);

    container_setting.setTouchable(false);
    popup_auto_diagnostic1.setTouchable(false);
    container_Display_mode.setTouchable(true);
    container_Language.setTouchable(false);
    container_sound.setTouchable(false);
    DisplayDark.setTouchable(true);
    DisplayChildren.setTouchable(true);
    DisplayDefault.setTouchable(true);

    container_setting.invalidate();
    popup_auto_diagnostic1.invalidate();
    container_Display_mode.invalidate();
    container_Language.invalidate();
    container_sound.invalidate();

}

void Settings__screenView::set_setting()
{
    container_setting.setVisible(true);
    popup_auto_diagnostic1.setVisible(false);
    container_Display_mode.setVisible(false);
    container_Language.setVisible(false);
    container_sound.setVisible(false);

    container_setting.setTouchable(true);
    popup_auto_diagnostic1.setTouchable(false);
    container_Display_mode.setTouchable(false);
    container_Language.setTouchable(false);
    container_sound.setTouchable(false);

    container_setting.invalidate();
    popup_auto_diagnostic1.invalidate();
    container_Display_mode.invalidate();
    container_Language.invalidate();
    container_sound.invalidate();
}

void Settings__screenView::goto_Language()
{
    container_setting.setVisible(false);
    popup_auto_diagnostic1.setVisible(false);
    container_Display_mode.setVisible(false);
    container_Language.setVisible(true);
    container_sound.setVisible(false);

    container_setting.setTouchable(false);
    popup_auto_diagnostic1.setTouchable(false);
    container_Display_mode.setTouchable(false);
    container_Language.setTouchable(true);
    container_sound.setTouchable(false);

    container_setting.invalidate();
    popup_auto_diagnostic1.invalidate();
    container_Display_mode.invalidate();
    container_Language.invalidate();
    container_sound.invalidate();
}

void Settings__screenView::displaychildren()
{
    presenter->savediplaymode(2);
    SetupDisplayMode();
    set_setting();
}
void Settings__screenView::displaydark()
{
    presenter->savediplaymode(1);
    SetupDisplayMode();
    set_setting();
}
void Settings__screenView::displaydefault()
{
    presenter->savediplaymode(0);
    SetupDisplayMode();
    set_setting();
}

void Settings__screenView::SetupDisplayMode(void)
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
        BackendChildren.setVisible(1);
    }
    else
    {
        backend.setVisible(1);
        BackendBlack.setVisible(0);
        BackendChildren.setVisible(0);
    }
}

void Settings__screenView::AlarmOrEvent(void)
{
    static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}

void Settings__screenView::gotomaintenance()
{
	presenter->SaveLock(2);
	presenter->savescreenlock(5);
	static_cast<FrontendApplication*>(Application::getInstance())->gotoLockScreenScreenNoTransition();
}
void Settings__screenView::gototimeanddate()
{
	presenter->SaveLock(2);
	presenter->savescreenlock(4);
	static_cast<FrontendApplication*>(Application::getInstance())->gotoLockScreenScreenNoTransition();
}
void Settings__screenView::gotohistory()
{
	presenter->SaveLock(2);
	presenter->savescreenlock(3);
	static_cast<FrontendApplication*>(Application::getInstance())->gotoLockScreenScreenNoTransition();
}
