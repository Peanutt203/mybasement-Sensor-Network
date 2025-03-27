#ifndef __SPI__
#define __SPI__


#include "stm32f10x.h"                  // Device header
#include "stm32f10x_spi.h"              // Keil::Device:StdPeriph Drivers:SPI
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC

void SPI_Config(void);
uint8_t SPI_SendByte(uint8_t byte);


#endif
