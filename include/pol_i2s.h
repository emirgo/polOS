/*
    Copyright @ polseq B.V.

    Author: Emirhan Gocturk

    Description: i2s library

    **WARNING**
    Users/developers can keep track of this
    library under [100]~[199] at the time of
    development on Trello.
*/

#ifndef POL_I2S_H
#define POL_I2S_H

#ifndef __STM32F4xx_HAL_H
#include "stm32f4xx_hal.h"
#endif

// private variables
// I2S_2 handler
I2S_HandleTypeDef hi2s2;
// DMA SPI2 handler
DMA_HandleTypeDef hdma_spi2_tx;

// Initialize GPIOs used in this example
void pol_i2s_gpio_init(void);
// Initialize DMA used in this example
void pol_i2s_dma_init(void);
// Initialize all
void pol_i2s_init(void);

#endif