#ifndef SYRINGELIBRARYPRESENTER_HPP
#define SYRINGELIBRARYPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SyringeLibraryView;

class SyringeLibraryPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SyringeLibraryPresenter(SyringeLibraryView& v);

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

    virtual ~SyringeLibraryPresenter() {};

private:
    SyringeLibraryPresenter();

    SyringeLibraryView& view;
};

#endif // SYRINGELIBRARYPRESENTER_HPP
