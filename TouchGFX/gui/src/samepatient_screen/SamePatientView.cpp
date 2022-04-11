#include <gui/samepatient_screen/SamePatientView.hpp>

SamePatientView::SamePatientView()
{

}

void SamePatientView::setupScreen()
{
    setupDisplayMode();
    SamePatientViewBase::setupScreen();
}

void SamePatientView::tearDownScreen()
{
    SamePatientViewBase::tearDownScreen();
}

void SamePatientView::setupDisplayMode(void)
{
    if (presenter->getDisplayMode() == DARK)
    {
        DefaultBackground.setVisible(false);
        DarkBackground.setVisible(true);
        ChildrenBackground.setVisible(false);
    }
    else if (presenter->getDisplayMode() == CHILDREN)
    {
        DefaultBackground.setVisible(false);
        DarkBackground.setVisible(false);
        ChildrenBackground.setVisible(true);
    }
    else
    {
        DefaultBackground.setVisible(true);
        DarkBackground.setVisible(false);
        ChildrenBackground.setVisible(false);
    }
}

void SamePatientView::AlarmOrEvent(void)
{
    static_cast<FrontendApplication*>(Application::getInstance())->gotoMainScreenNoTransition();
}

void SamePatientView::RequestLastPatient()
{
    presenter->requestLastPatientData();
}

void SamePatientView::VerifyData()
{
    uint8_t State = presenter->getPatientDataRequestState();
    if (State)
    {
        Patient = presenter->getPatient();
        LoadingAnimation.stopAnimation();
        LoadingPopUp.setVisible(false);
        LoadingPopUp.invalidate();
        displayPatient();
    }
    else
    {
        LoadingAnimation.stopAnimation();
        LoadingAnimation.setVisible(false);
        ErrorMsgTextArea.setVisible(true);
        LoadingPopUp.invalidate();
    }
}

void SamePatientView::displayPatient()
{
    Unicode::snprintf(NameTextAreaBuffer, NAMETEXTAREA_SIZE, Patient.Name);
    Unicode::snprintf(AgeTextAreaBuffer, AGETEXTAREA_SIZE, "%d", Patient.Age);
    Unicode::snprintf(HeightTextAreaBuffer, HEIGHTTEXTAREA_SIZE, "%d", Patient.Height);
    Unicode::snprintf(WeightTextAreaBuffer, WEIGHTTEXTAREA_SIZE, "%d", Patient.Weight);
    NameTextArea.invalidate();
    AgeTextArea.invalidate();
    HeightTextArea.invalidate();
    WeightTextArea.invalidate();
    if (Patient.Gender == 1)
    {
        if (Texts::getLanguage() == 0)
            Unicode::snprintf(GenderTextAreaBuffer, GENDERTEXTAREA_SIZE, GENDER_MALE_ENGLISH);
        else if (Texts::getLanguage() == 1)
            Unicode::snprintf(GenderTextAreaBuffer, GENDERTEXTAREA_SIZE, GENDER_MALE_FRENCH);
        GenderTextArea.invalidate();
    }
    else if (Patient.Gender == 2)
    {
        if (Texts::getLanguage() == 0)
            Unicode::snprintf(GenderTextAreaBuffer, GENDERTEXTAREA_SIZE, GENDER_FEMALE_ENGLISH);
        else if (Texts::getLanguage() == 1)
            Unicode::snprintf(GenderTextAreaBuffer, GENDERTEXTAREA_SIZE, GENDER_FEMALE_FRENCH);
        GenderTextArea.invalidate();
    }
}


