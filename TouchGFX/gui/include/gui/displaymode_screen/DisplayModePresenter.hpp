#ifndef DISPLAYMODEPRESENTER_HPP
#define DISPLAYMODEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DisplayModeView;

class DisplayModePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DisplayModePresenter(DisplayModeView& v);

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

    virtual ~DisplayModePresenter() {};

private:
    DisplayModePresenter();

    DisplayModeView& view;
};

#endif // DISPLAYMODEPRESENTER_HPP
