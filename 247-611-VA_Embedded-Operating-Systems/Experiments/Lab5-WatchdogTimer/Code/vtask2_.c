/*****************************************************************************
 * File: vTask2.c
 * Description: the following RTOS task runs forever and does not give slack
 *              time to the system.
 *              Running this task will not allow the idle hook function to run
 *              and will force the WDT to reset the system.
 * 
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author        	Date      		Version     Comments on this revision
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * SH               ?               1.0         First version of source file.
 * Leonardo F.      April 14 2022   1.1         Minor changes.
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
static void vTask2( void *pvParameters ){

   pvParameters = pvParameters; //This is to get rid of annoying warnings.
   
   for( ;; ){   
       //Hogs the system CPU...
   }//End of for(;;).
   
}//End of vTask2().


/* Public function declaration. */
void vStartTask2(void){
    xTaskCreate( vTask2, ( char * ) "Task 2", 240, NULL, 1, NULL );
}//End of vStartTask2().
