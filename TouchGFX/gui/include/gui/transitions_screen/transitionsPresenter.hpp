#ifndef TRANSITIONSPRESENTER_HPP
#define TRANSITIONSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class transitionsView;

class transitionsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    transitionsPresenter(transitionsView& v);

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

    virtual ~transitionsPresenter() {};

private:
    transitionsPresenter();

    transitionsView& view;
};

#endif // TRANSITIONSPRESENTER_HPP
