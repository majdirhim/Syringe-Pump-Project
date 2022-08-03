#ifndef NEW_PAITENTPRESENTER_HPP
#define NEW_PAITENTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class New_PaitentView;

class New_PaitentPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    New_PaitentPresenter(New_PaitentView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie.  made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    uint8_t getgender(void);
    void savepatientname(char *, uint8_t len);
    void savepatientheight(uint16_t);
    void savepatientweight(uint16_t);
    void savepatientage(uint8_t);
    void savepatientgender(uint8_t);
    uint8_t GetdisplayMode(void)
    {
        return model->GetDisplayMode();
    }
    virtual void AlarmOrEvent(void);
    void savepatient(void)
    {
    	model->SavePatient();
    }
    virtual ~New_PaitentPresenter() {};

private:
    New_PaitentPresenter();

    New_PaitentView& view;
};

#endif // NEW_PAITENTPRESENTER_HPP
