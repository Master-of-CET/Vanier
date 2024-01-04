/**************************************************************************************************
* FileName: vTaskTemperature.c
*
* Name: Leonardo Fusser (1946995)       Lab 4       Vending Machine II
*
* Description: vTaskTechnician source file for Lab4. This file contains the core vending machine
*              temperature monitoring algorithm. A thread continously runs to measure and calculate
*              the vending machine's internal fridge temperature. The reading comes from a pot on
*              the Explorer 16/32 board (to simulate temperature reading).
*              Macro constants can be found in the vDatabase.h or public.h file.
*
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   10 March 2022       v1.0.0      First version of source file.
*                                                   Added includes.
* Leonardo Fusser   22 March 2022       v1.0.1      Minor changes.
* Leonardo Fusser   10 April 2022       v1.0.2      Added comments.
*                                                   Completed source file.
* Leonardo Fusser   21 May 2022         v1.0.3      Minor changes.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include "include/vTaskTemperature.h"


/**********************************************************************************************
* Name: static void vTaskTempterature(void *pvParameters) 
* Description: Private static function definition for Lab4 RTOS vTaskTemperature. This is the 
*              thread routine that continously runs and measures the vending machine's internal
*              fridge temperature. The thread reads the ADC value from the pot, re-scales the
*              value and calculates the temperature. The range is from -7 to 20.
*              Macro constants can be found in public.h file or vTaskTemperature.h file.
* 
***********************************************************************************************/
static void vTaskTemperature( void *pvParameters ){
    
    pvParameters = pvParameters;   //This is to get rid of annoying warnings.
    int ADC_rx;                    //Stores ADC value read from pot on Explorer 16/32 board.
    int CurrentTemperature;        //Stores re-scaled temperature value.
    
    /* Mini infinite loop. */
    while(1){
     
        vTaskDelay(DELAY_TaskTemperature/portTICK_RATE_MS); //Gives slack time to system.
        LED_TEMP ^= 1;
        
        ADC_rx = readADC(2);                                //Reads the ADC.
        CurrentTemperature = ADC_rx * 27/1023;              //Re-scales the ADC for -7 to +20 range.
        CurrentTemperature = CurrentTemperature - 7;        //" ".
        
        mutex_SetFridgeTemperature(CurrentTemperature);     //Sets fridge temperature.
    }
}


/**********************************************************************************************
* Name: void vInit_vTaskTemperature(void) 
* Description: Public function definition for Lab4 RTOS vTaskTemperature. This function calls 
*              initializing functions for vTaskTemperature.
* 
***********************************************************************************************/
void vInit_vTaskTemperature(void){
    /* Calls task init function for vTaskTemperature. */
    vInit_StartTemperature();
}


/**********************************************************************************************
* Name: void vInit_StartTemperature(void)
* Description: Public function definition for Lab4 RTOS vTaskTemperature. This function creates 
*              vTaskTemperature. 
*              Macro constants can be found in public.h file or vTaskTemperature.h file. 
* 
***********************************************************************************************/
void vInit_StartTemperature(void){
    /* Creates vTaskTemperature task with user-set priority. */
    xTaskCreate( vTaskTemperature, ( char * ) "Temperature", 240, NULL, PRIORITY_Temperature, NULL );
}
