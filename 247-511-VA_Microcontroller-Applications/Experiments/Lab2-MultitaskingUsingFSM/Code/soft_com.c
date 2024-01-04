/**************************************************************************************************
* FileName: soft_com.c
*
* Name: Leonardo Fusser (1946995)       Lab 2       Cooperative multitasking using FSM
*       Collins Agyeman-Duah (1554428) 
*
* Description: Code that allows data to be printed serially on PIC32 TX pin.
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   21 September 2021   v1.0.0      Created soft_com.c file.
* Leonardo Fusser   26 September 2021   v1.0.1      Minor changes.
* Leonardo Fusser   28 September 2021   v1.0.2      Github push test.
*                                                   Added minor code.
* Leonardo Fusser   2 October    2021   v1.0.3      Added functions, comments, and fixed SoftComTask();
* Leonardo Fusser   5 October    2021   v1.0.4      Implemented string printing to TX output (multi-character).
* Leonardo Fusser   2 November   2021   v1.0.5      Added ifdef function blocks and cleaned up code.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#include "soft_com.h"

/**********************************************************************************************
* Name: void softComTask(void) 
* Description: Task that prints data serially (like RS232) to TX pin on PIC32.
* 
***********************************************************************************************/
void SoftComTask(void) {
    static int rx;
    static int32_t lastTick;                                                                    //Local variable to store time stamp.
 	static enum {SM_POLL, SM_RETR, SM_START_BIT, SM_STOP_BIT, SM_SEND_BITS} state = SM_POLL;    //Enumeration.

   	switch(state){
        static int StrCount,PrintCount,temp;               //Various local variables.
        static char Str[50];                               //Stores string that will be printed to serial pin on PIC32.
        
		////SM_POLL///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case SM_POLL:
            
            #ifdef  SIMULATION                              //If MPLAB X IDE simulator selected...
            sprintf(Str,"Hi");                              //Prints a simple message serially on PIC32 TX pin.
                
            #else                                           //Otherwise, Explorer 16/32 board selected...
                #ifdef  W_QUEUE                             //If queue is selected...
                    if(getQueue(&rx) == 0){                 //If queue is NOT empty...
                        sprintf(Str,"Count:%d\n\r", rx);    //Format and print value of "cnt" to "Str" buffer to be printed serially on PIC32 TX pin.
                    }
                
                #else                                       //Otherwise, queue is not being used.
                    sprintf(Str,"Count:%d\n\r",getCnt());   //Format and print value of "cnt" to "Str" buffer to be printed serially on PIC32 TX pin.
            
                #endif
            
            #endif

            PrintCount = 8;                                //Keeps track of how many data bits have been printed.
            StrCount = 0;                                  //Keeps track of how many characters have been printed.
            state = SM_RETR;                               //Move on to next state.
            break;
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
        ////SM_RETR///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case SM_RETR:
            if(Str[StrCount] == '\0'){state = SM_POLL;}                              //If done outputting character to TX, go to SM_POLL state.
            else{lastTick = TickGet();TX = 0x0;state = SM_START_BIT;PrintCount=8;}   //Otherwise, do timestamp, assert start bit and move on to 
                                                                                     //next state.
            break;
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
        ////SM_START_BIT//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case SM_START_BIT:
            if(TIMEOUT_START){state = SM_SEND_BITS;}                    //If start bit delay achieved, move on to next state.
            else{state = SM_START_BIT;}                                 //Otherwise, stay in SM_START_BIT state.
            break;
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
        ////SM_SEND_BITS//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case SM_SEND_BITS:
            if(PrintCount >= 0){                                        //If not finished outputting character...
                if(TIMEOUT){                                            //If character bit delay achieved...
                    temp = Str[StrCount] & MASK;                        //Current character bit masked with MASK and result stored in temp.
                    TX = temp;                                          //Output result to TX.
                    Str[StrCount] = Str[StrCount] >> 1;                 //Shift for next character bit to be masked and outputted to TX.
                    PrintCount--;                                       //Decrease output count by 1.
                    lastTick = TickGet();                               //Timestamp.
                    state = SM_SEND_BITS;}                              //Move on to next state.
                else{state = SM_SEND_BITS;}                             //...otherwise, stay in SM_SEND_BITS state.
            }
            else{state = SM_STOP_BIT;TX = 0x1;lastTick = TickGet();StrCount++;}    //...otherwise move on to next state, assert stop bit and do 
                                                                                   //timestamp.
            break;
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
        ////SM_STOP_BIT///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case SM_STOP_BIT:
            if(TIMEOUT_STOP){state = SM_RETR;}    //If stop bit delay achieved, move on to next state.
            else{state = SM_STOP_BIT;}            //Otherwise, stay in SM_STOP_BIT state.
            break;
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	}
}


/**********************************************************************************************
* Name: void SimpleSoftComTask(void) 
* Description: Tasks that prints a single character serially (like RS232) to TX pin on PIC32.
* 
***********************************************************************************************/
void SimpleSoftComTask(void){
    static int32_t lastTick;                        //Local variable to store time stamp.
 	static enum {SM_TX} state = SM_TX;              //Enumeration.
    
    switch(state){
        static int character = '5', i = 7, temp;    //Various local variables.
        
        case SM_TX:
            if(i>=0){                               //If not finished outputting character...
                if(TIMEOUT){                        //If character bit delay achieved...
                    temp = character & MASK;        //Current character bit masked with MASK and result stored in temp.
                    TX = temp;                      //Output result to TX.
                    character = character >> 1;     //Shift for next character bit to be masked and outputted to TX.
                    i--;                            //Decrease output count by 1.
                    lastTick = TickGet();           //Timestamp.
                    state = SM_TX;}                 //Move on to next state.
                else{state = SM_TX;}                //...otherwise, move on to next state.
            }
            else{state = SM_TX;}                    //...otherwise, move on to next state.
            break;
            
        default: state = SM_TX;                     //...otherwise, move on to next state.
            break;
    }
}
