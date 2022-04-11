#ifndef TIMEANDDATESETTINGVIEW_HPP
#define TIMEANDDATESETTINGVIEW_HPP

#include <gui_generated/timeanddatesetting_screen/TimeAndDateSettingViewBase.hpp>
#include <gui/timeanddatesetting_screen/TimeAndDateSettingPresenter.hpp>

class TimeAndDateSettingView : public TimeAndDateSettingViewBase
{
public:
    TimeAndDateSettingView();
    virtual ~TimeAndDateSettingView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TIMEANDDATESETTINGVIEW_HPP
