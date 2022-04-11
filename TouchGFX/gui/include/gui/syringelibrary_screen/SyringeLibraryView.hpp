#ifndef SYRINGELIBRARYVIEW_HPP
#define SYRINGELIBRARYVIEW_HPP

#include <gui_generated/syringelibrary_screen/SyringeLibraryViewBase.hpp>
#include <gui/syringelibrary_screen/SyringeLibraryPresenter.hpp>

class SyringeLibraryView : public SyringeLibraryViewBase
{
public:
    SyringeLibraryView();
    virtual ~SyringeLibraryView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SYRINGELIBRARYVIEW_HPP
