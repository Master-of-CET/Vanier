/*******************************************************************************
*
*   FileName:   main.c
*
*	Name: Leonardo Fusser (1946995) 
*
*	Description: this file is the main source file for Lab9. The following code
*                prints the measured temperature to a console from a TMP61 or a
*                TC1074A.
*                Two macros are used to toggle between printing the temperature
*                from a TMP61 or TC1074A.  
*
*
*   REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date      		Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould       April 3, 2022	Template code.
* Leonardo Fusser   April 16, 2022  Completed while(1).
*                                   Added calculations for Vtemp and Rtherm.
*                                   Added calculations for temperature (TMP61
*                                   and TC1047A).
*                                   Added macros.
*                                   Added comments.
* Leonardo Fusser   April 17, 2022  Minor changes.
* Leonardo Fusser   May 21, 2022    Minor changes.
*
*******************************************************************************/


#include <xc.h>
#include "Tick_core.h"
#include "adc.h"
#include "console.h"
#include "initBoard.h"
#include "util.h"
#include <stdio.h>
#include <math.h>


/* Macros. */
//#define TMP61         //This macro must be toggled in order for it to work/not work.
//#define TC1047A       //" ".
#define RBIAS   10000
#define VBIAS   3.3


/* Externs. */
extern const signed int lut[166][2];


int main( void ){
    
    /* Inits. */
    INTCONbits.MVEC = 1;
    initIOs();
    LCDInit();
    adc_init();
    heartbeat_init();
    
    /* Temp variables. */
    int rx_ADC;
    float Vtemp, Rtherm;
    char PrintBuff[20];
    int i;
    
    while(1){
        
        float Temperature;                                          //Temp variable.
        
        heartbeat();                                                //Heartbeat.
        
        #ifdef  TMP61                                               //If TMP61 selected...
            rx_ADC = adc_read(1);                                   //Reads from ADC channel 1.
        
        #elif defined TC1047A                                       //Otherwise, if TC1047A selected...
            rx_ADC = adc_read(4);                                   //Reads from ADC channel 4.
        
        #endif
        
        Vtemp = (float)rx_ADC * 3.3 / 1024;                         //Calculates Vtemp.
        Rtherm = (Vtemp / ((VBIAS - Vtemp) / RBIAS));               //Calculates Rtherm.
        
        #ifdef  TMP61                                               //If TMP61 selected...

            /* Determines temperature based on data inside LUT. */
            for(i = 0; Rtherm >= lut[i][1]; i += 1){
                Temperature = lut[i][0];                            //Stores correct temperature upon last loop iteration.
            }
            
            if(Temperature > 125 || Temperature < -40){
                /* Prints load error. */
                sprintf(PrintBuff, "Error!           \nNo load.           \n");
                fprintf2(C_LCD, PrintBuff);
            }
            else{
                /* Prints measured Rtherm value. */
                sprintf(PrintBuff, "Rtherm: %.2f        \n", Rtherm);
                fprintf2(C_LCD, PrintBuff);
                
                /* Prints measured temperature. */
                sprintf(PrintBuff, "\nTemp: %.2f        \n", Temperature);
                fprintf2(C_LCD, PrintBuff);
            }
            
        #elif defined  TC1047A                                      //Otherwise, if TC1047A selected...

            /* Prints measured Vtemp value. */
            sprintf(PrintBuff, "Vout: %.2f        \n", Vtemp);
            fprintf2(C_LCD, PrintBuff);
            
            Temperature = ((Vtemp - 500e-3) / 10e-3);               //Calculates temperature.
            
            /* Prints measured temperature. */
            sprintf(PrintBuff, "\nTemp: %.2f        \n", Temperature);
            fprintf2(C_LCD, PrintBuff);
        
        #endif
        

    }//End of while(1).

    return 0;

}//End of main().
