/**************************************************************************************************
* FileName: main.c
*
* Name: Leonardo Fusser (1946995)       Lab 1       Intro to RTOS
*                                       Lab 2       Intro to queues and mutexes
*
* Description: This code provides the main interface for the functionality of Lab1 and Lab2. Here, 
*              depending on which pair of task priorities is set in the public.h file, the appropriate
*              initialization functions and tasks are called and executed. The RTOS scheduler
*              handles all the possible tasks that could be running at any moment in time.
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould       ?                   v1.0.0      First version of source file.
* Leonardo Fusser   20 January 2022     v1.0.1      Completed source file (for Lab1).
*                                                   Completed main function.
*                                                   Added comments.
*                                                   Used macros for portability.
* Leonardo Fusser   22 January 2022     v1.0.2      Minor change.
* Leonardo Fusser   27 January 2022     v2.0.0      Beginning of Lab 2.
*                                                   Implemented #ifdef declarations.     
*                                                   Implemented queue initialization.
*                                                   Implemented idle hook function.
* Leonardo Fusser   15 February 2022    v2.0.1      Used macros for portability.
*                                                   Added comments.
*                                                   Completed main function.
*                                                   Completed idle hook.
*                                                   Completed source file (for Lab2).
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include "include/public.h"


/* RTOS function declarations (must be implemented in this file. */
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );
void vApplicationIdleHook( void );


/**********************************************************************************************
* Name: int main(void) 
* Description: Lab1 and Lab2 RTOS main function/thread. Includes all init function calls. 
*              Macro constants can be found in public.h file.
* 
***********************************************************************************************/
int main( void ){
    
    /* Init hardware. */
	prvSetupHardware();

    #ifndef SIMULATION      //If Explorer 16/32 board selected...
        initIO();           //Initializes PIC32 GPIO.
        initUart2();        //Initializes UART2 hardware on PIC32.
                
    #else                   //Else, MPLAB X IDE simulator is selected...
        initUart1();        //Initializes MPLAB X IDE simulator UART.
        initUart2_wInt();   //" ".
    
        /* Tests UART. */
        fprintf2(CONSOLE_1, "TESTING UART1! TESTING 1, 2, 3...\n");
        fprintf2(CONSOLE_2, "TESTING UART2! TESTING 1, 2, 3...\n");
        
    #endif
    
    #ifdef LAB1                 //If Lab1 selected...
        /* Init RTOS tasks. */
        vStartTask1();          //Init Task1.
        vStartTask2();          //Init Task2.

    #else                       //Else Lab2 selected...    
        /* Init RTOS tasks. */
        vInit_TaskA();          //Init TaskA.
        vInit_TaskB();          //Init TaskB.
        vInit_TaskC();          //Init TaskC.
        
    #endif
        
    /* Init RTOS scheduler. */
    vTaskStartScheduler();
	
    return 0;
}


/**********************************************************************************************
* Name: void vApplicationIdleHook(void) 
* Description: Lab1 and Lab2 RTOS idle function. Includes all idle tasks.
*              Macro constants can be found in public.h file.
* 
***********************************************************************************************/
void vApplicationIdleHook( void ){
    
    int skip_count = 0;                                 //Skip counter variable.
    
    while(1){
        
        #ifndef LAB1                                    //If Lab2 selected...
        
            skip_count = skip_count + 1;                //Increase count.
        
            if(skip_count == DELAY_Idle){
                #ifdef SIMULATION                       //If MPLAB X IDE simulator is selected...
                    fprintf2(CONSOLE_2, "IdleHook\n");  //Prints idle message.
                    skip_count = 0;                     //Reset count to 0.

                #else                                   //Else, Explorer 16/32 board selected...
                    LED_IDLE ^= 1;                      //Toggles an LED.
                    skip_count = 0;                     //Resets count to 0.
                
                #endif
            }
            
        #endif

        //Else, nothing happening here...
        
    }
}


/**********************************************************************************************
* Name: void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName) 
* Description: Lab1 RTOS overflow handler. Any critical errors will result in the system running
*              from inside this function.
*              Macro constants can be found in public.h file. 
* 
***********************************************************************************************/
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName ){
    pxTask = pxTask;
    pcTaskName = pcTaskName;
		for( ;; );
}
