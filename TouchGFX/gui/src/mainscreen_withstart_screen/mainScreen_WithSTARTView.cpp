#include <gui/mainscreen_withstart_screen/mainScreen_WithSTARTView.hpp>
#include <string.h>

#define GB 0

mainScreen_WithSTARTView::mainScreen_WithSTARTView()
{

}

void mainScreen_WithSTARTView::setupScreen()
{
    writeinmain(); 

    drug=presenter->getdrug();
    Namedrug(drug);

    updatesyringestatus();
 	
    currenttime = presenter->getCurrentTime();
    Unicode::snprintf(textclockBuffer1,TEXTCLOCKBUFFER1_SIZE, "%02d", currenttime.hours);
    Unicode::snprintf(textclockBuffer2,TEXTCLOCKBUFFER2_SIZE, "%02d", currenttime.minutes);
    Unicode::snprintf(textclocksecBuffer, TEXTCLOCKSEC_SIZE, "%02d", currenttime.seconds);
  
    container_main.setVisible(true);
    container_config.setVisible(false);

    container_main.setTouchable(true);
    container_config.setTouchable(false);

    mainScreen_WithSTARTViewBase::setupScreen();
}

void mainScreen_WithSTARTView::tearDownScreen()
{
    mainScreen_WithSTARTViewBase::tearDownScreen();
}

void mainScreen_WithSTARTView::handleTickEvent()
{
    /* clock tick event */
    static int tickCount = 0;

    tickCount++;
    alarms = presenter->getalarminfo();
    uint8_t alarmpending = presenter->getalarmpending();

    /* alarm update */
    if((alarms.status == 1) && alarmpending)
    {
        if (presenter->GetLock() == 1)
        {
            UnlockButton.setVisible(0);
            UnlockButton.invalidate();
            presenter->SaveLock(0);
            backtomain1();
        }
        gotoalarm();
        if ((alarmborder == 0)&& ((tickCount % 20) == 0))
        {
            boxWithBorder1.setAlpha(0);
            alarmPopup.setShadeColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
            alarmborder = 1;
        }   
        else if((alarmborder == 1) && ((tickCount % 20) == 0))
        {
            boxWithBorder1.setAlpha(255);
            alarmPopup.setShadeColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
            alarmborder = 0;
        }
        boxWithBorder1.invalidate();

    }

    else
    {


        if(presenter->geteventpending())
        {
        	gotoeveentpopup();
        }

        if (presenter->purgeget())
        {
            PurgepopUp.setVisible(true);
            PurgepopUp.setTouchable(true);
            if(presenter->getPerfusionmode() != PURGE)
            	PurgeButton.setTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0), touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
            PurgepopUp.invalidate();
        }
        if (presenter->GetLock() == 1)
        {
            UnlockButton.setVisible(1);
            UnlockButton.invalidate();
            container_main.setTouchable(0);
            container_main.invalidate();
            PurgepopUp.setTouchable(false);
            PurgepopUp.invalidate();
            eventPopup.setTouchable(false);
            eventPopup.invalidate();
        }

		currenttime = presenter->getCurrentTime();
		Unicode::snprintf(textclockBuffer1, TEXTCLOCKBUFFER1_SIZE, "%02d", currenttime.hours);
		Unicode::snprintf(textclockBuffer2, TEXTCLOCKBUFFER2_SIZE, "%02d", currenttime.minutes);
		Unicode::snprintf(textclocksecBuffer, TEXTCLOCKSEC_SIZE, "%02d", currenttime.seconds);
		textclock.invalidate();
		textclocksec.invalidate();
		battery = presenter->getbatteryinfo();
		boxProgress1.setValue(battery.charge_level);

		if (battery.charge_level < 30)
			boxProgress1.setColor(touchgfx::Color::getColorFrom24BitRGB(200, 200, 0));
		else if (battery.charge_level < 10)
			boxProgress1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
		else
			boxProgress1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));

		if (battery.power_source == 2)
			scalableImage1_1.setVisible(false);
		else
			scalableImage1_1.setVisible(true);

		scalableImage1_1.invalidate();
		boxProgress1.invalidate();

		pressuregauge();

	    volumeleft = presenter->getvolumeleft();
	    timeleft = presenter->gettimeleft();
	    float injected = (float)volume.value + ((float)volume.scale/10) - ((float)volumeleft.value + ((float)volumeleft.scale/10));
	    volumeleft.value = injected;
	    volumeleft.scale = (injected - (int)injected) * 10;
	    Unicode::snprintf(textArea3Buffer, TEXTAREA3_SIZE, "%d.%d", volumeleft.value, volumeleft.scale);
		Unicode::snprintf(textArea3_1_1Buffer1, TEXTAREA3_1_1BUFFER1_SIZE, "%dh", timeleft.hours);
		Unicode::snprintf(textArea3_1_1Buffer2, TEXTAREA3_1_1BUFFER2_SIZE, " %dmin", timeleft.minutes);
		textArea3.invalidate();
		textArea3_1_1.invalidate();
		updatesyringestatus();
    }
}

