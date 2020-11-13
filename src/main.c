/*
    Author: Emirhan Gocturk

    Description: I test functionality before
    implementing these in my main projects.
    This repository does not guarantee anything
    and is not representative of my professional 
    work 1:1.
    I do not perform error checks or write unit
    tests for this repository, or even any other 
    repository I publicly have available. 
    
    Microcontroller: STM32F446RE
    
    NO CubeMX whatsoever.
*/

#include "main.h"
#include "blink.h"

int main(void) {
    HAL_Init();

    LED_GREEN_Init();

    while (1)
    {
        LED_GREEN_toggle();
    }
}

void SysTick_Handler(void) {
  HAL_IncTick();
}
