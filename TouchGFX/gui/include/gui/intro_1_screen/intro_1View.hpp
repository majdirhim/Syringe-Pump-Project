#ifndef INTRO_1VIEW_HPP
#define INTRO_1VIEW_HPP

#include <gui_generated/intro_1_screen/intro_1ViewBase.hpp>
#include <gui/intro_1_screen/intro_1Presenter.hpp>

class intro_1View : public intro_1ViewBase
{
public:
    intro_1View();
    virtual ~intro_1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INTRO_1VIEW_HPP
