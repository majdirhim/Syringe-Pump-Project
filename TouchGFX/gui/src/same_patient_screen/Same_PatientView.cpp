#include <gui/same_patient_screen/Same_PatientView.hpp>

Same_PatientView::Same_PatientView()
{

}

void Same_PatientView::setupScreen()
{
    SetupDisplayMode();
    Same_PatientViewBase::setupScreen();
}

void Same_PatientView::tearDownScreen()
{
    Same_PatientViewBase::tearDownScreen();
}

void Same_PatientView::GetStoredParam()
{
    presenter->RequeststoredData();

}

void Same_PatientView::testdata()
{
    uint8_t answer = presenter->PatientDataRequestAnswer();
    if((answer == 1))
    {
        WaitPopUp.setVisible(0);
        WaitPopUp.invalidate();
        char * name = presenter->getpatientname();

        for (uint8_t i = 0; i < strlen(name); i++)
        {
            Unicode::snprintf(textAreaNameBuffer + i, TEXTAREANAME_SIZE - i, "%c", *(name + i));
        }
        textAreaName.invalidate();
        Unicode::snprintf(textAreaAgeBuffer, TEXTAREAAGE_SIZE, "%d", presenter->getpatientage());
        Unicode::snprintf(textAreaHeightBuffer, TEXTAREAHEIGHT_SIZE, "%d", presenter->getpatientheight());
        Unicode::snprintf(textAreaWeightBuffer, TEXTAREAWEIGHT_SIZE, "%d", presenter->getpatientweight());
        if(presenter->getpatientgender() == 2)
            Unicode::snprintf(textAreaGenderBuffer, TEXTAREAGENDER_SIZE, "Male");
        else if(presenter->getpatientgender() == 1)
            Unicode::snprintf(textAreaGenderBuffer, TEXTAREAGENDER_SIZE, "Female");
        textAreaAge.invalidate();
        textAreaHeight.invalidate();
        textAreaHeight.invalidate();
        textAreaHeight.invalidate();
    }
    else
    {
        WaitAnimation.stopAnimation();
        WaitAnimation.setVisible(0);
        nodata.setVisible(1);
        WaitAnimation.invalidate();
        nodata.invalidate();
    }
}

void Same_PatientView::SetupDisplayMode(void)
{
    if (presenter->GetdisplayMode() == 1)
    {
        backend.setVisible(0);
        BackendBlack.setVisible(1);
        BackendChildren.setVisible(0);
    }
    else if (presenter->GetdisplayMode() == 2)
    {
        backend.setVisible(0);
        BackendBlack.setVisible(0);
        BackendChildren.setVisible(2);
    }
    else
    {
        backend.setVisible(1);
        BackendBlack.setVisible(0);
        BackendChildren.setVisible(0);
    }
}

void Same_PatientView::AlarmOrEvent(void)
{
	static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}
