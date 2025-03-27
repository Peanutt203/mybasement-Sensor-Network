#ifndef __UART_H__
#define __UART_H__


#include "stm32f10x.h"                  // Device header
		
void USART1_Init(uint32_t baud_rate);
void USART1_Send_Char( char chr);
void USART1_Send_String(char* str);
void USART1_Send_Data(uint8_t* data, uint8_t length);
void USART1_Send_Number(int16_t num);
void USART1_Send_Float(float num);
void USART1_Send_Hex(uint8_t num);

#endif
