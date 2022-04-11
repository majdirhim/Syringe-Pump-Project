#include <gui/newpatient_screen/NewPatientView.hpp>
#include <gui/newpatient_screen/NewPatientPresenter.hpp>

NewPatientPresenter::NewPatientPresenter(NewPatientView& v)
    : view(v)
{

}

void NewPatientPresenter::activate()
{

}

void NewPatientPresenter::deactivate()
{

}

uint8_t NewPatientPresenter::getDisplayMode()
{
	return model->getDisplayMode();
}

void NewPatientPresenter::AlarmOrEvent(void)
 {
        view.AlarmOrEvent();
}

void NewPatientPresenter::saveKeyboardUser(uint8_t user)
{
	model->saveKeyboardUser(user);
}

Patient_dataT NewPatientPresenter::getPatient(void)
{
	return model->getPatient();
}

void NewPatientPresenter::savePatientName(char* Name)
{
	model->savePatientName(Name);
}
