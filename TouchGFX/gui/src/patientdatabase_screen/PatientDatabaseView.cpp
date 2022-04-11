#include <gui/patientdatabase_screen/PatientDatabaseView.hpp>

extern Unicode::UnicodeChar keyboardBuffer[2][18];
extern uint8_t KeyboardSource;

PatientDatabaseView::PatientDatabaseView()
{

}

void PatientDatabaseView::setupScreen()
{
    setupDisplayMode();
    DisplaySearchedName();
    PatientDatabaseViewBase::setupScreen();
}

void PatientDatabaseView::tearDownScreen()
{
    PatientDatabaseViewBase::tearDownScreen();
}

void PatientDatabaseView::InitKeyboard()
{
    KeyboardSource = 1;
}

void PatientDatabaseView::AlarmOrEvent(void)
{
    static_cast<FrontendApplication*>(Application::getInstance())->gotoMainScreenNoTransition();
}

void PatientDatabaseView::setupDisplayMode(void)
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

void PatientDatabaseView::DisplaySearchedName(void)
{
    if (Unicode::strlen(keyboardBuffer[1]) > 0)
    {
        bool testNameForCorectness = false;
        for (int i = 0; i < Unicode::strlen(keyboardBuffer[1]); i++)
        {
            if (!((('A' <= keyboardBuffer[1][i]) && ('z' >= keyboardBuffer[1][i]))) && (!(keyboardBuffer[1][i] == ' ')))
            {
                testNameForCorectness = true;
                break;
            }
            else
                testNameForCorectness = false;
        }
        if (!testNameForCorectness)
        {

            SearchBtn.setTouchable(true);
            SearchedNameBox.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));

        }
        else
        {
            SearchBtn.setTouchable(false);
            SearchedNameBox.setColor(touchgfx::Color::getColorFrom24BitRGB(200, 0, 0));
        }
        memset(&SearchedNameBtnBuffer, 0, SEARCHEDNAMEBTN_SIZE-1);
        Unicode::snprintf(SearchedNameBtnBuffer, SEARCHEDNAMEBTN_SIZE, keyboardBuffer[1]);
        Unicode::toUTF8(keyboardBuffer[1], (uint8_t*)Name, 18);
        memset(&keyboardBuffer[1], 0, 17*sizeof(char));
    }
}

void PatientDatabaseView::RequestPatientSearch()
{
    presenter->RequestPatientSearch(Name);
}

void PatientDatabaseView::VertifyRequestResponse(void)
{
    uint8_t State = presenter->getPatientDataRequestState();

    if (State)
    {
        Patient = presenter->getPatient();
        LoadingAnimation.stopAnimation();
        PatientDisplay.setVisible(true);
        PatientDisplay.invalidate();
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

void PatientDatabaseView::displayPatient()
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

void PatientDatabaseView::SavePatient()
{
    presenter->savePatientName(Patient.Name);
    static_cast<FrontendApplication*>(Application::getInstance())->gotoMainScreenWipeTransitionEast();
}
