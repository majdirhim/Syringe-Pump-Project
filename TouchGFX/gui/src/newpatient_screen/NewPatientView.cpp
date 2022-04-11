#include <gui/newpatient_screen/NewPatientView.hpp>
#include <touchgfx/Color.hpp>
#include <string>

Unicode::UnicodeChar keyboardBuffer[2][18];
uint8_t KeyboardSource;

NewPatientView::NewPatientView()
{

}

void NewPatientView::setupScreen()
{
	setupDisplayMode();
	setupPatient();
    NewPatientViewBase::setupScreen();
}

void NewPatientView::tearDownScreen()
{
    NewPatientViewBase::tearDownScreen();
}

void NewPatientView::setupDisplayMode(void)
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

void NewPatientView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotoMainScreenNoTransition();
}

void NewPatientView::InitKeyPadUser(uint8_t value)
{
	presenter->saveKeyboardUser(value);
	NewPatientViewBase::InitKeyPadUser(value);
}

void NewPatientView::setupPatient()
{
	Patient = presenter->getPatient();
    Unicode::snprintf(AgeBtnBuffer, NAMEBTN_SIZE, Patient.Name);
    Unicode::snprintf(AgeBtnBuffer, AGEBTN_SIZE, "%d", Patient.Age);
    Unicode::snprintf(HeightBtnBuffer, HEIGHTBTN_SIZE, "%d", Patient.Height);
    Unicode::snprintf(WeightBtnBuffer, WEIGHTBTN_SIZE, "%d", Patient.Weight);
    AgeBtn.invalidate();
    HeightBtn.invalidate();
    WeightBtn.invalidate();

    if(Patient.Gender == 1)
    {
    	if(Texts::getLanguage() == 0)
    		Unicode::snprintf(GenderBtnBuffer, GENDERBTN_SIZE, GENDER_MALE_ENGLISH);
    	else if(Texts::getLanguage() == 1)
    		Unicode::snprintf(GenderBtnBuffer, GENDERBTN_SIZE, GENDER_MALE_FRENCH);
        AgeBtn.invalidate();
    }
    else if(Patient.Gender == 2)
    {
    	if(Texts::getLanguage() == 0)
    		Unicode::snprintf(GenderBtnBuffer, GENDERBTN_SIZE, GENDER_FEMALE_ENGLISH);
    	else if(Texts::getLanguage() == 1)
    		Unicode::snprintf(GenderBtnBuffer, GENDERBTN_SIZE, GENDER_FEMALE_FRENCH);
        AgeBtn.invalidate();
    }

    if (Unicode::strlen(keyboardBuffer[0]) > 0)
    {
        bool testNameForCorectness = false;
        for (int i = 0; i < Unicode::strlen(keyboardBuffer[0]); i++)
        {
            if (!((('A' <= keyboardBuffer[0][i]) && ('z' >= keyboardBuffer[0][i]))) && (!(keyboardBuffer[0][i] == ' ')))
            {
                testNameForCorectness = true;
                break;
            }
            else
                testNameForCorectness = false;
        }
        if (!testNameForCorectness)
        {

            SaveBtn.setTouchable(true);
            NameBox.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));

        }
        else
        {
            SaveBtn.setTouchable(false);
            NameBox.setColor(touchgfx::Color::getColorFrom24BitRGB(200, 0, 0));
        }
        memset(&NameBtnBuffer, 0, NAMEBTN_SIZE-1);
        memset(Patient.Name, 0, 18);
        Unicode::snprintf(NameBtnBuffer, NAMEBTN_SIZE, keyboardBuffer[0]);
        Unicode::toUTF8(keyboardBuffer[0], (uint8_t*)Patient.Name, 18);
        Unicode::strncpy(NameBtnBuffer, keyboardBuffer[0], NAMEBTN_SIZE - 1);
        NameBtnBuffer[NAMEBTN_SIZE - 1] = '\0'; 
    }
}


void NewPatientView::SavePatientData(void)
{
    presenter->savePatientName(Patient.Name);
}

void NewPatientView::InitKeyboard()
{
    KeyboardSource = 0;
}


