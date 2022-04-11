#include <gui/keyboardnb_screen/KeyboardNbView.hpp>
#include <gui/keyboardnb_screen/KeyboardNbPresenter.hpp>

KeyboardNbPresenter::KeyboardNbPresenter(KeyboardNbView& v)
    : view(v)
{

}

void KeyboardNbPresenter::activate()
{

}

void KeyboardNbPresenter::deactivate()
{

}

uint8_t KeyboardNbPresenter::getDisplayMode()
{
	return model->getDisplayMode();
}

void KeyboardNbPresenter::AlarmOrEvent(void)
 {
        view.AlarmOrEvent();
}

uint8_t KeyboardNbPresenter::getKeyboardUser(void)
{
	return model->getKeyboardUser();
}

void KeyboardNbPresenter::savePatientWeight(uint16_t value)
{
	model->savePatientWeight(value);
}
void KeyboardNbPresenter::savePatientHeight(uint8_t value)
{
	model->savePatientHeight(value);
}
void KeyboardNbPresenter::savePatientAge(uint8_t value)
{
	model->savePatientAge(value);
}

void KeyboardNbPresenter::saveBolusRate(SW_float value)
{
	model->saveBolusRate(value);
}

void KeyboardNbPresenter::saveKVORate(SW_float value)
{
	model->saveKVORate(value);
}

void KeyboardNbPresenter::saveInfusionVolume(SW_float value)
{
	model->saveInfusionVolume(value);
}

void KeyboardNbPresenter::saveTotalVolume(SW_float value)
{
	model->saveTotalVolume(value);
}

void KeyboardNbPresenter::saveFlowaRate(SW_float value)
{
	model->saveFlowaRate(value);
}

void KeyboardNbPresenter::savePressureThresholdLow(uint16_t value)
{
	model->savePressureThresholdLow(value);
}

void KeyboardNbPresenter::savePressureThresholdMedium(uint16_t value)
{
	model->savePressureThresholdMedium(value);
}

void KeyboardNbPresenter::savePressureThresholdHigh(uint16_t value)
{
	model->savePressureThresholdHigh(value);
}
