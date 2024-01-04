/**************************************************************************************************
* FileName: vtask1.c
*
* Name: Leonardo Fusser (1946995)       Lab 1       Intro to RTOS
*
* Description: Task1 source file for Lab1. Task1 function can be found here. Macros used here can
*              be found in the vtask1.h or public.h file. Task1 function either toggles an LED or
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
#include "./include/vtask1.h"


/**********************************************************************************************
* Name: static void vTask1(void *pvParameters) 
* Description: Private static function declaration for Lab1 RTOS task 1. 
*              Macro constants can be found in public.h file or vtask1.h file.
* 
***********************************************************************************************/
static void vTask1( void *pvParameters ){
    
    pvParameters = pvParameters ;   // This is to get rid of annoying warnings.
	    
    /* Mini infinite loop. */
    while(1){
        
        #ifndef SIMULATION                              //If Explorer 16/32 board selected...
           LED_T1^=1;                                   //Toggles LED on Explorer 16/32 board.
        
        #else                                           //Else, MPLAB X IDE simulator is selected...
           fprintf2(CONSOLE_1, "Hello from TASK1!\n");  //Prints from inside Task 1.
           
        #endif
           
        /*Delay for a user-specified period.*/
        vTaskDelay(DELAY_T1/portTICK_RATE_MS);
    }
}


/**********************************************************************************************
* Name: void vStartTask1(void) 
* Description: Public function declaration for Lab1 RTOS task 1 initialization. 
*              Macro constants can be found in public.h file or vtask1.h file.
* 
***********************************************************************************************/
/* Public function declarations. */
void vStartTask1(void){
     xTaskCreate(	vTask1,						/* Pointer to the function that implements the task. */
					( char * ) "Task 1",        /* Text name for the task.  This is to facilitate debugging only. */
					240,						/* Stack depth in words. */
					NULL,						/* We are not using the task parameter. */
					PRIORITY_T1,    			/* This task will run at priority 1. */
					NULL );						/* We are not using the task handle. */
}
