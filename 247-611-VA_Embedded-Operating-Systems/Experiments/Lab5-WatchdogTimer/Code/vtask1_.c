/* ***************************************************************************
 * File: vTask1.c
 * Description: the following RTOS task runs forever and does two things. It
 *              increments a count to be shown on a console and a LED toggles.
 *              Running this task will allow the idle hook function to run
 *              and will not force the WDT to reset the system.
 * 
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author        	Date      		Version     Comments on this revision
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * SH               ?               1.0         First version of source file.
 * Leonardo F.      April 14 2022   1.1         Partially populated file.
 *                                              Added comments.
 * Leonardo F.      April 16 2022   1.2         Completed file.
 *                                              Added comments.
 * 
 *****************************************************************************/


/* Peripheral library include. */
#include <string.h>
#include <stdio.h>
/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "public.h"
#include "console.h"


/* Private static function declaration. */
static void vTask1( void *pvParameters ){
    
    pvParameters = pvParameters ;   //This is to get rid of annoying warnings.

    char PrintBuff[20];             //Temp buffer.
    int UpCnt = 0;                  //Counter variable.
    
	for( ;; ){   
        
        UpCnt += 1; //Increment count by 1.
        
        sprintf(PrintBuff, "\nvTask1 cnt: %d        \n", UpCnt);    //Prints count.
        mutex_print(PrintBuff);                                     //" ".
        
        vTASK1_LED ^= 1;                                            //Toggles an LED.
        
        vTaskDelay(100 / portTICK_RATE_MS);                         //Gives slack time (100mS blocking delay).
        
    }//End of for(;;).
    
}//End of vTask1().


/* Public function declaration. */
void vStartTask1(void){
     xTaskCreate(	vTask1,					/* Pointer to the function that implements the task. */
					( char * ) "Task 1",	/* Text name for the task.  This is to facilitate debugging only. */
					240,					/* Stack depth in words. */
					NULL,					/* We are not using the task parameter. */
					1,						/* This task will run at priority 1. */
					NULL );					/* We are not using the task handle. */
}//End of vStartTask1().
