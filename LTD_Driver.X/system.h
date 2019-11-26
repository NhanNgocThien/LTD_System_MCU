/* 
 * File:   system.h
 * Author: USER
 *
 * Created on November 19, 2019, 9:13 PM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif

    #include "xc.h"
    #include "OSCL_TMR_Set_Up.h"
    #include "clock.h"
    #include "struct.h"
    #include "global_var.h"
    #include "pin_manager.h"
    #include "DHT.h"
    #include "LCD.h"
    
    void System_Initialize();
    void Task_Init();
    void FSM();
    void test();
   
    void CheckHumid();
    void CheckTemp();
   
    void Heater_On();
    void Heater_Operation();
    void Heater_Off();
   
    void Pump_On();
    void Pump_Operation();
    void Pump_Off();

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

