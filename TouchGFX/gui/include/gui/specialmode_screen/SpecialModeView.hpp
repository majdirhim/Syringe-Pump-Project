#ifndef SPECIALMODEVIEW_HPP
#define SPECIALMODEVIEW_HPP

#include <gui_generated/specialmode_screen/SpecialModeViewBase.hpp>
#include <gui/specialmode_screen/SpecialModePresenter.hpp>

class SpecialModeView : public SpecialModeViewBase
{
public:
    SpecialModeView();
    virtual ~SpecialModeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void SetupDisplayMode(void);
    virtual void AlarmOrEvent(void);

protected:
};

#endif // SPECIALMODEVIEW_HPP
