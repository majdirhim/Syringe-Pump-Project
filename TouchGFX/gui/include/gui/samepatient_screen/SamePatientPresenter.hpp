#ifndef SAMEPATIENTPRESENTER_HPP
#define SAMEPATIENTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SamePatientView;

class SamePatientPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SamePatientPresenter(SamePatientView& v);

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

    virtual ~SamePatientPresenter() {};
    
    virtual void AlarmOrEvent(void);

    uint8_t getDisplayMode(void);

    void requestLastPatientData();
    uint8_t getPatientDataRequestState(void);
    Patient_dataT getPatient(void);


private:
    SamePatientPresenter();

    SamePatientView& view;
};

#endif // SAMEPATIENTPRESENTER_HPP
