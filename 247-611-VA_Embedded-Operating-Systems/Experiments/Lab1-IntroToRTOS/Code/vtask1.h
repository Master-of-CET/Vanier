/**************************************************************************************************
* FileName: vtask1.h
*
* Name: Leonardo Fusser (1946995)       Lab 1       Intro to RTOS
*
* Description: Header file for vtask1.c source file. Macro definitions and function prototypes for
*              the corresponding source file can be found here.
*  
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   January 20 2022     v1.0.0      First version of header file.
*                                                   Completed header file.
*                                                   Added function prototypes.
*                                                   Added comments.
*                                                   Added macros for portability. 
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef VTASK1_H
#define VTASK1_H

#include "include/public.h"

#define LED_T1 _LATA1   //LED D4 on Explorer 16/32 board.

/* Function prototypes. */
static void vTask1(void *pvParameters);
void vStartTask1(void);

#endif
