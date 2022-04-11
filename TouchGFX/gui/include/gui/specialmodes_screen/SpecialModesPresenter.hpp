#ifndef SPECIALMODESPRESENTER_HPP
#define SPECIALMODESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SpecialModesView;

class SpecialModesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SpecialModesPresenter(SpecialModesView& v);

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

    virtual ~SpecialModesPresenter() {};

    virtual void AlarmOrEvent(void);

    uint8_t getDisplayMode(void);

    void saveMode(uint8_t);

private:
    SpecialModesPresenter();

    SpecialModesView& view;
};

#endif // SPECIALMODESPRESENTER_HPP
