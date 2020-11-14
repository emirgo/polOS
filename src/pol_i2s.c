/*
    Copyright @ polseq B.V.

    Author: Emirhan Gocturk

    Description: i2s library
*/

#include "pol_i2s.h"

// Initialize RCC for GPIO A,B,C
void pol_i2s_gpio_init()
{
    __HAL_RCC_SYSCFG_CLK_ENABLE();
    __HAL_RCC_PWR_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    if(hi2s2.Instance==SPI2)
    {
        /* Peripheral clock enable */
        __HAL_RCC_SPI2_CLK_ENABLE();

        __HAL_RCC_GPIOC_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();
        __HAL_RCC_GPIOB_CLK_ENABLE();
        /**I2S2 GPIO Configuration    
        PC1     ------> I2S2_SD
        PA6     ------> I2S2_MCK
        PB10     ------> I2S2_CK
        PB12     ------> I2S2_WS 
        */
        GPIO_InitStruct.Pin = GPIO_PIN_1;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = GPIO_AF7_SPI2;
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_6;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = GPIO_AF6_SPI2;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_12;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    }
}

// Initialize DMA
void pol_i2s_dma_init()
{
    /* DMA controller clock enable */
    __HAL_RCC_DMA1_CLK_ENABLE();

    /* DMA interrupt init */
    /* DMA1_Stream4_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA1_Stream4_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA1_Stream4_IRQn);

    if (hi2s2.Instance == SPI2)
    {
        /* I2S2 DMA Init */
        /* SPI2_TX Init */
        hdma_spi2_tx.Instance = DMA1_Stream4;
        hdma_spi2_tx.Init.Channel = DMA_CHANNEL_0;
        hdma_spi2_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
        hdma_spi2_tx.Init.PeriphInc = DMA_PINC_DISABLE;
        hdma_spi2_tx.Init.MemInc = DMA_MINC_ENABLE;
        hdma_spi2_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_WORD;
        hdma_spi2_tx.Init.MemDataAlignment = DMA_MDATAALIGN_WORD;
        hdma_spi2_tx.Init.Mode = DMA_CIRCULAR;
        hdma_spi2_tx.Init.Priority = DMA_PRIORITY_LOW;
        hdma_spi2_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
        if (HAL_DMA_Init(&hdma_spi2_tx) != HAL_OK)
        {
            // routed to mainh
            Error_Handler();
        }
    }
}

// [tre:116]
void pol_i2s_handle_init(void)
{
    // Init settings for I2S_2 handler
    hi2s2.Instance = SPI2;
    hi2s2.Init.Mode = I2S_MODE_MASTER_TX;
    hi2s2.Init.Standard = I2S_STANDARD_PHILIPS;
    hi2s2.Init.DataFormat = I2S_DATAFORMAT_16B;
    hi2s2.Init.MCLKOutput = I2S_MCLKOUTPUT_ENABLE;
    hi2s2.Init.AudioFreq = I2S_AUDIOFREQ_48K;
    hi2s2.Init.CPOL = I2S_CPOL_LOW;
    hi2s2.Init.ClockSource = I2S_CLOCK_PLL;
    hi2s2.Init.FullDuplexMode = I2S_FULLDUPLEXMODE_DISABLE;
    // i2s_2 handler linkage hotfix [tre:118]
    if (HAL_I2S_Init(&hi2s2) != HAL_OK)
    {
        // routed to mainh
        Error_Handler();
    }   
}

// under active development [tre:101]
// Initialize various peripherals regarding i2s_2
// Read function for details
void pol_i2s_init(void)
{
    // example flow
    pol_i2s_handle_init();
    pol_i2s_gpio_init();
    pol_i2s_dma_init();

    // DMA linkage hotfix [tre:107]
    __HAL_LINKDMA(&hi2s2,hdmatx,hdma_spi2_tx);
}