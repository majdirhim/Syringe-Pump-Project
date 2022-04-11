#include <gui/containers/ScreenBorder.hpp>
#include <touchgfx/Color.hpp>

ScreenBorder::ScreenBorder()
{

}

void ScreenBorder::initialize()
{
    ScreenBorderBase::initialize();
}


void ScreenBorder::setColor(colortype color)
{
    line1Painter.setColor(color);
    line2Painter.setColor(color);
    line3Painter.setColor(color);
    line4Painter.setColor(color);
}
