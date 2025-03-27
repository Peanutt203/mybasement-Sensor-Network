#ifndef __SYS__
#define __SYS__

#include "uart.h"
#include "rfid.h"
#include "tim2.h"
#include "gpio.h"

void Sys_Init(void);
void Sys_Run(void);

#endif