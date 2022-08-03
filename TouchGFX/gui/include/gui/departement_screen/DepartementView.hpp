#ifndef DEPARTEMENTVIEW_HPP
#define DEPARTEMENTVIEW_HPP

#include <gui_generated/departement_screen/DepartementViewBase.hpp>
#include <gui/departement_screen/DepartementPresenter.hpp>

class DepartementView : public DepartementViewBase
{
public:
    DepartementView();
    virtual ~DepartementView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void SetupDisplayMode(void);
    virtual void peditrics();
        virtual void emergency();
        virtual void neonatal();
        virtual void icu();
        virtual void maternity();
        virtual void other();
        void deactivate(void);
    virtual void AlarmOrEvent(void);
protected:
};

#endif // DEPARTEMENTVIEW_HPP
