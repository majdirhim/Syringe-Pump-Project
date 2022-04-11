#include <gui/genderchoice_screen/GenderChoiceView.hpp>
#include <gui/genderchoice_screen/GenderChoicePresenter.hpp>

GenderChoicePresenter::GenderChoicePresenter(GenderChoiceView& v)
    : view(v)
{

}

void GenderChoicePresenter::activate()
{

}

void GenderChoicePresenter::deactivate()
{

}

uint8_t GenderChoicePresenter::getDisplayMode()
{
	return model->getDisplayMode();
}

void GenderChoicePresenter::AlarmOrEvent(void)
{
        view.AlarmOrEvent();
}

void GenderChoicePresenter::savePatientGender(uint8_t value)
{
	model->savePatientGender(value);
}