void mainScreen_WithSTARTView::gotoconfigue()
{
    container_main.setVisible(false);
    container_main.setTouchable(false);
    container_config.setVisible(true);
    container_config.setTouchable(true);
    container_main.invalidate();
    container_config.invalidate();
}

void mainScreen_WithSTARTView::gotoalarm()
{
    container_main.setVisible(false);
    container_main.setTouchable(false);
    container_config.setVisible(false);
    container_config.setTouchable(false);
    alarmPopup.setVisible(true);
    alarmPopup.setTouchable(true);
    container_main.invalidate();
    container_config.invalidate();
    alarmPopup.invalidate();
    uint8_t state = presenter->getalarmpending();
    displayalarmtext(state);
}

void mainScreen_WithSTARTView::backtomain1()
{
    container_main.setVisible(true);
    container_main.setTouchable(true);
    container_config.setVisible(false);
    container_config.setTouchable(false);
    container_main.invalidate();
    container_config.invalidate();
    Mode.setTouchable(false);
}

void mainScreen_WithSTARTView::outofpopup()
{
    container_main.setVisible(true);
    container_main.setTouchable(true);
    container_config.setVisible(false);
    container_config.setTouchable(false);
    alarmPopup.setVisible(false);
    alarmPopup.setTouchable(false);
    container_main.invalidate();
    container_config.invalidate();
    alarmPopup.invalidate();
    presenter->savealarmpending(0);
    displayalarmtext(presenter->getalarmpending());
}

void mainScreen_WithSTARTView::Namedrug(uint8_t drug1)
{ 
    switch (drug1) 
    {
    
    case 0:
        Unicode::snprintf(textAreadrugBuffer, TEXTAREADRUG_SIZE, "----");
        Unicode::snprintf(flexBtn_DrugBuffer,FLEXBTN_DRUG_SIZE, "----");
        break;
    case 1:
        Unicode::snprintf(textAreadrugBuffer, TEXTAREADRUG_SIZE, "Aciclovir");
        Unicode::snprintf(flexBtn_DrugBuffer, FLEXBTN_DRUG_SIZE, "Aciclovir");
        break;
    case 2:
        Unicode::snprintf(textAreadrugBuffer, TEXTAREADRUG_SIZE, "Actrapide");
        Unicode::snprintf(flexBtn_DrugBuffer, FLEXBTN_DRUG_SIZE, "Actrapide");
        break;
    case 3:
        Unicode::snprintf(textAreadrugBuffer, TEXTAREADRUG_SIZE, "Actilyse");
        Unicode::snprintf(flexBtn_DrugBuffer, FLEXBTN_DRUG_SIZE, "Actilyse");
        break;
    case 4:
        Unicode::snprintf(textAreadrugBuffer, TEXTAREADRUG_SIZE, "Adrenaline");
        Unicode::snprintf(flexBtn_DrugBuffer, FLEXBTN_DRUG_SIZE, "Adrenaline");
        break;
    case 5:
        Unicode::snprintf(textAreadrugBuffer, TEXTAREADRUG_SIZE, "Aggrastat");
        Unicode::snprintf(flexBtn_DrugBuffer, FLEXBTN_DRUG_SIZE, "Aggrastat");
        break;
    case 6:
        Unicode::snprintf(textAreadrugBuffer, TEXTAREADRUG_SIZE, "Altiazem");
        Unicode::snprintf(flexBtn_DrugBuffer, FLEXBTN_DRUG_SIZE, "Altiazem");
        break;
    case 7:
        Unicode::snprintf(textAreadrugBuffer, TEXTAREADRUG_SIZE, "Amikacine");
        Unicode::snprintf(flexBtn_DrugBuffer, FLEXBTN_DRUG_SIZE, "Amikacine");
        break;
    case 8:
        Unicode::snprintf(textAreadrugBuffer, TEXTAREADRUG_SIZE, "Amiodarone");
        Unicode::snprintf(flexBtn_DrugBuffer, FLEXBTN_DRUG_SIZE, "Amiodarone");
        break;
    case 9:
        Unicode::snprintf(textAreadrugBuffer, TEXTAREADRUG_SIZE, "Ventolin");
        Unicode::snprintf(flexBtn_DrugBuffer, FLEXBTN_DRUG_SIZE, "Ventolin");
        break;

    default:
        Unicode::snprintf(textAreadrugBuffer, TEXTAREADRUG_SIZE, "------");
        Unicode::snprintf(flexBtn_DrugBuffer, FLEXBTN_DRUG_SIZE, "------");
    }
    flexBtn_Drug.invalidate();
    textAreadrug.invalidate();

}

