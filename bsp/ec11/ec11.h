#ifndef _EC11_H_
#define _EC11_H_

#include "fsl_common.h"


void EC11_Init(void);
int16_t EC11_read_differential_value(void);
uint32_t EC11_key_get_value(void);

#endif
