#ifndef SCREENSELECTDRUGVIEW_HPP
#define SCREENSELECTDRUGVIEW_HPP

#include <gui_generated/screenselectdrug_screen/ScreenselectdrugViewBase.hpp>
#include <gui/screenselectdrug_screen/ScreenselectdrugPresenter.hpp>

class ScreenselectdrugView : public ScreenselectdrugViewBase
{
public:
    ScreenselectdrugView();
    virtual ~ScreenselectdrugView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void drugselectedvar(int8_t value);
    virtual void backtoselect1();
    virtual void gotoslectdrug2();
    virtual void savedrugSelected();
    void SetupDisplayMode(void);
    virtual void AlarmOrEvent(void);

protected:

};

#endif // SCREENSELECTDRUGVIEW_HPP
