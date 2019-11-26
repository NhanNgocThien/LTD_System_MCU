#include "OSCL_TMR_Set_Up.h"

void IFreq_Initialize() {
//    OSCCON = 0b01100011;
    OSCCON = 0x73;
    OSCTUNE = 0x0F;
    INTCON_DIR.GIE = 1;
    INTCON_DIR.PEIE = 1;
}

int CalculateNumOfTicks(double interrupt_time, long freq, int preScale) {
    int counts_per_sec = freq  / preScale;
    int local_millis_sec = counts_per_sec * interrupt_time;
    return local_millis_sec;
}

void TMR_Initialize(int timer_name) {
    switch(timer_name) {
        case 0:
            T0CON = 0b01000111;
            TMR0 = 0xB2;
//            timer_millis_sec[0] = CalculateNumOfTicks(ISR, FREQ, PRESCALE);
//            TMR0L = (0xFFFF - timer_millis_sec[0]);
//            TMR0H = ((0xFFFF - timer_millis_sec[0]) >> 8);
            INTCON_DIR.TMR0IE = 1;
            INTCON_DIR.TMR0IF = 0;
        break;
        
        case 1:
            T1CON = 0b10110100;
//            timer_millis_sec[1] = CalculateNumOfTicks(0.1, FREQ, 8);
//            TMR1H = ((0xFFFF - timer_millis_sec[1]) >> 8);
//            TMR1L = (0xFFFF - timer_millis_sec[1]);
            TMR1H = 0xF6;
            TMR1L = 0x3C;
            PIE1bits.TMR1IE = 1;
            PIR1bits.TMR1IF = 0;
            break;
    }   
}

void TMR_StartTimer(int timer_name) {
    switch(timer_name) {
        case 0:
            T0CONbits.TMR0ON = 1;
        break;
            
        case 1:
            T1CONbits.TMR1ON = 1;
        break;
    }
}   

void TMR_StopTimer(int timer_name) {
    switch(timer_name) {
        case 0:
            T0CONbits.TMR0ON = 0;
        break;
            
        case 1:
            T1CONbits.TMR1ON = 0;
        break;
    }
}
