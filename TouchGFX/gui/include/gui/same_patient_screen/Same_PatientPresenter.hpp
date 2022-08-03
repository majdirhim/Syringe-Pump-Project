#ifndef SAME_PATIENTPRESENTER_HPP
#define SAME_PATIENTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Same_PatientView;

class Same_PatientPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Same_PatientPresenter(Same_PatientView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    uint8_t GetdisplayMode(void)
    {
        return model->GetDisplayMode();
    }
    void RequeststoredData(void)
    {
        model->RequeststoredData();
    }

    uint8_t PatientDataRequestAnswer(void)
    {
        return model->PatientDataRequestAnswer();
    }

    char*getpatientname(void)
    {
        return model->getpatientname();
    }

    uint8_t getpatientage(void)
    {
        return model->getpatientage();
    }

    uint8_t getpatientgender(void)
    {
        return model->getgender();
    }

    uint16_t getpatientheight(void)
    {
        return model->getpatientheight();
    }

    uint16_t getpatientweight(void)
    {
        return model->getpatientweight();
    }

    virtual void AlarmOrEvent(void);
    virtual ~Same_PatientPresenter() {};

private:
    Same_PatientPresenter();

    Same_PatientView& view;
};

#endif // SAME_PATIENTPRESENTER_HPP
