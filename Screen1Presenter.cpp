#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::RedSlider(int value)
{
	model->RedSlider(value);
}

void Screen1Presenter::GreenSlider(int value)
{
	model->GreenSlider(value);
}

void Screen1Presenter::Blue(int value)
{
	model->Blue(value);
}

void Screen1Presenter::White(int value)
{
	model->White(value);
}
