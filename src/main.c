/*
    Author: Emirhan Gocturk

    Description: I test functionality before
    implementing these in my main projects.
    This repository does not guarantee aything
    and is not representative of my professional 
    work 1:1.
    I do not perform error checks or write unit
    tests for this repository, or even any other 
    repository I publicly have available. 
    
    Microcontroller: STM32F446RE
    
    NO CubeMX whatsoever.
*/
#include "main.h"

void LED_GREEN_Init();

int main(void) {
    HAL_Init();
    LED_GREEN_Init();

    while (1)
    {
        HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);
        HAL_Delay(1000);
    }
}

void LED_GREEN_Init() {
    LED_GPIO_CLK_ENABLE();
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);
}

void SysTick_Handler(void) {
  HAL_IncTick();
}