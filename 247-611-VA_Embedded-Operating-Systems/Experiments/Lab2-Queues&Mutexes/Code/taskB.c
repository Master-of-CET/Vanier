/**************************************************************************************************
* FileName: taskB.c
*
* Name: Leonardo Fusser (1946995)       Lab 2       Intro to queues and mutexes
*
* Description: taskB source file for Lab2. This code, through a thread routine, receives bursts of
*              data from another task using a queue, and displays the received data on a console.
*              The received data is a burst of 5 randomly generated capital letters. Macro constants
*              can be found in public.h file or taskB.h file.  
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   27 January 2022     v1.0.0      First version of source file.
*                                                   Created second task and task init.
*                                                   Partially filled newly created task.
* Leonardo Fusser   15 February 2022    v1.0.1      Added comments.
*                                                   Completed source file.
* Leonardo Fusser   16 February 2022    v1.0.2      Minor change.   
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include "./include/taskB.h"


/* Private queue declaration. */
static QueueHandle_t xQueue_TaskB = NULL;


/**********************************************************************************************
* Name: static void taskB(void *pvParameters) 
* Description: Private static function declaration for Lab2 RTOS TaskB. This task receives data
*              from another task using a queue and displays it onto a console.  
*              Macro constants can be found in public.h file or taskB.h file.
* 
***********************************************************************************************/
static void taskB( void *pvParameters ){
    
    pvParameters = pvParameters ;   //This is to get rid of annoying warnings.
    char taskB_rx;                  //Receiving queue data variable.
    char temp_buffer[QUEUE_DEPTH];  //Printing buffer.
    int i = 0;                      //Count variable.
    
    /* Mini infinite loop. */
    while(1){               
        if(i < 5){                                                  //If 5 random capital letters haven't been received...
            xQueueReceive(xQueue_TaskB, &taskB_rx, portMAX_DELAY);  //Receives data from queue.
            sprintf(temp_buffer, "%c ", taskB_rx);                  //Prints received data to buffer.
            fprintf2(CONSOLE_1, temp_buffer);                       //Prints buffer onto console.
            i++;                                                    //Increase count.
        }
        else{                                                       //Else, all 5 random capital letters have been received...
            sprintf(temp_buffer, "\r\n");                           //Prints newline and terminal emulator keywords to buffer.
            fprintf2(CONSOLE_1, temp_buffer);                       //Prints buffer onto console.
            i = 0;                                                  //Resets count.
        }
        
        /*Delay for a user-specified period.*/
        vTaskDelay(taskC_getDelay()/portTICK_RATE_MS);              //TaskB blocks depending on which pushbutton is pressed.
    }
}


/**********************************************************************************************
* Name: void vInit_TaskB(void) 
* Description: Public function definition for Lab2 RTOS TaskB. This function calls a initializing
*              function and a queue initialization function for TaskB.
* 
***********************************************************************************************/
void vInit_TaskB(void){
    vInitQueue_TaskB(); //Calls queue init function for TaskB.
    vInitStart_TaskB(); //Calls init function for TaskB.
}


/**********************************************************************************************
* Name: void vInitStart_TaskB(void) 
* Description: Public function definition for Lab2 RTOS TaskB. This function creates TaskB.
*              Macro constants can be found in public.h file or taskB.h file. 
* 
***********************************************************************************************/
void vInitStart_TaskB(void){
    /* Creates task with user-set priority. */
    xTaskCreate( taskB, ( char * ) "Task B", 240, NULL, PRIORITY_TaskB, NULL ); //Creates TaskB.
}


/**********************************************************************************************
* Name: void vInitQueue_TaskB(void) 
* Description:  Public function definition for Lab2 RTOS TaskB. This function initializes a queue
*               for TaskB.
*               Macro constants can be found in public.h file or taskB.h file.
* 
***********************************************************************************************/
void vInitQueue_TaskB(void){
    xQueue_TaskB = xQueueCreate( QUEUE_DEPTH, sizeof( char ) );
}


/**********************************************************************************************
* Name: void vSendQueue_TaskB(void) 
* Description: Public function definition for Lab2 RTOS TaskB. This function allows other tasks
*              to send data to TaskB through using a queue.
* 
***********************************************************************************************/
void vSendQueue_TaskB(char temp_data){
    xQueueSend(xQueue_TaskB, &temp_data, 0);
}
