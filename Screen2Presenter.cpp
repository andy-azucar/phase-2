#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

Screen2Presenter::Screen2Presenter(Screen2View& v)
    : view(v), FadeToggleActive(false) // Initialize FadeToggleActive here
{

}

void Screen2Presenter::activate()
{

}

void Screen2Presenter::deactivate()
{

}
void Screen2Presenter::toggleFade()
{
	FadeToggleActive = !FadeToggleActive;
	    model->setFadeActive(FadeToggleActive);
	    if (FadeToggleActive)
	    {
	        FadeF();
	    }
}
 void Screen2Presenter::FadeF()
{
    model->FadeF();
}

void Screen2Presenter::FadeTogglePressed()
{
    // Toggle the FadeActive state in the model
    bool isActive = model->isFadeActive();
    model->setFadeActive(!isActive);

    // Start the FadeF function if FadeActive is now true
    if (!isActive)
    {
        model->FadeF();
    }
}
