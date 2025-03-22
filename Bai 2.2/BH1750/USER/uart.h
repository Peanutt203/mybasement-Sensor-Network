#ifndef UART_H
#define UART_H

#include "stm32f10x.h"

void USART_Config(void);
void USART_SendString(char* str);

#endif
