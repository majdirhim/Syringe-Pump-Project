#include <gui/lockscreen_screen/LockScreenView.hpp>
#include <string>
LockScreenView::LockScreenView()
{

}

void LockScreenView::setupScreen()
{
	touchgfx_printf("Lock  %d  \n", presenter->GetLock());
	state = 0;
	UserInput = 0;
	SetupDisplayMode();
    LockScreenViewBase::setupScreen();

    if(presenter->GetLock() == 1)
    {
    	Intro.setVisible(0);
    	Keyboard.setVisible(1);
    	InsertPassword.setVisible(0);
		PasswordError.setVisible(0);
		InsertOldPassword.setVisible(0);
		InsertNewPassword.setVisible(0);
		PasswordChangeSuccess.setVisible(0);
		ScreenUnlocked.setVisible(0);
		ScreenLocked.setVisible(1);
		Back.setTouchable(0);
		Back.invalidate();
    	Intro.invalidate();
    	Keyboard.invalidate();
    	InsertPassword.invalidate();
		PasswordError.invalidate();
		InsertOldPassword.invalidate();
		InsertNewPassword.invalidate();
		PasswordChangeSuccess.invalidate();
		ScreenUnlocked.invalidate();
		ScreenLocked.invalidate();
		state = 1;
    }
    else if(presenter->GetLock() == 2)
    {
    	Intro.setVisible(0);
    	Keyboard.setVisible(1);
    	InsertPassword.setVisible(1);
		PasswordError.setVisible(0);
		InsertOldPassword.setVisible(0);
		InsertNewPassword.setVisible(0);
		PasswordChangeSuccess.setVisible(0);
		ScreenUnlocked.setVisible(0);
		ScreenLocked.setVisible(0);
		Back.setTouchable(1);
		Back.invalidate();
    	Intro.invalidate();
    	Keyboard.invalidate();
    	InsertPassword.invalidate();
		PasswordError.invalidate();
		InsertOldPassword.invalidate();
		InsertNewPassword.invalidate();
		PasswordChangeSuccess.invalidate();
		ScreenUnlocked.invalidate();
		ScreenLocked.invalidate();
		state = presenter->getscreenlock();
    }
}

void LockScreenView::tearDownScreen()
{
    LockScreenViewBase::tearDownScreen();
}

void LockScreenView::SetupDisplayMode(void)
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

void LockScreenView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}

void LockScreenView::write0()
{

    writetoscreen('0');

}

void LockScreenView::write1()
{
    writetoscreen('1');
}

void LockScreenView::write2()
{
    writetoscreen('2');

}

void LockScreenView::write3()
{
    writetoscreen('3');
}

void LockScreenView::write4()
{
    writetoscreen('4');
}

void LockScreenView::write5()
{
    writetoscreen('5');
}

void LockScreenView::write6()
{
    writetoscreen('6');
}

void LockScreenView::write7()
{
    writetoscreen('7');
}

void LockScreenView::write8()
{
    writetoscreen('8');
}

void LockScreenView::write9()
{
	writetoscreen('9');
}

void LockScreenView::writetoscreen(const char var)
{

	if(state == 1)
	{
    	InsertPassword.setVisible(1);
		PasswordError.setVisible(0);
		InsertOldPassword.setVisible(0);
		InsertNewPassword.setVisible(0);
		PasswordChangeSuccess.setVisible(0);
		ScreenUnlocked.setVisible(0);
		ScreenLocked.setVisible(0);
    	InsertPassword.invalidate();
		PasswordError.invalidate();
		InsertOldPassword.invalidate();
		InsertNewPassword.invalidate();
		PasswordChangeSuccess.invalidate();
		ScreenUnlocked.invalidate();
		ScreenLocked.invalidate();
	}
	if(state == 20)
	{
    	InsertPassword.setVisible(0);
		PasswordError.setVisible(0);
		InsertOldPassword.setVisible(1);
		InsertNewPassword.setVisible(0);
		PasswordChangeSuccess.setVisible(0);
		ScreenUnlocked.setVisible(0);
		ScreenLocked.setVisible(0);
    	InsertPassword.invalidate();
		PasswordError.invalidate();
		InsertOldPassword.invalidate();
		InsertNewPassword.invalidate();
		PasswordChangeSuccess.invalidate();
		ScreenUnlocked.invalidate();
		ScreenLocked.invalidate();
	}
	if (pas <= 3)
	{
		*(inputString + pas) = var;
		pas++;
		touchgfx_printf(" 000  %s  \n", inputString);
		Unicode::snprintf(textArea_centaineBuffer, TEXTAREA_CENTAINE_SIZE, "%04d", atoi(inputString));
		textArea_centaine.invalidate();
	}
	else if (pas > 3)
	{
		IT_ERASE();
		*(inputString + pas) = var;
		pas++;
		touchgfx_printf(" 000  %s  \n", inputString);
		Unicode::snprintf(textArea_centaineBuffer, TEXTAREA_CENTAINE_SIZE, "%04d", atoi(inputString));
		textArea_centaine.invalidate();
	}
}

