#ifndef TIMEPARAMVIEW_HPP
#define TIMEPARAMVIEW_HPP

#include <gui_generated/timeparam_screen/timeparamViewBase.hpp>
#include <gui/timeparam_screen/timeparamPresenter.hpp>

class timeparamView : public timeparamViewBase
{
public:
    timeparamView();
    virtual ~timeparamView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void buttonhourupclicked();
    virtual void buttonhourdownclicked();
    virtual void buttonminuteupclicked();
    virtual void buttonminutedownclicked();
    virtual void saveclockP();
    void AlarmOrEvent(void);
    void SetupDisplayMode(void);


protected:
    time_ps timeParameters = { 0, 0, 0 };

};

#endif // TIMEPARAMVIEW_HPP
