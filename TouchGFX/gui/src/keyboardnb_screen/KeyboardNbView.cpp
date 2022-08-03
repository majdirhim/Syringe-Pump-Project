#include <gui/keyboardnb_screen/KeyboardNBView.hpp>
#include <string>

KeyboardNBView::KeyboardNBView()
{
    

}

void KeyboardNBView::setupScreen()
{
   touchgfx_printf("------------------  %d  \n", presenter->getinputdestinsation());
   pas = 0;
   userinput.value = 0;
   userinput.scale = 0;
   SetupDisplayMode();
   KeyboardNBViewBase::setupScreen();
}

void KeyboardNBView::tearDownScreen()
{
    KeyboardNBViewBase::tearDownScreen();
}

void KeyboardNBView::write0()
{
    
    writetoscreen('0');

}

void KeyboardNBView::write1()
{
    writetoscreen('1');
}

void KeyboardNBView::write2()
{
    writetoscreen('2');

}

void KeyboardNBView::write3()
{
    writetoscreen('3');
}

void KeyboardNBView::write4()
{
    writetoscreen('4');
}

void KeyboardNBView::write5()
{
    writetoscreen('5');
}

void KeyboardNBView::write6()
{
    writetoscreen('6');
}

void KeyboardNBView::write7()
{
    writetoscreen('7');
}

void KeyboardNBView::write8()
{
    writetoscreen('8');
}

void KeyboardNBView::write9()
{
    writetoscreen('9');
}

void KeyboardNBView::writecomma()
{
    comma = 1;
}

void KeyboardNBView::writetoscreen(const char var)
{ 
    switch (comma)
    {
    case 0 :
        if (pas <= 3)
        {
            *(inputString + pas) = var;
            pas++;
            touchgfx_printf(" 000  %s  \n", inputString);
            Unicode::snprintf(textArea_centaineBuffer, TEXTAREA_CENTAINE_SIZE, inputString);
            textArea_centaine.invalidate();
        }
        else if (pas > 3)
        {
            IT_ERASE();
            *(inputString + pas) = var;
            pas++;
            touchgfx_printf(" 000  %s  \n", inputString);
            Unicode::snprintf(textArea_centaineBuffer, TEXTAREA_CENTAINE_SIZE, inputString);
            textArea_centaine.invalidate();
        }
        break;
    case 1 :
        userinput.scale = var - 48;
        Unicode::snprintf(textArea_commaBuffer, TEXTAREA_COMMA_SIZE, &var);
        textArea_comma.invalidate();
        comma = 0;
        break;
    default :
        break;
    }    
}

void KeyboardNBView::IT_ERASE()
{
        Unicode::snprintf(textArea_centaineBuffer, TEXTAREA_CENTAINE_SIZE, "0");
        Unicode::snprintf(textArea_commaBuffer, TEXTAREA_COMMA_SIZE, "0");
        textArea_comma.invalidate();
        textArea_centaine.invalidate();
        memset(inputString, 0, 4);
        userinput.scale = 0;
        pas = 0;
}

void KeyboardNBView::showpopup(void)
{
    modalinputerror.setVisible(true);
    modalinputerror.setTouchable(true);
    modalinputerror.invalidate();
}

void KeyboardNBView::closepopup(void)
{
    modalinputerror.setVisible(false);
    modalinputerror.setTouchable(false);
    modalinputerror.invalidate();
    IT_ERASE();
}

void KeyboardNBView::savedata()
{
    userinput.value = atoi(inputString);
    touchgfx_printf(" -------------------------------------   %d  \n", userinput.value);
    uint16_t N = presenter->getinputdestinsation();
    switch (N) 
    {
    case 1:
        presenter->saverate(userinput);
        static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
        break;
    case 2 :
        presenter->savevolume(userinput);
        static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
        break;
    case 3 :
    	presenter->savedinfusionvolume(userinput);
    	static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
    	break;
    case 4 :
        if ((userinput.value < 0) || (userinput.value > 5) || ((userinput.value == 5) && (userinput.scale > 0)) || ((userinput.value == 0) && (userinput.scale == 0)))
        {
            showpopup();
            Unicode::snprintf(errorBuffer, ERROR_SIZE, "0 < = KVO < = 5");
            error.invalidate();
        }
        else 
        {
            presenter->saveKVO(userinput);
            static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
        }
        break;
    case 5 :
        presenter->savebolus(userinput);
        static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
        break;
    case 61 :
        if((userinput.value < presenter->getoclusionMedium()) || (userinput.value < presenter->getoclusionLow()))
        {
            showpopup();
            Unicode::snprintf(errorBuffer, ERROR_SIZE, "%d < %d\n%d < %d", presenter->getoclusionLow(), userinput.value, presenter->getoclusionMedium(), userinput.value);
            error.invalidate();
        }
        else{
            presenter->saveoclusionHigh(userinput.value);
        	static_cast<FrontendApplication*>(Application::getInstance())->gotoOclusion_levelScreenNoTransition();
        }
        break;
    case 62 :
        if (((presenter->getoclusionHigh() != 0) && (userinput.value > presenter->getoclusionHigh())) || (userinput.value < presenter->getoclusionLow()))
        {
            showpopup();
            Unicode::snprintf(errorBuffer, ERROR_SIZE, "%d < %d\n%d > %d", presenter->getoclusionLow(), userinput.value, presenter->getoclusionHigh(), userinput.value);
            error.invalidate();
        }
        else{
            presenter->saveoclusionMedium(userinput.value);
        static_cast<FrontendApplication*>(Application::getInstance())->gotoOclusion_levelScreenNoTransition();
        }
        break;
    case 63 :
        if (((presenter->getoclusionMedium() != 0) && (userinput.value > presenter->getoclusionMedium())) || ((presenter->getoclusionHigh() != 0) && (userinput.value > presenter->getoclusionHigh())))
        {
            showpopup();
            Unicode::snprintf(errorBuffer, ERROR_SIZE, "%d > %d\n%d > %d", presenter->getoclusionMedium(), userinput.value, presenter->getoclusionHigh(), userinput.value);
            error.invalidate();
        }
        else{
         presenter->saveoclusionLow(userinput.value);
        static_cast<FrontendApplication*>(Application::getInstance())->gotoOclusion_levelScreenNoTransition();
        }
        break;
    case 8 :
    	presenter->saveposition(userinput.value);
    	static_cast<FrontendApplication*>(Application::getInstance())->gototestVersionScreenNoTransition();
    	break;
    case 7 :
    	presenter->savediameter(userinput.value);
    	static_cast<FrontendApplication*>(Application::getInstance())->gototestVersionScreenNoTransition();
    	break;
    default : 
        break;
    }
}

void KeyboardNBView::SetupDisplayMode(void)
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
        BackendChildren.setVisible(1);
    }
    else
    {
        Backend.setVisible(1);
        BackendBlack.setVisible(0);
        BackendChildren.setVisible(0);
    }
}

void KeyboardNBView::AlarmOrEvent(void)
{
    static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}
