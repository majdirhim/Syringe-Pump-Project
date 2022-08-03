#ifndef SYRINGEDETECTEDVIEW_HPP
#define SYRINGEDETECTEDVIEW_HPP

#include <gui_generated/syringedetected_screen/syringedetectedViewBase.hpp>
#include <gui/syringedetected_screen/syringedetectedPresenter.hpp>

class syringedetectedView : public syringedetectedViewBase
{
public:
    syringedetectedView();
    virtual ~syringedetectedView() {}
    virtual void handleTickEvent();
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void AlarmOrEvent(void);
    void SetupDisplayMode(void);
protected:
};

#endif // SYRINGEDETECTEDVIEW_HPP
