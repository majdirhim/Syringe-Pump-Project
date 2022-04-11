#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>

MainPresenter::MainPresenter(MainView& v)
    : view(v)
{

}

void MainPresenter::activate()
{

}

void MainPresenter::deactivate()
{

}

void MainPresenter::batteryUpdated(void)
{ 
    view.batteryUpdated();
}

void MainPresenter::currentTimeUpdated(void)
{
    view.currentTimeUpdated();
}

void MainPresenter::syringeUpdated(void)
{
    view.syringeUpdated();
}

void MainPresenter::motorStatusUpdated(void)
{
    view.motorStatusUpdated();
}

SW_float MainPresenter::getFlowRate(void)
{
    return model->getFlowRate();
}

SW_float MainPresenter::getTotalVolume(void)
{
    return model->getTotalVolume();
}

SW_float MainPresenter::getInfusionVolume(void)
{
    return model->getInfusionVolume();
}

SW_float MainPresenter::getKVORate(void)
{
    return model->getKVORate();
}

SW_float MainPresenter::getBolusRate(void)
{
    return model->getBolusRate();
}

uint8_t MainPresenter::getMode(void)
{
    return model->getMode();
}

SW_time MainPresenter::getInfusionTIme()
{
    return model->getInfusionTIme();
}

void MainPresenter::saveMode(uint8_t value)
{
    model->saveMode(value);
}

SW_float MainPresenter::getVolumeLeft()
{
    return model->getVolumeLeft();
}

SW_time MainPresenter::getTimeLeft()
{
    return model->getTimeLeft();
}

Infusion_paramT MainPresenter::getInfusionParameters()
{
    return model->getInfusionParameters();
}

void MainPresenter::saveTotalVolume(SW_float volume)
{
    model->saveTotalVolume(volume);
}

uint8_t MainPresenter::getSyringeState()
{
    return model->getSyringeState();
}

SyringeT MainPresenter::getSyringe()
{
    return model->getSyringe();
}

char* MainPresenter::getPatientName(void)
{
    return model->getPatient().Name;
}

SW_time MainPresenter::getCurrentTime(void)
{
    return model->getCurrentTime();
}

BatteryT MainPresenter::getBattery()
{
    return model->getBattery();
}

float MainPresenter::getCurrentPressure()
{
    return model->getCurrentPressure();
}

uint8_t MainPresenter::getDisplayMode(void)
{
    return model->getDisplayMode();
}

DrugT MainPresenter::getDrug()
{
    return model->getDrug();
}

void MainPresenter::saveKeyboardUser(uint8_t value)
{
    model->saveKeyboardUser(value);
}

const char* MainPresenter::getEventTitle(uint8_t index)
{
    return model->getEventTitle(index);
}

EventTypeT MainPresenter::getLatestEvent()
{
    return model->getLatestEvent();
}

uint8_t MainPresenter::getPendingEventStatus()
{
    return model->getPendingEventStatus();
}

void MainPresenter::savePendingEventStatus(void)
{
    model->savePendingEventStatus();
}

void MainPresenter::saveMuteStatus(void)
{
    model->saveMuteStatus();
}

