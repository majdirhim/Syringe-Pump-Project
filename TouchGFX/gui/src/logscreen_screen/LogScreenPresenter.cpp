#include <gui/logscreen_screen/LogScreenView.hpp>
#include <gui/logscreen_screen/LogScreenPresenter.hpp>

LogScreenPresenter::LogScreenPresenter(LogScreenView& v)
    : view(v)
{

}

void LogScreenPresenter::activate()
{

}

void LogScreenPresenter::deactivate()
{

}

void LogScreenPresenter::AlarmOrEvent(void)
{
    view.AlarmOrEvent();
}

logT LogScreenPresenter::getlogvector(uint8_t index)
{
	return model->GetLogVector(index);
}

void LogScreenPresenter::RequeststorelogdData(uint8_t direction)
{
	model->RequeststorelogdData(direction);
}

uint8_t LogScreenPresenter::LogDataRequestAnswer(void)
{
    return model->LogDataRequestAnswer();
}
