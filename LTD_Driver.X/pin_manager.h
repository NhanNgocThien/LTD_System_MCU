/* 
 * File:   pin_manager.h
 * Author: USER
 *
 * Created on September 30, 2019, 8:35 AM
 */

#ifndef PIN_MANAGER_H
#define	PIN_MANAGER_H

#ifdef	__cplusplus
extern "C" {
#endif

#define INTCON_DIR INTCONbits
#define INTCON2_DIR INTCON2bits 
    
#define BUTTON1_DIR TRISAbits.RA5
#define BUTTON2_DIR TRISBbits.RB0
#define BUTTON1 PORTAbits.RA5
#define BUTTON2 PORTBbits.RB0
    
#define DATA_OUT LATDbits.LATD0
#define DATA_IN PORTDbits.RD0
#define DATA_DIR TRISDbits.TRISD0

#define FAN1 LATDbits.LATD2
#define FAN1_DIR TRISDbits.TRISD2
    
#define FAN2 LATDbits.LATD3
#define FAN2_DIR TRISDbits.TRISD3 
    
#define FAN3 LATDbits.LATD4
#define FAN3_DIR TRISDbits.TRISD4    
    
#define IDLE LATDbits.LATD7
#define IDLE_DIR TRISDbits.TRISD7
    
#define WORKING LATDbits.LATD6
#define WORKING_DIR TRISDbits.TRISD6     
    
#define ERROR LATDbits.LATD5
#define ERROR_DIR TRISDbits.TRISD5    
   
    void PIN_SetUp();

#ifdef	__cplusplus
}
#endif

#endif	/* PIN_MANAGER_H */

