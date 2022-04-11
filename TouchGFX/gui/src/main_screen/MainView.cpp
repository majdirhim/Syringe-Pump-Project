#include <gui/main_screen/MainView.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/Texts.hpp>

MainView::MainView()
{

}

void MainView::setupScreen()
{
    setupScreenElement();
    MainViewBase::setupScreen();
}

void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

void MainView::setupScreenElement()
{
    touchgfx::Unicode::snprintf(TimetextAreaBuffer1, TIMETEXTAREABUFFER1_SIZE, "%02d", presenter->getCurrentTime().Hour);
    touchgfx::Unicode::snprintf(TimetextAreaBuffer2, TIMETEXTAREABUFFER2_SIZE, "%02d", presenter->getCurrentTime().Minute);

    if (strlen(presenter->getPatientName()) > 0)
    {
        touchgfx::Unicode::snprintf(NametextAreaBuffer, NAMETEXTAREA_SIZE, presenter->getPatientName());
    }
    
    switch (presenter->getBattery().PowerSource)
    {
    case SECTOR:
        ChargeSourceIndicator.setVisible(true);
        break;
    case BATTERY:
        ChargeSourceIndicator.setVisible(false);
        break;
    }

    switch (presenter->getBattery().BatteryChargingState)
    {
    case SECTOR:
        ChargeSourceIndicator.setVisible(true);
        break;
    case BATTERY:
        ChargeSourceIndicator.setVisible(false);
        break;
    default:
        break;
    }

    ChargeLevelIndicator.setWidth((presenter->getBattery().BatteryChargeLevel * 35) / 100);

    switch (presenter->getSyringeState())
    {
    case NOTDETECTED:
        SyringeNotPresentIndicator.setVisible(true);
        SyringePresentNotConfigured.setVisible(false);
        SyringePresentIndicator.setVisible(false);
        SyringeBtn.setTouchable(false);
        break;
    case NOTCONFIGURED:
        SyringeNotPresentIndicator.setVisible(false);
        SyringePresentNotConfigured.setVisible(true);
        SyringePresentIndicator.setVisible(false);
        SyringeBtn.setTouchable(true);
        break;
    case VALID :
        SyringeNotPresentIndicator.setVisible(false);
        SyringePresentNotConfigured.setVisible(false);
        SyringePresentIndicator.setVisible(true);
        SyringeBtn.setTouchable(true);
    default:
        break;
    }

    touchgfx::Unicode::snprintf(RateBtnBuffer, RATEBTN_SIZE, "%04d.%01d", presenter->getFlowRate().BeforeComma, presenter->getFlowRate().AfterComma);
    touchgfx::Unicode::snprintf(VolumeBtnBuffer, VOLUMEBTN_SIZE, "%04d.%01d", presenter->getTotalVolume().BeforeComma, presenter->getTotalVolume().AfterComma);
    touchgfx::Unicode::snprintf(TimeBtnBuffer1, TIMEBTNBUFFER1_SIZE, "%02d", presenter->getInfusionTIme().Hour);
    touchgfx::Unicode::snprintf(TimeBtnBuffer2, TIMEBTNBUFFER2_SIZE, "%02d", presenter->getInfusionTIme().Minute);
    touchgfx::Unicode::snprintf(PressuretextAreaBuffer, PRESSURETEXTAREA_SIZE, "%04d", presenter->getCurrentPressure());
    dynamicGraph1.addDataPoint(presenter->getCurrentPressure());
    dynamicGraph2.addDataPoint(presenter->getCurrentPressure());
    if (presenter->getCurrentPressure() < 400)
    {
        PressuretextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
        dynamicGraph1Line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
        dynamicGraph2Line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
        textbubble1.setText(presenter->getCurrentPressure(), 255, 255, 255);
    }
    else if (presenter->getCurrentPressure() < 600)
    {
        PressuretextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
        dynamicGraph1Line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
        dynamicGraph2Line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
        textbubble1.setText(presenter->getCurrentPressure(), 0, 255, 0);
    }
    else if (presenter->getCurrentPressure() < 800)
    {
        PressuretextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 0));
        dynamicGraph1Line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 0));
        dynamicGraph2Line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 0));
        textbubble1.setText(presenter->getCurrentPressure(), 255, 255, 0);
    }
    else
    {
        PressuretextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
        dynamicGraph1Line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
        dynamicGraph2Line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
        textbubble1.setText(presenter->getCurrentPressure(), 255, 0, 0);
    }

    if (presenter->getDrug().Id != 0)
    {
        touchgfx::Unicode::snprintf(DrugBtnBuffer, DRUGBTN_SIZE, presenter->getDrug().Name);

        switch (presenter->getDrug().ThreatLevel)
        {
        case NO_THREAT:
            DrugBtn.setWildcardTextColors(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255), touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
            break;
        case LOW_THREAT:
            DrugBtn.setWildcardTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
            break;
        case MEDIUM_THREAT:
            DrugBtn.setWildcardTextColors(touchgfx::Color::getColorFrom24BitRGB(255, 255, 0), touchgfx::Color::getColorFrom24BitRGB(255, 255, 0));
            break;
        case HIGH_THREAT:
            DrugBtn.setWildcardTextColors(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0), touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
            break;
        }
    }

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

    touchgfx::Unicode::snprintf(InjectedBuffer, INJECTED_SIZE, "%04d.%01d", presenter->getVolumeLeft().BeforeComma, presenter->getVolumeLeft().AfterComma);
    touchgfx::Unicode::snprintf(TimeLeftBuffer1, TIMEBTNBUFFER1_SIZE, "%02d", presenter->getTimeLeft().Hour);
    touchgfx::Unicode::snprintf(TimeLeftBuffer2, TIMEBTNBUFFER2_SIZE, "%02d", presenter->getTimeLeft().Minute);
}

