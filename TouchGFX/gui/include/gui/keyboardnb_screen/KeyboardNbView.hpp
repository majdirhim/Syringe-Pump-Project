#ifndef KEYBOARDNBVIEW_HPP
#define KEYBOARDNBVIEW_HPP

#include <gui_generated/keyboardnb_screen/KeyboardNBViewBase.hpp>
#include <gui/keyboardnb_screen/KeyboardNBPresenter.hpp>
#include <string> 
#include <stdio.h>

class KeyboardNBView : public KeyboardNBViewBase
{
public:
    KeyboardNBView();
    virtual ~KeyboardNBView() {}
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
    virtual void writecomma();
    virtual void savedata();
    virtual void IT_ERASE();
    void writetoscreen(const char var);
    virtual void closepopup();
    void showpopup(void);
    void SetupDisplayMode(void);
    virtual void AlarmOrEvent(void);
protected:
    int pas;
    char inputString[5] = "0";
    int comma = 0;
    ps_float userinput;

    Unicode::UnicodeChar keyboardBuff[3];
    /*
    * Callback Declarations
    */


};

#endif // KEYBOARDNBVIEW_HPP
