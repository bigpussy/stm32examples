#include "segment.h"

void seg_init(){
    // GPIO structure for port initialization
    GPIO_InitTypeDef GPIO_InitStructure;

    // enable clock on APB2
    RCC_APB2PeriphClockCmd(SEGMENT_RCC_CLK_PREP,  ENABLE);

    // configure port A1 for driving an LED
    GPIO_InitStructure.GPIO_Pin = SEGMENT_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;    // output push-pull mode
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;   // highest speed
    GPIO_Init(SEGMENT_PORT, &GPIO_InitStructure) ;             // initialize port

    GPIO_SetBits(SEGMENT_PORT, 0x7F);
}



void display(uint8_t number){
    
}