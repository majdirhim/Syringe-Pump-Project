#ifndef OCLUSIONTHRESHOLDSVIEW_HPP
#define OCLUSIONTHRESHOLDSVIEW_HPP

#include <gui_generated/oclusionthresholds_screen/OclusionThresholdsViewBase.hpp>
#include <gui/oclusionthresholds_screen/OclusionThresholdsPresenter.hpp>

class OclusionThresholdsView : public OclusionThresholdsViewBase
{
public:
    OclusionThresholdsView();
    virtual ~OclusionThresholdsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // OCLUSIONTHRESHOLDSVIEW_HPP
