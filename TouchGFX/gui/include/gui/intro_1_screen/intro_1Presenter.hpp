#ifndef INTRO_1PRESENTER_HPP
#define INTRO_1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class intro_1View;

class intro_1Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    intro_1Presenter(intro_1View& v);

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

    virtual ~intro_1Presenter() {};

private:
    intro_1Presenter();

    intro_1View& view;
};

#endif // INTRO_1PRESENTER_HPP
