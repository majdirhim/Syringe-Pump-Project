#ifndef FUNCTIONGENERATIONVIEW_HPP
#define FUNCTIONGENERATIONVIEW_HPP

#include <gui_generated/functiongeneration_screen/functiongenerationViewBase.hpp>
#include <gui/functiongeneration_screen/functiongenerationPresenter.hpp>

class functiongenerationView : public functiongenerationViewBase
{
public:
    functiongenerationView();
    virtual ~functiongenerationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // FUNCTIONGENERATIONVIEW_HPP
