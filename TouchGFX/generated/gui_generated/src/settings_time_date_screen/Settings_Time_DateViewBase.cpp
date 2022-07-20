/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/settings_time_date_screen/Settings_Time_DateViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Settings_Time_DateViewBase::Settings_Time_DateViewBase() :
    buttonCallback(this, &Settings_Time_DateViewBase::buttonCallbackHandler),
    flexButtonCallback(this, &Settings_Time_DateViewBase::flexButtonCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    BackendChildren.setBitmap(touchgfx::Bitmap(BITMAP_BACKEND4_ID));
    BackendChildren.setPosition(0, 0, 480, 272);
    BackendChildren.setVisible(false);
    BackendChildren.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    BackendBlack.setBitmap(touchgfx::Bitmap(BITMAP_BACKEND3_ID));
    BackendBlack.setPosition(0, 0, 480, 272);
    BackendBlack.setVisible(false);
    BackendBlack.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    Backend.setBitmap(touchgfx::Bitmap(BITMAP_BACKEND2_ID));
    Backend.setPosition(0, 2, 480, 270);
    Backend.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    box1.setPosition(63, 72, 75, 80);
    box1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    box1.setAlpha(155);

    box2.setPosition(296, 72, 75, 80);
    box2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    box2.setAlpha(155);

    textArea1.setXY(76, 72);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_K1RL));

    textArea2.setXY(300, 72);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_DP63));

    textaearHour.setPosition(85, 108, 28, 36);
    textaearHour.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textaearHour.setLinespacing(0);
    Unicode::snprintf(textaearHourBuffer, TEXTAEARHOUR_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_WGW1).getText());
    textaearHour.setWildcard(textaearHourBuffer);
    textaearHour.setTypedText(touchgfx::TypedText(T___SINGLEUSE_QWNB));

    textAreaminute.setXY(319, 108);
    textAreaminute.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaminute.setLinespacing(0);
    Unicode::snprintf(textAreaminuteBuffer, TEXTAREAMINUTE_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_Q4AF).getText());
    textAreaminute.setWildcard(textAreaminuteBuffer);
    textAreaminute.resizeToCurrentText();
    textAreaminute.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GMQ3));

    buttonhourup.setXY(163, 81);
    buttonhourup.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_ICONS_UP_ARROW_32_ID), touchgfx::Bitmap(BITMAP_DARK_ICONS_UP_ARROW_32_ID));
    buttonhourup.setAction(buttonCallback);

    buttonhourdown.setXY(163, 125);
    buttonhourdown.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_ICONS_DOWN_ARROW_32_ID), touchgfx::Bitmap(BITMAP_DARK_ICONS_DOWN_ARROW_32_ID));
    buttonhourdown.setAction(buttonCallback);

    buttonminuteup.setXY(240, 81);
    buttonminuteup.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_ICONS_UP_ARROW_32_ID), touchgfx::Bitmap(BITMAP_DARK_ICONS_UP_ARROW_32_ID));
    buttonminuteup.setAction(buttonCallback);

    buttonminutedown.setXY(240, 125);
    buttonminutedown.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_ICONS_DOWN_ARROW_32_ID), touchgfx::Bitmap(BITMAP_DARK_ICONS_DOWN_ARROW_32_ID));
    buttonminutedown.setAction(buttonCallback);

    Back.setText(TypedText(T___SINGLEUSE_ZD48));
    Back.setTextPosition(19, 3, 94, 31);
    Back.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255));
    Back.setPosition(371, 10, 94, 31);
    Back.setAction(flexButtonCallback);

    box3.setPosition(371, 10, 94, 31);
    box3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    box3.setAlpha(90);

    BackArrow.setBitmap(touchgfx::Bitmap(BITMAP_GROUPE49_ID));
    BackArrow.setPosition(375, 16, 22, 15);
    BackArrow.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    buttonclock.setXY(136, 187);
    buttonclock.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonclock.setLabelText(touchgfx::TypedText(T___SINGLEUSE_LVNN));
    buttonclock.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonclock.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonclock.setAction(buttonCallback);

    add(__background);
    add(BackendChildren);
    add(BackendBlack);
    add(Backend);
    add(box1);
    add(box2);
    add(textArea1);
    add(textArea2);
    add(textaearHour);
    add(textAreaminute);
    add(buttonhourup);
    add(buttonhourdown);
    add(buttonminuteup);
    add(buttonminutedown);
    add(Back);
    add(box3);
    add(BackArrow);
    add(buttonclock);
}

void Settings_Time_DateViewBase::setupScreen()
{

}

void Settings_Time_DateViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonhourup)
    {
        //Interaction5
        //When buttonhourup clicked call virtual function
        //Call buttonhourupclicked
        buttonhourupclicked();
    }
    else if (&src == &buttonhourdown)
    {
        //Interaction4
        //When buttonhourdown clicked call virtual function
        //Call buttonhourdownclicked
        buttonhourdownclicked();
    }
    else if (&src == &buttonminuteup)
    {
        //Interaction2
        //When buttonminuteup clicked call virtual function
        //Call buttonminuteupclicked
        buttonminuteupclicked();
    }
    else if (&src == &buttonminutedown)
    {
        //Interaction3
        //When buttonminutedown clicked call virtual function
        //Call buttonminutedownclicked
        buttonminutedownclicked();
    }
    else if (&src == &buttonclock)
    {
        //Interaction6
        //When buttonclock clicked call virtual function
        //Call saveclock
        saveclock();
    }
}

void Settings_Time_DateViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &Back)
    {
        //Interaction1
        //When Back clicked change screen to Settings
        //Go to Settings with no screen transition
        application().gotoSettingsScreenNoTransition();
    }
}