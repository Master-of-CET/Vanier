/**************************************************************************************************
* FileName: configuration.h
*
* Name: Leonardo Fusser (1946995)       Lab 3       Servomotor - open loop control
*                                       Lab 4       Servomotor - closed loop control 
*
* Description: Includes all common macros needed by many files. Includes the important macro to swap 
*              from simulation mode to target mode and vis-versa.
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould       28 January 2021     v1.0.0      First version of header file.
* Leonardo Fusser   29 October 2021     v1.0.1      Minor changes.
* Leonardo Fusser   9 November 2021     v2.0.0      Initial changes for Lab4.
* Leonardo Fusser   29 November 2021    v2.0.1      Completed configuration.h file.
*                                                   Added comments. 
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef CONFIGURATION_H
#define	CONFIGURATION_H

/*All dependencies required are included below*/
#include <xc.h>
#include <stdint.h>
#include "initBoard.h"
#include "console32.h"
#include "DCMotor_model3.h"
#include <stdio.h>
#include "pwm.h"
#include "pv_measure.h"
#include "configuration.h"
#include "public.h"
#include "Tick_core.h"
#include "adc32.h"

/* Macro to swap from simulation mode to target mode and vis-versa. */
/* To run target mode, comment out this line.                       */
//#define SIMULATION

/* Macro to swap between Lab3 and Lab4.     */
/* To run Lab4, comment out the line below. */
//#define Lab3

#define DIR             LATGbits.LATG9  //Direction pin on PIC32.
#define HUNDRED_DUTY    10000           //10000 uS or 100 Hz.
#define REVERSE         0               //Reverse direction.
#define FORWARD         1               //Forward direction.

#endif	/* CONFIGURATION_H */
