#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::syringePumpProgress(){
	//Flow=textArea1.getWildcard();
	Flow=textProgress1.getValue();
	presenter->PresenterGetFlowRate(Flow);
}

