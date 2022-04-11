#ifndef DEPARTEMENTSPRESENTER_HPP
#define DEPARTEMENTSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DepartementsView;

class DepartementsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DepartementsPresenter(DepartementsView& v);

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

    virtual ~DepartementsPresenter() {};

private:
    DepartementsPresenter();

    DepartementsView& view;
};

#endif // DEPARTEMENTSPRESENTER_HPP
