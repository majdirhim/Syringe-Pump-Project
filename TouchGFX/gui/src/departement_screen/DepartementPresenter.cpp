#include <gui/departement_screen/DepartementView.hpp>
#include <gui/departement_screen/DepartementPresenter.hpp>

DepartementPresenter::DepartementPresenter(DepartementView& v)
    : view(v)
{

}

void DepartementPresenter::activate()
{

}

void DepartementPresenter::deactivate()
{

}

void DepartementPresenter::AlarmOrEvent(void)
 {
        view.AlarmOrEvent();
}
