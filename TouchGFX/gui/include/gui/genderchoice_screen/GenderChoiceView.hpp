#ifndef GENDERCHOICEVIEW_HPP
#define GENDERCHOICEVIEW_HPP

#include <gui_generated/genderchoice_screen/GenderChoiceViewBase.hpp>
#include <gui/genderchoice_screen/GenderChoicePresenter.hpp>

class GenderChoiceView : public GenderChoiceViewBase
{
public:
    GenderChoiceView();
    virtual ~GenderChoiceView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void AlarmOrEvent(void);
    void setupDisplayMode(void);
    virtual void ChooseGender(uint8_t value);
protected:
};

#endif // GENDERCHOICEVIEW_HPP
