/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/configuration_screen/ConfigurationViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

ConfigurationViewBase::ConfigurationViewBase() :
    flexButtonCallback(this, &ConfigurationViewBase::flexButtonCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    ChildrenBackground.setBitmap(touchgfx::Bitmap(BITMAP_BACKEND4_ID));
    ChildrenBackground.setPosition(0, 0, 480, 272);
    ChildrenBackground.setVisible(false);
    ChildrenBackground.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    DarkBackground.setBitmap(touchgfx::Bitmap(BITMAP_BACKEND3_ID));
    DarkBackground.setPosition(0, 0, 480, 272);
    DarkBackground.setVisible(false);
    DarkBackground.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    DefaultBackground.setBitmap(touchgfx::Bitmap(BITMAP_BACKEND2_ID));
    DefaultBackground.setPosition(0, 0, 480, 272);
    DefaultBackground.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    BackBtnBox.setPosition(371, 3, 95, 32);
    BackBtnBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    BackBtnBox.setAlpha(90);

    BackBtn.setText(TypedText(T___SINGLEUSE_F77U));
    BackBtn.setTextPosition(-6, 7, 95, 32);
    BackBtn.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(133, 133, 133));
    BackBtn.setIconBitmaps(Bitmap(BITMAP_GROUPE49_ID), Bitmap(BITMAP_GROUPE49_ID));
    BackBtn.setIconXY(4, 9);
    BackBtn.setPosition(371, 3, 95, 32);
    BackBtn.setAction(flexButtonCallback);

    ConfigBtnBox.setPosition(375, 223, 95, 44);
    ConfigBtnBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    ConfigBtnBox.setAlpha(90);

    ConfigBtn.setText(TypedText(T___SINGLEUSE_JU8Y));
    ConfigBtn.setTextPosition(0, 0, 95, 44);
    ConfigBtn.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(133, 133, 133));
    ConfigBtn.setIconBitmaps(Bitmap(BITMAP_CONFIGURATION_ID), Bitmap(BITMAP_CONFIGURATION_ID));
    ConfigBtn.setIconXY(36, 18);
    ConfigBtn.setPosition(375, 224, 95, 44);

    InfusionBox.setPosition(19, 58, 336, 72);
    InfusionBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    InfusionBox.setAlpha(33);

    FirstRowBox.setPosition(19, 134, 336, 39);
    FirstRowBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    FirstRowBox.setAlpha(90);

    SecondRowBox.setPosition(19, 177, 336, 39);
    SecondRowBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    SecondRowBox.setAlpha(90);

    ThirdRowBox.setPosition(19, 220, 336, 39);
    ThirdRowBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    ThirdRowBox.setAlpha(90);

    Separator1.setBitmap(touchgfx::Bitmap(BITMAP_TRA107_ID));
    Separator1.setPosition(131, 134, 1, 39);
    Separator1.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    Separator2.setBitmap(touchgfx::Bitmap(BITMAP_TRA107_ID));
    Separator2.setPosition(243, 134, 1, 39);
    Separator2.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    Separator3.setBitmap(touchgfx::Bitmap(BITMAP_TRA107_ID));
    Separator3.setPosition(131, 179, 1, 39);
    Separator3.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    Separator4.setBitmap(touchgfx::Bitmap(BITMAP_TRA107_ID));
    Separator4.setPosition(243, 179, 1, 39);
    Separator4.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    Separator6.setBitmap(touchgfx::Bitmap(BITMAP_TRA107_ID));
    Separator6.setPosition(243, 220, 1, 39);
    Separator6.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    Separator5.setBitmap(touchgfx::Bitmap(BITMAP_TRA107_ID));
    Separator5.setPosition(131, 220, 1, 39);
    Separator5.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    RateBtn.setWildcardText(TypedText(T___SINGLEUSE_6S50));
    Unicode::snprintf(RateBtnBuffer, RATEBTN_SIZE, "%s", TypedText(T___SINGLEUSE_481E).getText());
    RateBtn.setWildcardTextBuffer(RateBtnBuffer);
    RateBtn.setWildcardTextPosition(0, 17, 336, 72);
    RateBtn.setWildcardTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(10, 10, 10));
    RateBtn.setPosition(19, 58, 336, 72);
    RateBtn.setAction(flexButtonCallback);

    RateTextArea.setXY(156, 58);
    RateTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    RateTextArea.setLinespacing(0);
    RateTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_CVGS));

    DrugBtn.setWildcardText(TypedText(T___SINGLEUSE_4HRK));
    Unicode::snprintf(DrugBtnBuffer, DRUGBTN_SIZE, "%s", TypedText(T___SINGLEUSE_SI6S).getText());
    DrugBtn.setWildcardTextBuffer(DrugBtnBuffer);
    DrugBtn.setWildcardTextPosition(0, 17, 112, 39);
    DrugBtn.setWildcardTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(10, 10, 10));
    DrugBtn.setPosition(19, 134, 112, 39);
    DrugBtn.setAction(flexButtonCallback);

    DrugTextArea.setXY(65, 134);
    DrugTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    DrugTextArea.setLinespacing(0);
    DrugTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_C4R9));

    VolumeBtn.setWildcardText(TypedText(T___SINGLEUSE_HZA1));
    Unicode::snprintf(VolumeBtnBuffer, VOLUMEBTN_SIZE, "%s", TypedText(T___SINGLEUSE_DN0H).getText());
    VolumeBtn.setWildcardTextBuffer(VolumeBtnBuffer);
    VolumeBtn.setWildcardTextPosition(0, 17, 112, 39);
    VolumeBtn.setWildcardTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(10, 10, 10));
    VolumeBtn.setPosition(131, 134, 112, 39);
    VolumeBtn.setAction(flexButtonCallback);

    VolumeTextArea.setXY(161, 134);
    VolumeTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    VolumeTextArea.setLinespacing(0);
    VolumeTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_83NG));

    TimeBtn.setTwoWildcardText(TypedText(T___SINGLEUSE_P4QD));
    Unicode::snprintf(TimeBtnBuffer1, TIMEBTNBUFFER1_SIZE, "%s", TypedText(T___SINGLEUSE_E7AK).getText());
    TimeBtn.setWildcardTextBuffer1(TimeBtnBuffer1);
    Unicode::snprintf(TimeBtnBuffer2, TIMEBTNBUFFER2_SIZE, "%s", TypedText(T___SINGLEUSE_PWCB).getText());
    TimeBtn.setWildcardTextBuffer2(TimeBtnBuffer2);
    TimeBtn.setTwoWildcardTextPosition(0, 17, 112, 39);
    TimeBtn.setTwoWildcardTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(10, 10, 10));
    TimeBtn.setPosition(245, 134, 112, 39);
    TimeBtn.setAction(flexButtonCallback);

    TimeTextArea.setXY(273, 134);
    TimeTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    TimeTextArea.setLinespacing(0);
    TimeTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_3O68));

    VTBIBtn.setWildcardText(TypedText(T___SINGLEUSE_XPVC));
    Unicode::snprintf(VTBIBtnBuffer, VTBIBTN_SIZE, "%s", TypedText(T___SINGLEUSE_A6SF).getText());
    VTBIBtn.setWildcardTextBuffer(VTBIBtnBuffer);
    VTBIBtn.setWildcardTextPosition(0, 17, 112, 39);
    VTBIBtn.setWildcardTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(10, 10, 10));
    VTBIBtn.setPosition(19, 177, 112, 39);
    VTBIBtn.setAction(flexButtonCallback);

    VTBITextArea.setXY(65, 177);
    VTBITextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    VTBITextArea.setLinespacing(0);
    VTBITextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8ABY));

    KVOBtn.setWildcardText(TypedText(T___SINGLEUSE_48UA));
    Unicode::snprintf(KVOBtnBuffer, KVOBTN_SIZE, "%s", TypedText(T___SINGLEUSE_3L5Y).getText());
    KVOBtn.setWildcardTextBuffer(KVOBtnBuffer);
    KVOBtn.setWildcardTextPosition(0, 17, 112, 39);
    KVOBtn.setWildcardTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(10, 10, 10));
    KVOBtn.setPosition(131, 177, 112, 39);
    KVOBtn.setAction(flexButtonCallback);

    KVOTextArea.setXY(169, 177);
    KVOTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    KVOTextArea.setLinespacing(0);
    KVOTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_12OE));

    BolusBtn.setWildcardText(TypedText(T___SINGLEUSE_3GG3));
    Unicode::snprintf(BolusBtnBuffer, BOLUSBTN_SIZE, "%s", TypedText(T___SINGLEUSE_3BLQ).getText());
    BolusBtn.setWildcardTextBuffer(BolusBtnBuffer);
    BolusBtn.setWildcardTextPosition(0, 17, 112, 39);
    BolusBtn.setWildcardTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(10, 10, 10));
    BolusBtn.setPosition(245, 177, 112, 39);
    BolusBtn.setAction(flexButtonCallback);

    BolusTextArea.setXY(280, 177);
    BolusTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    BolusTextArea.setLinespacing(0);
    BolusTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ILFS));

    LowThresholdTextArea.setXY(65, 219);
    LowThresholdTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    LowThresholdTextArea.setLinespacing(0);
    LowThresholdTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_MLFD));

    MediumThresholdTextArea.setXY(169, 220);
    MediumThresholdTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    MediumThresholdTextArea.setLinespacing(0);
    MediumThresholdTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_6LQ4));

    HighThresholdTextArea.setXY(291, 218);
    HighThresholdTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    HighThresholdTextArea.setLinespacing(0);
    HighThresholdTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_45FE));

    LowThresholdValueTextArea.setPosition(19, 239, 112, 15);
    LowThresholdValueTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    LowThresholdValueTextArea.setLinespacing(0);
    Unicode::snprintf(LowThresholdValueTextAreaBuffer, LOWTHRESHOLDVALUETEXTAREA_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_YVNF).getText());
    LowThresholdValueTextArea.setWildcard(LowThresholdValueTextAreaBuffer);
    LowThresholdValueTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_1NK5));

    MediumThresholdValueTextArea.setPosition(132, 239, 108, 15);
    MediumThresholdValueTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    MediumThresholdValueTextArea.setLinespacing(0);
    Unicode::snprintf(MediumThresholdValueTextAreaBuffer, MEDIUMTHRESHOLDVALUETEXTAREA_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_FNMP).getText());
    MediumThresholdValueTextArea.setWildcard(MediumThresholdValueTextAreaBuffer);
    MediumThresholdValueTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_OB2R));

    HighThresholdValueTextArea.setPosition(245, 239, 110, 15);
    HighThresholdValueTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    HighThresholdValueTextArea.setLinespacing(0);
    Unicode::snprintf(HighThresholdValueTextAreaBuffer, HIGHTHRESHOLDVALUETEXTAREA_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_0L97).getText());
    HighThresholdValueTextArea.setWildcard(HighThresholdValueTextAreaBuffer);
    HighThresholdValueTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_WKIS));

    PressureBtn.setBoxWithBorderPosition(0, 0, 50, 50);
    PressureBtn.setBorderSize(5);
    PressureBtn.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    PressureBtn.setPosition(19, 220, 336, 39);
    PressureBtn.setAlpha(0);
    PressureBtn.setAction(flexButtonCallback);

    add(__background);
    add(ChildrenBackground);
    add(DarkBackground);
    add(DefaultBackground);
    add(BackBtnBox);
    add(BackBtn);
    add(ConfigBtnBox);
    add(ConfigBtn);
    add(InfusionBox);
    add(FirstRowBox);
    add(SecondRowBox);
    add(ThirdRowBox);
    add(Separator1);
    add(Separator2);
    add(Separator3);
    add(Separator4);
    add(Separator6);
    add(Separator5);
    add(RateBtn);
    add(RateTextArea);
    add(DrugBtn);
    add(DrugTextArea);
    add(VolumeBtn);
    add(VolumeTextArea);
    add(TimeBtn);
    add(TimeTextArea);
    add(VTBIBtn);
    add(VTBITextArea);
    add(KVOBtn);
    add(KVOTextArea);
    add(BolusBtn);
    add(BolusTextArea);
    add(LowThresholdTextArea);
    add(MediumThresholdTextArea);
    add(HighThresholdTextArea);
    add(LowThresholdValueTextArea);
    add(MediumThresholdValueTextArea);
    add(HighThresholdValueTextArea);
    add(PressureBtn);
}

