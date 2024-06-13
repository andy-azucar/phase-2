#ifndef SCREEN2PRESENTER_HPP
#define SCREEN2PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen2View;

class Screen2Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen2Presenter(Screen2View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();
    virtual void deactivate();

    virtual ~Screen2Presenter() {};
    virtual void toggleFade();
    virtual void FadeF();
    virtual void FadeTogglePressed();
    void setFadeActive(bool active); // Ensure this is declared
private:
    Screen2Presenter();

    Screen2View& view;
    bool FadeToggleActive; // Add this member
};

#endif // SCREEN2PRESENTER_HPP
