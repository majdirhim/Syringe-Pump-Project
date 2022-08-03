#ifndef INTROVIEW_HPP
#define INTROVIEW_HPP

#include <gui_generated/intro_screen/introViewBase.hpp>
#include <gui/intro_screen/introPresenter.hpp>

class introView : public introViewBase
{
public:
    introView();
    virtual ~introView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void systemparaminit();
    void SetupDisplayMode(void);
    virtual void initsystem(void);
protected:
};

#endif // INTROVIEW_HPP
