#include "stdint.h"
#include "DHT.h"
#include "pin_manager.h"
#include "LCD.h"
#include "global_var.h" 


char getByte() {
    char i, j;
    unsigned int timeOut;
    timeOut = TIMEOUT;
    for(j = 0; j < 8; j++)
    {
        timeOut = TIMEOUT;
        while(!DATA_IN & 1)
            if(--timeOut == 0) return 0;
        __delay_us(28);
        if(DATA_IN == 0){
            i &= ~(1<<(7 - j)); 
        }
        else {
            i |= (1 << (7 - j)); 
        } 
        timeOut = TIMEOUT;
        while(DATA_IN & 1) 
            if(--timeOut == 0) return 0;
    }
    return i;
}

char readDHT() {
    unsigned int timeOut = TIMEOUT;
    DATA_DIR = 0;
    DATA_OUT = 0;
    __delay_ms(20);
    
    DATA_OUT = 1;
    __delay_us(20);
    DATA_DIR = 1;
    
    while(DATA_IN & 1) {
        //LCDPutStr("Response 1");
        if(--timeOut == 0) {
            error = 1;
            return 0;
        }
    }
    
    timeOut = TIMEOUT;
    while(!DATA_IN & 1) {
        //LCDPutStr("Response 2");
        if(--timeOut == 0) {
            error = 1;
            return 0;
        }
    }
   
    timeOut = TIMEOUT;
    while(DATA_IN & 1) {
        //LCDPutStr("Response 3");
        if(--timeOut == 0) {
            error = 1;
            return 0;
        }
    }

    humidity_dht11[0] = getByte();
    humidity_dht11[1] = getByte();
    temperature_dht11[0] = getByte();
    temperature_dht11[1] = getByte();
    checkSum = getByte();
    
    char test = (humidity_dht11[0] + humidity_dht11[1] + temperature_dht11[0] + temperature_dht11[1] ) & 0xFF;  
    if( test != checkSum ) {
        error = 1;
        return 0;
    }
 
    error = 0;
    return 1;
}

void getTempAndHumid(void) {
//    if(!readDHT()) {
////        error= 0;
//        return;
//    }
    if(error == 1) {
        return;
    }
    Temp = temperature_dht11[0];
    Humid = humidity_dht11[0];
    PrintTempHumid(1);
//    if(lastTemp != Temp || lastHumid != Humid) PrintTempHumid(1);
//    lastTemp = Temp;
//    lastHumid = Humid;
    return;
}

