#ifndef TRANSITIONSVIEW_HPP
#define TRANSITIONSVIEW_HPP

#include <gui_generated/transitions_screen/transitionsViewBase.hpp>
#include <gui/transitions_screen/transitionsPresenter.hpp>

class transitionsView : public transitionsViewBase
{
public:
    transitionsView();
    virtual ~transitionsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TRANSITIONSVIEW_HPP
