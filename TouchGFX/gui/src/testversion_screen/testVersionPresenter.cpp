#include <gui/testversion_screen/testVersionView.hpp>
#include <gui/testversion_screen/testVersionPresenter.hpp>

testVersionPresenter::testVersionPresenter(testVersionView& v)
    : view(v)
{

}

void testVersionPresenter::activate()
{

}

void testVersionPresenter::deactivate()
{

}

void testVersionPresenter::sendstart(uint8_t state)
{
    model->saveStart(state);
}

void testVersionPresenter::sendend(uint8_t state)
{
    model->saveEnd(state);
}

void testVersionPresenter::sendvar(uint16_t state)
{
    model->saveinputdestinsation(state);
}
