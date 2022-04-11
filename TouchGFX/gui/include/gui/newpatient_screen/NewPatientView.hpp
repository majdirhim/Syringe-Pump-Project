#ifndef NEWPATIENTVIEW_HPP
#define NEWPATIENTVIEW_HPP

#include <gui_generated/newpatient_screen/NewPatientViewBase.hpp>
#include <gui/newpatient_screen/NewPatientPresenter.hpp>

class NewPatientView : public NewPatientViewBase
{
public:
    NewPatientView();
    virtual ~NewPatientView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void AlarmOrEvent(void);
    void setupDisplayMode(void);
    virtual void InitKeyPadUser(uint8_t value);
    void setupPatient(void);
    virtual void SavePatientData();
    virtual void InitKeyboard();
protected:
    Patient_dataT Patient;
};

#endif // NEWPATIENTVIEW_HPP
