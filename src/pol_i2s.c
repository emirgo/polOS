/*
    Copyright @ polseq B.V.

    Author: Emirhan Gocturk

    Description: i2s library
*/

#include "pol_i2s.h"

void pol_i2s_gpio_init()
{
    // enable clocks for
    // A, B, C ports
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
}

void pol_i2s_dma_init()
{
  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream4_IRQn);
}

// under active development [tre:100]
void pol_i2s_init(void)
{
    /*
    I2S_InitTypeDef pcm5102_conf;
    I2S_HandleTypeDef pcm5102;
    GPIO_InitTypeDef SDIN;
    GPIO_InitTypeDef SCLK;
    GPIO_InitTypeDef LRCLK;
    GPIO_InitTypeDef MCLK;
    uint16_t buf[2] = {0x1245, 0x6842};

    pcm5102_conf.Mode = I2S_MODE_MASTER_TX;
    pcm5102_conf.Standard = I2S_STANDARD_PHILIPS;
    pcm5102_conf.DataFormat = I2S_DATAFORMAT_16B;
    pcm5102_conf.MCLKOutput = I2S_MCLKOUTPUT_ENABLE;
    pcm5102_conf.AudioFreq = I2S_AUDIOFREQ_48K;
    pcm5102_conf.CPOL = I2S_CPOL_LOW;
    pcm5102_conf.ClockSource = I2S_CLOCK_PLL;
    pcm5102_conf.FullDuplexMode = I2S_FULLDUPLEXMODE_DISABLE;

    // SPI3 isn't initialized yet [tre:103]
    pcm5102.Instance = SPI3;
    pcm5102.Init = pcm5102_conf;
    */

}