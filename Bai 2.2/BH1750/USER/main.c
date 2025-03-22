#include "stm32f10x.h"
#include "i2c.h"
#include "bh1750.h"
#include "uart.h"
#include <stdio.h>

// Bi?n luu tr? th?i gian delay
volatile uint32_t sysTickCounter = 0;

void SysTick_Handler(void) {
    if (sysTickCounter > 0) {
        sysTickCounter--;
    }
}

void SysTick_Config_Init(void) {
    SysTick_Config(SystemCoreClock / 1000); // C?u hình SysTick ng?t m?i 1ms
}

void delay_ms(uint32_t ms) {
    sysTickCounter = ms;
    while (sysTickCounter != 0);
}

int main(void) {
    SysTick_Config_Init();
    USART_Config();
    I2C_Config();
    BH1750_Init();

    while (1) {
        uint16_t light = BH1750_ReadLight();
        char buffer[20];

        sprintf(buffer, "Light: %d\n", light);
        USART_SendString(buffer);
        
        delay_ms(500);
    }
}