void MainView::handleTickEvent()
{
    /* Events */
    if ((presenter->getPendingEventStatus()) && (presenter->getLatestEvent().EventState))
    {
        if (Counter % presenter->getLatestEvent().FlashPeriod == 0)
        {
            AlarmContainer.setVisible(true);
            touchgfx::Unicode::snprintf(AlarmTextAreaBuffer, ALARMTEXTAREA_SIZE, presenter->getEventTitle(presenter->getLatestEvent().EventSource));

            if (ColorState)
            {
                AlarmBox.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
                screenBorder1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
                ColorState = 0;
            }
            else
            {
                switch (presenter->getLatestEvent().EventType)
                {
                case NOTIFICATION:
                    AlarmBox.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
                    screenBorder1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
                    break;
                case ALERT:
                    AlarmBox.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 180, 0));
                    screenBorder1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 180, 0));
                    break;
                case ALARM:
                    AlarmBox.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
                    screenBorder1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
                    break;
                }
                ColorState = 1;
            }
            AlarmContainer.invalidate();
        }
    }
    /* Pressure Graph */
    if (Counter % 600 == 0)
    {
        Unicode::snprintf(PressuretextAreaBuffer, PRESSURETEXTAREA_SIZE, "%d", PressureVector[i]);
        dynamicGraph1.addDataPoint(PressureVector[i]);
        dynamicGraph2.addDataPoint(PressureVector[i]);
        if (PressureVector[i] < 400)
        {
            PressuretextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
            dynamicGraph1Line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
            dynamicGraph2Line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
            textbubble1.setText(PressureVector[i], 255, 255, 255);
        }
        else if (PressureVector[i] < 600)
        {
            PressuretextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
            dynamicGraph1Line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
            dynamicGraph2Line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
            textbubble1.setText(PressureVector[i], 0, 255, 0);
        }
        else if (PressureVector[i] < 800)
        {
            PressuretextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 0));
            dynamicGraph1Line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 0));
            dynamicGraph2Line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 0));
            textbubble1.setText(PressureVector[i], 255, 255, 0);
        }
        else
        {
            PressuretextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
            dynamicGraph1Line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
            dynamicGraph2Line1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
            textbubble1.setText(PressureVector[i], 255, 0, 0);
        }
        PressuretextArea.invalidate();
        dynamicGraph1.invalidate();
        dynamicGraph2.invalidate();
        i++;
    }
    Counter++;
    if (i == 4)
        i = 0;
}

void MainView::InitKeyboard(uint8_t value)
{
    presenter->saveKeyboardUser(value);
    static_cast<FrontendApplication*>(Application::getInstance())->gotoKeyboardNbScreenWipeTransitionSouth();
}

