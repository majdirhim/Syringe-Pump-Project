#ifndef LANGUAGEVIEW_HPP
#define LANGUAGEVIEW_HPP

#include <gui_generated/language_screen/LanguageViewBase.hpp>
#include <gui/language_screen/LanguagePresenter.hpp>

class LanguageView : public LanguageViewBase
{
public:
    LanguageView();
    virtual ~LanguageView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LANGUAGEVIEW_HPP
