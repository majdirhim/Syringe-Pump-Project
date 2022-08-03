#ifndef ALARMLISTVIEW_HPP
#define ALARMLISTVIEW_HPP

#include <gui_generated/alarmlist_screen/AlarmListViewBase.hpp>
#include <gui/alarmlist_screen/AlarmListPresenter.hpp>
#include <gui/containers/Alarmlist.hpp>

class AlarmListView : public AlarmListViewBase
{
public:
    AlarmListView();
    virtual ~AlarmListView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    void listElementClicked(Alarmlist& element);

    virtual void AlarmOrEvent(void);
    void SetupDisplayMode(void);

protected:
    static const int numberOfListElements = 18;
    Alarmlist listElements[numberOfListElements];
    uint8_t alarmvector;
    const char * alarmSources[17] = {"Battery overcurrent",
	"Battery overcurrent",
	"Battery undercurrent",
	"Battery overheat",
	"Battery underheat",
	"Battery low voltage",
	"Battery charge depleted",
	"Battery timeout",
	"Motor overheat",
	"Motor T shutdown",
	"Motor overcurrent",
	"Motor undervoltage",
	"Motor driver not responding",
	"Occlusion",
	"Internal error",
	"position error",
	"Syringe not detected"};
    uint8_t alarmsState[17] = {0};

};

#endif // ALARMLISTVIEW_HPP