void MainView::reactToClick(AbstractDataGraph::GraphClickEvent value)
{
    textbubble2.moveTo(dynamicGraph1.getX() + dynamicGraph1.indexToScreenX(value.index) + dynamicGraph1.getGraphAreaPaddingLeft() + (int16_t) 23
        , dynamicGraph1.getY() + dynamicGraph1.indexToScreenY(value.index) + dynamicGraph1.getGraphAreaPaddingBottom());

    textbubble2.setText(dynamicGraph1.indexToDataPointYAsInt(value.index), 255, 255, 255);
}

void MainView::CloseAlarmPopUp()
{
    presenter->savePendingEventStatus();
    AlarmContainer.setVisible(false);
    AlarmContainer.invalidate();
}

void MainView::MuteSound()
{
    presenter->saveMuteStatus();
}

void MainView::batteryUpdated(void)
{
    switch (presenter->getBattery().PowerSource)
    {
    case SECTOR:
        ChargeSourceIndicator.setVisible(true);
        break;
    case BATTERY:
        ChargeSourceIndicator.setVisible(false);
        break;
    }

    switch (presenter->getBattery().BatteryChargingState)
    {
    case CHARGING:
        ChargeStateIndicator.setVisible(true);
        break;
    case NOT_CHARGING:
        ChargeStateIndicator.setVisible(false);
        break;
    default:
        break;
    }

    ChargeLevelIndicator.setWidth((presenter->getBattery().BatteryChargeLevel * 35) / 100);
}

void MainView::currentTimeUpdated(void)
{
    touchgfx::Unicode::snprintf(TimeBtnBuffer1, TIMEBTNBUFFER1_SIZE, "%02d", presenter->getInfusionTIme().Hour);
    touchgfx::Unicode::snprintf(TimeBtnBuffer2, TIMEBTNBUFFER2_SIZE, "%02d", presenter->getInfusionTIme().Minute);
}

void MainView::syringeUpdated(void)
{
    switch (presenter->getSyringeState())
    {
    case NOTDETECTED:
        SyringeNotPresentIndicator.setVisible(true);
        SyringePresentNotConfigured.setVisible(false);
        SyringePresentIndicator.setVisible(false);
        SyringeBtn.setTouchable(false);
        break;
    case NOTCONFIGURED:
        SyringeNotPresentIndicator.setVisible(false);
        SyringePresentNotConfigured.setVisible(true);
        SyringePresentIndicator.setVisible(false);
        SyringeBtn.setTouchable(true);
        break;
    case VALID:
        SyringeNotPresentIndicator.setVisible(false);
        SyringePresentNotConfigured.setVisible(false);
        SyringePresentIndicator.setVisible(true);
        SyringeBtn.setTouchable(true);
    default:
        break;
    }
}

void MainView::motorStatusUpdated(void)
{
    if (CurrentMode != presenter->getMode())
    {
        CurrentMode = presenter->getMode();
        switch (presenter->getMode())
        {
        case(STOP_M):
        case(ALARM_M):
                MainViewBase::InfusionStopingTransition();
                break;
        case(KVO_M):

            break;
        }
    }

    touchgfx::Unicode::snprintf(InjectedBuffer, INJECTED_SIZE, "%04d.%01d", presenter->getVolumeLeft().BeforeComma, presenter->getVolumeLeft().AfterComma);
    touchgfx::Unicode::snprintf(TimeLeftBuffer1, TIMEBTNBUFFER1_SIZE, "%02d", presenter->getTimeLeft().Hour);
    touchgfx::Unicode::snprintf(TimeLeftBuffer2, TIMEBTNBUFFER2_SIZE, "%02d", presenter->getTimeLeft().Minute);
    Injected.invalidate();
    TimeLeft.invalidate();
}

void MainView::ChangeMotorMode(uint8_t value)
{
    RequestedMode = value;
    switch (value)
    {
    case STOP_M:
        presenter->saveMode(STOP_M);
        MainViewBase::InfusionStopingTransition();
        break;
    case INFUSION_M:
        if (checkBeforeInfusion())
        {
            presenter->saveMode(INFUSION_M);
            RateBtn.setWildcardTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0), touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
            invalidate();
            MainViewBase::InfusionStartingTransition();
        }
        break;
    case BOLUS_M:
        presenter->saveMode(BOLUS_M);
        RateBtn.setWildcardTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0), touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
        break;
    case PAUSE_M:
        break;
    case PURGE_M:
        checkBeforePurge();
        break;
    case INFUSION_STATION_M:
        checkBeforeInfusionStation();
        break;
    }
}

