/**************************************************************************************************
* FileName: application.h
*
* Name: Leonardo Fusser (1946995)       Lab 5       SPI communication 
*
* Description: Incudes all macros and dependencies needed for application.c source file.
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   11 December 2021    v1.0.0      First version of header file.
*                                                   Completed header file.
*                                                   Added comments. 
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef APPLICATION_H
#define APPLICATION_H

/*All dependencies required included below*/
#include "public.h"
#include "oled.h"


/*Macros for drawing line on OLED display*/
#define Line_X1     20          //Start column address for drawing line.
#define Line_Y1     20          //Start row address for drawing line.
#define Line_X2     70          //End column address for drawing line.
#define Line_Y2     30          //End row address for drawing line.
#define Line_R      0           //R color for line.
#define Line_G      0           //G color for line.
#define Line_B      255         //B color for line.

/*Macros for drawing rectangle on OLED display*/
#define Rectangle_X1    10      //Start column address for drawing rectangle.
#define Rectangle_Y1    10      //Start row address for drawing rectangle.
#define Rectangle_X2    80      //End column address for drawing rectangle.
#define Rectangle_Y2    40      //End row address for drawing rectangle.
#define Rectangle_R     255     //R color for rectangle.
#define Rectangle_G     0       //G color for rectangle.
#define Rectangle_B     0       //B color for rectangle.


/*Function prototypes*/
void RectangleLineTASK(void);

#endif