void mainScreen_WithSTARTView::ratevar()
{
    presenter->saveinputdestinsation(1);
}
void mainScreen_WithSTARTView::KVOSet()
{
    presenter->saveinputdestinsation(4);

}
void mainScreen_WithSTARTView::bolusSet()
{
    presenter->saveinputdestinsation(5);

}
void mainScreen_WithSTARTView::ratevarvolume()
{
    presenter->saveinputdestinsation(2);

}

void mainScreen_WithSTARTView::setVTBI()
{
    presenter->saveinputdestinsation(3);
}

/* screen init */
void mainScreen_WithSTARTView::writeinmain()
{
    alarmborder = 0;
    rate = presenter->getrate();
    volume = presenter->getvolume();
    volumeVTBI = presenter->getinfusionvolume();
    pressureLow = presenter->getpressureLow();
    pressureMedium = presenter->getpressureMedium();
    pressureHigh= presenter->getpressureHigh();
    bolus = presenter->getbolus();
    KVO = presenter->getKVO();
    currenttime = presenter->getCurrentTime();
    perfusiontime = presenter->getPerfusiontime();
    battery = presenter->getbatteryinfo();
    volumeleft = presenter->getvolumeleft();
    timeleft = presenter->gettimeleft();

    SetupDisplayMode();

    /* battery charge level */
    boxProgress1.setValue(battery.charge_level);

    /* battery bar color*/
    if (battery.charge_level < 30)
        boxProgress1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 150, 0));
    else if (battery.charge_level < 30)
        boxProgress1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
    else 
        boxProgress1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));

    /* battery charging state */
    if (battery.power_source == 2)
        scalableImage1_1.setVisible(false);
    else 
        scalableImage1_1.setVisible(true);

    scalableImage1_1.invalidate();
    boxProgress1.invalidate();

    // write perfusion time
    Unicode::snprintf(flexBtn_timeBuffer1, FLEXBTN_TIMEBUFFER1_SIZE, "%02d", perfusiontime.hours);
    Unicode::snprintf(textArea4_2Buffer1, TEXTAREA4_2BUFFER1_SIZE, "%02d", perfusiontime.hours);
    Unicode::snprintf(flexBtn_timeBuffer2, FLEXBTN_TIMEBUFFER2_SIZE, "%02d", perfusiontime.minutes);
    Unicode::snprintf(textArea4_2Buffer2, TEXTAREA4_2BUFFER2_SIZE, "%02d", perfusiontime.minutes);
    flexBtn_time.invalidate();
    textArea4_2.invalidate();

    Unicode::snprintf(pressuretextBuffer, PRESSURETEXT_SIZE, "%d", pressureLow);
    Unicode::snprintf(flexBtn_occlusionlevelBuffer1, FLEXBTN_OCCLUSIONLEVELBUFFER1_SIZE, "%d", pressureHigh);
    Unicode::snprintf(flexBtn_occlusionlevelBuffer2, FLEXBTN_OCCLUSIONLEVELBUFFER2_SIZE, "%d", pressureMedium);
    pressuretext.invalidate();
    flexBtn_occlusionlevel.invalidate();

    Unicode::snprintf(flexBtn_bolusBuffer, FLEXBTN_BOLUS_SIZE, "%d.%d", bolus.value, bolus.scale);
    flexBtn_bolus.invalidate();

    Unicode::snprintf(flexBtn_KVOrateBuffer, FLEXBTN_KVORATE_SIZE, "%d.%d", KVO.value, KVO.scale);
    flexBtn_KVOrate.invalidate();            

    Unicode::snprintf(textArearateBuffer, TEXTAREARATE_SIZE, "%d.%d", rate.value, rate.scale);
    Unicode::snprintf(flexbtn_RateBuffer, FLEXBTN_RATE_SIZE, "%d.%d", rate.value, rate.scale);
    textArearate.invalidate();
    flexbtn_Rate.invalidate();

    Unicode::snprintf(textArea_volumeBuffer,TEXTAREA_VOLUME_SIZE, "%d.%d", volume.value, volume.scale);
    Unicode::snprintf(flexBtn_volumeBuffer,FLEXBTN_VOLUME_SIZE, "%d.%d", volume.value, volume.scale);
    textArea_volume.invalidate();
    flexBtn_volume.invalidate();

    Unicode::snprintf(flexBtn_VTBIBuffer, FLEXBTN_VTBI_SIZE, "%d.%d", volumeVTBI.value, volumeVTBI.scale);
    flexBtn_VTBI.invalidate();

    patientnamevar = getpatientname();
    for (uint8_t i = 0; i < strlen(patientnamevar); i++)
    {
        touchgfx_printf("%c\n", *(patientnamevar + i));
        Unicode::snprintf(patientnameBuffer + i, PATIENTNAME_SIZE - i, "%c", *(patientnamevar + i));
    }
    patientname.invalidate();
    
    Unicode::snprintf(textArea3Buffer, TEXTAREA3_SIZE, "%d.%d", volumeleft.value, volumeleft.scale);
    Unicode::snprintf(textArea3_1_1Buffer1, TEXTAREA3_1_1BUFFER1_SIZE, "%d", timeleft.hours);
    Unicode::snprintf(textArea3_1_1Buffer2, TEXTAREA3_1_1BUFFER2_SIZE, "%d", timeleft.minutes);
    textArea3.invalidate();
    textArea3_1_1.invalidate();
}


