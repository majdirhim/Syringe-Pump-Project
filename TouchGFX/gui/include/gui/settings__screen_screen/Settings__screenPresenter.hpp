#ifndef SETTINGS__SCREENPRESENTER_HPP
#define SETTINGS__SCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Settings__screenView;

class Settings__screenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Settings__screenPresenter(Settings__screenView& v);

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

    virtual ~Settings__screenPresenter() {};

    void SaveCurrentTime(time_ps hour)
    {
        model->SaveCurrentTime(hour);
    }
    time_ps GetCurrentTime()
    {
        return model->getcurrenttime();
    }

    uint8_t GetdisplayMode(void)
    {
        return model->GetDisplayMode();
    }

    void savediplaymode(uint8_t mode)
    {
        model->SaveDisplayMode(mode);
    }
    uint8_t getsound(void)
    {
        return model->getsound();
    }
    void savesound(uint8_t sound)
    {
        model->savesound(sound);
    }
    void savescreenlock(uint8_t screen)
    {
    	model->savescreenlock(screen);
    }
    void SaveLock(uint8_t state)
    {
    	model->SaveLock(state);
    }

    virtual void AlarmOrEvent(void);

private:
    Settings__screenPresenter();

    Settings__screenView& view;
};

#endif // SETTINGS__SCREENPRESENTER_HPP
