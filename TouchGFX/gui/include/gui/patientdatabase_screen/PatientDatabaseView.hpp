#ifndef PATIENTDATABASEVIEW_HPP
#define PATIENTDATABASEVIEW_HPP

#include <gui_generated/patientdatabase_screen/PatientDatabaseViewBase.hpp>
#include <gui/patientdatabase_screen/PatientDatabasePresenter.hpp>

class PatientDatabaseView : public PatientDatabaseViewBase
{
public:
    PatientDatabaseView();
    virtual ~PatientDatabaseView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void InitKeyboard();
    virtual void AlarmOrEvent(void);
    void setupDisplayMode(void);
    void DisplaySearchedName(void);
    virtual void RequestPatientSearch(void);
    virtual void VertifyRequestResponse(void);
    void displayPatient();
    virtual void SavePatient();
protected:
    char Name[20];
    Patient_dataT Patient;
};

#endif // PATIENTDATABASEVIEW_HPP
