#ifndef __MAIN_H
#define __MAIN_H
#define WHAT GPIO
#define WHICH C
#define WHERE 13
#define PREP APB2

#define GLUE(x, y) GLUE_(x, y)
#define GLUE_(x, y) x ## y

#define PORT GLUE(WHAT, WHICH)
#define RCC_CLK_PREP GLUE(GLUE(GLUE(GLUE(RCC_, PREP), Periph_), WHAT), WHICH)
// #define GPIO_Pin_ GPIO_Pin_
#define GPIO_PIN GLUE(GPIO_Pin_, WHERE)
// #define 
#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>

#define DELAY 1000  // in millis

#endif
