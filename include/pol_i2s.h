/*
    Copyright @ polseq B.V.

    Author: Emirhan Gocturk

    Description: i2s library
*/

#ifndef POL_I2S_H
#define POL_I2S_H

#ifndef __STM32F4xx_HAL_H
#include "stm32f4xx_hal.h"
#endif

// private variables
I2S_HandleTypeDef hi2s2;
DMA_HandleTypeDef hdma_spi2_tx;

void pol_i2s_gpio_init(void);
void pol_i2s_dma_init(void);
void pol_i2s_init(void);

#endif