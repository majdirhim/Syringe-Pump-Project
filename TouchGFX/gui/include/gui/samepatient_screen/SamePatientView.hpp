#ifndef SAMEPATIENTVIEW_HPP
#define SAMEPATIENTVIEW_HPP

#include <gui_generated/samepatient_screen/SamePatientViewBase.hpp>
#include <gui/samepatient_screen/SamePatientPresenter.hpp>

class SamePatientView : public SamePatientViewBase
{
public:
    SamePatientView();
    virtual ~SamePatientView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void AlarmOrEvent(void);
    void setupDisplayMode(void);
    virtual void RequestLastPatient();
    virtual void VerifyData();
    void displayPatient();
protected:
    Patient_dataT Patient;
};

#endif // SAMEPATIENTVIEW_HPP
