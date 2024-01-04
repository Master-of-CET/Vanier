/*
 *		pv_measure.c
 * 
 *      Measure the position of the motor by reading the rotary encoder pulses.
 *      Implemented using an CN interrupt.
 * 
 *		Serge Hould     Jan  2021       v1.0    		
 *      Serge Hould     3 Feb 2021      v1.1    Simpify code using register only
 *                                              No PLIB functions    
 */ 


#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/attribs.h>
//#include "peripheral/int.h"
#include "pv_measure.h"
#include "configuration.h"

static int32_t pos=0;  // motor position

// change notification interrupt service routine
void __ISR( _CHANGE_NOTICE_VECTOR, IPL1SOFT) CNInterrupt( void){ 
    
    if(PORTGbits.RG7){
        if(PORTGbits.RG6) pos++;
        else pos--;
    }
    // clear interrupt flag
    IFS1bits.CNIF=0;   
}

/* returns the motor position in tics */

#ifndef  SIMULATION
int get_pv(void){
    return pos;
}
#endif

/* Must be called at a constant period. e.g. every 10 mS*/
int get_speed(void){
    static int pos_mem;
    int speed;
    if(pos) speed = pos-pos_mem;
    else speed = pos_mem-pos;
    pos_mem = pos;
    if(speed != 0){
        speed = 2000/speed;
        return speed;
    }else return 0;
}

/* Initializes the CN interrupt */
void initPV_measure(void){
#ifndef  SIMULATION
    //CN
    CNENbits.CNEN9 = 1; // //SA channel- RG7
    //CNENbits.CNEN8 = 1; //SB channeL - RG6
    INTCONbits.MVEC=1; // enable multiVectoredInt
    __builtin_disable_interrupts();   // disable interrupts
    CNCONbits.ON = 1; // turn on Change Notification
    IPC6bits.CNIP=1;  
    IFS1bits.CNIF=0;   
    IEC1bits.CNIE=1;
    __builtin_enable_interrupts();   // enable interrupts
#endif
}

