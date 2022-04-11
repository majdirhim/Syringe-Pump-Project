#ifndef SCREENBORDER_HPP
#define SCREENBORDER_HPP

#include <gui_generated/containers/ScreenBorderBase.hpp>

class ScreenBorder : public ScreenBorderBase
{
public:
    ScreenBorder();
    virtual ~ScreenBorder() {}

    void setColor(colortype color);

    virtual void initialize();
protected:
};

#endif // SCREENBORDER_HPP
