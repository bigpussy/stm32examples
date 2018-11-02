#ifndef __SEGMENT_H
#define __SEGMENT_H

#include "../../common/system.h"
#include "stdint.h"
#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>

#define PREP APB2
#define PORT_WHAT GPIO
#define SEGMENT_PORT_N A
#define SEGMENT_RCC_CLK_PREP GLUE(GLUE(GLUE(GLUE(RCC_, PREP), Periph_), PORT_WHAT), SEGMENT_PORT_N)
#define SEGMENT_GPIO_PIN GLUE(GPIO_Pin_, 0) \
                       | GLUE(GPIO_Pin_, 1) \
                       | GLUE(GPIO_Pin_, 2) \
                       | GLUE(GPIO_Pin_, 3) \
                       | GLUE(GPIO_Pin_, 4) \
                       | GLUE(GPIO_Pin_, 5) \
                       | GLUE(GPIO_Pin_, 6) \
                       | GLUE(GPIO_Pin_, 7) 
/*
    SEG_PORT define a group of port
    the pins are continuous, and the lowest 7 pin are mapped, for example: a0~a6 mapping to the segment dispalys pins from A~G

    This code dosen's support disordered mappings
*/
#define SEGMENT_PORT GLUE(PORT_WHAT, SEGMENT_PORT_N)

/**
 * init
 * */
void seg_init();
/**
 * Display a number
 * number: one number less than 0x10(0~F)
 * */
void display(uint8_t number);
#endif