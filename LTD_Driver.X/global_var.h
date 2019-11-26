/* 
 * File:   global_var.h
 * Author: USER
 *
 * Created on September 30, 2019, 9:24 AM
 */

#ifndef GLOBAL_VAR_H
#define	GLOBAL_VAR_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    #define _XTAL_FREQ 10000000
    
    #define FREQ 4000000 // 1MHz
    #define PRESCALE 256 // TMR preScale
    #define ISR 0.01 // 100ms
    #define TICKS 1
    #define SIXTY_SEC 6000
    #define ONE_SEC 100
    #define FIVE_SEC 500
 
    typedef unsigned char TByte;
    typedef void (*FUNCTION_PTR)(); 
    
    TByte MAX_HEAT = 50;
    TByte MAX_HUMID = 90;
    int Time = 10;
    
    TByte timer_list[5] = {0, 1, 2, 3, 4};
    unsigned int timer_list_count[5] = {0, 0, 0, 0, 0};
    unsigned int timer_millis_sec[5] = {0, 0, 0, 0, 0};
    TByte task = 1;
    TByte id = 0;
    int TimeOut = SIXTY_SEC;
   
    TByte isPress_1 = 0;
    TByte isPress_2 = 0;
    
    enum{INIT, STATE1, STATE2, TIMEOUT} nextState;
    
    int demoTemp, demoHumid;
    
    TByte ready_1 = 0;
    TByte ready_2 = 0;
    TByte init_flag = 0;
    TByte set_flag = 0;
    
    TByte temp_set_flag = 0;
    TByte humid_set_flag = 0;
    TByte time_set_flag = 0;
    
    TByte demo_flag = 0;
    TByte send_count = 0;
    
    TByte idle_flag = 1;
    TByte heater_flag = 0;
    TByte pump_flag = 0;
    TByte error_flag = 0;
    
#ifdef	__cplusplus
}
#endif

#endif	/* GLOBAL_VAR_H */

