#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "stm32h7xx_hal.h"


extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim5;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{

}


void Model::RedSlider(int value)
{
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, value);
}

void Model::GreenSlider(int value)
{
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, value);
}

void Model::Blue(int value)
{
	__HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, value);
}

void Model::White(int value)
{
	__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_1, value);
}




void Model::setFadeActive(bool active) 
{
    fadeActive = active;
}

bool Model::isFadeActive() const 
{
    return fadeActive;
}

void Model::FadeF()
{
    int fadeTime = 75; // Time in milliseconds for each step
    int maxValue = 100; // Maximum PWM value for Red and Green
    int maxBlueValue = 6200; // Maximum PWM value for Blue
    int step = 10; // Step size for Red and Green
    int blueStep = maxBlueValue / (maxValue / step); // Proportional step size for Blue

    while (fadeActive)

    {
        // Fade from Red to Yellow 
        for (int i = 0; i <= maxValue; i += step)
        {
        	if (!fadeActive) return; // Exit if fade is no longer active
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, maxValue); // Red
            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, i); // Green
            HAL_Delay(fadeTime);
        }

        // Fade from Yellow to Green
        for (int i = maxValue; i >= 0; i -= step)
        {
        	if (!fadeActive) return;
        	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, i); // Red
            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, maxValue); // Green
            HAL_Delay(fadeTime);
        }

        // Fade from Green to Cyan (Green + Blue)
        for (int i = 0; i <= maxBlueValue; i += blueStep)
        {
        	if (!fadeActive) return;
        	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, maxValue); // Green
            __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, i); // Blue
            HAL_Delay(fadeTime);
        }

        // Fade from Cyan to Blue
        for (int i = maxValue; i >= 0; i -= step)
        {
        	if (!fadeActive) return;
        	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, i); // Green
            __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, maxBlueValue); // Blue
            HAL_Delay(fadeTime);
        }

        // Fade from Blue to Purple (Blue + Red)
        for (int i = 0; i <= maxValue; i += step)
        {
        	if (!fadeActive) return;
        	__HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, maxBlueValue); // Blue
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, i); // Red
            HAL_Delay(fadeTime);
        }

        // Fade from Purple to Red
        for (int i = maxBlueValue; i >= 0; i -= blueStep)
        {
        	if (!fadeActive) return;
        	__HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, i); // Blue
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, maxValue); // Red
            HAL_Delay(fadeTime);
        }
    }
}

void Model::toggleFade()
{
    fadeActive = !fadeActive; // Toggle the fade function state
    if (fadeActive)
    {
        FadeF(); 
    }
}
