/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/patientdatabase_screen/PatientDatabaseViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

PatientDatabaseViewBase::PatientDatabaseViewBase() :
    waitForRequestCounter(0),
    flexButtonCallback(this, &PatientDatabaseViewBase::flexButtonCallbackHandler)
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

    LoadingPopUp.setBackground(touchgfx::BitmapId(BITMAP_WARNVING_ID), 76, 45);
    LoadingPopUp.setShadeColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    LoadingPopUp.setShadeAlpha(150);
    LoadingPopUp.hide();

    ErrorMsgTextArea.setPosition(47, 66, 238, 50);
    ErrorMsgTextArea.setVisible(false);
    ErrorMsgTextArea.setColor(touchgfx::Color::getColorFromRGB(252, 5, 5));
    ErrorMsgTextArea.setLinespacing(0);
    ErrorMsgTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_B957));
    LoadingPopUp.add(ErrorMsgTextArea);

    LoadingAnimation.setXY(144, 70);
    LoadingAnimation.setBitmaps(BITMAP_MINI_FLAT_HOURGLASS_0_ID, BITMAP_MINI_FLAT_HOURGLASS_321_ID);
    LoadingAnimation.setUpdateTicksInterval(6);
    LoadingAnimation.startAnimation(false, true, true);
    LoadingPopUp.add(LoadingAnimation);

    PatientDisplay.setPosition(0, 0, 480, 271);
    PatientDisplay.setVisible(false);

    Name.setXY(38, 51);
    Name.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Name.setLinespacing(0);
    Name.setTypedText(touchgfx::TypedText(T___SINGLEUSE_LM1G));
    PatientDisplay.add(Name);

    Age.setXY(51, 91);
    Age.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Age.setLinespacing(0);
    Age.setTypedText(touchgfx::TypedText(T___SINGLEUSE_5AST));
    PatientDisplay.add(Age);

    Height.setXY(33, 129);
    Height.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Height.setLinespacing(0);
    Height.setTypedText(touchgfx::TypedText(T___SINGLEUSE_6T0L));
    PatientDisplay.add(Height);

    Weight.setXY(30, 168);
    Weight.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Weight.setLinespacing(0);
    Weight.setTypedText(touchgfx::TypedText(T___SINGLEUSE_2HC0));
    PatientDisplay.add(Weight);

    Gender.setXY(27, 207);
    Gender.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Gender.setLinespacing(0);
    Gender.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GL1P));
    PatientDisplay.add(Gender);

    NameBox.setPosition(84, 44, 347, 38);
    NameBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    NameBox.setAlpha(90);
    PatientDisplay.add(NameBox);

    AgeBox.setPosition(84, 83, 347, 38);
    AgeBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    AgeBox.setAlpha(90);
    PatientDisplay.add(AgeBox);

    HeightBox.setPosition(84, 122, 347, 38);
    HeightBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    HeightBox.setAlpha(90);
    PatientDisplay.add(HeightBox);

    WeightBox.setPosition(84, 161, 347, 38);
    WeightBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    WeightBox.setAlpha(90);
    PatientDisplay.add(WeightBox);

    GenderBox.setPosition(84, 200, 347, 38);
    GenderBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    GenderBox.setAlpha(90);
    PatientDisplay.add(GenderBox);

    SaveBtnBox.setPosition(208, 239, 95, 32);
    SaveBtnBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    SaveBtnBox.setAlpha(90);
    PatientDisplay.add(SaveBtnBox);

    SaveBtn.setText(TypedText(T___SINGLEUSE_OBHW));
    SaveBtn.setTextPosition(-1, 3, 95, 32);
    SaveBtn.setTextColors(touchgfx::Color::getColorFromRGB(250, 250, 250), touchgfx::Color::getColorFromRGB(133, 133, 133));
    SaveBtn.setPosition(208, 239, 95, 32);
    SaveBtn.setAction(flexButtonCallback);
    PatientDisplay.add(SaveBtn);

    WeightUnit.setXY(408, 168);
    WeightUnit.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    WeightUnit.setLinespacing(0);
    WeightUnit.setTypedText(touchgfx::TypedText(T___SINGLEUSE_W6JA));
    PatientDisplay.add(WeightUnit);

    HeightUnit.setXY(410, 129);
    HeightUnit.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    HeightUnit.setLinespacing(0);
    HeightUnit.setTypedText(touchgfx::TypedText(T___SINGLEUSE_OB5F));
    PatientDisplay.add(HeightUnit);

    NameTextArea.setPosition(84, 49, 346, 26);
    NameTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    NameTextArea.setLinespacing(0);
    Unicode::snprintf(NameTextAreaBuffer, NAMETEXTAREA_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_JUK2).getText());
    NameTextArea.setWildcard(NameTextAreaBuffer);
    NameTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_FLYQ));
    PatientDisplay.add(NameTextArea);

    AgeTextArea.setPosition(85, 89, 346, 26);
    AgeTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    AgeTextArea.setLinespacing(0);
    Unicode::snprintf(AgeTextAreaBuffer, AGETEXTAREA_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_2CQ4).getText());
    AgeTextArea.setWildcard(AgeTextAreaBuffer);
    AgeTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_TR6V));
    PatientDisplay.add(AgeTextArea);

    HeightTextArea.setPosition(85, 129, 346, 26);
    HeightTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    HeightTextArea.setLinespacing(0);
    Unicode::snprintf(HeightTextAreaBuffer, HEIGHTTEXTAREA_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_4AEJ).getText());
    HeightTextArea.setWildcard(HeightTextAreaBuffer);
    HeightTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_HW6V));
    PatientDisplay.add(HeightTextArea);

    WeightTextArea.setPosition(85, 167, 346, 26);
    WeightTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    WeightTextArea.setLinespacing(0);
    Unicode::snprintf(WeightTextAreaBuffer, WEIGHTTEXTAREA_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_EM69).getText());
    WeightTextArea.setWildcard(WeightTextAreaBuffer);
    WeightTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_FF24));
    PatientDisplay.add(WeightTextArea);

    GenderTextArea.setPosition(84, 206, 346, 26);
    GenderTextArea.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    GenderTextArea.setLinespacing(0);
    Unicode::snprintf(GenderTextAreaBuffer, GENDERTEXTAREA_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_SVRV).getText());
    GenderTextArea.setWildcard(GenderTextAreaBuffer);
    GenderTextArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_J0FQ));
    PatientDisplay.add(GenderTextArea);

    SearchContainer.setPosition(0, 0, 480, 272);

    SearchBtnBox.setPosition(193, 183, 95, 32);
    SearchBtnBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    SearchBtnBox.setAlpha(90);
    SearchContainer.add(SearchBtnBox);

    SearchBtn.setText(TypedText(T___SINGLEUSE_AI3R));
    SearchBtn.setTextPosition(-1, 3, 95, 32);
    SearchBtn.setTextColors(touchgfx::Color::getColorFromRGB(250, 250, 250), touchgfx::Color::getColorFromRGB(133, 133, 133));
    SearchBtn.setPosition(193, 183, 95, 32);
    SearchBtn.setAction(flexButtonCallback);
    SearchContainer.add(SearchBtn);

    SearchedName.setXY(176, 79);
    SearchedName.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    SearchedName.setLinespacing(0);
    SearchedName.setTypedText(touchgfx::TypedText(T___SINGLEUSE_AZPC));
    SearchContainer.add(SearchedName);

    SearchedNameBox.setPosition(67, 117, 347, 38);
    SearchedNameBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    SearchedNameBox.setAlpha(90);
    SearchContainer.add(SearchedNameBox);

    SearchedNameBtn.setWildcardText(TypedText(T___SINGLEUSE_BJRJ));
    SearchedNameBtnBuffer[0] = 0;
    SearchedNameBtn.setWildcardTextBuffer(SearchedNameBtnBuffer);
    SearchedNameBtn.setWildcardTextPosition(0, 7, 347, 39);
    SearchedNameBtn.setWildcardTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(255, 255, 255));
    SearchedNameBtn.setPosition(67, 117, 347, 39);
    SearchedNameBtn.setAction(flexButtonCallback);
    SearchContainer.add(SearchedNameBtn);

    Title.setXY(148, 3);
    Title.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Title.setLinespacing(0);
    Title.setTypedText(touchgfx::TypedText(T___SINGLEUSE_7VPT));

    BackBtnBox.setPosition(371, 3, 95, 32);
    BackBtnBox.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    BackBtnBox.setAlpha(90);

    BackBtn.setText(TypedText(T___SINGLEUSE_FW4M));
    BackBtn.setTextPosition(-6, 7, 95, 32);
    BackBtn.setTextColors(touchgfx::Color::getColorFromRGB(255, 255, 255), touchgfx::Color::getColorFromRGB(133, 133, 133));
    BackBtn.setPosition(371, 3, 95, 32);
    BackBtn.setAction(flexButtonCallback);

    BackArrow.setBitmap(touchgfx::Bitmap(BITMAP_GROUPE49_ID));
    BackArrow.setPosition(384, 14, 18, 11);
    BackArrow.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    add(__background);
    add(ChildrenBackground);
    add(DarkBackground);
    add(DefaultBackground);
    add(LoadingPopUp);
    add(PatientDisplay);
    add(SearchContainer);
    add(Title);
    add(BackBtnBox);
    add(BackBtn);
    add(BackArrow);
}

