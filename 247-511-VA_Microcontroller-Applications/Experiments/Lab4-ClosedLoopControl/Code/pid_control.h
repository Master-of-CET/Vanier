/**************************************************************************************************
* FileName: pid_control.h
*
* Name: Leonardo Fusser (1946995)       Lab 4       Servomotor - closed loop control
*
* Description: This code provides the pid_control.c file with all function prototypes, macros, and
*              any other dependencies that are needed. 
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   9 November 2021     v1.0.0      First version of header file.
* Leonardo Fusser   29 November 2021    v1.0.1      Completed pid_control.h file.
*                                                   Added comments and description header. 
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef PID_CONTROL_H
#define PID_CONTROL_H

#include "configuration.h"  //Includes all code dependencies.

#ifndef SIMULATION          //If target mode is desired...
    #define DELAY   100     //Set sampling time dealy to 10mS.

#else                       //Otherwise, simulation mode is desired...
    #define DELAY   1000    //Set sampling time delay to 1mS.

#endif

#define TICKS_DELAY        TICKS_PER_SECOND/DELAY                       //Convert sampling time delay in seconds to ticks.     
#define SAMPLING_TIME      TickDiff(lastTick) > TICKS_DELAY             //Checks to see if sampling time delay has elapsed (non-blocking way).

/*KP, KI and Anti-windup constants for simulation mode (best values)*/
#define KP_SIM             10
#define KI_SIM             0.1
#define ANTI_WINDUP_SIM    1000

/*KP, KI and Anti-windup constants for target mode (best values)*/
#define KP_TAR             30
#define KI_TAR             0.1
#define ANTI_WINDUP_TAR    200

void pid_control(void);                                                 //Function prototype.

#endif
