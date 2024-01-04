/**************************************************************************************************
* FileName: public.h
*
* Name: Leonardo Fusser (1946995)       Lab 1       Intro to RTOS
*                                       Lab 2       Intro to queues and mutexes 
*
* Description: Lab1 and 2 public.h header file. Here, the user can toggle between the MPLAB X IDE 
*              simulator (simulator mode) and the Explorer 16/32 board (target mode). The user can 
*              also change individual task priorities and delays. Depending if target mode or simulator 
*              mode is selected, other appropriate constants are automatically applied.
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould       ?                   v1.0.0      First version of header file.
* Leonardo Fusser   20 January 2022     v1.0.1      Completed header file.
*                                                   Added comments.
*                                                   Added macros for portability.
* Leonardo Fusser   22 January 2022     v1.0.2      Minor change.
* Leonardo Fusser   27 January 2022     v2.0.0      Beginning of Lab 2.
*                                                   Added macros for switching between Lab 1 & Lab 2.
*                                                   Added two newly created task files to includes.
*                                                   Added and changed some macros for user.
* Leonardo Fusser   February 15 2022    v2.0.1      Minor changes.
*                                                   Completed header file.
* Leonardo Fusser   16 February 2022    v2.0.2      Minor change.  
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef PUBLIC_H
#define PUBLIC_H

/* Includes. */////////////////////////////
/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h" 
#include "semphr.h"
#include "croutine.h"
/* Hardware specific includes. */
#include "include/ConfigPerformance.h"
#include "include/console32.h"
#include "include/initBoard.h"
/* Other includes. */
#include "vtask1.h"
#include "vtask2.h"
#include "taskA.h"
#include "taskB.h"
#include "taskC.h"
#include <stdio.h>
////////////////////////////////////////////


/* Other macros. */
#define LED_IDLE _LATA7

/* Macro that swaps between Lab 1 and Lab 2 code. */
//#define LAB1

/* Macro that swaps between MPLAB X IDE simulator and Explorer 16/32 board. */
//#define SIMULATION

    
    /* Macro to define queue depth (if applicable). *////////////////////////////
    #ifndef LAB1
        /* Macro that defines queue depth. */
        #define QUEUE_DEPTH 10

    #endif
    /////////////////////////////////////////////////////////////////////////////


    /* Macros to define tasks priorities. *//////////////////////////////////////
    #ifdef  LAB1                        //If Lab1 selected...
        /* Macros that control task priority. Higher number = higher priority. */
        #define     PRIORITY_T1 1       //Task 1 software priority.
        #define     PRIORITY_T2 1       //Task 2 software priority.

    #else                               //Else Lab 2 selected...
        /* Macros that control task priority. Higher number = higher priority. */
        #define     PRIORITY_TaskA 1    //Task A software priority.
        #define     PRIORITY_TaskB 1    //Task B software priority.
        #define     PRIORITY_TaskC 1    //Task C software priority.

    #endif
    /////////////////////////////////////////////////////////////////////////////


    /* Macros to define task delays. *///////////////////////////////////////////////////
    #ifndef SIMULATION                          //If Explorer 16/32 board selected...
        #define CONSOLE_1   C_UART2             //Hardware UART2 on Explorer 16/32 board.
        
            #ifdef LAB1                         //If Lab1 selected...
                #define     DELAY_T1    1500    //3 second delay for task 1.
                #define     DELAY_T2    250000  //30mS delay for task 2.

            #else                               //Else Lab 2 selected...
                #define     DELAY_TaskA 4000    //4 second delay for task A.
                #define     DELAY_Idle  10000000//Delay for idle task.

            #endif

    #else                                       //Else, MPLAB X IDE simulator is selected...
        #define CONSOLE_1 C_UART1               //MPLAB X IDE simulator UART1.
        #define CONSOLE_2 C_UART2               //MPLAB X IDE simulator UART2.

            #ifdef  LAB1                        //If Lab1 selected...
                #define     DELAY_T1    30      //30mS delay for task 1.
                #define     DELAY_T2    150000  //2mS delay for task 2.

            #else                               //Else Lab 2 selected...
                #define     DELAY_TaskA 50      //50mS delay for task A.
                #define     DELAY_Idle  100000  //Delay for idle task.

            #endif

    #endif
    //////////////////////////////////////////////////////////////////////////////////////

#endif
