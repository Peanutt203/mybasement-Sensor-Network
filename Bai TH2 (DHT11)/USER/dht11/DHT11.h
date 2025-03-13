// DHT11.h
#ifndef DHT11_H
#define DHT11_H

#include "stm32f10x.h"
#include <stdio.h>

// Struct for DHT11
typedef struct {
    GPIO_TypeDef* PORT;
    uint16_t Pin;
    float Temp;
    float Humi;
} DHT11_Name;

// UART Functions
void UART1_config(void);
void UART_SendChar(char c);
void UART_SendString(char *str);

// GPIO Configuration
void GPIO_Config(void);

// Delay Functions
void TIM2_Config(void);
void delay_us(uint16_t us);
void delay_ms(uint16_t ms);

// DHT11 Functions
void DHT11_Init(DHT11_Name* DHT11, GPIO_TypeDef* DS_PORT, uint16_t DS_Pin);
float DHT11_ReadTemp(DHT11_Name* DHT11);
float DHT11_ReadHumi(DHT11_Name* DHT11);

#endif
