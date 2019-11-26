/* 
 * File:   OSCL_TMR_Set_Up.h
 * Author: USER
 *
 * Created on September 30, 2019, 8:35 AM
 */

#ifndef OSCL_TMR_SET_UP_H
#define	OSCL_TMR_SET_UP_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    #ifdef _18F8722
    #pragma config  OSC = INTIO7
    #pragma config 	FCMEN = OFF
    #pragma config 	IESO = OFF
    #pragma config 	PWRT = OFF
    #pragma config 	BOREN = OFF
    #pragma config 	WDT = OFF
    #pragma config 	MCLRE = ON
    #pragma config 	LVP = OFF
    #pragma config 	XINST = OFF
    #endif 
    
    #include "xc.h"
    #include "global_var.h"
    #include "pin_manager.h"
    
    void IFreq_Initialize();
    int CalculateNumOfTicks(double interrupt_time, long freq, int preScale);
    void TMR_Initialize(int timer_name);
    void TMR_StartTimer(int timer_name);
    void TMR_StopTimer(int timer_name);

#ifdef	__cplusplus
}
#endif

#endif	/* OSCL_TMR_SET_UP_H */

