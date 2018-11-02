#include "led.h"

#define IIF(cond) IIF_ ## cond
#define IIF_0(t, f) f
#define IIF_1(t, f) t

uint8_t led1Status = 0;
uint8_t led2Status = 0;

void led_init(){
    // GPIO structure for port initialization
    GPIO_InitTypeDef GPIO_InitStructure;
 
    // enable clock on APB2
    RCC_APB2PeriphClockCmd(LED1_RCC_CLK_PREP,  ENABLE);
    RCC_APB2PeriphClockCmd(LED2_RCC_CLK_PREP,  ENABLE);

    // configure port A1 for driving an LED
    GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;    // output push-pull mode
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;   // highest speed
    GPIO_Init(LED1_PORT, &GPIO_InitStructure) ;             // initialize port

    // configure port A1 for driving an LED
    GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;    // output push-pull mode
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;   // highest speed
    GPIO_Init(LED2_PORT, &GPIO_InitStructure) ;             // initialize port

    led_turnOff(1);
    led_turnOff(2);
    
}

void led_toggle(uint8_t ledId){
    switch(ledId){
        case 1:
            if(led1Status == 1)
                led_turnOff(1);
            else
                led_turnOn(1);
            break;
        case 2:
            if(led2Status == 1)
                led_turnOff(2);
            else
                led_turnOn(2);
            break;
    }
}

void led_turnOn(uint8_t ledId){
    switch(ledId){
        case 1:
            led1Status = 1;
            GPIO_ResetBits(LED1_PORT, LED1_GPIO_PIN);    // turn the LED on
            break;
        case 2:
            led2Status = 1;
            GPIO_ResetBits(LED2_PORT, LED2_GPIO_PIN);    // turn the LED on
            break;
    }
}

void led_turnOff(uint8_t ledId){
    switch(ledId){
        case 1:
            led1Status = 0;
            GPIO_SetBits(LED1_PORT, LED1_GPIO_PIN);    // turn the LED off
            
            break;
        case 2:
            led2Status = 0;
            GPIO_SetBits(LED2_PORT, LED2_GPIO_PIN);    // turn the LED off
            break;
    }
}

