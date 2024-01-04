/**************************************************************************************************
* FileName: main.c
*
* Name: Leonardo Fusser (1946995)       Lab 2       Cooperative multitasking using FSM
*       Collins Agyeman-Duah (1554428)
*
* Description: This lab consists of a typical cooperative multitasking construct. A digital potentiometer
*              increases or decreases a count on the Explorer 16/32 LCD and a serial output prints
*              the value of the count to a terminal emulator. A queue is implemented in order for full
*              range of the count to be displayed in the terminal emulator. The digital potentiometer also
*              decodes a pair of LEDs that are on the Explorer 16/32 board.    
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould       15 September 2021   v1.0.0      First version of source file.
* Leonardo Fusser   26 September 2021   v1.0.1      Minor changes.
* Leonardo Fusser   28 September 2021   v1.0.2      Github push test.
* Leonardo Fusser   2 October    2021   v1.0.3      Added SIMULATION_SIMPLE_RS232 option.
*                                                   Added comments. 
* Collins Agyeman   21 September 2021   v1.0.4      Edited for encoder task.
* Collins Agyeman   28 September  2021  v1.0.5      Added includes, UART1 char buffer & inits, 
*                                                   Encoder task call.
* Leonardo Fusser   2 November   2021   v1.0.6      Applied ifdef function blocks and cleaned up code. 
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#include "public.h"

/**********************************************************************************************
* Name: int main(void) 
* Description: Main function for Lab2.
*              Calls all initializing functions. 
*              Constantly runs all tasks.
* 
***********************************************************************************************/
int main(void){
    
    initIO();           //Initializes PIC32 I/O.
    
    #ifdef    SIMULATION    //If MPLAB X IDE simulator selected... 
        initUart1();        //Initializes UART1 for console in simulation mode.
    
    #else                   //Otherwise, Explorer 16/32 board selected...
        initLCD();          //Initializes LCD for console in target mode.
    
    #endif
    
    initEncoderTask();  //Calls init task.
    
    while(1){
        
        #ifdef  SIMULATION_SIMPLE_RS232     //If simple RS232 simulation is selected...
            SimpleSoftComTask();            //Calls task. 
            
        #else                           //Otherwise, constantly run all the tasks below...
            encoderTask();              //Calls task.
            //idleTask();               //Calls task.
            SoftComTask();              //Calls task.              

        #endif
    }
}
