#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <touchgfx/widgets/Button.hpp>

class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void FadeF();
    virtual void FadeTogglePressed();
    virtual void buttonClicked(const touchgfx::AbstractButton& source);
    bool getFadeToggleState() const; // Ensure this is declared

protected:
    touchgfx::ToggleButton FadeToggleB;  // Declare the toggle button
    Callback<Screen2View, const AbstractButton&> buttonClickedCallback;
};

#endif // SCREEN2VIEW_HPP
