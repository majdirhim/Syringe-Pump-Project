#ifndef MAINTENANCEVIEW_HPP
#define MAINTENANCEVIEW_HPP

#include <gui_generated/maintenance_screen/MaintenanceViewBase.hpp>
#include <gui/maintenance_screen/MaintenancePresenter.hpp>

class MaintenanceView : public MaintenanceViewBase
{
public:
    MaintenanceView();
    virtual ~MaintenanceView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void SetupDisplayMode(void);
    virtual void AlarmOrEvent(void);
protected:
};

#endif // MAINTENANCEVIEW_HPP
