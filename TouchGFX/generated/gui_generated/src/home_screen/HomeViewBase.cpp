/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/home_screen/HomeViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

HomeViewBase::HomeViewBase() :
    flexButtonCallback(this, &HomeViewBase::flexButtonCallbackHandler)
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

    MediWaveLogo.setBitmap(touchgfx::Bitmap(BITMAP_GROUPE7_ID));
    MediWaveLogo.setPosition(252, 106, 78, 103);
    MediWaveLogo.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    NewPatientBtnBox.setPosition(7, 55, 200, 40);
    NewPatientBtnBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    NewPatientBtnBox.setAlpha(90);

    NewPatientBtn.setText(TypedText(T___SINGLEUSE_4IHP));
    NewPatientBtn.setTextPosition(40, 7, 200, 40);
    NewPatientBtn.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(133, 133, 133));
    NewPatientBtn.setIconBitmaps(Bitmap(BITMAP_MEDICAL_ID), Bitmap(BITMAP_MEDICAL_ID));
    NewPatientBtn.setIconXY(4, 5);
    NewPatientBtn.setPosition(7, 55, 200, 40);
    NewPatientBtn.setAction(flexButtonCallback);

    LastPatientBtnBox.setPosition(7, 96, 200, 40);
    LastPatientBtnBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    LastPatientBtnBox.setAlpha(90);

    LastPatientBtn.setText(TypedText(T___SINGLEUSE_6VQU));
    LastPatientBtn.setTextPosition(40, 7, 200, 40);
    LastPatientBtn.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(133, 133, 133));
    LastPatientBtn.setIconBitmaps(Bitmap(BITMAP_MEDICAL_HISTORY_ID), Bitmap(BITMAP_MEDICAL_HISTORY_ID));
    LastPatientBtn.setIconXY(5, 3);
    LastPatientBtn.setPosition(7, 96, 200, 40);
    LastPatientBtn.setAction(flexButtonCallback);

    AnonymousPatientBtnBox.setPosition(1, 116, 200, 40);
    AnonymousPatientBtnBox.setVisible(false);
    AnonymousPatientBtnBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    AnonymousPatientBtnBox.setAlpha(90);

    PatientDatabaseBtnBox.setPosition(7, 137, 200, 40);
    PatientDatabaseBtnBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    PatientDatabaseBtnBox.setAlpha(90);

    PatientDatabaseBtn.setText(TypedText(T___SINGLEUSE_PCEM));
    PatientDatabaseBtn.setTextPosition(40, 7, 200, 40);
    PatientDatabaseBtn.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(133, 133, 133));
    PatientDatabaseBtn.setIconBitmaps(Bitmap(BITMAP_MEDICALBASE_ID), Bitmap(BITMAP_MEDICALBASE_ID));
    PatientDatabaseBtn.setIconXY(5, 5);
    PatientDatabaseBtn.setPosition(7, 137, 200, 40);
    PatientDatabaseBtn.setAction(flexButtonCallback);

    SpecialModesBtnBox.setPosition(7, 178, 200, 40);
    SpecialModesBtnBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    SpecialModesBtnBox.setAlpha(90);

    SpecialModesBtn.setText(TypedText(T___SINGLEUSE_LS2S));
    SpecialModesBtn.setTextPosition(40, 7, 200, 40);
    SpecialModesBtn.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(133, 133, 133));
    SpecialModesBtn.setIconBitmaps(Bitmap(BITMAP_DOCTOR_ID), Bitmap(BITMAP_DOCTOR_ID));
    SpecialModesBtn.setIconXY(1, 4);
    SpecialModesBtn.setPosition(7, 178, 200, 40);
    SpecialModesBtn.setAction(flexButtonCallback);

    SyriWave.setXY(220, 1);
    SyriWave.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    SyriWave.setLinespacing(0);
    SyriWave.setTypedText(touchgfx::TypedText(T___SINGLEUSE_WYBN));

    Arc.setBitmap(touchgfx::Bitmap(BITMAP_TRACE4_ID));
    Arc.setPosition(401, -4, 37, 290);
    Arc.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    AnonymousPatientBtn.setIconBitmaps(Bitmap(BITMAP_GROUPE2_ID), Bitmap(BITMAP_GROUPE2_ID));
    AnonymousPatientBtn.setIconXY(3, 5);
    AnonymousPatientBtn.setPosition(401, 116, 53, 53);
    AnonymousPatientBtn.setAction(flexButtonCallback);

    add(__background);
    add(ChildrenBackground);
    add(DarkBackground);
    add(DefaultBackground);
    add(MediWaveLogo);
    add(NewPatientBtnBox);
    add(NewPatientBtn);
    add(LastPatientBtnBox);
    add(LastPatientBtn);
    add(AnonymousPatientBtnBox);
    add(PatientDatabaseBtnBox);
    add(PatientDatabaseBtn);
    add(SpecialModesBtnBox);
    add(SpecialModesBtn);
    add(SyriWave);
    add(Arc);
    add(AnonymousPatientBtn);
}

void HomeViewBase::setupScreen()
{

}

void HomeViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &NewPatientBtn)
    {
        //GotoNewPatient
        //When NewPatientBtn clicked change screen to NewPatient
        //Go to NewPatient with screen transition towards East
        application().gotoNewPatientScreenWipeTransitionEast();
    }
    else if (&src == &LastPatientBtn)
    {
        //GotoSamePatient
        //When LastPatientBtn clicked change screen to SamePatient
        //Go to SamePatient with screen transition towards East
        application().gotoSamePatientScreenWipeTransitionEast();
    }
    else if (&src == &PatientDatabaseBtn)
    {
        //GotoPatientsDataBase
        //When PatientDatabaseBtn clicked change screen to PatientDatabase
        //Go to PatientDatabase with screen transition towards East
        application().gotoPatientDatabaseScreenWipeTransitionEast();
    }
    else if (&src == &SpecialModesBtn)
    {
        //GotoSpecialModes
        //When SpecialModesBtn clicked change screen to SpecialModes
        //Go to SpecialModes with screen transition towards East
        application().gotoSpecialModesScreenWipeTransitionEast();
    }
    else if (&src == &AnonymousPatientBtn)
    {
        //GotoMain
        //When AnonymousPatientBtn clicked change screen to Main
        //Go to Main with screen transition towards East
        application().gotoMainScreenWipeTransitionEast();
    }
}