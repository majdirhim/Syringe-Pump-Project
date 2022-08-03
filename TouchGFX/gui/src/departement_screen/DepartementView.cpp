#include <gui/departement_screen/DepartementView.hpp>

DepartementView::DepartementView()
{

}

void DepartementView::setupScreen()
{
	SetupDisplayMode();
	deactivate();
	uint8_t Case = presenter->getdepartement();
	switch(Case)
	{
	case 0:
		btn_pediatrics.setTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
		btn_pediatrics.invalidate();
		break;
	case 1:
		btn_Emergency.setTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
			break;
	case 2:
		btn_neonatal.setTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
		btn_neonatal.invalidate();
			break;
	case 3:
		btn_icu.setTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
		btn_icu.invalidate();
			break;
	case 4:
		btn_maternity.setTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
		btn_maternity.invalidate();
			break;
	case 5:
		btn_other.setTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
		btn_other.invalidate();
			break;
	}
    DepartementViewBase::setupScreen();
}

void DepartementView::tearDownScreen()
{
    DepartementViewBase::tearDownScreen();
}

void DepartementView::SetupDisplayMode(void)
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

void DepartementView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}

void DepartementView::deactivate(void)
{
	btn_pediatrics.setTextColors(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
	btn_Emergency.setTextColors(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
	btn_neonatal.setTextColors(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
	btn_icu.setTextColors(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
	btn_maternity.setTextColors(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
	btn_other.setTextColors(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
	btn_pediatrics.invalidate();
	btn_Emergency.invalidate();
	btn_neonatal.invalidate();
	btn_icu.invalidate();
	btn_maternity.invalidate();
	btn_other.invalidate();
}


void DepartementView::peditrics()
{
	deactivate();
	presenter->savedepartement(0);
	btn_pediatrics.setTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
	btn_pediatrics.invalidate();
}

void DepartementView::emergency()
{
	deactivate();
	presenter->savedepartement(1);
	btn_Emergency.setTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
	btn_Emergency.invalidate();
}

void DepartementView::neonatal()
{
	deactivate();
	presenter->savedepartement(2);
	btn_neonatal.setTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
	btn_neonatal.invalidate();
}

void DepartementView::icu()
{
	deactivate();
	presenter->savedepartement(3);
	btn_icu.setTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
	btn_icu.invalidate();
}

void DepartementView::maternity()
{
	deactivate();
	presenter->savedepartement(4);
	btn_maternity.setTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
	btn_maternity.invalidate();
}

void DepartementView::other()
{
	deactivate();
	presenter->savedepartement(5);
	btn_other.setTextColors(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0), touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
	btn_other.invalidate();
}
