/**************************************************************************************************
* FileName: application.c
*
* Name: Leonardo Fusser (1946995)       Lab 5       SPI communication 
*
* Description: Application-Task layer for Lab5. Includes all application/task like functions below.
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   11 December 2021    v1.0.0      First version of source file.
*                                                   Completed source file.
*                                                   Added comments.  
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#include "application.h"

/**********************************************************************************************
* Name: void RectangleLineTASK(void) 
* Description: Application-Task layer function to draw a rectangle and line on PMOD OLED display.
*              Macros can be found in application.h file. 
* 
***********************************************************************************************/
void RectangleLineTASK(void){
    
    static int32_t lastTick;    //Timestamp variable.
    
    /*Draws a rectangle and line on OLED display by invoking driver layer*/
    if(SAMPLING_TIME){  //If reached sampling time...
        
        /*Draws line on OLED display*/
        oled_drw_line(Line_X1, Line_Y1, 
                      Line_X2, Line_Y2, 
                      Line_R, Line_G, Line_B);

        /*Draws rectangle on OLED display*/
        oled_drw_rect(Rectangle_X1, Rectangle_Y1, 
                      Rectangle_X2, Rectangle_Y2, 
                      Rectangle_R, Rectangle_G, Rectangle_B);
                    
        lastTick = TickGet();   //Timestamp.
    
    }
    
}
