#include <gui/screen2_screen/Screen2View.hpp>
#include <touchgfx/widgets/Button.hpp>

touchgfx::Button FadeToggleB;


Screen2View::Screen2View() : buttonClickedCallback(this, &Screen2View::buttonClicked)
{
}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
    FadeToggleB.setAction(buttonClickedCallback);
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}


void Screen2View::FadeF()
{
	presenter->FadeF();
}

void Screen2View::FadeTogglePressed()
{
    presenter->toggleFade();
}

void Screen2View::buttonClicked(const AbstractButton& source)
{
    if (&source == &FadeToggleB)
    {
        FadeTogglePressed();
    }
}

bool Screen2View::getFadeToggleState() const
{
    return FadeToggleB.getPressedState();
}
