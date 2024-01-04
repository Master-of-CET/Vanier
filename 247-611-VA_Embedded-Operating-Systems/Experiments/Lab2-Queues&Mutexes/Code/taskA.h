/**************************************************************************************************
* FileName: taskA.h
*
* Name: Leonardo Fusser (1946995)       Lab 2       Intro to queues and mutexes
*
* Description: Header file for taskA.c source file. Macro definitions and function prototypes for
*              the corresponding source file can be found here. Other macro constants can be found 
*              in public.h file.
*  
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   January 20 2022     v1.0.0      First version of header file.
*                                                   Added macros for portability.
*                                                   Created function prototypes.
* Leonardo Fusser   February 15 2022    v1.0.1      Minor changes.
*                                                   Completed header file. 
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef TASKA_H
#define TASKA_H

/* Includes. */
#include "include/public.h"

/* Function prototypes. */
static void taskA(void *pvParameters);
void vInit_TaskA(void);
void vInit_StartTaskA(void);

#endif
