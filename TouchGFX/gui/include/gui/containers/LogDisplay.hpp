#ifndef LOGDISPLAY_HPP
#define LOGDISPLAY_HPP

#include <gui_generated/containers/LogDisplayBase.hpp>

class LogDisplay : public LogDisplayBase
{
public:
    LogDisplay();
    virtual ~LogDisplay() {}

    virtual void initialize();
protected:
};

#endif // LOGDISPLAY_HPP
