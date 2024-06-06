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
