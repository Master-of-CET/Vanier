/**************************************************************************************************
* FileName: vtask2.h
*
* Name: Leonardo Fusser (1946995)       Lab 1       Intro to RTOS
*
* Description: Header file for vtask2.c source file. Macro definitions and function prototypes for
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


#ifndef VTASK2_H
#define VTASK2_H

#include "include/public.h"

#define LED_T2 _LATA0   //LED D3 on Explorer 16/32 board.

/* Function prototypes. */
static void vTask2(void *pvParameters);
void vStartTask2(void);

#endif
