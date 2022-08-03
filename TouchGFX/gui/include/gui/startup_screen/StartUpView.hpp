#ifndef STARTUPVIEW_HPP
#define STARTUPVIEW_HPP

#include <gui_generated/startup_screen/startupViewBase.hpp>
#include <gui/startup_screen/startupPresenter.hpp>

class startupView : public startupViewBase
{
public:
    startupView();
    virtual ~startupView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void SetupDisplayMode(void);
    virtual void AlarmOrEvent(void);

protected:
};

#endif // STARTUPVIEW_HPP
