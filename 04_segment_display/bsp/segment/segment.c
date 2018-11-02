#include "segment.h"

void seg_init(){
    // GPIO structure for port initialization
    GPIO_InitTypeDef GPIO_InitStructure;

    // enable clock on APB2
    RCC_APB2PeriphClockCmd(SEGMENT_RCC_CLK_PREP,  ENABLE);

    // configure port A1 for driving an LED
    GPIO_InitStructure.GPIO_Pin = SEGMENT_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;    // output push-pull mode
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;   // highest speed
    GPIO_Init(SEGMENT_PORT, &GPIO_InitStructure) ;             // initialize port

    GPIO_SetBits(SEGMENT_PORT, 0x7F);
}

uint16_t digit[16] =
{
    ~0x3f,
    ~0x06,
    ~0x5b,
    ~0x4f,
    ~0x66,
    ~0x6d,
    ~0x7d,
    ~0x07,
    ~0x7f,
    ~0x6f,
    ~0x77,
    ~0x7c,
    ~0x39,
    ~0x5e,
    ~0x79,
    ~0x71
};

void seg_display(uint8_t number){
    number = number % 0x10;
    GPIO_Write(SEGMENT_PORT, digit[number]);
} 