char* mainScreen_WithSTARTView::getpatientname(void)
{
    return presenter->getpatientname();
}

void mainScreen_WithSTARTView::updatesyringestatus(void)
{
    status = presenter->getstatus();
    mode = presenter->getPerfusionmode();
    if (status)
    {
    	Syringe.setVisible(true);
    	Syringe.setTouchable(true);
    	Syringeimage.setVisible(true);
    	Syringeimage.invalidate();
    	Syringe.invalidate();
        if ((mode == STOP) || (mode == ALARM))
        {
        	textArea4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 0));
        	textArea4.invalidate();
            btn_Start.setVisible(true);
            box_start.setVisible(true);
            Mode.setVisible(true);
            boxmode.setVisible(true);
            btn_NO_syringe_detected.setVisible(false);
            btn_Stop.setVisible(false);
            boxstop.setVisible(false);

            btn_Start.setTouchable(true);
            btn_NO_syringe_detected.setTouchable(false);
            Mode.setTouchable(false);
            btn_Stop.setTouchable(false);

            textArearate.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
            Unicode::snprintf(textArearateBuffer, TEXTAREARATE_SIZE, "%d.%d", rate.value, rate.scale);

            boxmode.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));

            textArearate.invalidate();

            Mode.invalidate();
            btn_Start.invalidate();
            btn_NO_syringe_detected.invalidate();
            btn_Stop.invalidate();

            box_start.invalidate();
            boxmode.invalidate();
            boxstop.invalidate();
        }
        else if (mode == INFUSION)
        {
        	textArea4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
        	textArea4.invalidate();
            btn_Stop.setVisible(true);
            boxstop.setVisible(true);
            Mode.setVisible(true);
            boxmode.setVisible(true);
            btn_NO_syringe_detected.setVisible(false);
            btn_Start.setVisible(false);
            box_start.setVisible(false);

            btn_Start.setTouchable(false);
            btn_NO_syringe_detected.setTouchable(false);
            Mode.setTouchable(true);
            btn_Stop.setTouchable(true);

            textArearate.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
            Unicode::snprintf(textArearateBuffer, TEXTAREARATE_SIZE, "%d.%d", rate.value, rate.scale);

            boxmode.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));

            textArearate.invalidate();

            Mode.invalidate();
            btn_Start.invalidate();
            btn_NO_syringe_detected.invalidate();
            btn_Stop.invalidate();

            box_start.invalidate();
            boxmode.invalidate();
            boxstop.invalidate();
        }
        else if (mode == BOLUS)
        {
        	textArea4.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
        	textArea4.invalidate();
            Unicode::snprintf(textArearateBuffer, TEXTAREARATE_SIZE, "%d.%d", bolus.value, bolus.scale);
            Mode.setTouchable(true);
            boxmode.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
            btn_NO_syringe_detected.setVisible(false);
            btn_Start.setVisible(false);
            box_start.setVisible(false);

            btn_Start.setTouchable(false);
            btn_NO_syringe_detected.setTouchable(false);

            btn_Start.invalidate();
            btn_NO_syringe_detected.invalidate();

            box_start.invalidate();
            textArearate.invalidate();
            Mode.invalidate();
            boxmode.invalidate();
        }
        else if (mode == 5)
                {
                	textArea4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
                	textArea4.invalidate();
                    btn_Stop.setVisible(true);
                    boxstop.setVisible(true);
                    Mode.setVisible(true);
                    boxmode.setVisible(true);
                    btn_NO_syringe_detected.setVisible(false);
                    btn_Start.setVisible(false);
                    box_start.setVisible(false);

                    btn_Start.setTouchable(false);
                    btn_NO_syringe_detected.setTouchable(false);
                    Mode.setTouchable(true);
                    btn_Stop.setTouchable(true);

                    textArearate.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
                    Unicode::snprintf(textArearateBuffer, TEXTAREARATE_SIZE, "%d.%d", KVO.value, KVO.scale);

                    boxmode.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));

                    textArearate.invalidate();

                    Mode.invalidate();
                    btn_Start.invalidate();
                    btn_NO_syringe_detected.invalidate();
                    btn_Stop.invalidate();

                    box_start.invalidate();
                    boxmode.invalidate();
                    boxstop.invalidate();
                }
    }
    else if(!status)
    {
    	Syringe.setVisible(false);
    	Syringe.setTouchable(false);
    	Syringeimage.setVisible(false);
    	Syringeimage.invalidate();
    	Syringe.invalidate();

    	textArea4.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
        box_start.setVisible(true);
        Mode.setVisible(true);
        boxmode.setVisible(true);
        btn_NO_syringe_detected.setVisible(true);
        btn_Stop.setVisible(false);
        boxstop.setVisible(false);
        btn_Start.setVisible(false);

        btn_Start.setTouchable(false);
        btn_NO_syringe_detected.setTouchable(true);
        Mode.setTouchable(false);
        btn_Stop.setTouchable(false);

        textArearate.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
        Unicode::snprintf(textArearateBuffer, TEXTAREARATE_SIZE, "%d.%d", rate.value, rate.scale);

        boxmode.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));

        textArearate.invalidate();

        Mode.invalidate();
        btn_Start.invalidate();
        btn_NO_syringe_detected.invalidate();
        btn_Stop.invalidate();

        box_start.invalidate();
        boxmode.invalidate();
        boxstop.invalidate();
    }
}


