#include <gui/screenselectdrug_screen/ScreenselectdrugView.hpp>

uint8_t DrugSelection = 0; // add



ScreenselectdrugView::ScreenselectdrugView()
{

}

void ScreenselectdrugView::setupScreen()
{
    SetupDisplayMode();
    containerSelect_Drug.setVisible(true);
    containerSelect_Drug.setTouchable(true);

    containerSelect_Drug2.setVisible(false);
    containerSelect_Drug2.setTouchable(false);

    containerSelect_Drug.invalidate();
    containerSelect_Drug2.invalidate();

    ScreenselectdrugViewBase::setupScreen();
}

void ScreenselectdrugView::tearDownScreen()
{
    ScreenselectdrugViewBase::tearDownScreen();
}

void ScreenselectdrugView::drugselectedvar(int8_t value)
{
    DrugSelection = value; // add
    touchgfx_printf(" %02d \n", DrugSelection);
    gotoslectdrug2();

}

void ScreenselectdrugView::backtoselect1()
{
    containerSelect_Drug.setVisible(true);
    containerSelect_Drug.setTouchable(true);

    containerSelect_Drug2.setVisible(false);
    containerSelect_Drug2.setTouchable(false);

    containerSelect_Drug.invalidate();
    containerSelect_Drug2.invalidate();

}

void ScreenselectdrugView::gotoslectdrug2()
{

    containerSelect_Drug.setVisible(false);
    containerSelect_Drug.setTouchable(false);

    containerSelect_Drug2.setVisible(true);
    containerSelect_Drug2.setTouchable(true);

    containerSelect_Drug.invalidate();
    containerSelect_Drug2.invalidate();

}

void ScreenselectdrugView::savedrugSelected()
{

    presenter->savedrug(DrugSelection);


}

void ScreenselectdrugView::SetupDisplayMode(void)
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

void ScreenselectdrugView::AlarmOrEvent(void)
{
    static_cast<FrontendApplication*>(Application::getInstance())->gotomainScreen_WithSTARTScreenNoTransition();
}