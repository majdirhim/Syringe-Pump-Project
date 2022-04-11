#ifndef LOGVIEW_HPP
#define LOGVIEW_HPP

#include <gui_generated/log_screen/LogViewBase.hpp>
#include <gui/log_screen/LogPresenter.hpp>

class LogView : public LogViewBase
{
public:
    LogView();
    virtual ~LogView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LOGVIEW_HPP
