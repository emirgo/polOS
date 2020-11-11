#ifndef MAIN_H
#define MAIN_H

#include "stm32f4xx_hal.h"

#define LED_GREEN_OIN                   GPIO_PIN_5
#define LED_GREEN_PORT                  GPIOA
#define LED_GREEN_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()

#endif // MAIN_H