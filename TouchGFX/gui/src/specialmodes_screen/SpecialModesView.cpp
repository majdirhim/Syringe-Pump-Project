#include <gui/specialmodes_screen/SpecialModesView.hpp>

SpecialModesView::SpecialModesView()
{

}

void SpecialModesView::setupScreen()
{
    setupDisplayMode();
    SpecialModesViewBase::setupScreen();
}

void SpecialModesView::tearDownScreen()
{
    SpecialModesViewBase::tearDownScreen();
}

void SpecialModesView::setupDisplayMode(void)
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

void SpecialModesView::AlarmOrEvent(void)
{
    static_cast<FrontendApplication*>(Application::getInstance())->gotoMainScreenNoTransition();
}

void SpecialModesView::AivocMode(void)
{
    presenter->saveMode(AIVOC_M);
    static_cast<FrontendApplication*>(Application::getInstance())->gotoMainScreenWipeTransitionEast();
}

void SpecialModesView::TivaMode(void)
{
    presenter->saveMode(TIVA_M);
    static_cast<FrontendApplication*>(Application::getInstance())->gotoMainScreenWipeTransitionEast();
}
