/**************************************************************************************************
* FileName: ol_control.c
*
* Name: Leonardo Fusser (1946995)       Lab 3       Servomotor - open loop control
*
* Description: This code provides the functionality of an open-loop controlled system. This code
*              relies on the feedback of the user, in both simulation mode or target mode, by observing
*              what PWM value is desired by the user and to behave like a typical open-loop controlled 
*              system. 
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   29 October 2021     v1.0.0      First version of source file.
* Leonardo Fusser   14 November 2021    v1.0.1      Completed ol_control.c file.
*                                                   Added comments and description header.  
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#include "ol_control.h"
#include <stdio.h>

/**********************************************************************************************
* Name: void ol_control(void) 
* Description: Open-loop control task for simulation and target mode.
*              Macro constants can be found in ol_control.h and configuration.h files. 
* 
***********************************************************************************************/
void ol_control(void){
        
    static int32_t lastTick;    //Timestamp variable.
    static char buffer[50];     //Display buffer.
    static int PV;              //Position variable.
    static int sim_ADC;         //Set-point variable (for simulation mode).
    static int tar_ADC;         //Set-point variable (for target mode.)
	
    if(SAMPLING_TIME){  //Sampling time delay.

        #ifndef SIMULATION                                                  //If target mode is desired...
            /*Read ADC*/
            tar_ADC = readADC(2);
            
            /*Read and re-scale the read value*/
            tar_ADC = tar_ADC * 20000/1023;
            tar_ADC = tar_ADC - 10000;
            
            /*Set the PWM*/
            set_pwm(tar_ADC);
            
            /*Read position*/
            PV = get_pv();
            
            /*Print PWM and PV value*/
            sprintf(buffer,"PWM: %d       \nPV: %d       \n", tar_ADC, PV); //Print to buffer first.
            fprintf2(C_LCD,buffer);                                         //Then dump result to LCD on Explorer 16/32 board.
            
            /*Timestamp*/
            lastTick = TickGet();
            
        #else                                                               //Otherwise, when simulation mode is desired...
            /*Read ADC*/
            sim_ADC = readADC(2);

            /*Read and re-scale the read value*/
            sim_ADC = sim_ADC * 20000/1023;
            sim_ADC = sim_ADC - 10000;
        
            /*Set the PWM*/
            set_pwm(sim_ADC);
        
            /*Timestamp*/
            lastTick = TickGet();
            
        #endif
        
    }
}
