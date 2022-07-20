#ifndef LOCKSCREENPRESENTER_HPP
#define LOCKSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class LockScreenView;

class LockScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    LockScreenPresenter(LockScreenView& v);

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
    // uint8_t GetdisplayMode(void)
    // {
        // return model->GetDisplayMode();
   // }
    uint16_t GetPassword(void)
    {
        return model->getpassword();
    }
    void SavePassword(uint16_t pwd)
    {
        return model->savepassword(pwd);
    }
    void SaveLock(uint8_t state)
    {
        return model->SaveLock(state);
    }
    uint8_t GetLock(void)
    {
        return model->GetLock();
    }
    uint8_t getscreenlock(void)
    {
    	return model->getscreenlock();
    }
    uint16_t getpwdtech(void)
    {
    	return model->getpwdtech();
    }
    virtual void AlarmOrEvent(void);
    virtual ~LockScreenPresenter() {};

private:
    LockScreenPresenter();

    LockScreenView& view;
};

#endif // LOCKSCREENPRESENTER_HPP

