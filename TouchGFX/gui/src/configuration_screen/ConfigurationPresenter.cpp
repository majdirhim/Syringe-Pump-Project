#include <gui/configuration_screen/ConfigurationView.hpp>
#include <gui/configuration_screen/ConfigurationPresenter.hpp>

ConfigurationPresenter::ConfigurationPresenter(ConfigurationView& v)
    : view(v)
{

}

void ConfigurationPresenter::activate()
{

}

void ConfigurationPresenter::deactivate()
{

}

uint8_t ConfigurationPresenter::getDisplayMode(void)
{
    return model->getDisplayMode();
}

void ConfigurationPresenter::AlarmOrEvent(void)
{
    view.AlarmOrEvent();
}

void ConfigurationPresenter::saveKeyboardUser(uint8_t User)
{
    model->saveKeyboardUser(User);
}

SW_float ConfigurationPresenter::getFlowRate()
{
    return model->getFlowRate();
}

SW_float ConfigurationPresenter::getTotalVolume()
{
    return model->getTotalVolume();
}

SW_float ConfigurationPresenter::getInfusionVolume()
{
    return model->getInfusionVolume();
}

SW_float ConfigurationPresenter::getKVORate()
{
    return model->getKVORate();
}

SW_float ConfigurationPresenter::getBolusRate()
{
    return model->getBolusRate();
}

Pressure_thresholdsT ConfigurationPresenter::getPressureThresholds()
{
    return model->getPressureThresholds();
}
