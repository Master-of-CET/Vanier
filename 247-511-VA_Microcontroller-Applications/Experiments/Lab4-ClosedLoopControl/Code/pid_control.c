/**************************************************************************************************
* FileName: pid_control.c
*
* Name: Leonardo Fusser (1946995)       Lab 4       Servomotor - closed loop control
*
* Description: This code provides the functionality of a closed-loop controlled system. This code
*              does not rely entirely on the feedback of the user. Instead, regardless of the mode
*              used (target or simulation), PIC32 observes what SP value is desired by the user and 
*              attempts to re-produce that value based off an algorithm, just like how a typical 
*              closed-loop controlled system would behave.
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   9 November 2021     v1.0.0      First version of source file.
* Leonardo Fusser   29 November 2021    v1.0.1      Completed pid_control.c file.
*                                                   Added comments and description header.  
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#include "pid_control.h"
#include <stdio.h>

/**********************************************************************************************
* Name: void pid_control(void) 
* Description: Closed-loop control task for simulation and target mode.
*              Macro constants can be found in pid_control.h and configuration.h files. 
* 
***********************************************************************************************/
void pid_control(void){

    static int32_t lastTick;    //Timestamp variable.
    static char buffer[50];     //Display buffer.
    static float SP;            //Setpoint variable.
    static float SP_rescaled;   //Setpoint variable (rescaled).
    static int PV;              //Position variable.
    static float e;             //Error variable.
    static float PTerm;         //P-term variable.
    static float ITerm;         //I-term variable.
    static int ONTime;          //PWM on-time variable.
    
    #ifdef SIMULATION
        static int SP_debug;        //Setpoint variable (for debugging purposes).
        static int PV_debug;        //Position variable (for debugging purposes).
        static int e_debug;         //Error variable (for debugging purposes).
        static int PTerm_debug;     //P-term variable (for debugging purposes).
    #endif
	
    if(SAMPLING_TIME){                                              //Sampling time delay.

        #ifndef SIMULATION                                          //If target mode is desired...
            /*Read ADC*/
            SP = readADC(2);
            
            /*Read and re-scale the read value*/
            SP_rescaled = SP * 320/1023;                            //Rescale for range from 0 to 320 on slider POT.
            
            /*Read position*/
            PV = get_pv();
            
            /*Error calculation*/
            e = SP_rescaled - PV;
            
            /*I-Term*/
            ITerm = ITerm + KI_TAR * e;
            
            /*Anti-windup*/
            if(ITerm > ANTI_WINDUP_TAR){ITerm = ANTI_WINDUP_TAR;}
            if(ITerm <- ANTI_WINDUP_TAR){ITerm = -ANTI_WINDUP_TAR;}
            
            /*P-Term*/
            PTerm = KP_TAR * e;
            
            /*On-Time*/
            ONTime = PTerm + ITerm;
            
            /*Set the PWM*/
            set_pwm(ONTime);
            
            /*Print PWM and PV value*/
            sprintf(buffer,"SP: %4.2f             \nPV: %d            \n", SP_rescaled, PV);    //Print to buffer first...
            fprintf2(C_LCD,buffer);                                                             //Then dump result to LCD on Explorer 16/32 board.
            
            /*Timestamp*/
            lastTick = TickGet();
            
        #else                                                           //Otherwise, when simulation mode is desired...
            /*Read ADC*/
            SP = readADC(2);
            SP_debug = SP;
        
            /*Read position*/
            PV = get_pv();
            PV_debug = PV;
            
            /*Error calculation*/
            e = SP - PV;
            e_debug = e;
            
            /*I-Term*/
            ITerm = ITerm + KI_SIM * e;
            
            /*Anti-windup*/
            if(ITerm > ANTI_WINDUP_SIM){ITerm = ANTI_WINDUP_SIM;}
            if(ITerm <- ANTI_WINDUP_SIM){ITerm = -ANTI_WINDUP_SIM;}
  
            /*P-Term*/
            PTerm = KP_SIM * e;
            PTerm_debug = PTerm;
            
            /*On-Time*/
            ONTime = PTerm + ITerm;
        
            /*Set the PWM*/
            set_pwm(ONTime);
            
            /*Timestamp*/
            lastTick = TickGet();
            
        #endif
    }
}
