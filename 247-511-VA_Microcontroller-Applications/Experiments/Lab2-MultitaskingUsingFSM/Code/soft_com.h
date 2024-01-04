/**************************************************************************************************
* FileName: soft_com.h
*
* Name: Leonardo Fusser (1946995)       Lab 2       Cooperative multitasking using FSM
*       Collins Agyeman-Duah (1554428) 
*
* Description: Code that allows data to be printed serially on PIC32 TX pin.
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   21 September 2021   v1.0.0      Created soft_com.h file.
* Leonardo Fusser   26 September 2021   v1.0.1      Implemented function prototypes.
* Leonardo Fusser   28 September 2021   v1.0.2      Github push test.
*                                                   Added macros. 
* Leonardo Fusser   2 October    2021   v1.0.3      Added SIMULATION and EXPLORER options.
*                                                   Added more function prototypes.
*                                                   Fixed some macros. 
*                                                   Added comments.
* Leonardo Fusser   2 November   2021   v1.0.4      Added ifdef function blocks and cleaned up code.   
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef SOFT_COM_H
#define SOFT_COM_H

#include "public.h"

    #ifdef  SIMULATION              //If MPLAB X IDE simulator selected...         
        #define  BAUD   200000      //Set baud rate to 200 kBaud.

    #else                           //Otherwise, Explorer 16/32 board selected...
        #define  BAUD   500         //Set baud rate to 500 Baud.

    #endif

#define  TIMEOUT_START  TickDiff(lastTick)>TICKS_PER_SECOND/BAUD        //RS232 start-bit bit time.
#define  TIMEOUT_STOP   TickDiff(lastTick)>(TICKS_PER_SECOND/BAUD)*4    //RS232 stop-bit bit time.
#define  TIMEOUT        TickDiff(lastTick)>TICKS_PER_SECOND/BAUD        //Character-bit bit time.
#define  TX             LATFbits.LATF5                                  //TX pin on PIC32.
#define  MASK           0x1                                             //For masking character bits to be sent to TX pin.

void SoftComTask(void);         //Function prototype.
void SimpleSoftComTask(void);   //" ".

#endif
