/**************************************************************************************************
* FileName: public.h
*
* Name: Leonardo Fusser (1946995)       Lab 3       Vending Machine
*                                       Lab 4       Vending Machine II
*
* Description: Lab3 and Lab4 public.h header file. Here, the user can toggle between the MPLAB X 
*              IDE simulator (simulator mode) and the Explorer 16/32 board (target mode). The user 
*              can also change individual task priorities, delays and various other task related 
*              functions. Depending if target mode or simulator mode is selected, other appropriate 
*              constants are automatically applied.
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould       ?                   v1.0.0      First version of header file.
* Leonardo Fusser   17 February 2022    v1.0.1      Added includes.
*                                                   Added struct for vending machine internals.
*                                                   Implemented macros.
*                                                   Added #ifdef statements.
* Leonardo Fusser   24 February 2022    v1.0.2      Added more macros.
*                                                   Added more comments.
* Leonardo Fusser   5 March 2022        v1.0.3      Added include.
*                                                   Added comments.
* Leonardo Fusser   9 March 2022        v1.0.4      Minor changes.
* Leonardo Fusser   22 March 2022       v1.0.5      Added macros.
*                                                   Added comments.
* Leonardo Fusser   10 April 2022       v1.0.6      Minor changes.
*                                                   Added comments.
*                                                   Completed header file.
* Leonardo Fusser   21 May 2022         v1.0.7      Minor changes.
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
#include "Tick_core.h"
#include "adc32.h"
/* Other includes. */
#include "vTaskUI.h"
#include "vDatabase.h"
#include "vTaskTechnician.h"
#include "vTaskTemperature.h"
#include <stdio.h>
#include <string.h>
////////////////////////////////////////////


/* Macro that swaps between MPLAB X IDE simulator and Explorer 16/32 board. */
//#define SIMULATION

/* Macro that defines queue depth. */
#define QUEUE_DEPTH 10

/* Defines a struck to handle X number of vending machine drinks. */
#define STRUCT_DEPTH 3

/* Vending machine drinks. */
#define ORANGE  0
#define YELLOW  1
#define RED     2

/* Other macros. */
#define LED_IDLE    _LATA7
#define LED_TEMP    _LATA0
#define MAX_CREDIT  9
#define BUSY        1
#define FREE        0


/* Struct that contains various vending machine internals. *////////////////////
typedef struct{
    int price;      //Drink price.
    int qty;        //Drink quantity.
    char name[10];  //Drink name.
}product_t;
////////////////////////////////////////////////////////////////////////////////


    /* Macros to define tasks priorities. *//////////////////////////////////////
    /* Macros that control task priority. Higher number = higher priority. */
    #define     PRIORITY_TaskUI      2   //vTaskUI software priority.
    #define     PRIORITY_Database    4   //vDatabase software priortiy.
    #define     PRIORITY_Technician  3   //vTaskTechnician software priority.
    #define     PRIORITY_Temperature 1   //vTaskTemperature software priority.

    /////////////////////////////////////////////////////////////////////////////


    /* Macros to define task delays. *///////////////////////////////////////////////////
    #ifndef SIMULATION                              //If Explorer 16/32 board selected...
        #define CONSOLE_TaskTechnician  C_UART2
        #define CONSOLE_1               C_LCD       //LCD on Explorer 16/32 board.
        #define DELAY_Idle              100000      //Delay for idle task.
        #define DELAY_TaskTechnician    10          //Delay for vTaskTechnician.
        #define DELAY_TaskTemperature   500         //Delay for vTaskTemperature.
        #define DELAY_TaskUI            10          //Delay for vTaskUI.

    #else                                           //Else, MPLAB X IDE simulator is selected...
        #define CONSOLE_TaskTechnician  C_UART1
        #define CONSOLE_1               C_UART1     //MPLAB X IDE simulator UART1.
        #define CONSOLE_2               C_UART2     //MPLAB X IDE simulator UART2.
        #define DELAY_Idle              100000      //Delay for idle task.
        #define DELAY_TaskTechnician    10          //Delay for vTaskTechnician.
        #define DELAY_TaskTemperature   10
        #define DELAY_TaskUI            10

    #endif
    //////////////////////////////////////////////////////////////////////////////////////


#endif
