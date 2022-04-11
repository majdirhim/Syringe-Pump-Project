#ifndef ALARMANDEVENTCONFIGVIEW_HPP
#define ALARMANDEVENTCONFIGVIEW_HPP

#include <gui_generated/alarmandeventconfig_screen/AlarmAndEventConfigViewBase.hpp>
#include <gui/alarmandeventconfig_screen/AlarmAndEventConfigPresenter.hpp>

class AlarmAndEventConfigView : public AlarmAndEventConfigViewBase
{
public:
    AlarmAndEventConfigView();
    virtual ~AlarmAndEventConfigView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ALARMANDEVENTCONFIGVIEW_HPP
