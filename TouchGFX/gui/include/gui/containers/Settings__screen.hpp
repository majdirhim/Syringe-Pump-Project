#ifndef SETTINGS__SCREEN_HPP
#define SETTINGS__SCREEN_HPP

#include <gui_generated/containers/Settings__screenBase.hpp>

class Settings__screen : public Settings__screenBase
{
public:
    Settings__screen();
    virtual ~Settings__screen() {}

    virtual void initialize();
protected:
};

#endif // SETTINGS__SCREEN_HPP
