#ifndef DEPARTEMENTSVIEW_HPP
#define DEPARTEMENTSVIEW_HPP

#include <gui_generated/departements_screen/DepartementsViewBase.hpp>
#include <gui/departements_screen/DepartementsPresenter.hpp>

class DepartementsView : public DepartementsViewBase
{
public:
    DepartementsView();
    virtual ~DepartementsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // DEPARTEMENTSVIEW_HPP
