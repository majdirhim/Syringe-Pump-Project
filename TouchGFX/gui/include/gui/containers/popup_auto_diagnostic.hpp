#ifndef POPUP_AUTO_DIAGNOSTIC_HPP
#define POPUP_AUTO_DIAGNOSTIC_HPP

#include <gui_generated/containers/popup_auto_diagnosticBase.hpp>

class popup_auto_diagnostic : public popup_auto_diagnosticBase
{
public:
    popup_auto_diagnostic();
    virtual ~popup_auto_diagnostic() {}

    virtual void initialize();
protected:
};

#endif // POPUP_AUTO_DIAGNOSTIC_HPP
