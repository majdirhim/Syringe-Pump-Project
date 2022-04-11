#ifndef CONFIGURATIONVIEW_HPP
#define CONFIGURATIONVIEW_HPP

#include <gui_generated/configuration_screen/ConfigurationViewBase.hpp>
#include <gui/configuration_screen/ConfigurationPresenter.hpp>

class ConfigurationView : public ConfigurationViewBase
{
public:
    ConfigurationView();
    virtual ~ConfigurationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void AlarmOrEvent();
    void setupDisplayMode();
    virtual void InitKeyboard(uint8_t value);
protected:
};

#endif // CONFIGURATIONVIEW_HPP