void LockScreenView::IT_ERASE()
{
        Unicode::snprintf(textArea_centaineBuffer, TEXTAREA_CENTAINE_SIZE, "0000");
        textArea_centaine.invalidate();
        memset(inputString, 0, 4);
        UserInput= 0;
        pas = 0;
}

void LockScreenView::savedata()
{
    UserInput = atoi(inputString);
    switch (state)
    {
    case 1:
        if(presenter->GetPassword() == UserInput)
        {
        	InsertPassword.setVisible(0);
    		PasswordError.setVisible(0);
    		InsertOldPassword.setVisible(0);
    		InsertNewPassword.setVisible(0);
    		PasswordChangeSuccess.setVisible(0);
        	InsertPassword.invalidate();
    		PasswordError.invalidate();
    		InsertOldPassword.invalidate();
    		InsertNewPassword.invalidate();
    		PasswordChangeSuccess.invalidate();
        	if(presenter->GetLock() == 0)
        	{
        		presenter->SaveLock(1);
        		ScreenUnlocked.setVisible(0);
        		ScreenLocked.setVisible(1);
        		AlarmOrEvent();
        	}
        	else if(presenter->GetLock() == 1)
        	{
        		presenter->SaveLock(0);
        		ScreenUnlocked.setVisible(1);
        		ScreenLocked.setVisible(0);
        		Back.setTouchable(1);
        		Back.invalidate();
        		Back.setPressed(1);
        		Back.executeAction();


        	}
    		ScreenUnlocked.invalidate();
    		ScreenLocked.invalidate();
			touchgfx_printf("Lock  %d  \n", presenter->GetLock());
        }
        else if(presenter->GetPassword() != UserInput)
        {
        	InsertPassword.setVisible(0);
    		PasswordError.setVisible(1);
    		InsertOldPassword.setVisible(0);
    		InsertNewPassword.setVisible(0);
    		PasswordChangeSuccess.setVisible(0);
    		ScreenUnlocked.setVisible(0);
    		ScreenLocked.setVisible(0);
        	InsertPassword.invalidate();
    		PasswordError.invalidate();
    		InsertOldPassword.invalidate();
    		InsertNewPassword.invalidate();
    		PasswordChangeSuccess.invalidate();
    		ScreenUnlocked.invalidate();
    		ScreenLocked.invalidate();
        }
        break;
    case 20 :
    	if(presenter->GetPassword() == UserInput)
		{
			InsertPassword.setVisible(0);
			PasswordError.setVisible(0);
			InsertOldPassword.setVisible(0);
			InsertNewPassword.setVisible(1);
			PasswordChangeSuccess.setVisible(0);
			ScreenUnlocked.setVisible(0);
			ScreenLocked.setVisible(0);
			InsertPassword.invalidate();
			PasswordError.invalidate();
			InsertOldPassword.invalidate();
			InsertNewPassword.invalidate();
			PasswordChangeSuccess.invalidate();
			ScreenUnlocked.invalidate();
			ScreenLocked.invalidate();
			state = 21;
		}
		else if(presenter->GetPassword() != UserInput)
		{
			InsertPassword.setVisible(0);
			PasswordError.setVisible(1);
			InsertOldPassword.setVisible(0);
			InsertNewPassword.setVisible(0);
			PasswordChangeSuccess.setVisible(0);
			ScreenUnlocked.setVisible(0);
			ScreenLocked.setVisible(0);
			InsertPassword.invalidate();
			PasswordError.invalidate();
			InsertOldPassword.invalidate();
			InsertNewPassword.invalidate();
			PasswordChangeSuccess.invalidate();
			ScreenUnlocked.invalidate();
			ScreenLocked.invalidate();
		}
        break;
    case 21 :
			InsertPassword.setVisible(0);
			PasswordError.setVisible(0);
			InsertOldPassword.setVisible(0);
			InsertNewPassword.setVisible(0);
			PasswordChangeSuccess.setVisible(1);
			ScreenUnlocked.setVisible(0);
			ScreenLocked.setVisible(0);
			InsertPassword.invalidate();
			PasswordError.invalidate();
			InsertOldPassword.invalidate();
			InsertNewPassword.invalidate();
			PasswordChangeSuccess.invalidate();
			ScreenUnlocked.invalidate();
			ScreenLocked.invalidate();
			state = 20;
			presenter->SavePassword(UserInput);
			break;
    case 3 :
    	if(presenter->GetPassword() == UserInput)
		{
			InsertPassword.setVisible(0);
			PasswordError.setVisible(0);
			InsertOldPassword.setVisible(0);
			InsertNewPassword.setVisible(0);
			PasswordChangeSuccess.setVisible(0);
			InsertPassword.invalidate();
			PasswordError.invalidate();
			InsertOldPassword.invalidate();
			InsertNewPassword.invalidate();
			PasswordChangeSuccess.invalidate();
			presenter->SaveLock(0);
			static_cast<FrontendApplication*>(Application::getInstance())->gotoLogScreenScreenNoTransition();
		}
		else if(presenter->GetPassword() != UserInput)
		{
			InsertPassword.setVisible(0);
			PasswordError.setVisible(1);
			InsertOldPassword.setVisible(0);
			InsertNewPassword.setVisible(0);
			PasswordChangeSuccess.setVisible(0);
			ScreenUnlocked.setVisible(0);
			ScreenLocked.setVisible(0);
			InsertPassword.invalidate();
			PasswordError.invalidate();
			InsertOldPassword.invalidate();
			InsertNewPassword.invalidate();
			PasswordChangeSuccess.invalidate();
			ScreenUnlocked.invalidate();
			ScreenLocked.invalidate();
		}
        break;
    case 4 :
    	if(presenter->GetPassword() == UserInput)
		{
			InsertPassword.setVisible(0);
			PasswordError.setVisible(0);
			InsertOldPassword.setVisible(0);
			InsertNewPassword.setVisible(0);
			PasswordChangeSuccess.setVisible(0);
			InsertPassword.invalidate();
			PasswordError.invalidate();
			InsertOldPassword.invalidate();
			InsertNewPassword.invalidate();
			PasswordChangeSuccess.invalidate();
			presenter->SaveLock(0);
			static_cast<FrontendApplication*>(Application::getInstance())->gotoSettings_Time_DateScreenNoTransition();
		}
		else if(presenter->GetPassword() != UserInput)
		{
			InsertPassword.setVisible(0);
			PasswordError.setVisible(1);
			InsertOldPassword.setVisible(0);
			InsertNewPassword.setVisible(0);
			PasswordChangeSuccess.setVisible(0);
			ScreenUnlocked.setVisible(0);
			ScreenLocked.setVisible(0);
			InsertPassword.invalidate();
			PasswordError.invalidate();
			InsertOldPassword.invalidate();
			InsertNewPassword.invalidate();
			PasswordChangeSuccess.invalidate();
			ScreenUnlocked.invalidate();
			ScreenLocked.invalidate();
		}
    	break;
    case 5 :
    	if(presenter->getpwdtech() == UserInput)
		{
			InsertPassword.setVisible(0);
			PasswordError.setVisible(0);
			InsertOldPassword.setVisible(0);
			InsertNewPassword.setVisible(0);
			PasswordChangeSuccess.setVisible(0);
			InsertPassword.invalidate();
			PasswordError.invalidate();
			InsertOldPassword.invalidate();
			InsertNewPassword.invalidate();
			PasswordChangeSuccess.invalidate();
			presenter->SaveLock(0);
			static_cast<FrontendApplication*>(Application::getInstance())->gotoMaintenanceScreenNoTransition();
		}
		else if(presenter->getpwdtech() != UserInput)
		{
			InsertPassword.setVisible(0);
			PasswordError.setVisible(1);
			InsertOldPassword.setVisible(0);
			InsertNewPassword.setVisible(0);
			PasswordChangeSuccess.setVisible(0);
			ScreenUnlocked.setVisible(0);
			ScreenLocked.setVisible(0);
			InsertPassword.invalidate();
			PasswordError.invalidate();
			InsertOldPassword.invalidate();
			InsertNewPassword.invalidate();
			PasswordChangeSuccess.invalidate();
			ScreenUnlocked.invalidate();
			ScreenLocked.invalidate();
		}
    	break;
    default :
        break;
    }
}

