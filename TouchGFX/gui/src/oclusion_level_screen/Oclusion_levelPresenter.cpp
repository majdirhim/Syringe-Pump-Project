#include <gui/oclusion_level_screen/Oclusion_levelView.hpp>
#include <gui/oclusion_level_screen/Oclusion_levelPresenter.hpp>

Oclusion_levelPresenter::Oclusion_levelPresenter(Oclusion_levelView& v)
    : view(v)
{

}

void Oclusion_levelPresenter::activate()
{

}

void Oclusion_levelPresenter::deactivate()
{

}


void Oclusion_levelPresenter::AlarmOrEvent(void)
{
    view.AlarmOrEvent();
}
