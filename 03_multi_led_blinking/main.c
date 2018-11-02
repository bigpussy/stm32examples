#include "main.h"

void delay(int millis) {
    while (millis-- > 0) {
        volatile int x = 5971;
        while (x-- > 0) {
            __asm("nop");
        }
    }
}


int main(void) {

    led_init();
    led_toggle(2);
    while(1) {
        delay(DELAY);
        led_toggle(1);
        led_toggle(2);
    }
}
