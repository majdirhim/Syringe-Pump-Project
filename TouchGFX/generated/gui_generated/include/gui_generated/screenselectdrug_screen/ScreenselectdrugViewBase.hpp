/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREENSELECTDRUGVIEWBASE_HPP
#define SCREENSELECTDRUGVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screenselectdrug_screen/ScreenselectdrugPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/SwipeContainer.hpp>

class ScreenselectdrugViewBase : public touchgfx::View<ScreenselectdrugPresenter>
{
public:
    ScreenselectdrugViewBase();
    virtual ~ScreenselectdrugViewBase() {}
    virtual void setupScreen();

    /*
     * Custom Actions
     */
    virtual void drugselectedvar(int8_t value);

    /*
     * Virtual Action Handlers
     */
    virtual void backtoselect1()
    {
        // Override and implement this function in Screenselectdrug
    }

    virtual void drugSelected(int8_t value)
    {
        // Override and implement this function in Screenselectdrug
    }

    virtual void savedrugSelected()
    {
        // Override and implement this function in Screenselectdrug
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Image backend;
    touchgfx::ScalableImage BackendBlack;
    touchgfx::ScalableImage BackendChildren;
    touchgfx::Container containerSelect_Drug2;
    touchgfx::ScalableImage scalableImage2;
    touchgfx::TextButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  btn_SELECT;
    touchgfx::TextButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  btn_CANCEL;
    touchgfx::TextArea textArea1;
    touchgfx::Container containerSelect_Drug;
    touchgfx::SwipeContainer swipeContainer1;
    touchgfx::Container swipeContainer1Page2;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  Aciclovir_1;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  Ventolin_1;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  flexButton1_2_1;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  Actilyse_1;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  Actrapide_1;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  flexButton1_5_1;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  Amiodarone_1;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  Amikacine_1;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  Adrenaline_1;
    touchgfx::Container swipeContainer1Page1;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  Aciclovir;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  Ventolin;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  Altiazem;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  Actilyse;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  Actrapide;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  Aggrastat;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  Amiodarone;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  Amikacine;
    touchgfx::TextButtonStyle< touchgfx::ImageButtonStyle< touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  >  >  Adrenaline;
    touchgfx::TextArea textAreaselectdrug;
    touchgfx::Box box1;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ClickButtonTrigger >  >  btn_Back;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<ScreenselectdrugViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // SCREENSELECTDRUGVIEWBASE_HPP