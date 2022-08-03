#ifndef LOGSCREENVIEW_HPP
#define LOGSCREENVIEW_HPP

#include <gui_generated/logscreen_screen/LogScreenViewBase.hpp>
#include <gui/logscreen_screen/LogScreenPresenter.hpp>
#include <gui/containers/Alarmlist.hpp>

class LogScreenView : public LogScreenViewBase
{
public:
    LogScreenView();
    virtual ~LogScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void listElementClicked(Alarmlist& element);
    virtual void AlarmOrEvent();
    void SetupDisplayMode(void);
    virtual void RequestData();
    virtual void testdata();
    virtual void testdataafteInit();
    virtual void RequestForward();
    virtual void RequestBack();
protected:
    static const int numberOfListElements = 33;
    Alarmlist listElements[numberOfListElements];
    logT logvector;
   const char* alarmSources[17] = { "Battery overcurrent",
    "Battery charge depleted",
    "Battery overheat",
     "Battery underheat",
     "Battery low voltage",
     "contact failure",
     "Battery undercurrent",
     "Battery timeout",
     "Motor overheat",
     "Motor T shutdown",
     "Motor overcurrent",
     "Motor undervoltage",
     "Motor driver not responding",
     "Occlusion",
     "Internal error",
     "position error",
     "Syringe not detected" };
    const char * eventSources[15] = {"Perfusion Started",
    "Perfusion Stopped",
    "Perfusion Complete",
    "Bolus Started",
    "Bolus Stopped",
    "Bolus Complete",
    "KVO Started",
    "KVO Stopped",
    "Purge Started",
    "Purge Complete",
    "Purge Stopped",
    "Syringe Near Empty",
    "Syringe Empty",
    "End of Trail",
    "Power Source Change"};
};

#endif // LOGSCREENVIEW_HPP
