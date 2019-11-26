#include "xc.h"
#include "global_var.h"
#include "pin_manager.h"
#include "OSCL_TMR_Set_Up.h"
#include "system.h"
#include "buttons.h"

void readButtonRA5() {
//    firstReadRA5 = secondReadRA5;
//    secondReadRA5 = BUTTON1;
    if(BUTTON1 == 0 && isPress_1 == 0) {
        isPress_1 = 1;
        if(idle_flag == 1) {
            if(set_flag == 1) {
                if(temp_set_flag == 1) {
                    temp_set_flag = 0;
                    humid_set_flag = 1;
                    return;
                }
                else if(humid_set_flag == 1) {
                    humid_set_flag = 0;
                    time_set_flag = 1;
                    mCURSOR_LINE2;
                    LCDPutStr("   Time = 00      ");
                    PrintSetTime();
                    return;
                }
                else if(time_set_flag == 1) {
                    time_set_flag = 0;
                    set_flag = 0;
                    PrintIdle();
                }
            }
            else if(set_flag == 0) {
                Task_Init();
                idle_flag = 0;
            }
        }
        else if(idle_flag == 0) {
            if(demo_flag == 0) {
                demoTemp = 0;
                demoHumid = 0;
                TMR_StopTimer(0);
                demo_flag = 1;
            }
            else if(demo_flag == 1) {
                TMR_StartTimer(0);
                demo_flag = 0;
            }
            return;
        }
    }
    else if(BUTTON1 == 1) isPress_1 = 0;
}

void readButtonRB0() {
//    firstReadRB0 = secondReadRB0;
//    secondReadRB0 = BUTTON2;
    if(BUTTON2 == 0 && isPress_2 == 0) {
        isPress_2 = 1;
        if(idle_flag == 1) {
            if(set_flag == 0) {
                MAX_HEAT = 0;
                MAX_HUMID = 0;
                Time = 0;
                PrintSetUp();
                temp_set_flag = 1;
                set_flag = 1;
            }
            else if(set_flag == 1 && temp_set_flag == 1) {
                MAX_HEAT = (MAX_HEAT + 5) % 60;
                SetUp_Temp();
            }
            else if(set_flag == 1 && humid_set_flag == 1) {
                MAX_HUMID = (MAX_HUMID + 10) % 90;
                SetUp_Humid();
            }
            else if(set_flag == 1 && time_set_flag == 1) {
                Time = (Time + 1) % 10;
                PrintSetTime();
            }
        }
        else if(idle_flag == 0) {
            if(demo_flag == 0) {
                IDLE = 1;
                WORKING = 0;
                idle_flag = 1;
                return;
            }
            else if(demo_flag == 1) {
                demoTemp = (demoTemp + 5) % 60;
                demoHumid = (demoHumid + 10) % 90;
                CheckTemp();
                CheckHumid();
                return;
            }
        }
    }
    else if(BUTTON2 == 1) isPress_2 = 0;
}