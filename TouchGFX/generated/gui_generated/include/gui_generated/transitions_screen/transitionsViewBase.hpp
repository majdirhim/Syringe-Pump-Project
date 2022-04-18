/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TRANSITIONSVIEWBASE_HPP
#define TRANSITIONSVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/transitions_screen/transitionsPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Button.hpp>

class transitionsViewBase : public touchgfx::View<transitionsPresenter>
{
public:
    transitionsViewBase();
    virtual ~transitionsViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Button button1;
    touchgfx::Button button1_1;
    touchgfx::Button button1_1_1;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<transitionsViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // TRANSITIONSVIEWBASE_HPP