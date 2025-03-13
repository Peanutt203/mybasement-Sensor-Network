#include "DHT11.h"
#include "delay.h"

static void DHT11_SetPinOut(DHT11_Name* DHT11) {
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = DHT11->Pin;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(DHT11->PORT, &GPIO_InitStruct);
}

static void DHT11_SetPinIn(DHT11_Name* DHT11) {
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = DHT11->Pin;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(DHT11->PORT, &GPIO_InitStruct);
}

static void DHT11_Start(DHT11_Name* DHT11) {
    DHT11_SetPinOut(DHT11);
    GPIO_ResetBits(DHT11->PORT, DHT11->Pin);
    delay_ms(20);
    GPIO_SetBits(DHT11->PORT, DHT11->Pin);
    DHT11_SetPinIn(DHT11);
}

static uint8_t DHT11_Read(DHT11_Name* DHT11) {
    uint8_t data = 0;
    for (uint8_t i = 0; i < 8; i++) {
        while (!GPIO_ReadInputDataBit(DHT11->PORT, DHT11->Pin));
        delay_us(30);
        if (GPIO_ReadInputDataBit(DHT11->PORT, DHT11->Pin)) {
            data |= (1 << (7 - i));
        }
        while (GPIO_ReadInputDataBit(DHT11->PORT, DHT11->Pin));
    }
    return data;
}

void DHT11_Init(DHT11_Name* DHT11, GPIO_TypeDef* DS_PORT, uint16_t DS_Pin) {
    DHT11->PORT = DS_PORT;
    DHT11->Pin = DS_Pin;
}

float DHT11_ReadTemp(DHT11_Name* DHT11) {
    uint8_t temp1, temp2, humi1, humi2, checksum;
    DHT11_Start(DHT11);
    humi1 = DHT11_Read(DHT11);
    humi2 = DHT11_Read(DHT11);
    temp1 = DHT11_Read(DHT11);
    temp2 = DHT11_Read(DHT11);
    checksum = DHT11_Read(DHT11);
    if ((humi1 + humi2 + temp1 + temp2) == checksum) {
        DHT11->Temp = temp1;
        DHT11->Humi = humi1;
        return DHT11->Temp;
    }
    return -1;
}

float DHT11_ReadHumi(DHT11_Name* DHT11) {
    return DHT11->Humi;
}
