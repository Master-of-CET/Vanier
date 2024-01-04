/**************************************************************************************************
* FileName: encoder.c
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
* Collins Agyeman   2021-09-21          V1.0        First version of source file.
* Collins Agyeman   2021-09-21          V1.1        Implement encoderTask & counter 
*                                                   for each signal state.
* Collins Agyeman   2021-09-28          V1.2        Fixed print to console.
* Collins Agyeman   2021-10-05          V1.3        Fixed fprintf2, added LED on click.
*                                                   Test ONBOARD with public setter-getter.
* Collins Agyeman   2021-10-19          V1.4        Fixed LED click detent. 
* Collins Agyeman   2021-10-26          V2.0        With queue.
* Leonardo Fusser   2010-11-2           V2.1        Added ifdef function blocks and cleaned up code.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#include "encoder.h"

int cnt;            //Counter.
char buffer [100];

/**********************************************************************************************
* Name: void initEncoderTask(void) 
* Description: ...
* 
***********************************************************************************************/
void initEncoderTask(void){
    sprintf(buffer, "Starting...cnt: 0    \n");     //Print to console.
    fprintf2(CONSOLE, buffer);                      //" ".
    _PCFG0=1;                                       //Configure RB0 & RD0 in digital mode.
    
    #ifdef W_QUEUE
        queue = xQueueCreate(QUEUE_SIZE);           //Queue initialization for 15PPR encoder.
    #endif
}


/**********************************************************************************************
* Name: void encoderTask(void) 
* Description: ...
* 
***********************************************************************************************/
void encoderTask(void) {
 	static enum {SM11_ENTRY,SM11_HANDLER, SM10_ENTRY,SM10_HANDLER,SM00_ENTRY,SM00_HANDLER,SM01_ENTRY,SM01_HANDLER} state=0;
   	if (S3==0){cnt = 0;}    //Reset count when S3 pressed.
    switch(state){
        
        /*SM11*/
        /////////////////////////////////////////////////////////////////////
		case SM11_ENTRY:
            sprintf(buffer, "SM11 cnt: %d    \n", cnt); //Print to console.
            fprintf2(CONSOLE, buffer);                  //" ".
            D4 = 1;
            D3 = 1;
            state = SM11_HANDLER;
			break;
		case SM11_HANDLER:
            if((S4 == 0) && (S5 == 1)){         //If inputs = 01.
                cnt = cnt-1;                    //Decrease counter.
                #ifdef W_QUEUE
                    xQueueSendToBack(queue, &cnt);
                #endif
                state = SM10_ENTRY;
			}
            else if ((S4 == 1) && (S5 == 0)){   //If inputs = 10.
                cnt = cnt+1;                    //Increase counter.
                #ifdef W_QUEUE
                    xQueueSendToBack(queue, &cnt);
                #endif 
                state = SM01_ENTRY;
            }
            else state = SM11_HANDLER;
			break;
        /////////////////////////////////////////////////////////////////////
        
        /*SM10*/
        /////////////////////////////////////////////////////////////////////
        case SM10_ENTRY:
            sprintf(buffer, "SM10 cnt: %d    \n", cnt); //Print to console.
            fprintf2(CONSOLE, buffer);                  //" ".
            D4 = 1;
            D3 = 0;
            state = SM10_HANDLER;
			break;
		case SM10_HANDLER:
            if((S4 == 1) && (S5 == 1)){             //If inputs = 11.
                cnt = cnt-1;                        //Decrease counter.
                #ifdef W_QUEUE
                    xQueueSendToBack(queue, &cnt);
                #endif
                state = SM00_ENTRY;
			}
            else if((S4 == 0) && (S5 == 0)){        //If inputs = 00.
                cnt = cnt+1;                        //Increase counter.
                #ifdef W_QUEUE
                    xQueueSendToBack(queue, &cnt);
                #endif
                state = SM11_ENTRY;
            }    
            else state = SM10_HANDLER;
			break;
        /////////////////////////////////////////////////////////////////////
            
        /*SM00*/
        /////////////////////////////////////////////////////////////////////
        case SM00_ENTRY:
            sprintf(buffer, "SM00 cnt: %d    \n", cnt); //Print to console.
            fprintf2(CONSOLE, buffer);                  //" ".
            D4 = 0;
            D3 = 0;
            state = SM00_HANDLER;
			break;
		case SM00_HANDLER:
            if((S4 == 1) && (S5 == 0)){             //If inputs = 10.
                cnt = cnt-1;                        //Decrease counter.
                #ifdef W_QUEUE
                    xQueueSendToBack(queue, &cnt);
                #endif
                state = SM01_ENTRY;
			}
            else if((S4 == 0) && (S5 == 1)){        //If inputs = 01.
                cnt = cnt+1;                        //Increase counter.
                #ifdef W_QUEUE
                    xQueueSendToBack(queue, &cnt);
                #endif
                state = SM10_ENTRY;
            }
            else state = SM00_HANDLER;
			break;
        /////////////////////////////////////////////////////////////////////
            
        /*SM01*/
        /////////////////////////////////////////////////////////////////////
        case SM01_ENTRY:
            sprintf(buffer, "SM01 cnt: %d    \n", cnt); //Print to console.
            fprintf2(CONSOLE, buffer);                  //" ".
            D4 = 0;
            D3 = 1;
            state = SM01_HANDLER;
			break;
		case SM01_HANDLER:
            if((S4 == 1) && (S5 == 1)){                 //If inputs = 11.
                cnt = cnt-1;                            //Decrease counter.
                #ifdef W_QUEUE
                    xQueueSendToBack(queue, &cnt);
                #endif
                state = SM00_ENTRY;
			}
            else if((S4 == 0) && (S5 == 0)){            //If input = 00.
                cnt = cnt+1;                            //Increase counter.
                #ifdef W_QUEUE
                    xQueueSendToBack(queue, &cnt);
                #endif
                state = SM11_ENTRY;
            }    
            else state = SM01_HANDLER;
			break;
        /////////////////////////////////////////////////////////////////////
	}
}


/**********************************************************************************************
* Name: int getQueue(int *) 
* Description: ...
* 
***********************************************************************************************/
#ifdef W_QUEUE                              //If queue is selected...
    int getQueue (int *p){                  //Enable getQueue() function.
        return xQueueReceive(queue, p);     //Return current head of queue.
    }
#endif


/**********************************************************************************************
* Name: int getCnt(void) 
* Description: ...
* 
***********************************************************************************************/
int getCnt (void){
    return cnt;     //Return current value of "cnt" variable.
}
