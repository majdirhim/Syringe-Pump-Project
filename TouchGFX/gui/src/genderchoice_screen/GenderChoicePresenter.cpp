#include <gui/genderchoice_screen/genderchoiceView.hpp>
#include <gui/genderchoice_screen/genderchoicePresenter.hpp>

genderchoicePresenter::genderchoicePresenter(genderchoiceView& v)
    : view(v)
{

}

void genderchoicePresenter::activate()
{

}

void genderchoicePresenter::deactivate()
{

}

void genderchoicePresenter::savegender(uint8_t value)
{
    model->savegender(value);
}

void genderchoicePresenter::AlarmOrEvent(void)
 {
        view.AlarmOrEvent();
}
