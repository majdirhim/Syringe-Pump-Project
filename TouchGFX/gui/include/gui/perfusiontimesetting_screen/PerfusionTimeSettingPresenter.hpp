#ifndef PERFUSIONTIMESETTINGPRESENTER_HPP
#define PERFUSIONTIMESETTINGPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class PerfusionTimeSettingView;

class PerfusionTimeSettingPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    PerfusionTimeSettingPresenter(PerfusionTimeSettingView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~PerfusionTimeSettingPresenter() {};

private:
    PerfusionTimeSettingPresenter();

    PerfusionTimeSettingView& view;
};

#endif // PERFUSIONTIMESETTINGPRESENTER_HPP
