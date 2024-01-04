/**************************************************************************************************
* FileName: taskC.c
*
* Name: Leonardo Fusser (1946995)       Lab 2       Intro to queues and mutexes
*
* Description: taskC source file for Lab2. This code, through a thread routine, changes the delay
*              in TaskB depending on what pushbuttons are pressed on the Explorer 16/32 board.
*              Macro constants can be found in public.h file or taskC.h file.    
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   10 February 2022    v1.0.0      First version of source file.
*                                                   Created second task and task init.
*                                                   Partially filled newly created task.
* Leonardo Fusser   15 February 2022    v1.0.1      Added comments.
*                                                   Completed source file.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include "./include/taskC.h"


/* Private mutex semaphore declaration. */
static SemaphoreHandle_t xMutex_TaskC = NULL;

/* Global variable. */
static int Delay_TaskB;


/**********************************************************************************************
* Name: static void taskC(void *pvParameters) 
* Description: Private static function declaration for Lab2 RTOS task C. 
*              Macro constants can be found in public.h file or taskC.h file.
* 
***********************************************************************************************/
static void taskC( void *pvParameters ){
    
    pvParameters = pvParameters;                //This is to get rid of annoying warnings.
    
    /* Mini infinite loop. */
    while(1){
        
        if(!S3){                                //If S3 pushbutton is pressed...
            taskC_setDelay(DELAY_200mS);        //Calls a setter to change TaskB delay to 200mS.
        }
        if(!S6){                                //If S6 pushbutton is pressed...
            taskC_setDelay(DELAY_400mS);        //Calls a setter to change TaskB delay to 400mS.
        }
        if(!S4){                                //If S4 pushbutton is pressed...
            taskC_setDelay(DELAY_0mS);          //Calls a setter to change TaskB delay to 0mS.
        }

        /*Delay for a user-specified period.*/
        vTaskDelay(DELAY_10mS/portTICK_RATE_MS);    //Small blocking delay.
    }
}


/**********************************************************************************************
* Name: void vInit_TaskC(void) 
* Description: Public function definition for Lab2 RTOS TaskC. This function calls a initializing
*              function and a mutex initialization function for TaskC.
* 
***********************************************************************************************/
void vInit_TaskC(void){
    vInitSemaphore_TaskC(); //Calls mutex init function for TaskC.
    vInitStart_TaskC();     //Calls init function for TaskC.
}


/**********************************************************************************************
* Name: void vInitStart_TaskC(void) 
* Description: Public function definition for Lab2 RTOS TaskC. This function creates TaskC.
*              Macro constants can be found in public.h file or taskC.h file. 
* 
***********************************************************************************************/
void vInitStart_TaskC(void){
    /* Creates task with user-set priority. */
    xTaskCreate( taskC, ( char * ) "Task C", 240, NULL, PRIORITY_TaskC, NULL ); //Creates TaskC.
}


/**********************************************************************************************
* Name: void vInitSemaphore_TaskC(void) 
* Description: Public function definition for Lab2 RTOS TaskC. This function initializes a mutex
*              semaphore for TaskC. 
* 
***********************************************************************************************/
void vInitSemaphore_TaskC(void){
    /* Creates mutex semaphore. */
    xMutex_TaskC = xSemaphoreCreateMutex(); //Creates mutex semaphore.
}


/**********************************************************************************************
* Name: void taskC_setDelay(int temp_set) 
* Description: Public function definition for Lab2 RTOS TaskC. This function acts as a setter
*              between TaskC and TaskB to change a common variable. 
* 
***********************************************************************************************/
void taskC_setDelay(int temp_set){
    xSemaphoreTake(xMutex_TaskC, portMAX_DELAY);    //Locks.
    Delay_TaskB = temp_set;                         //Updates "Delay_TaskB".
    xSemaphoreGive(xMutex_TaskC);                   //Unlocks.
}


/**********************************************************************************************
* Name: int taskC_getDelay(void) 
* Description: Public function definition for Lab2 RTOS TaskC. This function acts as a getter
*              between TaskC and TaskB to retrieve a common variable.
* 
***********************************************************************************************/
int taskC_getDelay(void){
    int temp_get;                                   //Temp getter variable.
    xSemaphoreTake(xMutex_TaskC, portMAX_DELAY);    //Locks.
    temp_get = Delay_TaskB;                         //Retrieves "Delay_TaskB".
    xSemaphoreGive(xMutex_TaskC);                   //Unlocks.
    return temp_get;                                //Returns value of "Delay_TaskB".
}
