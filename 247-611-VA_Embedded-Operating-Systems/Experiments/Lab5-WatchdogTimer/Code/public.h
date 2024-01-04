/* ***************************************************************************
 * File: public.h
 * Description: contains public prototypes and shared macros for Lab5.
 * 
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author        	Date      		Version     Comments on this revision
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * SH               ?               1.0         First version of header file.
 * Leonardo F.      April 14 2022   1.1         Created macros.
 *                                              Added function prototypes.
 *                                              Added comments.
 * Leonardo F.      April 16 2022   1.2         Completed header file.
 *                                              Added #ifdef statement.
 *                                              Added more macros.
 *                                              Added comments.
 * 
 *****************************************************************************/


#ifndef PUBLIC_H
#define PUBLIC_H

/* Macros. */
#define     SIMULATION                    //This comment toggles between Explorer 16/32 board and MPLAB X IDE simulator.
#define     vTASK1_LED  LATAbits.LATA0      //LED on Explorer 16/32 board.
#define     IDLE_LED    LATAbits.LATA7      //" ".
#define     HUNG_LED    LATAbits.LATA4      //" ".
#define     POR_FLAG    RCONbits.POR        //Power-on-reset flag.
#define     EXTR_FLAG   RCONbits.EXTR       //External-reset flag.
#define     WDT_FLAG    RCONbits.WDTO       //Watchdog time-out flag.
#define     WDT_KICK    WDTCONbits.WDTCLR   //Watchdog overflow flag.
#define     WDT_ENABLE  WDTCONbits.ON       //Watchdog module enable/disable.


#ifndef SIMULATION                  //If Explorer 16/32 board selected...
    #define CONSOLE_1    C_LCD      //Console is LCD.
#else                               //Otherwise, if MPLAB X IDE simulator selected...
    #define CONSOLE_1   C_UART1     //First console is UART1.
    #define CONSOLE_2   C_UART2     //Second console is UART2.
#endif


/* Function prototypes. */
void vStartTask1(void);
void vStartTask2(void);
void vInit_mutex(void);
void mutex_print(char* temp_str);

#endif
