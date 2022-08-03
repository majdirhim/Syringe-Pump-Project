/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/syringedetected_screen/syringedetectedViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

syringedetectedViewBase::syringedetectedViewBase() :
    flexButtonCallback(this, &syringedetectedViewBase::flexButtonCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    BackendBlack.setBitmap(touchgfx::Bitmap(BITMAP_BACKEND3_ID));
    BackendBlack.setPosition(0, 0, 480, 272);
    BackendBlack.setVisible(false);
    BackendBlack.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    BackendChildren.setBitmap(touchgfx::Bitmap(BITMAP_BACKEND4_ID));
    BackendChildren.setPosition(0, 0, 481, 272);
    BackendChildren.setVisible(false);
    BackendChildren.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    backend.setXY(0, 0);
    backend.setBitmap(touchgfx::Bitmap(BITMAP_MINI_BACKEND2_ID));

    scalableImage4.setBitmap(touchgfx::Bitmap(BITMAP_MINI_TRACE99_ID));
    scalableImage4.setPosition(218, 122, 45, 33);
    scalableImage4.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    SyrineDiameter.setPosition(158, 180, 210, 26);
    SyrineDiameter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    SyrineDiameter.setLinespacing(0);
    SyrineDiameterBuffer[0] = 0;
    SyrineDiameter.setWildcard(SyrineDiameterBuffer);
    SyrineDiameter.setTypedText(touchgfx::TypedText(T___SINGLEUSE_U0NG));

    button.setBitmaps(Bitmap(BITMAP_GROUPE2_ID), Bitmap(BITMAP_GROUPE2_ID));
    button.setBitmapXY(0, 0);
    button.setPosition(419, 111, 50, 50);
    button.setAction(flexButtonCallback);

    Syringe.setXY(118, 48);
    Syringe.setProgressIndicatorPosition(29, 24, 161, 22);
    Syringe.setRange(0, 100);
    Syringe.setDirection(touchgfx::AbstractDirectionProgress::RIGHT);
    Syringe.setBackground(touchgfx::Bitmap(BITMAP_GROUPE10_ID));
    Syringe.setColor(touchgfx::Color::getColorFromRGB(6, 224, 4));
    Syringe.setValue(0);

    VolumeLeft.setPosition(159, 206, 209, 26);
    VolumeLeft.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    VolumeLeft.setLinespacing(0);
    VolumeLeftBuffer[0] = 0;
    VolumeLeft.setWildcard(VolumeLeftBuffer);
    VolumeLeft.setTypedText(touchgfx::TypedText(T___SINGLEUSE_FE51));

    InfusionVolume.setPosition(159, 232, 209, 26);
    InfusionVolume.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    InfusionVolume.setLinespacing(0);
    InfusionVolumeBuffer[0] = 0;
    InfusionVolume.setWildcard(InfusionVolumeBuffer);
    InfusionVolume.setTypedText(touchgfx::TypedText(T___SINGLEUSE_COEJ));

    add(__background);
    add(BackendBlack);
    add(BackendChildren);
    add(backend);
    add(scalableImage4);
    add(SyrineDiameter);
    add(button);
    add(Syringe);
    add(VolumeLeft);
    add(InfusionVolume);
}

void syringedetectedViewBase::setupScreen()
{

}

void syringedetectedViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &button)
    {
        //Interaction3
        //When button clicked change screen to mainScreen_WithSTART
        //Go to mainScreen_WithSTART with no screen transition
        application().gotomainScreen_WithSTARTScreenNoTransition();
    }
}