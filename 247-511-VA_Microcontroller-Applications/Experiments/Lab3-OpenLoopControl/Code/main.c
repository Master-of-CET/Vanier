/**************************************************************************************************
* FileName: main.c
*
* Name: Leonardo Fusser (1946995)       Lab 3       Servomotor - open loop control
*
* Description: This code provides the main interface for the functionality of Lab3. Here, depending
*              on what mode is set in the configuration.h file (simulation or target), the appropriate
*              initialization functions and tasks are called and executed from this file.      
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould       ?                   v1.0.0      First version of source file.
* Leonardo Fusser   29 October 2021     v1.0.1      Minor changes.
* Leonardo Fusser   14 November 2021    v1.0.2      Completed main.c file.
*                                                   Added comments and description header. 
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#include "configuration.h"
#include "ol_control.h"

/**********************************************************************************************
* Name: int main(void) 
* Description: Main function for Lab3.
*              Calls all initializing functions. 
*              Constantly runs all tasks.
* 
***********************************************************************************************/
int main(void){
    
    /*init IOs*/
    initIO();                       //Calls this task always regardless of which mode is set (simulation or target).
    
    
    #ifndef SIMULATION              //If target mode is desired...
        /*init position measure*/
        initPV_measure();           //Call this task.
        
        /*init LCD*/
        LCDInit();                  //" ".
    
        /*ADC init*/
        initADC();                  //" ".
 
        /*init PWM*/
        initPWM();                  //" ".
        
    #else                           //Otherwise, when simulation mode is desired...
        /*init UARTs*/
        initUart1();                //Call this task.
        initUart2();                //" ".
    
        /*Test UARTs*/
        fprintf2(C_UART1, "UART1 says: Board reset \n");
        fprintf2(C_UART2, "UART2 says: Board reset\n");
        
    #endif
    
    /*Super loop*/
	while (1){
        ol_control();   //Regardless of which mode is set (simulation or target), this task gets called and executed always.
    }   
}
