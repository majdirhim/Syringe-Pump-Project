#ifndef NEW_PAITENTVIEW_HPP
#define NEW_PAITENTVIEW_HPP

#include <gui_generated/new_paitent_screen/New_PaitentViewBase.hpp>
#include <gui/new_paitent_screen/New_PaitentPresenter.hpp>

class New_PaitentView : public New_PaitentViewBase
{
public:
    New_PaitentView();
    virtual ~New_PaitentView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void keyboardSelected(uint8_t value);
    virtual void updateScreen();
    uint8_t getgender(void);
    virtual void savepatientdata();
    void SetupDisplayMode(void);
    virtual void AlarmOrEvent(void);
protected:
    char name[18];
    uint16_t weight;
    uint8_t age;
    uint16_t height;
    uint8_t gender;
};

#endif // NEW_PAITENTVIEW_HPP
