#ifndef BH1750_H
#define BH1750_H

#include "stm32f10x.h"
#include "i2c.h"

#define BH1750_ADDRESS 0x46

void BH1750_Init(void);
uint16_t BH1750_ReadLight(void);

#endif
