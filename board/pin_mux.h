/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/* GPIO_AD_B0_07 (number 101), UART1_RXD/J17[4] */
#define BOARD_INITPINS_UART1_RXD_PERIPHERAL                              LPUART1   /*!< Device name: LPUART1 */
#define BOARD_INITPINS_UART1_RXD_SIGNAL                                       RX   /*!< LPUART1 signal: RX */

/* GPIO_AD_B0_06 (number 105), UART1_TXD/J17[6] */
#define BOARD_INITPINS_UART1_TXD_PERIPHERAL                              LPUART1   /*!< Device name: LPUART1 */
#define BOARD_INITPINS_UART1_TXD_SIGNAL                                       TX   /*!< LPUART1 signal: TX */

/* GPIO_AD_B0_15 (number 93), LCD_DC_GPIO_PIN/U11[25]/J19[2] */
#define BOARD_INITPINS_LCD_DC_GPIO_PIN_GPIO                                GPIO3   /*!< GPIO device name: GPIO1 */
#define BOARD_INITPINS_LCD_DC_GPIO_PIN_PORT                                GPIO3   /*!< PORT device name: GPIO1 */
#define BOARD_INITPINS_LCD_DC_GPIO_PIN_PIN                                   4U   /*!< GPIO1 pin index: 15 */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void LPSPI4_InitPins(void);



/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void LPSPI4_DeinitPins(void);


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void LPSPI2_InitPins(void);



/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void LPSPI2_DeinitPins(void);


// /*!
//  * @brief Configures pin routing and optionally pin electrical features.
//  *
//  */
// void LPI2C4_InitPins(void);


// /*!
//  * @brief Configures pin routing and optionally pin electrical features.
//  *
//  */
// void LPI2C4_DeinitPins(void);


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
// void PWM_InitPins(void);

void ENC_InitPins(void);
#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
