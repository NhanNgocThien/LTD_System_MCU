#include "pin_manager.h"
#include "xc.h"

void PIN_SetUp() {
    
    TRISDbits.TRISD1 = 0;
    LATDbits.LATD1 = 0;
    
    FAN1_DIR = 0;
    FAN2_DIR = 0;
    FAN3_DIR = 0;
    
    IDLE_DIR = 0;
    WORKING_DIR = 0;
    ERROR_DIR = 0;
    
    FAN1 = FAN2 = FAN3 = 0;
    IDLE = 0;
    WORKING = 0;
    ERROR = 0;
    
    BUTTON1_DIR = 1;
    BUTTON2_DIR = 1;
    ADCON1=0x0F;
};
