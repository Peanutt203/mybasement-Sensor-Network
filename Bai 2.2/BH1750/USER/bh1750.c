#include "bh1750.h"

void BH1750_Init(void) {
    I2C_StartTransmission(I2C1, BH1750_ADDRESS, I2C_Direction_Transmitter);
    I2C_SendData(I2C1, 0x10); // Ch? d? do liên t?c, d? phân gi?i cao
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
    I2C_StopTransmission(I2C1);
}

uint16_t BH1750_ReadLight(void) {
    uint16_t light = 0;
    
    I2C_StartTransmission(I2C1, BH1750_ADDRESS, I2C_Direction_Receiver);
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED));
    light = I2C_ReceiveData(I2C1) << 8;
    while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED));
    light |= I2C_ReceiveData(I2C1);
    I2C_StopTransmission(I2C1);
    
    return light / 1.2; // C?m bi?n BH1750 tr? v? giá tr? theo h? s? 1.2
}
