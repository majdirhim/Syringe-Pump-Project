#ifndef GENDERCHOICEPRESENTER_HPP
#define GENDERCHOICEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class GenderChoiceView;

class GenderChoicePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    GenderChoicePresenter(GenderChoiceView& v);

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

    virtual ~GenderChoicePresenter() {};

    virtual void AlarmOrEvent(void);

    uint8_t getDisplayMode(void);

    void savePatientGender(uint8_t);

private:
    GenderChoicePresenter();

    GenderChoiceView& view;
};

#endif // GENDERCHOICEPRESENTER_HPP
