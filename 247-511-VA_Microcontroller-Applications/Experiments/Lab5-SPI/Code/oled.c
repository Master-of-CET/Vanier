/**************************************************************************************************
* FileName: oled.c
*
* Name: Leonardo Fusser (1946995)       Lab 5       SPI communication 
*
* Description: Driver layer for Lab5. Includes all driver like functions below.
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   7 December 2021     v1.0.0      First version of source file.
* Leonardo Fusser   11 December 2021    v1.0.1      Cleaned up source file.
*                                                   Completed source file.
*                                                   Added comments.    
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#include "oled.h"

/**********************************************************************************************
* Name: void oled_clr(void) 
* Description: Driver layer function to clear PMOD OLED display.
* 
***********************************************************************************************/
void oled_clr(void){
    
    /*Clears OLED display by invoking HAL layer*/
    WriteSPI2(0x25);    //Tells DS3234 to get ready to clear OLED display (address 25 in datasheet).
    WriteSPI2(0x00);    //Start column address for screen clearing.
    WriteSPI2(0x00);    //Start row address for screen clearing.
    WriteSPI2(95);      //End column address for screen clearing.
    WriteSPI2(63);      //End row address for screen clearing.
    
    delay_ms(1);        //Small delay for internal RAM clearing.
    
}

/**********************************************************************************************
* Name: void oled_drw_line(int x1, int y1, int x2, int y2, int red, int green, int blue) 
* Description: Driver layer function to draw a line on PMOD OLED display.
* 
***********************************************************************************************/
void oled_drw_line(int x1, int y1, int x2, int y2, int red, int green, int blue){
    
    /*Draws line on OLED display by invoking HAL layer*/
    WriteSPI2(0x21);    //Tells DS3234 to get ready to draw a line on OLED display (address 21 in datasheet).
    WriteSPI2(x1);      //Start column address for line.
    WriteSPI2(y1);      //Start row address for line.
    WriteSPI2(x2);      //End column address for line.
    WriteSPI2(y2);      //End row address for line.
    WriteSPI2(red);     //R color (C in DS3234 datasheet).
    WriteSPI2(green);   //G color (B in DS3234 datasheet).
    WriteSPI2(blue);    //B color (A in DS3234 datasheet).
    
}

/**********************************************************************************************
* Name: void oled_drw_rect(int x1, int y1, int x2, int y2, int red, int green, int blue) 
* Description: Driver layer function to draw a rectangle on PMOD OLED display.
* 
***********************************************************************************************/
void oled_drw_rect(int x1, int y1, int x2, int y2, int red, int green, int blue){
    
    /*Draws rectangle on OLED display by invoking HAL layer*/
    WriteSPI2(0x22);    //Tells DS3234 to get ready to draw a rectangle on OLED display (address 22 in datasheet).
    WriteSPI2(x1);      //Start column address for rectangle.
    WriteSPI2(y1);      //Start row address for rectangle.
    WriteSPI2(x2);      //End column address for rectangle.
    WriteSPI2(y2);      //End row address for rectangle.
    WriteSPI2(red);     //R color (C in DS3234 datasheet).
    WriteSPI2(green);   //G color (B in DS3234 datasheet).
    WriteSPI2(blue);    //B color (A in DS3234 datasheet).
    
}
