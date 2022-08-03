#ifndef SCREENKEYBOARDPRESENTER_HPP
#define SCREENKEYBOARDPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScreenKeyboardView;

class ScreenKeyboardPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ScreenKeyboardPresenter(ScreenKeyboardView& v);

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

    uint8_t GetdisplayMode(void)
    {
        return model->GetDisplayMode();
    }

    virtual void AlarmOrEvent(void);
    virtual ~ScreenKeyboardPresenter() {};

private:
    ScreenKeyboardPresenter();

    ScreenKeyboardView& view;
};

#endif // SCREENKEYBOARDPRESENTER_HPP