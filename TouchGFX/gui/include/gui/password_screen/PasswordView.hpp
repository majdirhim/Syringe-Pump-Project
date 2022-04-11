#ifndef PASSWORDVIEW_HPP
#define PASSWORDVIEW_HPP

#include <gui_generated/password_screen/PasswordViewBase.hpp>
#include <gui/password_screen/PasswordPresenter.hpp>

class PasswordView : public PasswordViewBase
{
public:
    PasswordView();
    virtual ~PasswordView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // PASSWORDVIEW_HPP
