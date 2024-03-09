#ifndef _XPT2046TS_H_
#define _XPT2046TS_H_

#include <stdint.h>

void XPT2046_Init(void);
uint32_t XPT2046_irq_read(void);
void XPT2046_GetTouch_XY(volatile uint16_t* x_kor, volatile uint16_t* y_kor, uint8_t count_read);
void xpt2046_corr(uint16_t * x, uint16_t * y);
#endif
