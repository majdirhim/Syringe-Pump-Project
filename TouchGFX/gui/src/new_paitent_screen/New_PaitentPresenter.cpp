#include <gui/new_paitent_screen/New_PaitentView.hpp>
#include <gui/new_paitent_screen/New_PaitentPresenter.hpp>

New_PaitentPresenter::New_PaitentPresenter(New_PaitentView& v)
    : view(v)
{

}

void New_PaitentPresenter::activate()
{

}

void New_PaitentPresenter::deactivate()
{

}

uint8_t New_PaitentPresenter::getgender()
{
    return model->getgender();
}

void New_PaitentPresenter::savepatientage(uint8_t value)
{
    model->savepatientage(value);
}

void New_PaitentPresenter::savepatientname(char * value, uint8_t len)
{
    model->savepatientname(value, len);
}

void New_PaitentPresenter::savepatientgender(uint8_t value)
{
    model->savegender(value);
}

void New_PaitentPresenter::savepatientheight(uint16_t value)
{
    model->savepatientheight(value);
}

void New_PaitentPresenter::savepatientweight(uint16_t value)
{
    model->savepatientweight(value);
}

void New_PaitentPresenter::AlarmOrEvent(void)
 {
        view.AlarmOrEvent();
}


