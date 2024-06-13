#ifndef MODEL_HPP
#define MODEL_HPP
#include <touchgfx/widgets/Button.hpp>

extern touchgfx::Button FadeToggleB;


class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void RedSlider(int value);
    void GreenSlider(int value);
    void Blue(int value);
    void White(int value);
    void FadeF();       // Function prototype for the fade function
    void toggleFade();
    void setFadeActive(bool active); // Add this function
    bool isFadeActive() const; // Add this function

protected:
    ModelListener* modelListener;
    bool fadeActive = false; // State variable to track fade status
};

#endif // MODEL_HPP
