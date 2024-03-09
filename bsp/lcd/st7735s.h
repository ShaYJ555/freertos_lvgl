/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017, 2019-2020, 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_ILI9341_H_
#define _FSL_ILI9341_H_

#include "fsl_common.h"

/*
 * Change log:
 *
 *   1.0.2
 *     - Add FT9341_Init1.
 *
 *   1.0.1
 *     - Fix MISRA 2012 issues.
 *
 *   1.0.0
 *     - Initial version
 */

/*!
 * @addtogroup ili9341
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Register defines */
// ST7735
#define ST7735_SLPOUT   0x11
#define ST7735_FRMCTR1  0xB1
#define ST7735_FRMCTR2  0xB2
#define ST7735_FRMCTR3  0xB3
#define ST7735_INVCTR   0xB4
#define ST7735_PWCTR1   0xC0
#define ST7735_PWCTR2   0xC1
#define ST7735_PWCTR3   0xC2
#define ST7735_PWCTR4   0xC3
#define ST7735_PWCTR5   0xC4
#define ST7735_VMCTR1   0xC5
#define ST7735_COLMOD   0x3A
#define ST7735_GMCTRP1  0xE0
#define ST7735_GMCTRN1  0xE1
#define ST7735_NORON    0x13
#define ST7735_DISPON   0x29
#define ST7735_CASET    0x2A
#define ST7735_RASET    0x2B
#define ST7735_RAMWR    0x2C
#define ST7735_INVOFF   0x20
#define ST7735_INVON    0x21

#define ST7735_MADCTL     0x36
#define ST7735_MADCTL_MX  0x40
#define ST7735_MADCTL_MY  0x80
#define ST7735_MADCTL_MV  0x20
#define ST7735_MADCTL_RGB 0x00
#define ST7735_MADCTL_BGR 0x08





/* 120ms is necessary after reset, for loading ID bytes, VCOM setting,
 * and other settings from NV memory to registers.
 */
#define ST7735_RESET_CANCEL_MS 120U

typedef void (*st7735_send_byte_t)(uint8_t dataToSend);
typedef void (*st7735_send_cmd_data_t)(uint8_t cmd, const uint8_t *data, uint32_t dataLen);

void ST7735_Init(st7735_send_byte_t _writeData, st7735_send_byte_t _writeCommand);
void adjustBacklight(uint8_t duty);
void BackLight_Init();

#endif
