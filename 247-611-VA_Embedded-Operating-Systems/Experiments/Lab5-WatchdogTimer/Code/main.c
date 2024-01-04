/*****************************************************************************
 * Author       Date              Version     Comment
 * SH           April ?  2022     1.0         Watchdog timer template.
 * Leonardo F.  April 14 2022     1.1         Partially populated file.
 *                                            Added comments.
 * Leonardo F.  April 16 2022     1.2         Completed file.
 *                                            Added comments.
 * 
 *****************************************************************************/


/* Peripheral library include. */
#include <stdio.h>
/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h" 
#include "semphr.h"
#include "croutine.h"
#include "console.h"
#include "initBoard.h"
#include "public.h"


/* Prototypes for the standard FreeRTOS callback/hook functions implemented within this file. */
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );

/* Local semaphore declaration. */
static SemaphoreHandle_t xMutex_Print = NULL;

/* Persistent variables. */
int ResetCnt __attribute__((persistent));


int main( void ){
    
    int cnt = 10000;        //Count variable.
    char CharBuff[20];      //Temp buffer.
    
    /* Prepare the hardware. */
	INTCONbits.MVEC = 1;    //Enable multiVectoredInt.
    
    /* Init critical resources. */
    vInit_mutex();
    
    #ifndef SIMULATION      //If Explorer 16/32 board selected...
        initIOs();          //Init PIC32 IO.
        LCDInit();          //Init LCD.
    #else                   //Otherwise, MPLAB X IDE simulator selected...
        initUart1();        //Init UART1.
        initUart2();        //Init UART2.
    #endif
    
    while(cnt--);           //Fixes LCD printing issue.
    
    /* WDT task. */
    WDT_ENABLE = 1;         //Enable WDT.
    
    if(POR_FLAG || EXTR_FLAG){                   //If POR or EXTR...
        mutex_print("POR detected...        \n");   //Prints message.
        ResetCnt = 0;                               //Resets system reset count.
        POR_FLAG = 0;                               //Reset POR.
        EXTR_FLAG = 0;                              //Reset EXTR.
    }//End of if(POR_FLAG || EXTR_FLAG).
    else if(WDT_FLAG){                          //If WDT resets system...
        if(ResetCnt >= 6){                          //If more than 6 system resets have occurred.
            WDT_ENABLE = 0;                             //Disable WDT.
            mutex_print("Board frozen!        \n");     //Print message.
            HUNG_LED = 1;                               //Turns LED on.
            while(1){                                   
                //Force system to stay stuck here...
            }//End of while(1).
        }//End of if(ResetCnt >= 6).
        else{                                                   //Otherwise...
            WDT_FLAG = 0;                                            //Clears WDT.
            ResetCnt += 1;                                           //Increment system reset count by 1.
            sprintf(CharBuff, "Sys. reset #%d!        \n", ResetCnt);//Print message.
            mutex_print(CharBuff);                                   //" ".
            //mutex_print("Sys. reset!        \n");
        }//End of else().
    }//End of else if(WDT_FLAG).
    
    /* Creates RTOS tasks. */
    vStartTask1();  //Task that does not hog the system CPU.
    vStartTask2();  //Task that hogs the system CPU.
    
	/* Start the tasks and timer running. */
    vTaskStartScheduler();
	
	return 0;
    
}//End of main().


/* vApplicationIdleHook runs only when no task requires the CPU. */
void vApplicationIdleHook( void ){

    int skip_count = 0;                             //Skip count variable.
    
    while(1){
    
        WDT_KICK = 1;                               //Kicks the WDT.
        skip_count = skip_count + 1;                //Increase skip count.
        
        if(skip_count == 100000){
            #ifdef SIMULATION                       //If MPLAB X IDE simulator is selected...
                fprintf2(CONSOLE_2, "IdleHook\n");  //Prints idle message.
                skip_count = 0;                     //Resets skip count to 0.
            #else                                   //Else, Explorer 16/32 board selected...
                IDLE_LED ^= 1;                      //Toggles an LED.
                skip_count = 0;                     //Resets skip count to 0.
            #endif
        }//End of if(skip_count == 100000).
        
    }//End of while(1).
    
}//End of vApplicationIdleHook().


/* vApplicationStackOverflowHook. */
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName ){
    pxTask= pxTask;
    pcTaskName = pcTaskName;
		for( ;; );
}//End of vApplicationStackOverflowHook().


/* Initializes mutex semaphores. */
void vInit_mutex(void){
    xMutex_Print = xSemaphoreCreateMutex();
}//End of vInit_mutex().


/* Prints string onto mutex-protected console. */
void mutex_print(char* temp_str){
    xSemaphoreTake(xMutex_Print, portMAX_DELAY);    //Protects.
    fprintf2(CONSOLE_1, temp_str);                  //Prints.
    xSemaphoreGive(xMutex_Print);                   //Un-protects.
}//End of mutex_print().
