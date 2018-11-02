#ifndef __LED_H
#define __LED_H
#include "../../common/system.h"
#include "stdint.h"
#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>

#define PREP APB2

#define LED_WHAT GPIO
#define LED1_P B
#define LED1_PIN 11

#define LED_WHAT GPIO
#define LED2_P A
#define LED2_PIN 4

#define LED1_PORT GLUE(LED_WHAT, LED1_P)
#define LED1_RCC_CLK_PREP GLUE(GLUE(GLUE(GLUE(RCC_, PREP), Periph_), LED_WHAT), LED1_P)
#define LED1_GPIO_PIN GLUE(GPIO_Pin_, LED1_PIN)

#define LED2_PORT GLUE(LED_WHAT, LED2_P)
#define LED2_RCC_CLK_PREP GLUE(GLUE(GLUE(GLUE(RCC_, PREP), Periph_), LED_WHAT), LED2_P)
#define LED2_GPIO_PIN GLUE(GPIO_Pin_, LED2_PIN)

void led_init();
void led_toggle(uint8_t ledId);
void led_turnOn(uint8_t ledId);
void led_turnOff(uint8_t ledId);
#endif