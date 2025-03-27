#include "sys.h"

void Sys_Init(void)
{
    // Initialize Timer2
    Timer2_Init();
    // Initialize GPIO
    GPIO_Debug_Init();
    // Initialize USART at 9600 baud
    USART1_Init(9600);
    // Add a startup delay
    Delay_ms(200);
    // Initialize RFID module
    RFID_Init();
    USART1_Send_String("RFID Reader Initialized\r\n");
    Off();
}

void Sys_Run(void)
{
    //RFID_Debug_ReadCard();
    //On();
		//Delay_ms(1000);
    //Off();
		Debug();
}
