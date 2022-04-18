/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/LogDisplayBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>

LogDisplayBase::LogDisplayBase()
{
    setWidth(480);
    setHeight(35);
    box.setPosition(0, 0, 480, 35);
    box.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    box.setAlpha(90);

    Separator1.setBitmap(touchgfx::Bitmap(BITMAP_TRA107_ID));
    Separator1.setPosition(37, 0, 1, 35);
    Separator1.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    Separator2.setBitmap(touchgfx::Bitmap(BITMAP_TRA107_ID));
    Separator2.setPosition(221, 0, 1, 35);
    Separator2.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    Separator3.setBitmap(touchgfx::Bitmap(BITMAP_TRA107_ID));
    Separator3.setPosition(288, 0, 1, 35);
    Separator3.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    Separator5.setBitmap(touchgfx::Bitmap(BITMAP_TRA107_ID));
    Separator5.setPosition(391, 0, 1, 35);
    Separator5.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    add(box);
    add(Separator1);
    add(Separator2);
    add(Separator3);
    add(Separator5);
}

void LogDisplayBase::initialize()
{

}
