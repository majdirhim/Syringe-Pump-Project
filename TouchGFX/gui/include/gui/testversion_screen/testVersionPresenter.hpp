#ifndef TESTVERSIONPRESENTER_HPP
#define TESTVERSIONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class testVersionView;

class testVersionPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    testVersionPresenter(testVersionView& v);

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

    void sendvar(uint16_t);
    void sendend(uint8_t);
    void sendstart(uint8_t);

    virtual ~testVersionPresenter() {};

private:
    testVersionPresenter();

    testVersionView& view;
};

#endif // TESTVERSIONPRESENTER_HPP
