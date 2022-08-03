#include <gui/syringedetected_screen/syringedetectedView.hpp>

syringedetectedView::syringedetectedView()
{

}

void syringedetectedView::setupScreen()
{
	int progress = 0;
    ps_float volume = presenter->getVolume(), volumeleft = presenter->getVolumeleft();
	if(volume.value != 0)
		progress = (volumeleft.value * 100) / volume.value;
    uint16_t diameter = presenter->GetSyringeDiameter();

	SetupDisplayMode();

    Syringe.setValue(progress);

    Unicode::snprintf(SyrineDiameterBuffer, SYRINEDIAMETER_SIZE, "%d", diameter);
    Unicode::snprintf(InfusionVolumeBuffer, INFUSIONVOLUME_SIZE, "%d.%d", volume.value, volume.scale);
    Unicode::snprintf(VolumeLeftBuffer, VOLUMELEFT_SIZE, "%d.%d", volumeleft.value, volumeleft.scale);
    syringedetectedViewBase::setupScreen();
}

void syringedetectedView::tearDownScreen()
{
    syringedetectedViewBase::tearDownScreen();
}

void syringedetectedView::handleTickEvent(void)
{
	int progress = 0;
	ps_float volume = presenter->getVolume(), volumeleft = presenter->getVolumeleft();
	if (volume.value != 0)
		progress = (volumeleft.value * 100) / volume.value;
	uint16_t diameter = presenter->GetSyringeDiameter();

	Syringe.setValue(progress);
	Syringe.invalidate();
	Unicode::snprintf(SyrineDiameterBuffer, SYRINEDIAMETER_SIZE, "%d", diameter);
	Unicode::snprintf(VolumeLeftBuffer, VOLUMELEFT_SIZE, "%03d.%d", volumeleft.value, volumeleft.scale);
	SyrineDiameter.invalidate();
	VolumeLeft.invalidate();
}

void syringedetectedView::AlarmOrEvent(void)
{
    static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}

void syringedetectedView::SetupDisplayMode(void)
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
