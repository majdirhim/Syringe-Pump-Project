#ifndef POPUP_MANUAL_HPP
#define POPUP_MANUAL_HPP

#include <gui_generated/containers/popup_ManualBase.hpp>

class popup_Manual : public popup_ManualBase
{
public:
    popup_Manual();
    virtual ~popup_Manual() {}

    virtual void initialize();
protected:
};

#endif // POPUP_MANUAL_HPP
