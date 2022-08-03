#include <gui/oclusion_level_screen/Oclusion_levelView.hpp>

Oclusion_levelView::Oclusion_levelView()
{

}

void Oclusion_levelView::setupScreen()
{
	SetupDisplayMode();
    writeinmain();

    Oclusion_levelViewBase::setupScreen();
}

void Oclusion_levelView::tearDownScreen()
{
    Oclusion_levelViewBase::tearDownScreen();
}

void Oclusion_levelView::highpressure()
{
    presenter->saveinputdestination(61);
}

void Oclusion_levelView::mediumpressure()
{
    presenter->saveinputdestination(62);
}

void Oclusion_levelView::Lowpressure()
{
    presenter->saveinputdestination(63);
}

void Oclusion_levelView::writeinmain()
{
    pressureLow = presenter->getoclusionLow();
    pressureMedium = presenter->getoclusionMedium();
    pressureHigh = presenter->getoclusionHigh();


    Unicode::snprintf(low_pressure_btnBuffer, LOW_PRESSURE_BTN_SIZE, "%03d", pressureLow);
    Unicode::snprintf(medium_pressure_btnBuffer, MEDIUM_PRESSURE_BTN_SIZE, "%03d", pressureMedium);
    Unicode::snprintf(high_pressure_btnBuffer, HIGH_PRESSURE_BTN_SIZE, "%03d", pressureHigh);
    low_pressure_btn.invalidate();
    medium_pressure_btn.invalidate();
    high_pressure_btn.invalidate();

}

void Oclusion_levelView::SetupDisplayMode(void)
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

void Oclusion_levelView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}