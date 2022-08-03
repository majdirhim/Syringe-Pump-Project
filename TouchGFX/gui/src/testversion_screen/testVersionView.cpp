#include <gui/testversion_screen/testVersionView.hpp>

testVersionView::testVersionView()
{

}

void testVersionView::setupScreen()
{
    testVersionViewBase::setupScreen();
}

void testVersionView::tearDownScreen()
{
    testVersionViewBase::tearDownScreen();
}
void testVersionView::StartSensor()
{
    switch(start)
    {
    case 0:
    	presenter->sendstart(1);
    	start = 1;
    	break;
    case 1:
    	presenter->sendstart(0);
    	start = 0;
    }
}

void testVersionView::EndSensor()
{
    switch(end)
    {
    case 0:
    	presenter->sendend(1);
    	end = 1;
    	break;
    case 1:
    	presenter->sendend(0);
    	end = 0;
    }
}

void testVersionView::Diameter()
{
	presenter->sendvar(7);
}

void testVersionView::Position()
{
	presenter->sendvar(8);
}
