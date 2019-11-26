#include "xc.h"

#include "system.h"
#include "buttons.h"

void __interrupt() global_timer(void) {
    // Timer 0 interrupt
    if(INTCON_DIR.TMR0IE == 1 && INTCON_DIR.TMR0IF == 1) {
        if(idle_flag == 0 && demo_flag == 0) {
            timer_list_count[0]++;
        }
        TMR0 = 0xB2;
        INTCON_DIR.TMR0IF = 0;
    }
    if(timer_list_count[0] >= TICKS && idle_flag == 0) {
        timer_list_count[0] = 0;
        UpdateElements();
        UpdateTimeOut();
    }
     // Timer 1 interrupt
    if(PIE1bits.TMR1IE == 1 && PIR1bits.TMR1IF == 1) {
         if(ready_2 == 0) {
            ready_2 = 1;
        }
//        if(idle_flag == 0 && demo_flag == 0) {
//            timer_list_count[1]++;
//        }
        readButtonRA5();
        readButtonRB0();
        TMR1H = 0xF6;
        TMR1L = 0x3C;
        PIR1bits.TMR1IF = 0;
    }
}

void main(void) {
    System_Initialize();
    while(1) {
        if(init_flag == 0) {
            if(ready_2 == 1){
                PrintIdle();
                IDLE = 1;
                init_flag = 1;
            }
        }
        FSM();
        if(idle_flag == 0 && demo_flag == 0) dispatchISR();
    }
    return;
}
