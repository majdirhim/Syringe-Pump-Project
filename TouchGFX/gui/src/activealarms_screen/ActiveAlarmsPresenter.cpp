#include <gui/activealarms_screen/ActiveAlarmsView.hpp>
#include <gui/activealarms_screen/ActiveAlarmsPresenter.hpp>

ActiveAlarmsPresenter::ActiveAlarmsPresenter(ActiveAlarmsView& v)
    : view(v)
{

}

void ActiveAlarmsPresenter::activate()
{

}

void ActiveAlarmsPresenter::deactivate()
{

}

uint8_t ActiveAlarmsPresenter::getDisplayMode(void)
{
    return model->getDisplayMode();
}

void ActiveAlarmsPresenter::AlarmOrEvent(void)
{
    view.AlarmOrEvent();
}

uint8_t ActiveAlarmsPresenter::getActiveEvents(uint8_t index)
{
    return model->getActiveEvents(index);
}

const char* ActiveAlarmsPresenter::getEventTitle(uint8_t index)
{
    return model->getEventTitle(index);
}
