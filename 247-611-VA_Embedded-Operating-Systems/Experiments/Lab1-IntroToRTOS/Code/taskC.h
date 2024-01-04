/**************************************************************************************************
* FileName: taskC.h
*
* Name: Leonardo Fusser (1946995)       Lab 2       Intro to queues and mutexes
*
* Description: Header file for taskC.c source file. Macro definitions and function prototypes for
*              the corresponding source file can be found here. Other macro constants can be found 
*              in public.h file.
*  
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   10 February 2022    v1.0.0      First version of header file.
*                                                   Added macros for portability.
*                                                   Created function prototypes.
* Leonardo Fusser   February 15 2022    v1.0.1      Minor changes.
*                                                   Completed header file.
* Leonardo Fusser   16 February 2022    v1.0.2      Minor change.  
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef TASKC_H
#define TASKC_H

/* Includes. */
#include "include/public.h"

/* Various macros constants. */
#define S3 _RD6             //S3 pushbutton on Explorer 16/32 board.
#define S6 _RD7             //S6 pushbutton on Explorer 16/32 board.
#define S4 _RD13            //S4 pushbutton on Explorer 16/32 board.

#ifndef SIMULATION          //If Explorer 16/32 board selected...
    #define DELAY_400mS 400 //Defines 400mS delay.
    #define DELAY_200mS 200 //Defines 200mS delay.

#else                       //Else, MPLAB X IDE simulator is selected...
    #define DELAY_400mS 40  //Defines 40mS delay.
    #define DELAY_200mS 10  //Defines 10mS delay.

#endif

#define DELAY_10mS  10      //10mS delay.
#define DELAY_0mS   0       //0mS delay.

/* Function prototypes. */
static void taskC( void *pvParameters );
void vInit_TaskC(void);
void vInitStart_TaskC(void);
void vInitSemaphore_TaskC(void);
void taskC_setDelay(int temp_set);
int taskC_getDelay(void);

#endif
