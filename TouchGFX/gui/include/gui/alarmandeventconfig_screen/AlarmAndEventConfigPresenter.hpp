#ifndef ALARMANDEVENTCONFIGPRESENTER_HPP
#define ALARMANDEVENTCONFIGPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class AlarmAndEventConfigView;

class AlarmAndEventConfigPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    AlarmAndEventConfigPresenter(AlarmAndEventConfigView& v);

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

    virtual ~AlarmAndEventConfigPresenter() {};

private:
    AlarmAndEventConfigPresenter();

    AlarmAndEventConfigView& view;
};

#endif // ALARMANDEVENTCONFIGPRESENTER_HPP
