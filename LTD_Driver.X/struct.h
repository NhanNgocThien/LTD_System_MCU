/* 
 * File:   struct.h
 * Author: USER
 *
 * Created on October 7, 2019, 8:32 AM
 */

#ifndef STRUCT_H
#define	STRUCT_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    #include <xc.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>
    #include "OSCL_TMR_Set_Up.h"
    #include "global_var.h"
    #include "clock.h"

    #define MAX_NUM 10
    
    typedef unsigned long long uint64_t;
    
    struct Node{
        void (*pTask)();      
        uint64_t Delay;
        uint64_t Period;
        int task_identifier;
        unsigned char isMark;
        int next;
    };
    
    int capacity = MAX_NUM;
    int size = 0;   
    
    int head = 0;
    int executed_list_index = 0;
    
    struct Node elementList[MAX_NUM];
    FUNCTION_PTR executedList[MAX_NUM];
  
    void InitializeElements(); 
    TByte AddElement(uint64_t delay, uint64_t period, FUNCTION_PTR data, int task_id);
    void AddExecutedTask(FUNCTION_PTR data);
    
    void UpdateElements();
    void UpdateTimeOut();
    void dispatchISR();
    
    int deQueue();  
    int RemoveElement(int id);
    
 
#ifdef	__cplusplus
}
#endif

#endif	/* STRUCT_H */

