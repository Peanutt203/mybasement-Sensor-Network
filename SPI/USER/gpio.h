#ifndef __GPIO__
#define __GPIO__

#include "stm32f10x.h"                  // Device header
#include "tim2.h"

#define LED_PIN GPIO_Pin_13
#define LED_PORT GPIOC

void GPIO_Debug_Init(void);
void Debug(void);
void On (void);
void Off (void);

#endif
