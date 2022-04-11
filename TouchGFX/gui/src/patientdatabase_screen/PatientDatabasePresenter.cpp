#include <gui/patientdatabase_screen/PatientDatabaseView.hpp>
#include <gui/patientdatabase_screen/PatientDatabasePresenter.hpp>

PatientDatabasePresenter::PatientDatabasePresenter(PatientDatabaseView& v)
    : view(v)
{

}

void PatientDatabasePresenter::activate()
{

}

void PatientDatabasePresenter::deactivate()
{

}

void PatientDatabasePresenter::AlarmOrEvent(void)
{
    view.AlarmOrEvent();
}

uint8_t PatientDatabasePresenter::getDisplayMode(void)
{
    return model->getDisplayMode();
}

void PatientDatabasePresenter::RequestPatientSearch(char * Name)
{
    model->RequestPatientSearch(Name);
}

uint8_t PatientDatabasePresenter::getPatientDataRequestState(void)
{
    return model->getPatientDataRequestState();
}

Patient_dataT PatientDatabasePresenter::getPatient()
{
    return model->getPatient();
}

void PatientDatabasePresenter::savePatientName(char* Name)
{
    model->savePatientName(Name);
}

