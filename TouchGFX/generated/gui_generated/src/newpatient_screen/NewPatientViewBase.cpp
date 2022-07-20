/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/newpatient_screen/NewPatientViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

NewPatientViewBase::NewPatientViewBase() :
    flexButtonCallback(this, &NewPatientViewBase::flexButtonCallbackHandler)
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
    DefaultBackground.setPosition(0, 0, 480, 271);
    DefaultBackground.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    Title.setXY(182, 3);
    Title.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Title.setLinespacing(0);
    Title.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Q1XL));

    BackBtnBox.setPosition(371, 3, 95, 32);
    BackBtnBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    BackBtnBox.setAlpha(90);

    BackBtn.setText(TypedText(T___SINGLEUSE_0ZXQ));
    BackBtn.setTextPosition(-6, 5, 95, 32);
    BackBtn.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(133, 133, 133));
    BackBtn.setPosition(371, 3, 95, 32);
    BackBtn.setAction(flexButtonCallback);

    BackArrow.setBitmap(touchgfx::Bitmap(BITMAP_GROUPE49_ID));
    BackArrow.setPosition(384, 14, 18, 11);
    BackArrow.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    Name.setXY(38, 51);
    Name.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Name.setLinespacing(0);
    Name.setTypedText(touchgfx::TypedText(T___SINGLEUSE_2MRF));

    Age.setXY(51, 91);
    Age.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Age.setLinespacing(0);
    Age.setTypedText(touchgfx::TypedText(T___SINGLEUSE_SEI9));

    Height.setXY(33, 129);
    Height.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Height.setLinespacing(0);
    Height.setTypedText(touchgfx::TypedText(T___SINGLEUSE_KDZJ));

    Weight.setXY(30, 168);
    Weight.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Weight.setLinespacing(0);
    Weight.setTypedText(touchgfx::TypedText(T___SINGLEUSE_AHH2));

    Gender.setXY(27, 207);
    Gender.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Gender.setLinespacing(0);
    Gender.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ESE7));

    NameBox.setPosition(84, 44, 347, 38);
    NameBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    NameBox.setAlpha(90);

    AgeBox.setPosition(84, 83, 347, 38);
    AgeBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    AgeBox.setAlpha(90);

    HeightBox.setPosition(84, 122, 347, 38);
    HeightBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    HeightBox.setAlpha(90);

    WeightBox.setPosition(84, 161, 347, 38);
    WeightBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    WeightBox.setAlpha(90);

    GenderBox.setPosition(84, 200, 347, 38);
    GenderBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    GenderBox.setAlpha(90);

    SaveBtnBox.setPosition(208, 239, 95, 32);
    SaveBtnBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    SaveBtnBox.setAlpha(90);

    SaveBtn.setText(TypedText(T___SINGLEUSE_G9T6));
    SaveBtn.setTextPosition(-1, 3, 95, 32);
    SaveBtn.setTextColors(touchgfx::Color::getColorFromRGB(250, 250, 250), touchgfx::Color::getColorFromRGB(133, 133, 133));
    SaveBtn.setPosition(208, 239, 95, 32);
    SaveBtn.setAction(flexButtonCallback);

    HeightUnit.setXY(410, 129);
    HeightUnit.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    HeightUnit.setLinespacing(0);
    HeightUnit.setTypedText(touchgfx::TypedText(T___SINGLEUSE_3CBF));

    WeightUnit.setXY(408, 168);
    WeightUnit.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    WeightUnit.setLinespacing(0);
    WeightUnit.setTypedText(touchgfx::TypedText(T___SINGLEUSE_DM4E));

    NameBtn.setWildcardText(TypedText(T___SINGLEUSE_HT20));
    NameBtnBuffer[0] = 0;
    NameBtn.setWildcardTextBuffer(NameBtnBuffer);
    NameBtn.setWildcardTextPosition(0, 7, 347, 39);
    NameBtn.setWildcardTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255));
    NameBtn.setPosition(84, 44, 347, 39);
    NameBtn.setAction(flexButtonCallback);

    AgeBtn.setWildcardText(TypedText(T___SINGLEUSE_NLK2));
    AgeBtnBuffer[0] = 0;
    AgeBtn.setWildcardTextBuffer(AgeBtnBuffer);
    AgeBtn.setWildcardTextPosition(0, 7, 347, 39);
    AgeBtn.setWildcardTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255));
    AgeBtn.setPosition(84, 82, 347, 39);
    AgeBtn.setAction(flexButtonCallback);

    HeightBtn.setWildcardText(TypedText(T___SINGLEUSE_5CD1));
    HeightBtnBuffer[0] = 0;
    HeightBtn.setWildcardTextBuffer(HeightBtnBuffer);
    HeightBtn.setWildcardTextPosition(0, 7, 347, 39);
    HeightBtn.setWildcardTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255));
    HeightBtn.setPosition(84, 122, 347, 39);
    HeightBtn.setAction(flexButtonCallback);

    WeightBtn.setWildcardText(TypedText(T___SINGLEUSE_YNPX));
    WeightBtnBuffer[0] = 0;
    WeightBtn.setWildcardTextBuffer(WeightBtnBuffer);
    WeightBtn.setWildcardTextPosition(0, 7, 347, 39);
    WeightBtn.setWildcardTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255));
    WeightBtn.setPosition(84, 160, 347, 39);
    WeightBtn.setAction(flexButtonCallback);

    GenderBtn.setWildcardText(TypedText(T___SINGLEUSE_DG0Q));
    GenderBtnBuffer[0] = 0;
    GenderBtn.setWildcardTextBuffer(GenderBtnBuffer);
    GenderBtn.setWildcardTextPosition(0, 7, 347, 39);
    GenderBtn.setWildcardTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255));
    GenderBtn.setPosition(84, 199, 347, 39);
    GenderBtn.setAction(flexButtonCallback);

    add(__background);
    add(ChildrenBackground);
    add(DarkBackground);
    add(DefaultBackground);
    add(Title);
    add(BackBtnBox);
    add(BackBtn);
    add(BackArrow);
    add(Name);
    add(Age);
    add(Height);
    add(Weight);
    add(Gender);
    add(NameBox);
    add(AgeBox);
    add(HeightBox);
    add(WeightBox);
    add(GenderBox);
    add(SaveBtnBox);
    add(SaveBtn);
    add(HeightUnit);
    add(WeightUnit);
    add(NameBtn);
    add(AgeBtn);
    add(HeightBtn);
    add(WeightBtn);
    add(GenderBtn);
}

