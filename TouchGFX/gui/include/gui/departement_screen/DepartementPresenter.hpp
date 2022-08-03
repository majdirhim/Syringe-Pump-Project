#ifndef DEPARTEMENTPRESENTER_HPP
#define DEPARTEMENTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DepartementView;

class DepartementPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DepartementPresenter(DepartementView& v);

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
    uint8_t getdepartement(void)
    {
        return model->getdepartement();
    }
    void savedepartement(uint8_t dep)
    {
        model->savedepartement(dep);
    }
    virtual void AlarmOrEvent(void);
    virtual ~DepartementPresenter() {};

private:
    DepartementPresenter();

    DepartementView& view;
};

#endif // DEPARTEMENTPRESENTER_HPP
