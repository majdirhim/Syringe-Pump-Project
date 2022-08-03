#ifndef SAME_PATIENTVIEW_HPP
#define SAME_PATIENTVIEW_HPP

#include <gui_generated/same_patient_screen/Same_PatientViewBase.hpp>
#include <gui/same_patient_screen/Same_PatientPresenter.hpp>

class Same_PatientView : public Same_PatientViewBase
{
public:
    Same_PatientView();
    virtual ~Same_PatientView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void GetStoredParam();
    virtual void testdata();
    void SetupDisplayMode(void);
    virtual void AlarmOrEvent(void);
protected:
};

#endif // SAME_PATIENTVIEW_HPP
