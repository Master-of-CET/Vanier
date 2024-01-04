/**************************************************************************************************
* FileName: vTaskTemperature.h
*
* Name: Leonardo Fusser (1946995)       Lab 4       Vending Machine
*
* Description: Header file for vTaskTemperature.c source file. Macro definitions and function 
*              prototypes for the corresponding source file can be found here. Other macro constants 
*              can be found in public.h file.
*  
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   March 10 2022       v1.0.0      First version of header file.
*                                                   Added includes.
*                                                   Added comments.
* Leonardo Fusser   March 22 2022       v1.0.1      ...
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef VTASKTEMPERATURE_H
#define VTASKTEMPERATURE_H

/* Includes. */
#include "public.h"

/* Function prototypes. */
static void vTaskTemperature( void *pvParameters );
void vInit_vTaskTemperature(void);
void vInit_StartTemperature(void);

#endif
