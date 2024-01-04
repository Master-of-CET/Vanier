/**************************************************************************************************
* FileName: vTaskTechnician.h
*
* Name: Leonardo Fusser (1946995)       Lab 4       Vending Machine II
*
* Description: Header file for vTaskTechnician.c source file. Macro definitions and function 
*              prototypes for the corresponding source file can be found here. 
*              Other macro constants can be found in public.h file.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   March 10 2022       v1.0.0      First version of header file.
*                                                   Added includes.
*                                                   Added comments.
*                                                   Added function prototypes.
* Leonardo Fusser   March 22 2022       v1.0.1      Added macros.
*                                                   Added comments. 
* Leonardo Fusser   April 10 2022       v1.0.2      Completed header file.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef VTASKTECHNICIAN_H
#define VTASKTECHNICIAN_H

/* Includes. */
#include "public.h"

/* Function prototypes. */
static void vTaskTechnician( void *pvParameters );
void vInit_vTaskTechnician(void);
void vInit_StartTechnician(void);
void vInitQueue_TaskTechnician(void);
void vSendQueue_TaskTechnician(char temp_data);

#endif
