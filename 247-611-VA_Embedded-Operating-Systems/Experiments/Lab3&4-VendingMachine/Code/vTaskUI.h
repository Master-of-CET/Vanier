/**************************************************************************************************
* FileName: vTaskUI.h
*
* Name: Leonardo Fusser (1946995)       Lab 3       Vending Machine
*                                       Lab 4       Vending Machine II 
*
* Description: Header file for vTaskUI.c source file. Macro definitions and function prototypes for
*              the corresponding source file can be found here. Other macro constants can be found 
*              in public.h file.
*  
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   February 17 2022    v1.0.0      First version of header file.
*                                                   Added includes.
*                                                   Added function prototypes.
*                                                   Added comments.
* Leonardo Fusser   5 March 2022        v1.0.1      Added macros.
*                                                   Added function prototype.
*                                                   Added comments.
* Leonardo Fusser   9 March 2022        v1.0.2      Added macros.
*                                                   Added comments.
*                                                   Removed a function prototype.
* Leonardo Fusser   10 April 2022       v2.0.0      Minor changes.
*                                                   Completed header file. 
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef VTASKUI_H
#define VTASKUI_H

/* Includes. */
#include "public.h"

/* PB macros. */
#define S3  _RD6                //S3 on Explorer 16/32 board.
#define S4  _RD13               //S4 on Explorer 16/32 board.
#define S6  _RD7                //S6 on Explorer 16/32 board.

/* Delay macros. */
#define DELAY_200mS 2000000     //20-million ticks.
#define DELAY_3S    30000000    //30-million ticks.

/* PB state macros. */
#define NO_PRESS 0x0007         //PB state when no PBs are pressed.
#define S3_PRESS 0x0006         //PB state when only S3 is pressed.
#define S4_PRESS 0x0005         //PB state when only S4 is pressed.
#define S6_PRESS 0x0003         //PB state when only S6 is pressed.

/* Function prototypes. */
static void vTaskUI( void *pvParameters );
void vInit_vTaskUI(void);
void vInit_StartTaskUI(void);

#endif
