#ifndef SOUNDVIEW_HPP
#define SOUNDVIEW_HPP

#include <gui_generated/sound_screen/SoundViewBase.hpp>
#include <gui/sound_screen/SoundPresenter.hpp>

class SoundView : public SoundViewBase
{
public:
    SoundView();
    virtual ~SoundView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SOUNDVIEW_HPP
