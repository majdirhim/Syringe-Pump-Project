#include <gui/keyboardnb_screen/KeyboardNbView.hpp>
#include <stdlib.h>


KeyboardNbView::KeyboardNbView()
{

}

void KeyboardNbView::setupScreen()
{
	User = presenter->getKeyboardUser();
	Step  = 0;
	UserInput.BeforeComma = 0;
	UserInput.AfterComma = 0;
	setUnit();
	setupDisplayMode();
	setFloatArea();
    KeyboardNbViewBase::setupScreen();
}

void KeyboardNbView::tearDownScreen()
{
    KeyboardNbViewBase::tearDownScreen();
}

void KeyboardNbView::setupDisplayMode(void)
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

void KeyboardNbView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotoMainScreenNoTransition();
}

void KeyboardNbView::ChangeScreen()
{
	switch(User)
	{
	case AGE:
	case HEIGHT:
	case WEIGHT:
		static_cast<FrontendApplication*>(Application::getInstance())->gotoNewPatientScreenWipeTransitionNorth();
		break;
	case TOTALVOLUME:
	case INFUSIONVOLUME:
	case FLOWRATE:
	case KVO:
	case BOLUS:
		static_cast<FrontendApplication*>(Application::getInstance())->gotoConfigurationScreenWipeTransitionNorth();
		break;
	case FLOWRATE_MAIN :
	case TOTALVOLUME_MAIN :
		static_cast<FrontendApplication*>(Application::getInstance())->gotoMainScreenWipeTransitionNorth();
		break;
	case PRESSURE_H:
	case PRESSURE_M:
	case PRESSURE_L:

		break;
	}
}

void KeyboardNbView::Input0()
{
	writeToScreen('0');
}

void KeyboardNbView::Input1()
{
	writeToScreen('1');
}

void KeyboardNbView::Input2()
{
	writeToScreen('2');
}

void KeyboardNbView::Input3()
{
	writeToScreen('3');
}

void KeyboardNbView::Input4()
{
	writeToScreen('4');
}

void KeyboardNbView::Input5()
{
	writeToScreen('5');
}

void KeyboardNbView::Input6()
{
	writeToScreen('6');
}

void KeyboardNbView::Input7()
{
	writeToScreen('7');
}

void KeyboardNbView::Input8()
{
	writeToScreen('8');
}

void KeyboardNbView::Input9()
{
	writeToScreen('9');
}

void KeyboardNbView::InputComma()
{
	Comma = true;
}

void KeyboardNbView::writeToScreen(char Input)
{
    switch (Comma)
    {
    case false :
        if (Step <= 3)
        {
            *(InputString + Step) = Input;
            Step++;
            Unicode::snprintf(IntTextAreaBuffer, INTTEXTAREA_SIZE, InputString);
            IntTextArea.invalidate();
        }
        else if (Step > 3)
        {
        	EraseInput();
            *(InputString + Step) = Input;
            Step++;
            Unicode::snprintf(IntTextAreaBuffer, INTTEXTAREA_SIZE, InputString);
            IntTextArea.invalidate();
        }
        break;
    case true :
    	UserInput.AfterComma = Input - 48;
        Unicode::snprintf(FloatTextAreaBuffer, FLOATTEXTAREA_SIZE, &Input);
        FloatTextArea.invalidate();
        Comma = false;
        break;
    default :
        break;
    }
}

