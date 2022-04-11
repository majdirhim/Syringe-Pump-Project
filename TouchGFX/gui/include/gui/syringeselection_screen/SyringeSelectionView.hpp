#ifndef SYRINGESELECTIONVIEW_HPP
#define SYRINGESELECTIONVIEW_HPP

#include <gui_generated/syringeselection_screen/SyringeSelectionViewBase.hpp>
#include <gui/syringeselection_screen/SyringeSelectionPresenter.hpp>

class SyringeSelectionView : public SyringeSelectionViewBase
{
public:
    SyringeSelectionView();
    virtual ~SyringeSelectionView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SYRINGESELECTIONVIEW_HPP
