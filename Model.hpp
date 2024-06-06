#ifndef MODEL_HPP
#define MODEL_HPP

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
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
