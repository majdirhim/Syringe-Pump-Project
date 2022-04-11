#include <gui/containers/ActiveAlarms.hpp>
#include <touchgfx/Color.hpp>

ActiveAlarms::ActiveAlarms()
{

}

void ActiveAlarms::setUpTitle()
{
    Unicode::snprintf(IdTextAreaBuffer, IDTEXTAREA_SIZE, "Id");
    Unicode::snprintf(DescriptionTextAreaBuffer, DESCRIPTIONTEXTAREA_SIZE, "Description");
    Unicode::snprintf(TypeTextAreaBuffer, TYPETEXTAREA_SIZE, "Type");
    Unicode::snprintf(StatusTextAreaBuffer, STATUSTEXTAREA_SIZE, "Status");
}

void ActiveAlarms::setUpAlarm(uint8_t Id, touchgfx::Unicode::UnicodeChar * Description, uint8_t Status)
{
    Unicode::snprintf(IdTextAreaBuffer, IDTEXTAREA_SIZE, "%d", Id);
    Unicode::snprintf(DescriptionTextAreaBuffer, DESCRIPTIONTEXTAREA_SIZE, Description);
    if (Status)
    {
        Unicode::snprintf(StatusTextAreaBuffer, STATUSTEXTAREA_SIZE, "Active");
        setUpColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
    }
    else
    {
        Unicode::snprintf(StatusTextAreaBuffer, STATUSTEXTAREA_SIZE, "Not Active");
        setUpColor(touchgfx::Color::getColorFrom24BitRGB(0, 255, 0));
    }
    if (Id < NUMBER_OF_ALARMS + 1)
    {
        Unicode::snprintf(TypeTextAreaBuffer, TYPETEXTAREA_SIZE, "Alarm");
        TypeTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 0, 0));
    }
    else
    {
        Unicode::snprintf(TypeTextAreaBuffer, TYPETEXTAREA_SIZE, "Alert");
        TypeTextArea.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 180, 0));
    }
}

void ActiveAlarms::setUpColor(colortype Color)
{
    StatusTextArea.setColor(Color);
}

void ActiveAlarms::initialize()
{
    ActiveAlarmsBase::initialize();
}
