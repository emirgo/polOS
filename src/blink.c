#include "blink.h"

void LED_GREEN_Init(void) 
{
    LED_GREEN_GPIO_CLK_ENABLE();
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = LED_GREEN_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(LED_GREEN_PORT, &GPIO_InitStruct);
}

void LED_GREEN_toggle(void)
{
    HAL_GPIO_TogglePin(LED_GREEN_PORT, LED_GREEN_PIN);
    HAL_Delay(1000);
}
