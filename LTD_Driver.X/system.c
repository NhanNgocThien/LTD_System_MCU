#include "system.h"

void test() {
    LATDbits.LATD1 = !LATDbits.LATD1;
}

void Task_Init() {
    int task_1 = register_timer(0, Time * 200, Heater_On);
    int task_2 = register_timer(Time * 100, Time * 200, Pump_On);
    int task_3 = register_timer(0, 100, CheckTemp);
    int task_4 = register_timer(0, 100, CheckHumid);
    int task_6 = register_timer(0, 100, test);
    
    TMR_StartTimer(0);
}

void System_Initialize() {
    IFreq_Initialize();
    
    TMR_Initialize(0);
    TMR_Initialize(1);
    
    InitializeElements();
    
    PIN_SetUp();
    LCD_SetUp();
    
    TMR_StartTimer(1);
}

void CheckHumid() {
    if((demoHumid > MAX_HUMID || Humid >= MAX_HUMID) && idle_flag == 0 && FAN1 == 0) {
        FAN1 = 1;
    }
}

void CheckTemp() {
    if((demoTemp >= MAX_HEAT || Temp >= MAX_HEAT) && heater_flag == 1) {
        Heater_Off();
        Pump_On();
    }
    if((demoTemp >= MAX_HEAT || Temp >= MAX_HEAT) && pump_flag == 1) {
        idle_flag = 1;
    }
}

void Heater_On() {
    heater_flag = 1;
}

void Heater_Operation() {
    FAN2 = 1;
}

void Heater_Off() {
    heater_flag = 0;
    FAN2 = 0;
}

void Pump_On() {
    pump_flag = 1;
}

void Pump_Operation() {
    FAN3 = 1;
}

void Pump_Off() {
    pump_flag = 0;
    FAN3 = 0;
}

void FSM() {
    switch(nextState) {
        case INIT:
            IDLE = 1;
            WORKING = 0;
            if(idle_flag == 0) {
                IDLE = ERROR = 0;
                WORKING = 1;
                Heater_Operation();
                PrintHeater();
                nextState = STATE1;
                TimeOut = SIXTY_SEC;
            }
            break;
        case STATE1:
            // Heater Operation
            if(pump_flag == 1) {
                Heater_Off();
                nextState = STATE2;
                Pump_Operation();
                PrintPump();
                TimeOut = SIXTY_SEC;
            }
            else if(idle_flag == 1) {
                Heater_Off();
                Pump_Off();
                FAN1 = 0;
                demoTemp = demoHumid = 0;
                nextState = INIT;
                PrintIdle();
            }
            else if(error_flag == 1) {
                ERROR = 1;
                Heater_Off();
                idle_flag = 1;
                nextState = INIT;
                PrintIdle();
            }
            else {
                readDHT();
                if(demo_flag == 0) {
                    getTempAndHumid();
   
                } else {
                    PrintDemo();
                }
            }
            break;
        case STATE2:
            // Dehydration Operation
            if(heater_flag == 1) {
                Pump_Off();
                nextState = STATE1;
                Heater_Operation();
                PrintHeater();
                TimeOut = SIXTY_SEC;
            }
            else if(idle_flag == 1) {
                Heater_Off();
                Pump_Off();
                FAN1 = 0;
                demoTemp = demoHumid = 0;
                nextState = INIT;
                PrintIdle();
            }
            else if(error_flag == 1) {
                ERROR = 1;
                Pump_Off();
                idle_flag = 1;
                nextState = INIT;
            }
            else{ 
                readDHT();
                if(demo_flag == 0) {
                    getTempAndHumid();
                } else {
                    PrintDemo();
                }
            }
            break;
    }
}