#ifndef POPUP_HISTORY_HPP
#define POPUP_HISTORY_HPP

#include <gui_generated/containers/popup_HistoryBase.hpp>

class popup_History : public popup_HistoryBase
{
public:
    popup_History();
    virtual ~popup_History() {}

    virtual void initialize();
protected:
};

#endif // POPUP_HISTORY_HPP
