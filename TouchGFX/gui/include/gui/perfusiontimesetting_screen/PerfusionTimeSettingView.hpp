#ifndef PERFUSIONTIMESETTINGVIEW_HPP
#define PERFUSIONTIMESETTINGVIEW_HPP

#include <gui_generated/perfusiontimesetting_screen/PerfusionTimeSettingViewBase.hpp>
#include <gui/perfusiontimesetting_screen/PerfusionTimeSettingPresenter.hpp>

class PerfusionTimeSettingView : public PerfusionTimeSettingViewBase
{
public:
    PerfusionTimeSettingView();
    virtual ~PerfusionTimeSettingView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // PERFUSIONTIMESETTINGVIEW_HPP
