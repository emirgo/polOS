#ifndef _BLINK_H
#define _BLINK_H

#ifndef __STM32F4xx_HAL_H
#include "stm32f4xx_hal.h"
#endif

#define LED_GREEN_PIN                   GPIO_PIN_5
#define LED_GREEN_PORT                  GPIOA
#define LED_GREEN_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()

void LED_GREEN_Init(void);
void LED_GREEN_toggle(void);

#endif
