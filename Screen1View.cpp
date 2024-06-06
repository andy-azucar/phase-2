#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::RedSlider(int value)
{
    presenter->RedSlider(value);
}

void Screen1View::GreenSlider(int value)
{
    presenter->GreenSlider(value);
}

void Screen1View::Blue(int value)
{
    presenter->Blue(value);
}

void Screen1View::White(int value)
{
    presenter->White(value);
}