void mainScreen_WithSTARTView::startperfusion()
{
    if (((rate.scale == 0) && (rate.value == 0)) || ((volume.value == 0)&&(volume.scale == 0)) || ((perfusiontime.hours == 0) && (perfusiontime.minutes == 0) && (perfusiontime.seconds == 0)))
    {
        gotoalarm();
        Unicode::snprintf(alarmBuffer, ALARM_SIZE, "Missing input");
        Unicode::snprintf(ActionBuffer, ACTION_SIZE, "");
        Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, "");
        alarm.invalidate();
        Action.invalidate();
        Description.invalidate();
    }
    else 
    {
        if ((bolus.value == 0) && (bolus.scale == 0))
        {
            bolus = rate;
            presenter->savebolus(bolus);
        }
        if ((KVO.value == 0) && (KVO.scale == 0))
        {
            KVO = {0, 1};
            presenter->saveKVO(KVO); 
        }
        presenter->savePerfusionmode(INFUSION);
    }
}

void mainScreen_WithSTARTView::changemode()
{
    if (mode == INFUSION)
    {
       presenter->savePerfusionmode(BOLUS);
    }
    if (mode == BOLUS)
    {
        presenter->savePerfusionmode(INFUSION);
    }
}

void mainScreen_WithSTARTView::stopperfusion()
{
    presenter->savePerfusionmode(STOP);
}

