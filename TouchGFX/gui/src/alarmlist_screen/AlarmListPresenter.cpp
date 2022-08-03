#include <gui/alarmlist_screen/AlarmListView.hpp>
#include <gui/alarmlist_screen/AlarmListPresenter.hpp>

AlarmListPresenter::AlarmListPresenter(AlarmListView& v)
    : view(v)
{

}

void AlarmListPresenter::activate()
{

}

void AlarmListPresenter::deactivate()
{

}
void AlarmListPresenter::AlarmOrEvent(void)
{
    view.AlarmOrEvent();
}

uint8_t AlarmListPresenter::getalarmvector(uint8_t index)
{
    return model->GetAlarmVector(index);
}
