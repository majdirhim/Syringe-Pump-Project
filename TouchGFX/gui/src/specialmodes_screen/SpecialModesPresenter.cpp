#include <gui/specialmodes_screen/SpecialModesView.hpp>
#include <gui/specialmodes_screen/SpecialModesPresenter.hpp>

SpecialModesPresenter::SpecialModesPresenter(SpecialModesView& v)
    : view(v)
{

}

void SpecialModesPresenter::activate()
{

}

void SpecialModesPresenter::deactivate()
{

}

void SpecialModesPresenter::AlarmOrEvent(void)
{
    view.AlarmOrEvent();
}

uint8_t SpecialModesPresenter::getDisplayMode(void)
{
    return model->getDisplayMode();
}

void SpecialModesPresenter::saveMode(uint8_t value)
{
    model->saveMode(value);
}