void mainScreen_WithSTARTView::purgeClicked()
{
    static uint8_t state = 0;
    if (!state)
    {
        PurgeButton.setTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
        state = 1;
        presenter->savePerfusionmode(PURGE);
    }
    else
    {
        PurgeButton.setTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0), touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
        state = 0; 
        presenter->savePerfusionmode(STOP);
    }
    PurgeButton.invalidate();
}

void mainScreen_WithSTARTView::Closepurgepopup()
{
    PurgeButton.setTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
    PurgeButton.invalidate();
    PurgepopUp.setVisible(false);
    PurgepopUp.invalidate();
    backtomain1();
    PurgeButton.invalidate();
    presenter->savepurge(0);   
    presenter->savePerfusionmode(STOP);
    presenter->savevolume({0, 0});
}

void mainScreen_WithSTARTView::pressuregauge()
{
    uint16_t temp;
    if (presenter->getcurrentpressure() < presenter->getpressureLow())
    {
        temp = ((presenter->getcurrentpressure() * 50) / presenter->getpressureLow());
        iconGreen.setVisible(true);
        iconYellow.setVisible(false);
        iconRed.setVisible(false);
        gauge.updateValue(temp, 20);
        iconGreen.invalidate();
        iconYellow.invalidate();
        iconRed.invalidate();
    }
    else if ((presenter->getcurrentpressure() > presenter->getpressureLow()) && (presenter->getcurrentpressure() < presenter->getpressureMedium()))
    {
        temp = (((presenter->getcurrentpressure() - presenter->getpressureLow()) * (82 - 50)) / presenter->getpressureMedium());
        iconGreen.setVisible(false);
        iconYellow.setVisible(true);
        iconRed.setVisible(false);
        gauge.updateValue(50 + temp, 20);
        iconGreen.invalidate();
        iconYellow.invalidate();
        iconRed.invalidate();
    }
    else if ((presenter->getcurrentpressure() > presenter->getpressureMedium()))
    {
        temp = (((presenter->getcurrentpressure() - presenter->getpressureMedium()) * (100 - 82)) / presenter->getpressureHigh());
        iconGreen.setVisible(false);
        iconYellow.setVisible(false);
        iconRed.setVisible(true);
        gauge.updateValue(82 + temp, 20);
        iconGreen.invalidate();
        iconYellow.invalidate();
        iconRed.invalidate();
    }
    
    gauge.invalidate();
}

void mainScreen_WithSTARTView::SetupDisplayMode(void)
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
        BackendChildren.setVisible(2);
    }
    else
    {
        backend.setVisible(1);
        BackendBlack.setVisible(0);
        BackendChildren.setVisible(0);
    }
}

