#include "tim2.h"

static volatile uint32_t counter_ms = 0; 

void Timer2_Init(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    TIM2->PSC = 72 - 1;       // Prescaler: 1 MHz (1 tick = 1 µs)
    TIM2->ARR = 1000 - 1;     // Auto-reload: 1000 µs = 1 ms

    TIM2->DIER |= TIM_DIER_UIE;

    TIM2->CR1 |= TIM_CR1_CEN;

    NVIC_SetPriority(TIM2_IRQn, 1); 
    NVIC_EnableIRQ(TIM2_IRQn);
}

void TIM2_IRQHandler(void)
{
    if (TIM2->SR & TIM_SR_UIF)
    {
        TIM2->SR &= ~TIM_SR_UIF;
        counter_ms++;           
    }
}

uint32_t millis(void)
{
    return counter_ms; 
}

void Delay_ms(uint32_t ms)
{
    uint32_t start_time = millis();
    while ((millis() - start_time) < ms); 
}

void Delay_us(uint16_t us)
{
    TIM2->CNT = 0; // Reset counter
    while (TIM2->CNT < us);
}
