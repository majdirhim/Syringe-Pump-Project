#ifndef LOCKSCREENVIEW_HPP
#define LOCKSCREENVIEW_HPP

#include <gui_generated/lockscreen_screen/LockScreenViewBase.hpp>
#include <gui/lockscreen_screen/LockScreenPresenter.hpp>

class LockScreenView : public LockScreenViewBase
{
public:
    LockScreenView();
    virtual ~LockScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void write0();
    virtual void write1();
    virtual void write2();
    virtual void write3();
    virtual void write4();
    virtual void write5();
    virtual void write6();
    virtual void write7();
    virtual void write8();
    virtual void write9();
    virtual void savedata();
    virtual void IT_ERASE();
    virtual void ChangePasswordF();
    virtual void LockF();
    void writetoscreen(const char var);
    virtual void AlarmOrEvent(void);
    void SetupDisplayMode(void);
protected:
    uint8_t pas = 0;
    char inputString[5] = "0";
    uint8_t state = 0;
    uint16_t UserInput = 0;
};

#endif // LOCKSCREENVIEW_HPP
