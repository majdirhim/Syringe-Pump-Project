/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/perfusiontimesetting_screen/PerfusionTimeSettingViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>

PerfusionTimeSettingViewBase::PerfusionTimeSettingViewBase()
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

    add(__background);
    add(ChildrenBackground);
    add(DarkBackground);
    add(DefaultBackground);
}

void PerfusionTimeSettingViewBase::setupScreen()
{

}