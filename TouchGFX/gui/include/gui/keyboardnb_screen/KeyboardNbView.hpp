#ifndef KEYBOARDNBVIEW_HPP
#define KEYBOARDNBVIEW_HPP

#include <gui_generated/keyboardnb_screen/KeyboardNbViewBase.hpp>
#include <gui/keyboardnb_screen/KeyboardNbPresenter.hpp>
#include "../../../Core/Inc/SW_common.h"



class KeyboardNbView : public KeyboardNbViewBase
{
public:
    KeyboardNbView();
    virtual ~KeyboardNbView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void AlarmOrEvent(void);
    void setupDisplayMode(void);
    virtual void ChangeScreen();
    virtual void Input0();
    virtual void Input1();
    virtual void Input2();
    virtual void Input3();
    virtual void Input4();
    virtual void Input5();
    virtual void Input6();
    virtual void Input7();
    virtual void Input8();
    virtual void Input9();
    virtual void InputComma();
    void writeToScreen(char Input);
    virtual void SaveData();
    virtual void EraseInput();
    void setUnit(void);
    void setFloatArea();
protected:
    uint8_t User;
    uint8_t Step;
    SW_float UserInput;
    uint8_t Comma = false;
    char InputString[5] = "0";
};

#endif // KEYBOARDNBVIEW_HPP
