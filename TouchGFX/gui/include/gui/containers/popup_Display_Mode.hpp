#ifndef POPUP_DISPLAY_MODE_HPP
#define POPUP_DISPLAY_MODE_HPP

#include <gui_generated/containers/popup_Display_ModeBase.hpp>

class popup_Display_Mode : public popup_Display_ModeBase
{
public:
    popup_Display_Mode();
    virtual ~popup_Display_Mode() {}

    virtual void initialize();
protected:
};

#endif // POPUP_DISPLAY_MODE_HPP
