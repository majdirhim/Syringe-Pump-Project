#include <gui/timeparam_screen/timeparamView.hpp>
timeparamView::timeparamView()
{

}

void timeparamView::setupScreen()
{
    SetupDisplayMode();
    touchgfx_printf(" %dh:%dmin  \n", timeParameters.hours, timeParameters.minutes);
    timeparamViewBase::setupScreen();
}

void timeparamView::tearDownScreen()
{
    timeparamViewBase::tearDownScreen();
}

void timeparamView::buttonhourupclicked()
{
    timeParameters.hours = (timeParameters.hours + 1); 
    Unicode::snprintf(textaearHourBuffer, TEXTAEARHOUR_SIZE, "%02d", timeParameters.hours);
    textaearHour.invalidate();
    touchgfx_printf(" %dh:%dmin  \n", timeParameters.hours, timeParameters.minutes);
}

void timeparamView::buttonhourdownclicked()
{
    
    if ((timeParameters.hours != 0))
    {
        timeParameters.hours--;
    }
        
    Unicode::snprintf(textaearHourBuffer, TEXTAEARHOUR_SIZE, "%02d", timeParameters.hours);
    textaearHour.invalidate();
    touchgfx_printf(" %dh:%dmin  \n", timeParameters.hours, timeParameters.minutes);
}

void timeparamView::buttonminuteupclicked()
{
    timeParameters.minutes = (timeParameters.minutes + 1) % 60; // Keep new value in range 0..59
    Unicode::snprintf(textAreaminuteBuffer, TEXTAREAMINUTE_SIZE, "%02d", timeParameters.minutes);
    textAreaminute.invalidate();
    touchgfx_printf(" %dh:%dmin  \n", timeParameters.hours, timeParameters.minutes);
}

void timeparamView::buttonminutedownclicked()
{
    timeParameters.minutes = (timeParameters.minutes + 60 - 1) % 60; // Keep new value in range 0..59
    Unicode::snprintf(textAreaminuteBuffer, TEXTAREAMINUTE_SIZE, "%02d", timeParameters.minutes);
    textAreaminute.invalidate();
    touchgfx_printf(" %dh:%dmin  \n", timeParameters.hours, timeParameters.minutes);
}

void timeparamView::saveclockP()
{
    touchgfx_printf("view %dh:%dmin  \n", timeParameters.hours, timeParameters.minutes);

    timeParameters.seconds = 0;
    presenter->savePerfusiontime(timeParameters);
}

void timeparamView::SetupDisplayMode(void)
{
    if (presenter->GetdisplayMode() == 1)
    {
        Backend.setVisible(0);
        BackendBlack.setVisible(1);
        BackendChildren.setVisible(0);
    }
    else if (presenter->GetdisplayMode() == 2)
    {
        Backend.setVisible(0);
        BackendBlack.setVisible(0);
        BackendChildren.setVisible(2);
    }
    else
    {
        Backend.setVisible(1);
        BackendBlack.setVisible(0);
        BackendChildren.setVisible(0);
    }
}

void timeparamView::AlarmOrEvent(void)
{
    static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}
