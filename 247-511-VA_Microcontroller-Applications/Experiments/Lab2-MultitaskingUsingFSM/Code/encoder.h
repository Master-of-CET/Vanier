/**************************************************************************************************
* FileName: encoder.h
*
* Name: Leonardo Fusser (1946995)       Lab 2       Cooperative multitasking using FSM
*       Collins Agyeman-Duah (1554428) 
*
* Description: State machine to decode encoder pulses.
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Collins Agyeman   2021-09-21          V1.0        First version of header file.
* Collins Agyeman   2021-09-21          V1.1        Add encoderTask() function & initEncoderTask().
* Collins Agyeman   2021-09-28          V1.2        Add on IO port MACROS, change input pins to 
*                                                   RB0 & RD0.
* Leonardo Fusser   2021-11-2           V1.3        Added ifdef function blocks and cleaned up code. 
* 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef ENCODER_H
#define	ENCODER_H

#include "public.h"

    #ifdef SIMULATION           //If MPLAB X IDE simulator selected...
        #define CONSOLE C_UART1 //Set console to use UART1.
    #else                       //Otherwise, Explorer 16/32 board selected...
        #define CONSOLE C_LCD   //Set console to use LCD.   
    #endif


    #ifdef W_QUEUE              //If queue is selected...
        #define QUEUE_SIZE 50   //Create a queue with a size of 50 bytes.
        QueueHandle_t* queue;   //Queue pointer declaration.
    #endif

        
/*PIC32 I/O macros*/
#define S4  PORTDbits.RD0   //Signal B.
#define S5  PORTBbits.RB0   //Signal A.
#define S3  PORTDbits.RD6   //Counter reset.
#define D3  LATAbits.LATA0  //LED B.
#define D4  LATAbits.LATA1  //LED A.

/*Function prototypes*/
void initEncoderTask(void);
void encoderTask(void);
int getQueue(int*);
int getCnt(void);

#endif	/* ENCODER_H */
