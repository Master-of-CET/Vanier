/**************************************************************************************************
* FileName: public.h
*
* Name: Leonardo Fusser (1946995)       Lab 2       Cooperative multitasking using FSM
*       Collins Agyeman-Duah (1554428) 
*
* Description: Header file that includes all code dependencies and macros that need to be un-commented
*              or commented based on the user's desire. 
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   21 September 2021   v1.0.0      Created public.h file.
* Leonardo Fusser   26 September 2021   v1.0.1      Minor changes.
* Leonardo Fusser   28 September 2021   v1.0.2      Github push test.
*                                                   Minor changes. 
* Leonardo Fusser   2 October    2021   v1.0.3      Removed unnecessary code.
* Leonardo Fusser   2 November   2021   v1.0.4      Cleaned up code.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef PUBLIC_H
#define PUBLIC_H

#include <xc.h>
#include <stdio.h>
#include "Tick_core.h"
#include "include/initBoard.h"
#include <stdint.h>
#include <sys/attribs.h>
#include "console32.h"
#include "idle.h"
#include "encoder.h"
#include "include/queue.h"
#include "soft_com.h"

//#define SIMULATION                //SELECT IF TESTING CODE USING MPLAB X IDE SIMULATOR.
//#define W_QUEUE                     //SELECT IF A QUEUE IS DESIRED.
//#define SIMULATION_SIMPLE_RS232   //SELECT IF TESTING SIMPLE RS232 WITH MPLAB X IDE SIMULATOR.
                                    //OTHERWISE COMPLEX RS232 SIMULATION DEFAULT WILL BE USED.
        
#endif
