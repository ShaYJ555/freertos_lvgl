#ifndef _NSHT30_H_
#define _NSHT30_H_

#include "fsl_common.h"

#ifndef __weak
#define __weak __attribute__((weak))
#endif /* __weak */

//NSHT30驱动代码
#define CMD_MEAS_SINGLE_H 0x2400 // measurement: SINGLE Mode high repeatability
#define CMD_MEAS_SINGLE_M 0x240B // measurement: SINGLE Mode medium repeatability
#define CMD_MEAS_SINGLE_L 0x2416 // measurement: SINGLE Mode low repeatability
#define CMD_MEAS_PERI_05_H 0x2032 // measurement: periodic Mode 0.5 mps high repeatability
#define CMD_MEAS_PERI_05_M 0x2024 // measurement: periodic Mode 0.5 mps medium repeatability
#define CMD_MEAS_PERI_05_L 0x202F // measurement: periodic Mode 0.5 mps low repeatability
#define CMD_MEAS_PERI_1_H 0x2130 // measurement: periodic Mode 1 mps high repeatability
#define CMD_MEAS_PERI_1_M 0x2126 // measurement: periodic Mode 1 mps medium repeatability
#define CMD_MEAS_PERI_1_L 0x212D // measurement: periodic Mode 1 mps low repeatability
#define CMD_MEAS_PERI_2_H 0x2236 // measurement: periodic Mode 2 mps high repeatability
#define CMD_MEAS_PERI_2_M 0x2220 // measurement: periodic Mode 2 mps medium repeatability
#define CMD_MEAS_PERI_2_L 0x222B // measurement: periodic Mode 2 mps low repeatability
#define CMD_MEAS_PERI_4_H 0x2334 // measurement: periodic Mode 4 mps high repeatability
#define CMD_MEAS_PERI_4_M 0x2322 // measurement: periodic Mode 4 mps medium repeatability
#define CMD_MEAS_PERI_4_L 0x2329 // measurement: periodic Mode 4 mps low repeatability
#define CMD_MEAS_PERI_10_H 0x2737 // measurement: periodic Mode 10 mps high repeatability
#define CMD_MEAS_PERI_10_M 0x2721 // measurement: periodic Mode 10 mps medium repeatability
#define CMD_MEAS_PERI_10_L 0x272A // measurement: periodic Mode 10 mps low repeatability

#define NSHT30_ADDR         0x44

void nsht30_init(void);
int32_t nsht30_read_temp_humi_1ch(float *pout);
#endif