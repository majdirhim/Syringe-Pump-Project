#ifndef NEWPATIENTPRESENTER_HPP
#define NEWPATIENTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class NewPatientView;

class NewPatientPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    NewPatientPresenter(NewPatientView& v);

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

    virtual ~NewPatientPresenter() {};

    virtual void AlarmOrEvent(void);

    uint8_t getDisplayMode(void);

    void saveKeyboardUser(uint8_t);

    Patient_dataT getPatient(void);
    void savePatientName(char*);

private:
    NewPatientPresenter();

    NewPatientView& view;
};

#endif // NEWPATIENTPRESENTER_HPP
