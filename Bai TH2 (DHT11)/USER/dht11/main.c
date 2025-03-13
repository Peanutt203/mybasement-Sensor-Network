#include "stm32f10x.h"
#include "DHT11.h"
#include "delay.h"
#include "uart.h"

void GPIO_Config(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

int main() {
    SystemInit();
    DHT11_Name DHT11;
    DHT11_Init(&DHT11, GPIOC, GPIO_Pin_14);
    UART1_config();
    GPIO_Config();
    TIM2_Config();
    char Tempstring[8], Humistring[8];
    while (1) {
        float Temp = DHT11_ReadTemp(&DHT11);
        float Humi = DHT11_ReadHumi(&DHT11);
        sprintf(Tempstring, "%.2fC", Temp);
        sprintf(Humistring, "%.2f", Humi);
        UART_SendString("Nhiet do: ");
        UART_SendString(Tempstring);
        UART_SendString("\n");
        UART_SendString("Do am: ");
        UART_SendString(Humistring);
        UART_SendString("\n");
        delay_ms(1000);
    }
}
