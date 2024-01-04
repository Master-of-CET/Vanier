/**************************************************************************************************
* FileName: public.h
*
* Name: Leonardo Fusser (1946995)       Lab 5       SPI communication 
*
* Description: Includes all common macros and dependencies needed by many files.
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   30 November 2021    v1.0.0      First version of header file.
* Leonardo Fusser   7 December 2021     v1.0.1      Cleanup of header file.
* Leonardo Fusser   11 December 2021    v1.0.2      Completed header file.
*                                                   Added comments. 
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef PUBLIC_H
#define PUBLIC_H

/*All dependencies required are included below*/
#include <xc.h>
#include <stdint.h>
#include "initBoard.h"
#include "console32.h"
#include <stdio.h>
#include "Tick_core.h"
#include "adc32.h"
#include "util.h"
#include "oled_init.h"


#define DELAY          100                                  //Sampling time delay (10mS).
#define TICKS_DELAY    TICKS_PER_SECOND/DELAY               //Convert sampling time delay in seconds to ticks.     
#define SAMPLING_TIME  TickDiff(lastTick) > TICKS_DELAY     //Checks to see if sampling time delay has elapsed (non-blocking way).


/*Macro to select which part of lab is used*/
//#define Part1
#define Part2


/*Other macro constants*/   
#ifdef  Part1
    //#define Mode0                 //Selects SPI mode 0.
    //#define Mode3                 //Selects SPI mode 3.
    #define LOAD_BYTE   0xA3        //Loads byte into SPI module on PIC32.
    #define BAUD        100000      //Sets baud rate of 100kBaud.

#elif defined Part2
    #define Mode2                   //Selects SPI mode 2.
    #define BAUD        100000      //Sets baud rate of 100kBaud.

#endif


#endif
