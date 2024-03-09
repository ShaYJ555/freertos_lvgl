/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _RTE_DEVICE_H
#define _RTE_DEVICE_H


// extern void LPSPI2_InitPins();
// extern void LPSPI2_DeinitPins();
extern void LPSPI4_InitPins();
extern void LPSPI4_DeinitPins();
extern void LPI2C1_InitPins();
extern void LPI2C1_DeinitPins();

/* Driver name mapping. */
/* User needs to provide the implementation of LPSPIX_GetFreq/LPSPIX_InitPins/LPSPIX_DeinitPins for the enabled LPSPI
 * instance. */

// #define RTE_SPI2            0
// #define RTE_SPI2_PIN_INIT   LPSPI2_InitPins
// #define RTE_SPI2_PIN_DEINIT LPSPI2_DeinitPins
// #define RTE_SPI2_DMA_EN     0

#define RTE_SPI4            0
#define RTE_SPI4_PIN_INIT   LPSPI4_InitPins
#define RTE_SPI4_PIN_DEINIT LPSPI4_DeinitPins
#define RTE_SPI4_DMA_EN     1

/* User needs to provide the implementation of LPI2CX_GetFreq/LPI2CX_InitPins/LPI2CX_DeinitPins for the enabled LPI2C
 * instance. */
#define RTE_I2C1            1
#define RTE_I2C1_PIN_INIT   LPI2C1_InitPins
#define RTE_I2C1_PIN_DEINIT LPI2C1_DeinitPins
#define RTE_I2C1_DMA_EN     1

#define RTE_I2C1_DMA_TX_CH          12
#define RTE_I2C1_DMA_TX_PERI_SEL    (uint8_t) kDmaRequestMuxLPI2C1
#define RTE_I2C1_DMA_TX_DMAMUX_BASE DMAMUX
#define RTE_I2C1_DMA_TX_DMA_BASE    DMA0
#define RTE_I2C1_DMA_RX_CH          13
#define RTE_I2C1_DMA_RX_PERI_SEL    (uint8_t) kDmaRequestMuxLPI2C1
#define RTE_I2C1_DMA_RX_DMAMUX_BASE DMAMUX
#define RTE_I2C1_DMA_RX_DMA_BASE    DMA0



/* SPI configuration. */
#define SPI0_RX_FIFO_SIZE 8
#define SPI0_TX_FIFO_SIZE 8
#define SPI1_RX_FIFO_SIZE 8
#define SPI1_TX_FIFO_SIZE 8

/* LSPI4 */
#define RTE_SPI4_DMA_TX_CH          11
#define RTE_SPI4_DMA_TX_PERI_SEL    (uint8_t) kDmaRequestMuxLPSPI4Tx
#define RTE_SPI4_DMA_TX_DMAMUX_BASE DMAMUX
#define RTE_SPI4_DMA_TX_DMA_BASE    DMA0
#define RTE_SPI4_DMA_RX_CH          10
#define RTE_SPI4_DMA_RX_PERI_SEL    (uint8_t) kDmaRequestMuxLPSPI4Rx
#define RTE_SPI4_DMA_RX_DMAMUX_BASE DMAMUX
#define RTE_SPI4_DMA_RX_DMA_BASE    DMA0

#define RTE_SPI4_PCS_TO_SCK_DELAY       0
#define RTE_SPI4_SCK_TO_PCS_DELAY       0
#define RTE_SPI4_BETWEEN_TRANSFER_DELAY 50 /* For 10MHz baudrate. delay(ns) = 10^9/baudrate/2. */
#define RTE_SPI4_MASTER_PCS_PIN_SEL     kLPSPI_MasterPcs0

#define RTE_SPI4_SCK_TO_PSC_DELAY RTE_SPI4_SCK_TO_PCS_DELAY

/* LSPI2 */
// #define RTE_SPI2_DMA_TX_CH          11
// #define RTE_SPI2_DMA_TX_PERI_SEL    (uint8_t) kDmaRequestMuxLPSPI2Tx
// #define RTE_SPI2_DMA_TX_DMAMUX_BASE DMAMUX
// #define RTE_SPI2_DMA_TX_DMA_BASE    DMA0
// #define RTE_SPI2_DMA_RX_CH          10
// #define RTE_SPI2_DMA_RX_PERI_SEL    (uint8_t) kDmaRequestMuxLPSPI2Rx
// #define RTE_SPI2_DMA_RX_DMAMUX_BASE DMAMUX
// #define RTE_SPI2_DMA_RX_DMA_BASE    DMA0

// #define RTE_SPI2_PCS_TO_SCK_DELAY       0
// #define RTE_SPI2_SCK_TO_PCS_DELAY       0
// #define RTE_SPI2_BETWEEN_TRANSFER_DELAY 50 /* For 10MHz baudrate. delay(ns) = 10^9/baudrate/2. */
// #define RTE_SPI2_MASTER_PCS_PIN_SEL     kLPSPI_MasterPcs0

// #define RTE_SPI2_SCK_TO_PSC_DELAY RTE_SPI2_SCK_TO_PCS_DELAY


#endif /* _RTE_DEVICE_H */
