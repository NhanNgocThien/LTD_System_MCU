/* 
 * File:   clock.h
 * Author: USER
 *
 * Created on October 5, 2019, 10:59 AM
 */

#ifndef CLOCK_H
#define	CLOCK_H

#ifdef	__cplusplus
extern "C" {
#endif

    #include <stdint.h>
    #include <xc.h>
    #include "struct.h"
    #include "pin_manager.h"
    #include "OSCL_TMR_Set_Up.h"
       
    int register_timer(uint64_t delay, uint64_t callback, FUNCTION_PTR data);

#ifdef	__cplusplus
}
#endif

#endif	/* CLOCK_H */

