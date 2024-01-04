/**************************************************************************************************
* FileName: oled.h
*
* Name: Leonardo Fusser (1946995)       Lab 5       SPI communication 
*
* Description: Incudes all macros and dependencies needed for oled.c source file.
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   7 December 2021     v1.0.0      First version of header file.
* Leonardo Fusser   11 December 2021    v1.0.1      Cleaned up header file.
*                                                   Completed header file.
*                                                   Added comments.     
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef OLED_H
#define OLED_H

/*All dependencies required included below*/
#include "public.h"
#include "spi.h"

/*Function prototypes*/
void oled_clr(void);
void oled_drw_line(int x1, int y1, int x2, int y2, int red, int green, int blue);
void oled_drw_rect(int x1, int y1, int x2, int y2, int red, int green, int blue);

#endif
