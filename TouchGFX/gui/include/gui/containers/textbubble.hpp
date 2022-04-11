#ifndef TEXTBUBBLE_HPP
#define TEXTBUBBLE_HPP

#include <gui_generated/containers/textbubbleBase.hpp>
#include <touchgfx/Color.hpp>

class textbubble : public textbubbleBase
{
public:
    textbubble();
    virtual ~textbubble() {}
    void setText(uint16_t, uint8_t, uint8_t, uint8_t);

    virtual void initialize();
protected:
};

#endif // TEXTBUBBLE_HPP
