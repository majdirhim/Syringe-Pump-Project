#ifndef INTROPRESENTER_HPP
#define INTROPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class introView;

class introPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    introPresenter(introView& v);

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

    void purgeactivate(uint8_t var)
    {
        model->purgeactivate(var);
    }
    uint8_t GetdisplayMode(void)
    {
        return model->GetDisplayMode();
    }
    uint8_t init(void)
    {
        return model->getinit();
    }
    virtual ~introPresenter() {};

private:
    introPresenter();

    introView& view;
};

#endif // INTROPRESENTER_HPP
