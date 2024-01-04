/**************************************************************************************************
* FileName: main.c
*
* Name: Leonardo Fusser (1946995)       Lab 5       SPI communication
*
* Description: This code provides the main interface for the functionality of Lab5. Here, depending
*              on which part is set in the public.h file (Part1 or Part2), the appropriate
*              initialization functions and tasks are called and executed from this file.      
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould       ?                   v1.0.0      First version of source file.
* Leonardo Fusser   30 November 2021    v1.0.1      Minor changes. 
* Leonardo Fusser   7 December 2021     v1.0.2      Cleaned up source file.
* Leonardo Fusser   11 December 2021    v1.0.3      Completed source file.
*                                                   Added comments.   
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#include "public.h"
#include "oled.h"
#include "application.h"
#include "spi.h"

/**********************************************************************************************
* Name: int main(void) 
* Description: Lab5 main function for Part1 and Part2. Includes all init function calls and main
*              super loop. 
*              Macro constants can be found in public.h file. 
* 
***********************************************************************************************/
int main(void) {
    
    static int32_t lastTick;
    static int dummy;
   
    /*When using the OLED, the following line MUST always be the first line to run when entering the main*/  
    #ifndef Part1
        /*init OLED*/
        oled_init();
    #endif

    /*init IOs*/
    initIOs();
    
    /*init SPI*/
    spi_init(BAUD, CPOL, CPHA);

    /*clears OLED display*/
    oled_clr();
    
    
    /*Main super loop*/
    while(1){    
        
        #ifdef Part1                                //If part1 defined...
            if(SAMPLING_TIME){                      //If sampling time elapsed...
                dummy = spi_ld_buffer(LOAD_BYTE);   //Call function and assign returned value to dummy.
                lastTick = TickGet();               //Timestamp.
            }
            
        #elif defined Part2                         //Otherwise, if part2 defined...
            RectangleLineTASK();                    //Calls task.
            
        #endif

    }
    
    return 0;
    
}
