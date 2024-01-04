/**************************************************************************************************
* FileName: main.c
*
* Name: Leonardo Fusser (1946995)   Lab 1       Function Generator
*
* Description: This is a multi-part program covering Lab 1. In Part 1, the MPLAB X IDE simulator is
*              used to simulate the real working measurement of an encoder connected to a motor. In
*              Part 2 and 3, the same simulation done before is now done on the Explorer 16/32 board, 
*              where a jumper connects between P97 and P11 on the board. In Part 4, a motor is connected 
*              to the board and a real RPM measurement is done and the result is displayed to the board's
*              LCD. In addition, a pushbutton is used to turn on or off the motor and a LED blinks
*              when a measurement is taking place otherwise it will remain off.       
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould       ?                   v1.0.0      Initial configuration for Lab1.
* Leonardo Fusser   24 August 2021      v1.0.1      Added initialization function calls.
* Leonardo Fusser   31 August 2021      v1.0.2      Added UART1 features and frequency calculation.
* Leonardo Fusser   3 September 2021    v1.0.3      Added SIMULATION and EXPLORER options.
* Leonardo Fusser   5 September 2021    v1.0.4      Added LED heartbeat for EXPLORER.
* Leonardo Fusser   7 September 2021    v1.0.5      Added EXPLORER_WithMOTOR option.
*                                                   Substituted calculations for motor RPM and gearbox RPM. 
*                                                   Added push-button feature for motor. 
*                                                   Cleaned up code and added more comments.
* Leonardo Fusser   14 September 2021   v1.0.6      Added description.  
* Leonardo Fusser   19 September 2021   v1.0.7      Added comments and function prologs. 
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#include <stdio.h>
#include "initBoard.h"
#include "console32.h"
#include "Tick_core.h"


//#define     SIMULATION                        //SELECT FOR USING MPLAB X IDE SIMULATOR.
//#define     EXPLORER_NoMOTOR                  //SELECT FOR USING EXPLORER 16/32 BOARD WITHOUT MOTOR.
//#define     EXPLORER_WithMOTOR                //SELECT FOR USING EXPLORER 16/32 BOARD WITH MOTOR.

#define     LCD_PRINT_RESET  1000                               //LCD printing measuring reset on Explorer 16/32 board (value "of" has to reach before display shows "0").
#define     LCD_NoBLOCKING   TickDiff(stamp)>TICKS_PER_SECOND/2 //LCD non-blocking refreshing delay on Explorer 16/32 board.
#define     LCD_BLOCKING     500000                             //LCD blocking refreshing delay (in uS) on Explorer 16/32 board.

#define     CONSOLE_PRINT_RESET 1000                            //Console printing measuring reset in MPLAB X IDE simulator (value "of" has to reach before display shows "0").
#define     CONSOLE_BLOCKING    62000                           //Console blocking refreshing delay (in uS) in MPLAB X IDE simulator.

#define     PBCLK               20000000                        //Macros for value of PIC32 PBCLK (in Hz).
#define     HEARTBEAT           LATAbits.LATA0                  //LED3 on Explorer 16/32 board.
#define     MOTOR               LATGbits.LATG8                  //Enable pin for motor connected to Explorer 13/32 board.
#define     CONSOLE             C_UART1                         //UART1 module for MPLAB X IDE simulator.
#define     LCD                 C_LCD                           //LCD module for Explorer 16/32 board.
#define     MOTOR_PPR           16                              //Motor PPR constant.
#define     GEARBOX_RATIO       19                              //Motor gearbox ratio constant.


/**********************************************************************************************
* Name: int main(void) 
* Description: Main function for Lab1.
*              Calls all initializing functions. 
*              Covers all four parts of Lab1 (can be individually selected below).
*              Calculates waveform measurements in Hertz and displays to either console or LCD.  
* 
***********************************************************************************************/
int main(void){
    
    char buf[100];                      //Array for buffer (used when printing to UART1 or LCD).
    int frequency;                      //Variable for frequency (used when converting period to frequency).
    int motor_rpm;                      //Variable for storing measured motor RPM value.
    int gearbox_rpm;                    //Variable for storing measured motor gearbox RPM value.
    int stamp;                          //Variable for storing PIC32 tick time stamp.
    extern int timePeriod;              //Extern variable to get meaured period in ticks ("timePeriod" located in isr_driven.c).
    extern signed int of;               //Extern variable to get value of Timer2 overflows ("of" located in isr_driven.c).
    
    initIO();                           //Initializes PIC32 I/O.
    initT2();                           //Initializes PIC32 Timer2 module for interrupts.
    initCN9();                          //Initializes CN9 (RG7) on PIC32 for interrupts.
    
    
    #if defined (SIMULATION)
        initUart1();                    //Initializes UART1 serial port.
        //fprintf2(C_UART1,"Hello!\n"); //Tests UART1 by printing simple message.
        
    #elif defined (EXPLORER_NoMOTOR)
        initLCD();                      //Initializes LCD on Explorer 16/32 board.
        //initT3_3kHz();                  //3kHz square wave generator (SELECT THIS OR THE OTHER ON THE LINE BELOW).
        //initT3_100Hz();                 //100Hz square wave generator (SELECT THIS OR THE OTHER ON THE LINE ABOVE).
        
    #elif defined (EXPLORER_WithMOTOR)
        initLCD();                      //Initializes LCD on Explorer 16/32 board.
        stamp = TickGet();              //First time stamp.
        
    #endif
    
        
    //[Super loop]
    while(1){                                                   //Infinite loop.
        
        #if defined (SIMULATION)
            if(of >= CONSOLE_PRINT_RESET){                      //If x amount of time elapsed since last successful measurement...
                delay_us(CONSOLE_BLOCKING);                     //User-set console refreshing delay (changed above).
                sprintf(buf,"Frequency: %dHz    \n",0);         //Formats and prints "0Hz" to buffer "buf".
                fprintf2(CONSOLE,buf);                          //Prints value from buffer "buf" to UART1 (console).
            }
            else{                                               //Else, keep showing result of measurement to console.
                delay_us(CONSOLE_BLOCKING);                     //User-set console refreshing delay (changed above).
                frequency = PBCLK/timePeriod;                   //Calculates frequency (Value of PBCLK depends on prescale and value of SYSCLK).
                sprintf(buf,"Frequency: %dHz    \n",frequency); //Formats and prints value of frequency to buffer "buf".
                fprintf2(CONSOLE,buf);                          //Prints value from buffer "buf" to UART1 (console).
            }
            
        #elif defined (EXPLORER_NoMOTOR)
            if(of >= LCD_PRINT_RESET){                          //If x amount of time elapsed since last successful measurement...
                delay_us(LCD_BLOCKING);                         //User-set LCD refreshing delay (changed above).
                sprintf(buf,"Frequency: %dHz    \n",0);         //Formats and prints "0Hz" to buffer "buf".
                fprintf2(LCD,buf);                              //Prints value from buffer "buf" to LCD.
                HEARTBEAT = 0;                                  //Turns LED3 off on Explorer 16/32 board.
            }
            else{                                               //Else, keep showing result of measurement to LCD.
                delay_us(LCD_BLOCKING);                         //User-set LCD refreshing delay (changed above).
                frequency = PBCLK/timePeriod;                   //Calculates frequency (Value of PBCLK depends on prescale and value of SYSCLK).
                sprintf(buf,"Frequency: %d    \n",frequency);   //Formats and prints value of frequency to buffer "buf".
                fprintf2(LCD,buf);                              //Prints value from buffer "buf" to LCD.
                HEARTBEAT ^=1;                                  //Toggles LED3 on Explorer 16/32 board.
            }
            
        #elif defined (EXPLORER_WithMOTOR)
            if(S4 == 1){                                                        //If push-button is no longer held down...
                MOTOR = 0;                                                      //Turn off motor.
                sprintf(buf,"Motor RPM: %d    \nGearbox RPM: %d    ",0, 0);     //Formats and prints "0RPM" for motor RPM and gearbox RPM to buffer "buf".
                fprintf2(LCD,buf);                                              //Prints value from buffer "buf" to LCD.
                HEARTBEAT = 0;                                                  //Turns LED3 off on Explorer 16/32 board.
            }
            else{                                                                                     //Else, allow motor to run and to perform RPM measuring.
                MOTOR = 1;                                                                            //Turn on motor.
                if(LCD_NoBLOCKING){                                                                   //User-set LCD refreshing delay (changed above).
                     if(of >= LCD_PRINT_RESET){                                                       //If x amount of time elapsed since last successful measurement...
                        sprintf(buf,"Motor RPM: %d    \nGearbox RPM: %d    ",0, 0);                   //Formats and prints "0RPM" to buffer "buf".
                        fprintf2(LCD,buf);                                                            //Prints value from buffer "buf" to LCD.
                        HEARTBEAT = 0;                                                                //Turns LED3 off on Explorer 16/32 board. 
                     }  
                     else{                                                                            //Else, keep showing result of measurement to LCD.
                        frequency = (PBCLK/timePeriod)/MOTOR_PPR;                                     //Calculates motor frequency (Value of PBCLK depends on prescale and value of SYSCLK).
                        motor_rpm = frequency * 60;                                                   //Calculates motor RPM.
                        gearbox_rpm = motor_rpm / GEARBOX_RATIO;                                      //Calculates motor gearbox RPM.
                        sprintf(buf,"Motor RPM: %d    \nGearbox RPM: %d    ",motor_rpm, gearbox_rpm); //Formats and prints value of motor RPM and gearbox RPM to buffer "buf".
                        fprintf2(LCD,buf);                                                            //Prints value from buffer "buf" to LCD.
                        HEARTBEAT ^=1;                                                                //Toggles LED3 on Explorer 16/32 board.
                     }
                     stamp = TickGet();                                                               //Second time stamp (re-stamp).
                }
                else{
                    //Nothing happening here...
                }
            }
            
        #endif
            
	}
}
