#include <gui/same_patient_screen/Same_PatientView.hpp>
#include <gui/same_patient_screen/Same_PatientPresenter.hpp>

Same_PatientPresenter::Same_PatientPresenter(Same_PatientView& v)
    : view(v)
{

}

void Same_PatientPresenter::activate()
{

}

void Same_PatientPresenter::deactivate()
{

}

void Same_PatientPresenter::AlarmOrEvent(void)
 {
        view.AlarmOrEvent();
}
