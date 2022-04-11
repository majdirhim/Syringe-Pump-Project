#ifndef SPECIALMODESVIEW_HPP
#define SPECIALMODESVIEW_HPP

#include <gui_generated/specialmodes_screen/SpecialModesViewBase.hpp>
#include <gui/specialmodes_screen/SpecialModesPresenter.hpp>

class SpecialModesView : public SpecialModesViewBase
{
public:
    SpecialModesView();
    virtual ~SpecialModesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void setupDisplayMode(void);
    virtual void AlarmOrEvent(void);
    virtual void AivocMode(void);
    virtual void TivaMode(void);
protected:
};

#endif // SPECIALMODESVIEW_HPP
