/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef DISPLAYMODEVIEWBASE_HPP
#define DISPLAYMODEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/displaymode_screen/DisplayModePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>

class DisplayModeViewBase : public touchgfx::View<DisplayModePresenter>
{
public:
    DisplayModeViewBase();
    virtual ~DisplayModeViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::ScalableImage ChildrenBackground;
    touchgfx::ScalableImage DarkBackground;
    touchgfx::ScalableImage DefaultBackground;

private:

};

#endif // DISPLAYMODEVIEWBASE_HPP