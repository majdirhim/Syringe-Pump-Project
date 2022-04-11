#ifndef OCLUSIONTHRESHOLDSPRESENTER_HPP
#define OCLUSIONTHRESHOLDSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class OclusionThresholdsView;

class OclusionThresholdsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    OclusionThresholdsPresenter(OclusionThresholdsView& v);

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

    virtual ~OclusionThresholdsPresenter() {};

private:
    OclusionThresholdsPresenter();

    OclusionThresholdsView& view;
};

#endif // OCLUSIONTHRESHOLDSPRESENTER_HPP