void PatientDatabaseViewBase::setupScreen()
{

}

//Handles delays
void PatientDatabaseViewBase::handleTickEvent()
{
    if(waitForRequestCounter > 0)
    {
        waitForRequestCounter--;
        if(waitForRequestCounter == 0)
        {
            //VertifyRequestResponse
            //When WaitForRequest completed call virtual function
            //Call VertifyRequestResponse
            VertifyRequestResponse();
        }
    }
}

void PatientDatabaseViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &SaveBtn)
    {
        //SavePatient
        //When SaveBtn clicked call virtual function
        //Call SavePatient
        SavePatient();
    }
    else if (&src == &SearchBtn)
    {
        //RequestPatientSearch
        //When SearchBtn clicked call virtual function
        //Call RequestPatientSearch
        RequestPatientSearch();

        //HideSearchContainer
        //When RequestPatientSearch completed hide SearchContainer
        //Hide SearchContainer
        SearchContainer.setVisible(false);
        SearchContainer.invalidate();

        //ShowLoadingPopUp
        //When HideSearchContainer completed show LoadingPopUp
        //Show LoadingPopUp
        LoadingPopUp.setVisible(true);
        LoadingPopUp.invalidate();

        //WaitForRequest
        //When ShowLoadingPopUp completed delay
        //Delay for 1500 ms (90 Ticks)
        waitForRequestCounter = WAITFORREQUEST_DURATION;
    }
    else if (&src == &SearchedNameBtn)
    {
        //InitKeyboard
        //When SearchedNameBtn clicked call virtual function
        //Call InitKeyboard
        InitKeyboard();

        //GotoKeyboard
        //When InitKeyboard completed change screen to Keyboard
        //Go to Keyboard with screen transition towards South
        application().gotoKeyboardScreenWipeTransitionSouth();
    }
    else if (&src == &BackBtn)
    {
        //GoBack
        //When BackBtn clicked change screen to Home
        //Go to Home with screen transition towards West
        application().gotoHomeScreenWipeTransitionWest();
    }
}