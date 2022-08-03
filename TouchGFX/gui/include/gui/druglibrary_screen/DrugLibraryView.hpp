#ifndef DRUGLIBRARYVIEW_HPP
#define DRUGLIBRARYVIEW_HPP

#include <gui_generated/druglibrary_screen/DrugLibraryViewBase.hpp>
#include <gui/druglibrary_screen/DrugLibraryPresenter.hpp>

class DrugLibraryView : public DrugLibraryViewBase
{
public:
    DrugLibraryView();
    virtual ~DrugLibraryView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void SetupDisplayMode(void);
    virtual void AlarmOrEvent(void);
protected:
};

#endif // DRUGLIBRARYVIEW_HPP
