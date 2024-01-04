/**************************************************************************************************
* FileName: main.c
*
* Name: Leonardo Fusser (1946995)       Lab 3       Vending Machine
*                                       Lab 4       Vending Machine II
*
* Description: This code provides the main interface for the functionality of Lab3 and Lab4. Here, 
*              depending on which pair of task priorities is set in the public.h file, the appropriate
*              initialization functions and tasks are called and executed. The RTOS scheduler
*              handles all the possible tasks that could be running at any moment in time.
*              Macro definitions can be found in the public.h file.
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould       ?                   v1.0.0      First version of source file.
* Leonardo Fusser   17 February 2022    v1.0.1      Added vInit_TaskUI() call.
*                                                   Populated vApplicationIdleHook() function.
*                                                   Implemented macros. 
*                                                   Added comments.
*                                                   Added #ifdef statements.
* Leonardo Fusser   24 February 2022    v1.0.2      Added vInit_vDatabase() call.
* Leonardo Fusser   22 March 2022       v1.0.3      Minor changes.
* Leonardo Fusser   10 April 2022       v2.0.0      Added more hardware init functions.
*                                                   Added more task init functions.
*                                                   Added comments.
*                                                   Completed source file. 
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include "include/public.h"


/* RTOS function prototypes (must be implemented in this file). */
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );
void vApplicationIdleHook( void );


/**********************************************************************************************
* Name: int main(void) 
* Description: Lab3 and Lab4 RTOS main function/thread. Includes all init function calls. 
*              Macro constants can be found in public.h file.
* 
***********************************************************************************************/
int main( void )
{
    /* Prepares the hardware *//////////
	prvSetupHardware();
    
    #ifndef SIMULATION
        initIO();
        LCDInit();
        initUart2_wInt();
        initADC();
    
    #else    
        initUart1();
        initUart2_wInt();
    
    #endif
    ////////////////////////////////////
        
    /* Tests UARTs. *//////////////////////////////////////////////
    #ifdef SIMULATION    
        fprintf2(CONSOLE_1, "TESTING UART1! TESTING 1, 2, 3...\n");
        fprintf2(CONSOLE_2, "TESTING UART2! TESTING 1, 2, 3...\n");
    
    #endif
    ///////////////////////////////////////////////////////////////
        
    /* Init RTOS tasks. */
    vInit_vDatabase();
    vInit_vTaskUI();
    vInit_vTaskTechnician();
    vInit_vTaskTemperature();
        
    /* Init RTOS scheduler. */
    vTaskStartScheduler();
	
    return 0;
}


/**********************************************************************************************
* Name: void vApplicationIdleHook(void) 
* Description: Lab3 and Lab4 RTOS idle hook function. Includes all idle related tasks.
*              Macro constants can be found in public.h file.
* 
***********************************************************************************************/
void vApplicationIdleHook( void ){
    
    int skip_count = 0;                             //Skip counter variable.
    
    while(1){
        
        skip_count = skip_count + 1;                //Increase skip count.
        
        if(skip_count == DELAY_Idle){
            #ifdef SIMULATION                       //If MPLAB X IDE simulator is selected...
                fprintf2(CONSOLE_2, "IdleHook\n");  //Prints idle message.
                skip_count = 0;                     //Resets skip count to 0.

            #else                                   //Else, Explorer 16/32 board selected...
                LED_IDLE ^= 1;                      //Toggles an LED.
                skip_count = 0;                     //Resets skip count to 0.
                
            #endif
        }

    }
}


/**********************************************************************************************
* Name: void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName) 
* Description: Lab3 and Lab4 RTOS overflow handler. Any critical errors will result in the 
*              system running from inside this function. 
* 
***********************************************************************************************/
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
    pxTask= pxTask;
    pcTaskName = pcTaskName;
		for( ;; );
}