void ConfigurationViewBase::setupScreen()
{

    //MoveBtnBox
    //When screen transition begins move ConfigBtnBox
    //Move ConfigBtnBox to x:375, y:223 with LinearIn easing in 200 ms (12 Ticks)
    ConfigBtnBox.clearMoveAnimationEndedAction();
    ConfigBtnBox.startMoveAnimation(375, 223, 12, touchgfx::EasingEquations::linearEaseIn, touchgfx::EasingEquations::linearEaseIn);

}

void ConfigurationViewBase::InitKeyboard(uint8_t value)
{
    //GotoKeyboard
    //When InitKeyboard is called change screen to KeyboardNb
    //Go to KeyboardNb with screen transition towards South
    application().gotoKeyboardNbScreenWipeTransitionSouth();
}

void ConfigurationViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &BackBtn)
    {
        //GoBackToMain
        //When BackBtn clicked change screen to Main
        //Go to Main with screen transition towards North
        application().gotoMainScreenWipeTransitionNorth();
    }
    else if (&src == &RateBtn)
    {
        //InitKeyboardRate
        //When RateBtn clicked call InitKeyboard on Configuration
        //Call InitKeyboard
        InitKeyboard(4);
    }
    else if (&src == &DrugBtn)
    {
        //gotoDrug
        //When DrugBtn clicked change screen to DrugLibrary
        //Go to DrugLibrary with screen transition towards South
        application().gotoDrugLibraryScreenWipeTransitionSouth();
    }
    else if (&src == &VolumeBtn)
    {
        //InitKeyboardVolume
        //When VolumeBtn clicked call InitKeyboard on Configuration
        //Call InitKeyboard
        InitKeyboard(5);
    }
    else if (&src == &TimeBtn)
    {
        //setPerfusionTime
        //When TimeBtn clicked change screen to PerfusionTimeSetting
        //Go to PerfusionTimeSetting with screen transition towards South
        application().gotoPerfusionTimeSettingScreenWipeTransitionSouth();
    }
    else if (&src == &VTBIBtn)
    {
        //InitKeyboardVTBI
        //When VTBIBtn clicked call InitKeyboard on Configuration
        //Call InitKeyboard
        InitKeyboard(6);
    }
    else if (&src == &KVOBtn)
    {
        //InitKeyboardKVO
        //When KVOBtn clicked call InitKeyboard on Configuration
        //Call InitKeyboard
        InitKeyboard(7);
    }
    else if (&src == &BolusBtn)
    {
        //InitKeyboardBolus
        //When BolusBtn clicked call InitKeyboard on Configuration
        //Call InitKeyboard
        InitKeyboard(8);
    }
    else if (&src == &PressureBtn)
    {
        //GotoPressureThresholds
        //When PressureBtn clicked change screen to OclusionThresholds
        //Go to OclusionThresholds with screen transition towards South
        application().gotoOclusionThresholdsScreenWipeTransitionSouth();
    }
}
