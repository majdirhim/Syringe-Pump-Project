#ifndef GENDERCHOICEVIEW_HPP
#define GENDERCHOICEVIEW_HPP

#include <gui_generated/genderchoice_screen/genderchoiceViewBase.hpp>
#include <gui/genderchoice_screen/genderchoicePresenter.hpp>

class genderchoiceView : public genderchoiceViewBase
{
public:
    genderchoiceView();
    virtual ~genderchoiceView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void gendersave(int8_t value);
    void SetupDisplayMode(void);
    virtual void AlarmOrEvent(void);
protected:
};

#endif // GENDERCHOICEVIEW_HPP
