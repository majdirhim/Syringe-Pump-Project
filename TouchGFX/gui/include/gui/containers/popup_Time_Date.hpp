#ifndef POPUP_TIME_DATE_HPP
#define POPUP_TIME_DATE_HPP

#include <gui_generated/containers/popup_Time_DateBase.hpp>
#include <gui/settings__screen_screen/Settings__screenView.hpp>


class popup_Time_Date : public popup_Time_DateBase
{
public:
    popup_Time_Date();
    virtual ~popup_Time_Date() {}

    virtual void initialize();

    virtual void buttonhourupclicked();
    virtual void buttonhourdownclicked();
    virtual void buttonminuteupclicked();
    virtual void buttonminutedownclicked();
    virtual void saveclock();

protected:
    int16_t hour;
    int16_t minute;
};

#endif // POPUP_TIME_DATE_HPP
