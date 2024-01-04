/**************************************************************************************************
* FileName: spi.c
*
* Name: Leonardo Fusser (1946995)       Lab 5       SPI communication 
*
* Description: HAL layer for Lab5. Includes all HAL like functions below.
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   30 November 2021    v1.0.0      First version of source file.
* Leonardo Fusser   7 December 2021     v1.0.1      Cleaned up source file.
* Leonardo Fusser   11 December 2021    v1.0.2      Added WriteSPI2 function.
*                                                   Cleaned up source file 
*                                                   Completed source file.
*                                                   Added comments.   
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#include "spi.h"

/**********************************************************************************************
* Name: void spi_init(int baud, int cpol, int cpha) 
* Description: HAL layer function to init SPI2 module on PIC32.
*              Macro constants can be found in spi.h file. 
* 
***********************************************************************************************/
void spi_init(int baud, int cpol, int cpha){
    
    SPI2BRG = (SYS_FREQ/(2*baud)) - 1;  //Sets SPI2 baud rate.
    
    SPI2CONbits.ON = 0;      //Turn off SPI2.
    SPI2CONbits.CKP = cpol;  //Sets SPI2 select clock polarity.
    SPI2CONbits.CKE = ~cpha; //Sets SPI2 select clock edge.
    SPI2CONbits.SMP = 0;     //SPI2 samples input data in middle of output data.
    SPI2CONbits.SSEN = 0;    //SPI2 SS pin not used.
    SPI2CONbits.MSTEN = 1;   //Sets SPI2 as master.
    SPI2CONbits.MODE16 = 0;  //Sets SPI2 for 8-bit communication.
    SPI2CONbits.MODE32 = 0;  //" ".
    SPI2CONbits.ON = 1;      //Turn on SPI2.
    
}

/**********************************************************************************************
* Name: int spi_ld_buffer(int load) 
* Description: HAL layer function to test SPI2 module on PIC32 for Part1.
*              Macro constants can be found in spi.h file. 
* 
***********************************************************************************************/
int spi_ld_buffer(int load){
    
    SS = 0;                         //Wakes up SPI slave.
    
    SPI2BUF = load;                 //Loads a byte into SPI2 buffer.
    while(!SPI2STATbits.SPIRBF);    //Waits for transmission to complete.
    return SPI2BUF;                 //Returns value that was received in SPI2 buffer and clears flag.
    
    SS = 1;                         //Puts SPI slave to sleep.
    
}

/**********************************************************************************************
* Name: void WriteSPI2(int load) 
* Description: HAL layer function to write data from SPI2 module (master) to SPI slave connected
*              to Explorer 16/32 board.
*              Macro constants can be found in spi.h file. 
* 
***********************************************************************************************/
void WriteSPI2(int load){
    
    static int dummy;               //Garbage variable.
    
    SS = 0;                         //Wakes up SPI slave.
    DC = 0;                         //Tells DS3234 to get ready to write some data.
    
    SPI2BUF = load;                 //Writes data to DS3234.
    while(!SPI2STATbits.SPIRBF);    //Waits for SPI transmission to complete.
    dummy = SPI2BUF;                //Clears SPIRBF flag by reading garbage.
    
    DC = 1;                         //Tells DS3234 to not write any data.
    SS = 1;                         //Puts SPI slave to sleep.
    
}
