/**************************************************************************************************
* FileName: taskA.c
*
* Name: Leonardo Fusser (1946995)       Lab 2       Intro to queues and mutexes
*
* Description: taskA source file for Lab2. This code, through a thread routine, sends a burst of five
*              random capital letters to another task using a queue. Macro constants can be found 
*              in public.h file or taskA.h file.
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   27 January 2022     v1.0.0      First version of source file.
*                                                   Created first task and task init.
*                                                   Partially filled newly created task.
*                                                   Added macros and #ifdef for portability.
* Leonardo Fusser   15 February 2022    v1.0.1      Added comments.
*                                                   Completed source file.  
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include "./include/taskA.h"


/**********************************************************************************************
* Name: static void taskA(void *pvParameters) 
* Description: Private static function definition for Lab2 RTOS TaskA. This task sends bursts
*              of data to another task using a queue.
*              Macro constants can be found in public.h file or taskA.h file.
* 
***********************************************************************************************/
static void taskA( void *pvParameters ){
    
    pvParameters = pvParameters ;   //This is to get rid of annoying warnings.
    char taskA_tx[QUEUE_DEPTH];     //Array to store randomly generated characters (for debugging).
	    
    /* Mini infinite loop. */
    while(1){
                  
        /* Loop that generates 5 random capital letters. */
        for(int i = 0; i < 5; i++){
            taskA_tx[i] = (90 - (rand() % 26)); //Generates a capital letter.
            vSendQueue_TaskB(taskA_tx[i]);      //Sends generated capital letter to a queue.
        }
           
        /* Delay for a user-specified period. */
        vTaskDelay(DELAY_TaskA/portTICK_RATE_MS);
    }
}


/**********************************************************************************************
* Name: void vInit_TaskA(void) 
* Description: Public function definition for Lab2 RTOS TaskA. This function calls a initializing
*              function for TaskA. 
* 
***********************************************************************************************/
void vInit_TaskA(void){
    vInit_StartTaskA(); //Calls init function for TaskA.
}


/**********************************************************************************************
* Name: void vInit_StartTaskA(void) 
* Description: Public function definition for Lab2 RTOS TaskA. This function creates TaskA.
*              Macro constants can be found in public.h file or taskA.h file. 
* 
***********************************************************************************************/
void vInit_StartTaskA(void){
    /* Creates task with user-set priority. */
    xTaskCreate( taskA, ( char * ) "Task A", 240, NULL, PRIORITY_TaskA, NULL ); //Creates TaskA.
}
