#ifndef OCLUSION_LEVELVIEW_HPP
#define OCLUSION_LEVELVIEW_HPP

#include <gui_generated/oclusion_level_screen/Oclusion_levelViewBase.hpp>
#include <gui/oclusion_level_screen/Oclusion_levelPresenter.hpp>

class Oclusion_levelView : public Oclusion_levelViewBase
{
public:
    Oclusion_levelView();
    virtual ~Oclusion_levelView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void highpressure();
    virtual void Lowpressure();
    virtual void mediumpressure();
    virtual void writeinmain();
    virtual void AlarmOrEvent(void);
    void SetupDisplayMode(void);


protected:
    int16_t pressureLow;
    int16_t pressureMedium;
    int16_t pressureHigh;
};

#endif // OCLUSION_LEVELVIEW_HPP
