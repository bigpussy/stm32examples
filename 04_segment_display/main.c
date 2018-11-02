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
    // seg_display(5);
    while(1) {
        uint8_t number;
        for(number=0xf;number>=0;number--){
            delay(DELAY);
            seg_display(number);
        }
    }
}
