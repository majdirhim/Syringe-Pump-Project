#ifndef POPUP_ALERT_HPP
#define POPUP_ALERT_HPP

#include <gui_generated/containers/popup_AlertBase.hpp>

class popup_Alert : public popup_AlertBase
{
public:
    popup_Alert();
    virtual ~popup_Alert() {}

    virtual void initialize();
protected:
};

#endif // POPUP_ALERT_HPP