uint8_t MainView::checkBeforeInfusion()
{
    do {
        if (!checkSyringe())
            break;
        if ((!checkDrug()) && (!DrugCheckPass))
            break;
        if ((!checkVolume()))
            break;
        return 1;
    } while (0);

    return 0;
}

uint8_t MainView::checkBeforeInfusionStation()
{
    do {
        if (!checkSyringe())
            break;
        if (!checkVolume())
            break;
        if ((!checkDrug()) && (!DrugCheckPass))
            break;
        return 1;
    } while (0);

    return 0;
}

uint8_t MainView::checkBeforePurge()
{
    do {
        if (!checkSyringe())
            break;
        if (!checkVolume())
            break;
        if ((!checkDrug())&&(!DrugCheckPass))
            break;
        return 1;
    } while (0);

    return 0;
}

uint8_t MainView::checkSyringe()
{
    switch (presenter->getSyringeState())
    {
    case NOTDETECTED:
        if (touchgfx::Texts::getLanguage() == 0)
        {

        }
        else if (touchgfx::Texts::getLanguage() == 1)
        {

        }
        return 0;
        break;
    case NOTCONFIGURED:
        if (touchgfx::Texts::getLanguage() == 0)
        {

        }
        else if (touchgfx::Texts::getLanguage() == 1)
        {

        }
        break;
        return 0;
    case VALID:
        return 1;
        break;
    default:
        return 0;
        break;
    }
    return 0;
}

uint8_t MainView::checkDrug()
{
    if (presenter->getDrug().Id != 0)
    {
        if ((presenter->getDrug().MaxRate < presenter->getInfusionParameters().Flowrate) || (presenter->getDrug().MinRate > presenter->getInfusionParameters().Flowrate))
        {
            if (touchgfx::Texts::getLanguage() == 0)
            {

            }
            else if (touchgfx::Texts::getLanguage() == 1)
            {

            }
            return 0;
        }
    }
    return 1;
}

uint8_t MainView::checkVolume()
{
    if (presenter->getInfusionParameters().Flowrate == 0)
    {
        if (touchgfx::Texts::getLanguage() == 0)
        {

        }
        else if (touchgfx::Texts::getLanguage() == 1)
        {

        }
        return 0;
    }
    if (presenter->getInfusionParameters().TotalVolume == 0)
    {
        presenter->saveTotalVolume({ presenter->getSyringe().VolumeInvterval, 0 });
        touchgfx::Unicode::snprintf(InjectedBuffer, INJECTED_SIZE, "%04d.%01d", presenter->getVolumeLeft().BeforeComma, presenter->getVolumeLeft().AfterComma);
        touchgfx::Unicode::snprintf(VolumeBtnBuffer, VOLUMEBTN_SIZE, "%04d.%01d", presenter->getTotalVolume().BeforeComma, presenter->getTotalVolume().AfterComma);
        touchgfx::Unicode::snprintf(TimeBtnBuffer1, TIMEBTNBUFFER1_SIZE, "%02d", presenter->getInfusionTIme().Hour);
        touchgfx::Unicode::snprintf(TimeBtnBuffer1, TIMEBTNBUFFER2_SIZE, "%02d", presenter->getInfusionTIme().Minute);
        touchgfx::Unicode::snprintf(TimeLeftBuffer1, TIMELEFTBUFFER1_SIZE, "%02d", presenter->getTimeLeft().Hour);
        touchgfx::Unicode::snprintf(TimeLeftBuffer2, TIMELEFTBUFFER2_SIZE, "%02d", presenter->getTimeLeft().Minute);
    }

    if ((RequestedMode != INFUSION_STATION_M) && (presenter->getInfusionParameters().InfousionVolume > presenter->getInfusionParameters().TotalVolume))
    {
        if (touchgfx::Texts::getLanguage() == 0)
        {

        }
        else if (touchgfx::Texts::getLanguage() == 1)
        {

        }
        return 0;
    }

    return 1;
}
