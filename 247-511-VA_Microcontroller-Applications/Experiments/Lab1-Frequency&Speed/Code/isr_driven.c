/**********************************************************************************************
* FileName: isr_driven.c
*
* Name: Leonardo Fusser (1946995)   Lab 1       Function Generator
*
* Description: This is a multi-part program covering Lab 1. In Part 1, the MPLAB X IDE simulator is
*              used to simulate the real working measurement of an encoder connected to a motor. In
*              Part 2 and 3, the same simulation done before is now done on the Explorer 16/32 board, 
*              where a jumper connects between P97 and P11 on the board. In Part 4, a motor is connected 
*              to the board and a real RPM measurement is done and the result is displayed to the board's
*              LCD. In addition, a pushbutton is used to turn on or off the motor and a LED blinks
*              when a measurement is taking place otherwise it will remain off.  
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   24 August 2021      v1.0.0      Created isr_driven.c file.
*                                                   Added T2 and CN9 interrupt functions and comments.
* Leonardo Fusser   31 August 2021      v1.0.1      Added Timer2 overflow counter.
*                                                   Added calculation for period in CN9 ISR.
* Leonardo Fusser   3 September 2021    v1.0.2      Made "of" variable available to main.c .
* Leonardo Fusser   14 September 2021   v1.0.3      Added description.
* Leonardo Fusser   19 September 2021   v1.0.4      Added comments and function prologs. 
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


//#include "isr_driven.h"
#include <stdint.h>
#include <xc.h>
#include <sys/attribs.h>

extern signed int of = 0;           //Variable to store Timer2 overflow count.
extern int timePeriod = 1;          //Variable to store calculated period in ticks.

/**********************************************************************************************
* Name: void __ISR( _TIMER_2_VECTOR, IPL1SOFT) T2InterruptHandler(void) 
* Description: Interrupt service routine (ISR) for Timer2 module.
*              Interrupts every 65'537 ticks. 
*              During each interrupt, overflow variable "of" is increased by 1. 
* 
***********************************************************************************************/
void __ISR( _TIMER_2_VECTOR, IPL1SOFT) T2InterruptHandler(void){
    
    IFS0bits.T2IF = 0;          //Clears Timer2 module interrupt flag (prevents ISR trapping).
    of++;                       //Increments overflow variable by 1 when Timer2 overflows.
    
}

/**********************************************************************************************
* Name: void __ISR( _CHANGE_NOTICE_VECTOR, IPL2SOFT) CNInterrupt(void) 
* Description: Interrupt service routine (ISR) for change notification on PIC32 I/O pins.
*              Interrupts every time change-of-state is detected on any CN pins on PIC32. 
*              During each interrupt, a period measurement (in ticks) is performed. 
* 
***********************************************************************************************/
void __ISR(_CHANGE_NOTICE_VECTOR, IPL2SOFT) CNInterrupt(void){
    
    static signed int start;    //Variable for T1 in ticks (beginning of period).
    static signed int final;    //Variable for T2 in ticks (end of period).
    
    if(PORTGbits.RG7){                                  //If detect rising edge, execute code below...
        final = TMR2;                                   //Store last value in TMR2 register.
        timePeriod = (of * 0x10000) + final - start;    //Calculate period in ticks.
        start = final;                                  //Store value of T2 in T1.
        of = 0;                                         //Clear overflow counter.
    } 
    
    IFS1bits.CNIF = 0;                                  //Clears CN interrupt flag (prevents ISR trapping).
    
}