void LockScreenView::ChangePasswordF()
{
	Intro.setVisible(0);
	Keyboard.setVisible(1);
	state = 20;
	InsertPassword.setVisible(0);
	PasswordError.setVisible(0);
	InsertOldPassword.setVisible(1);
	InsertNewPassword.setVisible(0);
	PasswordChangeSuccess.setVisible(0);
	ScreenUnlocked.setVisible(0);
	ScreenLocked.setVisible(0);
	InsertPassword.invalidate();
	PasswordError.invalidate();
	InsertOldPassword.invalidate();
	InsertNewPassword.invalidate();
	PasswordChangeSuccess.invalidate();
	ScreenUnlocked.invalidate();
	ScreenLocked.invalidate();
	Intro.invalidate();
	Keyboard.invalidate();
}
void LockScreenView::LockF()
{
	Intro.setVisible(0);
	Keyboard.setVisible(1);
	state = 1;
	InsertPassword.setVisible(1);
	PasswordError.setVisible(0);
	InsertOldPassword.setVisible(0);
	InsertNewPassword.setVisible(0);
	PasswordChangeSuccess.setVisible(0);
	ScreenUnlocked.setVisible(0);
	ScreenLocked.setVisible(0);
	InsertPassword.invalidate();
	PasswordError.invalidate();
	InsertOldPassword.invalidate();
	InsertNewPassword.invalidate();
	PasswordChangeSuccess.invalidate();
	ScreenUnlocked.invalidate();
	ScreenLocked.invalidate();
	Intro.invalidate();
	Keyboard.invalidate();
}
