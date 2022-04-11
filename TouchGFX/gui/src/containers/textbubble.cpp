#include <gui/containers/textbubble.hpp>

textbubble::textbubble()
{

}

void textbubble::setText(uint16_t pressure, uint8_t red, uint8_t green, uint8_t blue)
{
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", pressure);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(red, green, blue));
    textArea1.invalidate();
}

void textbubble::initialize()
{
    textbubbleBase::initialize();
}
