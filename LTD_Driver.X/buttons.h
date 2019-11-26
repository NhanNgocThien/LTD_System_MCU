/* 
 * File:   buttons.h
 * Author: USER
 *
 * Created on November 16, 2019, 9:08 PM
 */

#ifndef BUTTONS_H
#define	BUTTONS_H

#ifdef	__cplusplus
extern "C" {
#endif

    TByte firstReadRA5 = 1; 
    TByte secondReadRA5 = 1;
    
    TByte firstReadRB0 = 1;
    TByte secondReadRB0 = 1;
    
    void readButtonRA5();
    void readButtonRB0();

#ifdef	__cplusplus
}
#endif

#endif	/* BUTTONS_H */

