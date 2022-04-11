#include <gui/startup_screen/StartUpView.hpp>
#include <gui/startup_screen/StartUpPresenter.hpp>

StartUpPresenter::StartUpPresenter(StartUpView& v)
    : view(v)
{

}

void StartUpPresenter::activate()
{

}

void StartUpPresenter::deactivate()
{

}

uint8_t StartUpPresenter::getDisplayMode()
{
	return model->getDisplayMode();
}

uint8_t StartUpPresenter::getInitStatus()
{
	return model->getInitStatus();
}
