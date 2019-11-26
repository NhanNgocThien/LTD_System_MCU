/* 
 * File:   DHT.h
 * Author: USER
 *
 * Created on November 8, 2019, 8:23 PM
 */

#ifndef DHT_H
#define	DHT_H

#ifdef	__cplusplus
extern "C" {
#endif

    #include "xc.h"
    #include "global_var.h"
    
    #define TIMEOUT 10000000
    
    char Sum, checkSum;
    char response = 0;
    char error = 0;
    int Temp, Humid;
    int lastTemp, lastHumid = 0;
    char temperature_dht11[2];
    char humidity_dht11[2];
    
    char readDHT();
    char GetByte();
    void getTempAndHumid();
   
#ifdef	__cplusplus
}
#endif

#endif	/* DHT_H */

