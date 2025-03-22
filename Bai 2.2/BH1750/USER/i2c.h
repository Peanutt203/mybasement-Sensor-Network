#ifndef I2C_H
#define I2C_H

#include "stm32f10x.h"

void I2C_Config(void);
void I2C_StartTransmission(I2C_TypeDef* I2Cx, uint8_t address, uint8_t direction);
void I2C_StopTransmission(I2C_TypeDef* I2Cx);

#endif
