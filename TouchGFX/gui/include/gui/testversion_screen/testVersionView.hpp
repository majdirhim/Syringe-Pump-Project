#ifndef TESTVERSIONVIEW_HPP
#define TESTVERSIONVIEW_HPP

#include <gui_generated/testversion_screen/testVersionViewBase.hpp>
#include <gui/testversion_screen/testVersionPresenter.hpp>

class testVersionView : public testVersionViewBase
{
public:
    testVersionView();
    virtual ~testVersionView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void StartSensor();
    virtual void EndSensor();
    virtual void Diameter();
    virtual void Position();

protected:
   uint8_t start = 0;
   uint8_t end = 0;
   uint8_t var = 0;
};

#endif // TESTVERSIONVIEW_HPP
