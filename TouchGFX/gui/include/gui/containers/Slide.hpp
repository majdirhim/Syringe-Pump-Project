#ifndef SLIDE_HPP
#define SLIDE_HPP

#include <gui_generated/containers/SlideBase.hpp>

class Slide : public SlideBase
{
public:
    Slide();
    virtual ~Slide() {}

    virtual void initialize();
protected:
};

#endif // SLIDE_HPP
