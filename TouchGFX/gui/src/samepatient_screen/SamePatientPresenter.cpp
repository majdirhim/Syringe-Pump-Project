#include <gui/samepatient_screen/SamePatientView.hpp>
#include <gui/samepatient_screen/SamePatientPresenter.hpp>

SamePatientPresenter::SamePatientPresenter(SamePatientView& v)
    : view(v)
{

}

void SamePatientPresenter::activate()
{

}

void SamePatientPresenter::deactivate()
{

}

uint8_t SamePatientPresenter::getDisplayMode()
{
    return model->getDisplayMode();
}

void SamePatientPresenter::requestLastPatientData()
{
    model->requestLastPatientData();
}

uint8_t SamePatientPresenter::getPatientDataRequestState(void)
{
    return model->getPatientDataRequestState();
}

Patient_dataT SamePatientPresenter::getPatient(void)
{
    return model->getPatient();
}

void SamePatientPresenter::AlarmOrEvent(void)
{
    view.AlarmOrEvent();
}
