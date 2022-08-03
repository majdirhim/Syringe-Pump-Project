#ifndef GENDERCHOICEPRESENTER_HPP
#define GENDERCHOICEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class genderchoiceView;

class genderchoicePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    genderchoicePresenter(genderchoiceView& v);

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

    virtual void savegender(uint8_t value);
    uint8_t GetdisplayMode(void)
    {
        return model->GetDisplayMode();
    }
    virtual void AlarmOrEvent(void);
    virtual ~genderchoicePresenter() {};

private:
    genderchoicePresenter();

    genderchoiceView& view;
};

#endif // GENDERCHOICEPRESENTER_HPP
