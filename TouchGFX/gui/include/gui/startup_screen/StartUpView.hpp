#ifndef STARTUPVIEW_HPP
#define STARTUPVIEW_HPP

#include <gui_generated/startup_screen/StartUpViewBase.hpp>
#include <gui/startup_screen/StartUpPresenter.hpp>

class StartUpView : public StartUpViewBase
{
public:
    StartUpView();
    virtual ~StartUpView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void setupDisplayMode(void);
    virtual void handleTickEvent(void);
    virtual void checkInitStatus();
protected:
};

#endif // STARTUPVIEW_HPP
