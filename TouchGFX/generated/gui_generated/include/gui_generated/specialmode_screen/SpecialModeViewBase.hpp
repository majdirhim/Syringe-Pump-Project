/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SPECIALMODEVIEWBASE_HPP
#define SPECIALMODEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/specialmode_screen/SpecialModePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>

class SpecialModeViewBase : public touchgfx::View<SpecialModePresenter>
{
public:
    SpecialModeViewBase();
    virtual ~SpecialModeViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::ScalableImage BackendBlack;
    touchgfx::ScalableImage BackendChildren;
    touchgfx::Image backend;
    touchgfx::ButtonWithLabel buttonWithmale;
    touchgfx::ButtonWithLabel buttonWithfemale;
    touchgfx::Box box1;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ClickButtonTrigger >  >  Back;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<SpecialModeViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<SpecialModeViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // SPECIALMODEVIEWBASE_HPP