void NewPatientViewBase::setupScreen()
{

}

void NewPatientViewBase::InitKeyPadUser(uint8_t value)
{
    //GotoNumberKeyboard
    //When InitKeyPadUser is called change screen to KeyboardNb
    //Go to KeyboardNb with screen transition towards South
    application().gotoKeyboardNbScreenWipeTransitionSouth();
}

void NewPatientViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &BackBtn)
    {
        //GoBack
        //When BackBtn clicked change screen to Home
        //Go to Home with screen transition towards West
        application().gotoHomeScreenWipeTransitionWest();
    }
    else if (&src == &SaveBtn)
    {
        //SavePatientData
        //When SaveBtn clicked call virtual function
        //Call SavePatientData
        SavePatientData();

        //GotoMain
        //When SavePatientData completed change screen to Main
        //Go to Main with screen transition towards East
        application().gotoMainScreenWipeTransitionEast();
    }
    else if (&src == &NameBtn)
    {
        //InitKeyboard
        //When NameBtn clicked call virtual function
        //Call InitKeyboard
        InitKeyboard();

        //GotoNameInputKeyboard
        //When InitKeyboard completed change screen to Keyboard
        //Go to Keyboard with screen transition towards South
        application().gotoKeyboardScreenWipeTransitionSouth();
    }
    else if (&src == &AgeBtn)
    {
        //InitKeyboardToAge
        //When AgeBtn clicked call InitKeyPadUser on NewPatient
        //Call InitKeyPadUser
        InitKeyPadUser(1);
    }
    else if (&src == &HeightBtn)
    {
        //InitKeyboardToHeight
        //When HeightBtn clicked call InitKeyPadUser on NewPatient
        //Call InitKeyPadUser
        InitKeyPadUser(2);
    }
    else if (&src == &WeightBtn)
    {
        //InitKeyboardToWeight
        //When WeightBtn clicked call InitKeyPadUser on NewPatient
        //Call InitKeyPadUser
        InitKeyPadUser(3);
    }
    else if (&src == &GenderBtn)
    {
        //GotoGenderChoiceScreen
        //When GenderBtn clicked change screen to GenderChoice
        //Go to GenderChoice with screen transition towards South
        application().gotoGenderChoiceScreenWipeTransitionSouth();
    }
}
