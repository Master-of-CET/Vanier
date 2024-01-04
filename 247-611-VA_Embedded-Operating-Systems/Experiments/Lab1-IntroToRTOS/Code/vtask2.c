/**************************************************************************************************
* FileName: vtask2.c
*
* Name: Leonardo Fusser (1946995)       Lab 1       Intro to RTOS
*
* Description: Task2 source file for Lab1. Task1 function can be found here. Macros used here can
*              be found in the vtask2.h or public.h file. Task1 function either toggles an LED or
*              prints a message for a certain amount of time depending on what the user has set in
*              the public.h file.  
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould       ?                   v1.0.0      First version of source file.
* Leonardo Fusser   20 January 2022     v1.0.1      Completed source file.
*                                                   Completed task function.
*                                                   Added comments.
*                                                   Used macros for portability.
* Leonardo Fusser   22 January 2022     v1.0.2      Minor change.
* Leonardo Fusser   27 January 2022     v2.0.0      Beginning of Lab 2.
*                                                   Changed some #ifdef declarations.
*                                                   Changed some macros.       
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include "./include/vtask2.h"


/**********************************************************************************************
* Name: static void vTask2(void *pvParameters) 
* Description: Private static function declaration for Lab1 RTOS task 2. 
*              Macro constants can be found in public.h file or vtask2.h file.
* 
***********************************************************************************************/
static void vTask2( void *pvParameters ){
    
    volatile unsigned long i;       //Loop variable.
    pvParameters = pvParameters ;   //This is to get rid of annoying warnings.

    /* Mini infinite loop. */
    while(1){
        
        #ifndef SIMULATION                              //If Explorer 16/32 board selected...
           LED_T2^=1;                                   //Toggles LED on Explorer 16/32 board.
        
        #else                                           //Else, MPLAB X IDE simulator is selected...
           fprintf2(CONSOLE_1, "Hello from TASK2!\n");  //Prints from inside Task 1.
           
        #endif
                
        /* Crude NULL loop delay for a user-specified period. */
        for(i = 0; i < DELAY_T2; i++);
    }
}


/**********************************************************************************************
* Name: void vStartTask2(void) 
* Description: Public function declaration for Lab1 RTOS task 2 initialization. 
*              Macro constants can be found in public.h file or vtask2.h file.
* 
***********************************************************************************************/
void vStartTask2(void){
    xTaskCreate( vTask2, ( char * ) "Task 2", 240, NULL, PRIORITY_T2, NULL );   //Creates task with user-set priority.
}