void mainScreen_WithSTARTView::displayalarmtext(uint8_t state)
{
    int switchcase = alarms.alarmSources;
    switch (switchcase)
    {
    case OVERPRESSURE:
        if (Texts::getLanguage() == GB)
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, oclusion_text_english);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, oclusion_action_english);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, oclusion_description_english);
        }
        else
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, oclusion_text_frensh);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, oclusion_action_frensh);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, oclusion_description_frensh);
        }
        break;
    case BATTERY_OVERCURRENT:
        if (Texts::getLanguage() == GB)
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, battovc_text_english);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, battovc_action_english);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, battovc_description_english);
        }
        else
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, battovc_text_frensh);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, battovc_action_frensh);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, battovc_description_frensh);
        }
        break;
    case BATTERY_CHHARGE_DEPLETED:
        if (Texts::getLanguage() == GB)
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, battcxpld_text_english);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, battcdpld_action_english);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, battcdpld_description_english);
        }
        else
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, battcdpld_text_frensh);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, battcdpld_action_frensh);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, battcdpld_description_frensh);
        }
        break;
    case BATTERY_OVERHEAT:
        if (Texts::getLanguage() == GB)
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, battovh_text_english);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, battovh_action_english);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, battovh_description_english);
        }
        else
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, battovh_text_frensh);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, battovh_action_frensh);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, battovh_description_frensh);
        }
        break;
    case BATTERY_UNDERHEAT:
        if (Texts::getLanguage() == GB)
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, battunh_text_english);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, battunh_action_english);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, battunh_description_english);
        }
        else
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, battunh_text_frensh);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, battunh_action_frensh);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, battunh_description_frensh);
        }
        break;
    case BATTERY_LOW_CHARGE:
        if (Texts::getLanguage() == GB)
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, battlov_text_english);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, battlov_action_english);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, battlov_description_english);
        }
        else
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, battlov_text_frensh);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, battlov_action_frensh);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, battlov_description_frensh);
        }
        break;
    case BATTERY_CONTACT_FAILURE:
        if (Texts::getLanguage() == GB)
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, battcontactfai_text_english);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, battcontactfai_action_english);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, battcontactfai_description_english);
        }
        else
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, battcontactfai_text_frensh);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, battcontactfai_action_frensh);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, battcontactfai_description_frensh);
        }
        break;
    case BATTERY_UNDERCURRENT:
        if (Texts::getLanguage() == GB)
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, battunc_text_english);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, battunc_action_english);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, battunc_description_english);
        }
        else
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, battunc_text_frensh);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, battunc_action_frensh);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, battunc_description_frensh);
        }
        break;
    case BATTERTY_CHARGE_TIMEOUT:
        if (Texts::getLanguage() == GB)
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, batttmout_text_english);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, batttmout_action_english);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, batttmout_description_english);
        }
        else
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, batttmout_text_frensh);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, batttmout_action_frensh);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, batttmout_description_frensh);
        }
        break;
    case MOTOR_THERMAL_OVERHEAT:
        if (Texts::getLanguage() == GB)
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, motorovh_text_english);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, motorovh_action_english);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, motorovh_description_english);
        }
        else
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, motorovh_text_frensh);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, motorovh_action_frensh);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, motorovh_description_frensh);
        }
        break;
    case MOTOR_THERMAL_SHUTDOWN:
        if (Texts::getLanguage() == GB)
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, motorthermalshut_text_english);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, motorthermalshut_action_english);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, motorthermalshut_description_english);
        }
        else
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, motorthermalshut_text_frensh);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, motorthermalshut_action_frensh);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, motorthermalshut_description_frensh);
        }
        break;
    case MOTOR_OVERCURRENT:
        if (Texts::getLanguage() == GB)
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, motorovc_text_english);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, motorovc_action_english);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, motorovc_description_english);
        }
        else
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, motorovc_text_frensh);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, motorovc_action_frensh);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, motorovc_description_frensh);
        }
        break;
    case MOTOR_UNDERVOLTAGE:
        if (Texts::getLanguage() == GB)
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, motorundv_text_english);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, motorundv_action_english);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, motorundv_description_english);
        }
        else
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, motorundv_text_frensh);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, motorundv_action_frensh);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, motorundv_description_frensh);
        }
        break;
    case MOTOR_DRIVER_NOT_RESPONSDING:
        if (Texts::getLanguage() == GB)
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, motornotresp_text_english);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, motornotresp_action_english);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, motornotresp_description_english);
        }
        else
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, motornotresp_text_frensh);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, motornotresp_action_frensh);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, motornotresp_description_frensh);
        }
        break;
    case INTERNAL_ERROR:
        if (Texts::getLanguage() == GB)
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, internalerror_text_english);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, internalerror_action_english);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, internalerror_description_english);
        }
        else
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, internalerror_text_frensh);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, internalerror_action_frensh);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, internalerror_description_frensh);
        }
        break;
    case POSTION_ERROR:
        if (Texts::getLanguage() == GB)
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, poserror_text_english);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, poserror_action_english);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, poserror_description_english);
        }
        else
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, poserror_text_frensh);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, poserror_action_frensh);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, poserror_description_frensh);
        }
        break;
    case SYRINGUE_NOT_DETECTED_ALARM:
        if (Texts::getLanguage() == GB)
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, syringeerror_text_english);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, syringeerror_action_english);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, syringeerror_description_english);
        }
        else
        {
            Unicode::snprintf(alarmBuffer, ALARM_SIZE, syringeerror_text_frensh);
            Unicode::snprintf(ActionBuffer, ACTION_SIZE, syringeerror_action_frensh);
            Unicode::snprintf(DescriptionBuffer, DESCRIPTION_SIZE, syringeerror_description_frensh);
        }
        break;
    default:

        break;
    }
    alarm.invalidate();
    Action.invalidate();
    Description.invalidate();
}

