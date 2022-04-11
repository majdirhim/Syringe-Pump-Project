#ifndef DISPLAYMODEVIEW_HPP
#define DISPLAYMODEVIEW_HPP

#include <gui_generated/displaymode_screen/DisplayModeViewBase.hpp>
#include <gui/displaymode_screen/DisplayModePresenter.hpp>

class DisplayModeView : public DisplayModeViewBase
{
public:
    DisplayModeView();
    virtual ~DisplayModeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // DISPLAYMODEVIEW_HPP
