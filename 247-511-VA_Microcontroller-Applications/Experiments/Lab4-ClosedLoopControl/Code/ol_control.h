/**************************************************************************************************
* FileName: ol_control.h
*
* Name: Leonardo Fusser (1946995)       Lab 3       Servomotor - open loop control
*
* Description: This code provides the ol_control.c file with all function prototypes, macros, and
*              any other dependencies that are needed. 
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   29 October 2021     v1.0.0      First version of header file.
* Leonardo Fusser   14 November 2021    v1.0.1      Completed ol_control.h file.
*                                                   Added comments and description header. 
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef OL_CONTROL_H
#define	OL_CONTROL_H

#include "configuration.h"  //Includes all code dependencies.

#ifndef SIMULATION          //If target mode is desired...
    #define DELAY   100     //Set sampling time dealy to 10mS.

#else                       //Otherwise, when simulation mode is desired...
    #define DELAY   1000    //Set sampling time delay to 1mS.

#endif

#define TICKS_DELAY        TICKS_PER_SECOND/DELAY           //Convert sampling time delay in seconds to ticks.     
#define SAMPLING_TIME      TickDiff(lastTick) > TICKS_DELAY //Checks to see if sampling time delay has elapsed (non-blocking way).

void ol_control(void);     //Function prototype.

#endif