void KeyboardNbView::SaveData()
{
	UserInput.BeforeComma = atoi(InputString);
	
	switch(User)
	{
	case AGE:
		if((UserInput.BeforeComma <= 255) && (UserInput.BeforeComma > 0))
		{
			presenter->savePatientAge((uint8_t)UserInput.BeforeComma);
			ChangeScreen();
		}
		else
		{

		}
		break;
	case HEIGHT:
		if((UserInput.BeforeComma <= 255) && (UserInput.BeforeComma > 0))
		{
			presenter->savePatientHeight((uint8_t)UserInput.BeforeComma);
			ChangeScreen();
		}
		else
		{

		}
		break;
	case WEIGHT:
			presenter->savePatientWeight(UserInput.BeforeComma);
			ChangeScreen();
		break;
	case TOTALVOLUME:
	case TOTALVOLUME_MAIN :
		// cannot bigger than syringe volume
		if (1)
		{
			presenter->saveTotalVolume(UserInput);
			ChangeScreen();
		}
		else
		{

		}
		break;
	case INFUSIONVOLUME:
		// cannot bigger than syringe volume 
		if (1)
		{
			presenter->saveInfusionVolume(UserInput);
			ChangeScreen();
		}
		else
		{

		}
		break;
	case FLOWRATE:
	case FLOWRATE_MAIN:
		// cannot bigger than syringe volume 
		if (1)
		{
			presenter->saveFlowaRate(UserInput);
			ChangeScreen();
		}
		else
		{

		}
		break;
	case KVO:
		// cannot bigger than syringe volume 
		if (1)
		{
			presenter->saveKVORate(UserInput);
			ChangeScreen();
		}
		else
		{

		}
		break;
	case BOLUS:
		// cannot bigger than syringe volume 
		if (1)
		{
			presenter->saveBolusRate(UserInput);
			ChangeScreen();
		}
		else
		{

		}
		break;
	case PRESSURE_H:
		// cannot bigger than syringe volume 
		if (1)
		{
			presenter->savePressureThresholdHigh(UserInput.BeforeComma);
			ChangeScreen();
		}
		else
		{

		}
		break;
	case PRESSURE_M:
		// cannot bigger than syringe volume 
		if (1)
		{
			presenter->savePressureThresholdMedium(UserInput.BeforeComma);
			ChangeScreen();
		}
		else
		{

		}
		break;
	case PRESSURE_L:
		// cannot bigger than syringe volume 
		if (1)
		{
			presenter->savePressureThresholdLow(UserInput.BeforeComma);
			ChangeScreen();
		}
		else
		{

		}
		break;
	}
}

void KeyboardNbView::EraseInput()
{
    Unicode::snprintf(IntTextAreaBuffer, INTTEXTAREA_SIZE, "0");
    Unicode::snprintf(FloatTextAreaBuffer, FLOATTEXTAREA_SIZE, "0");
    IntTextArea.invalidate();
    FloatTextArea.invalidate();
    memset(InputString, 0, 4);
    UserInput.AfterComma = 0;
    UserInput.BeforeComma = 0;
    Step = 0;
}

void KeyboardNbView::setUnit()
{
	switch(User)
	{
	case AGE:
		Unicode::snprintf(UnitTextAreaBuffer, UNITTEXTAREA_SIZE, "");
		break;
	case HEIGHT:
		Unicode::snprintf(UnitTextAreaBuffer, UNITTEXTAREA_SIZE, "cm");
		break;
	case WEIGHT:
		Unicode::snprintf(UnitTextAreaBuffer, UNITTEXTAREA_SIZE, "Kg");
		break;
	case PRESSURE_H:
	case PRESSURE_M:
	case PRESSURE_L:
		Unicode::snprintf(UnitTextAreaBuffer, UNITTEXTAREA_SIZE, "mmHg");
		break;
	case FLOWRATE:
	case KVO:
	case BOLUS:
	case FLOWRATE_MAIN:
		Unicode::snprintf(UnitTextAreaBuffer, UNITTEXTAREA_SIZE, "mL/h");
		break;
	case TOTALVOLUME:
	case INFUSIONVOLUME:
	case TOTALVOLUME_MAIN:
		Unicode::snprintf(UnitTextAreaBuffer, UNITTEXTAREA_SIZE, "mL");
		break;
	}
	UnitTextArea.invalidate();
}

void KeyboardNbView::setFloatArea()
{
	if ((User == AGE) || (User == PRESSURE_L) || (User == PRESSURE_M) || (User == PRESSURE_H))
	{
		FloatTextArea.setVisible(false);
	}
}



