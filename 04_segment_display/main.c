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

    seg_init();
    while(1) {
        delay(DELAY);
        // GPIO_ResetBits(LED1_PORT, LED1_GPIO_PIN); 
        // GPIO_SetBits(SEGMENT_PORT, 0x03);
    }
}
