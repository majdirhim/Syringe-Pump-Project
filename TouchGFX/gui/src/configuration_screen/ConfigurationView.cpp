#include <gui/configuration_screen/ConfigurationView.hpp>

ConfigurationView::ConfigurationView()
{

}

void ConfigurationView::setupScreen()
{
    ConfigBtn.setTouchable(false);
    setupDisplayMode();
    ConfigurationViewBase::setupScreen();
}

void ConfigurationView::tearDownScreen()
{
    ConfigurationViewBase::tearDownScreen();
}

void ConfigurationView::AlarmOrEvent()
{
    static_cast<FrontendApplication*>(Application::getInstance())->gotoMainScreenNoTransition();
}

void ConfigurationView::setupDisplayMode(void)
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

    touchgfx::Unicode::snprintf(RateBtnBuffer, RATEBTN_SIZE, "%04d.%01d", presenter->getFlowRate().BeforeComma, presenter->getFlowRate().AfterComma);
    touchgfx::Unicode::snprintf(VolumeBtnBuffer, VOLUMEBTN_SIZE, "%04d.%01d", presenter->getTotalVolume().BeforeComma, presenter->getTotalVolume().AfterComma);
    touchgfx::Unicode::snprintf(VTBIBtnBuffer, VTBIBTN_SIZE, "%04d.%01d", presenter->getInfusionVolume().BeforeComma, presenter->getInfusionVolume().AfterComma);
    touchgfx::Unicode::snprintf(BolusBtnBuffer, BOLUSBTN_SIZE, "%04d.%01d", presenter->getBolusRate().BeforeComma, presenter->getBolusRate().AfterComma);
    touchgfx::Unicode::snprintf(KVOBtnBuffer, KVOBTN_SIZE, "%04d.%01d", presenter->getKVORate().BeforeComma, presenter->getKVORate().AfterComma);
    touchgfx::Unicode::snprintf(HighThresholdValueTextAreaBuffer, HIGHTHRESHOLDVALUETEXTAREA_SIZE, "%04d", presenter->getPressureThresholds().HighThreshold);
    touchgfx::Unicode::snprintf(MediumThresholdValueTextAreaBuffer, MEDIUMTHRESHOLDVALUETEXTAREA_SIZE, "%04d", presenter->getPressureThresholds().MediumThreshold);
    touchgfx::Unicode::snprintf(LowThresholdValueTextAreaBuffer, LOWTHRESHOLDVALUETEXTAREA_SIZE, "%04d", presenter->getPressureThresholds().LowThreshold);
}

void ConfigurationView::InitKeyboard(uint8_t value)
{
    presenter->saveKeyboardUser(value);
    ConfigurationViewBase::InitKeyboard(value);
}