void mainScreen_WithSTARTView::MuteF(void)
{
	if(presenter->GetMute() == 0)
		presenter->SaveMute(1);
	else if(presenter->GetMute() == 1)
			presenter->SaveMute(0);
}


void mainScreen_WithSTARTView::outofeventpop()
{
    container_main.setVisible(true);
    container_main.setTouchable(true);
    container_config.setVisible(false);
    container_config.setTouchable(false);
    eventPopup.setVisible(false);
    eventPopup.setTouchable(false);
    container_main.invalidate();
    container_config.invalidate();
    eventPopup.invalidate();
    presenter->saveeventpending(0);
}

void mainScreen_WithSTARTView::gotoeveentpopup(void)
{
	eventPopup.setVisible(true);
    eventPopup.setTouchable(true);
    eventPopup.invalidate();
	displayeventtext();
}

void mainScreen_WithSTARTView::displayeventtext(void)
{
	int switchcase = presenter->geteventinfo();
	    switch (switchcase)
	    {
	    case PERFUSION_COMPLETE:
	        if (Texts::getLanguage() == GB)
	        {
	            Unicode::snprintf(EventBuffer, EVENT_SIZE, perfusioncomplete_text_english);

	        }
	        else
	        {
	            Unicode::snprintf(alarmBuffer, ALARM_SIZE, perfusioncomplete_text_frensh);

	        }
	        break;
	    case BOLUS_COMPLETE:
	        if (Texts::getLanguage() == GB)
	        {
	            Unicode::snprintf(EventBuffer, EVENT_SIZE, boluscomplete_text_english);

	        }
	        else
	        {
	            Unicode::snprintf(alarmBuffer, ALARM_SIZE, boluscomplete_text_frensh);

	        }
	        break;
	    case KVO_STARTED:
	        if (Texts::getLanguage() == GB)
	        {
	            Unicode::snprintf(EventBuffer, EVENT_SIZE, kvostart_text_english);

	        }
	        else
	        {
	            Unicode::snprintf(alarmBuffer, ALARM_SIZE, kvostart_text_frensh);

	        }
	        break;
	    case PURGE_COMPLETE:
	        if (Texts::getLanguage() == GB)
	        {
	            Unicode::snprintf(EventBuffer, EVENT_SIZE, purgecomplete_text_english);

	        }
	        else
	        {
	            Unicode::snprintf(alarmBuffer, ALARM_SIZE, purgecomplete_text_frensh);

	        }
	        break;
	    case SYRINGE_NEAR_EMPTY:
	        if (Texts::getLanguage() == GB)
	        {
	            Unicode::snprintf(EventBuffer, EVENT_SIZE, syringenearempty_text_english);

	        }
	        else
	        {
	            Unicode::snprintf(alarmBuffer, ALARM_SIZE, syringenearempty_text_frensh);

	        }
	        break;
	    case SYRINGE_EMPTY:
	        if (Texts::getLanguage() == GB)
	        {
	            Unicode::snprintf(EventBuffer, EVENT_SIZE, syringeempty_text_english);

	        }
	        else
	        {
	            Unicode::snprintf(alarmBuffer, ALARM_SIZE, syringeempty_text_frensh);

	        }
	        break;
	    case END_OF_TRAIL:
		        if (Texts::getLanguage() == GB)
		        {
		            Unicode::snprintf(EventBuffer, EVENT_SIZE, endoftrail_text_english);

		        }
		        else
		        {
		            Unicode::snprintf(alarmBuffer, ALARM_SIZE, endoftrail_text_frensh);

		        }
	        break;
	    case POWER_SOURCE_CHANGED:
		        if (Texts::getLanguage() == GB)
		        {
		            Unicode::snprintf(EventBuffer, EVENT_SIZE, powersourcechange_text_english);

		        }
		        else
		        {
		            Unicode::snprintf(alarmBuffer, ALARM_SIZE, powersourcechange_text_frensh);

		        }
	        break;
	    default:
	        break;
	    }
	    Event.invalidate();
}
