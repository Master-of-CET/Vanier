/**********************************************************************************************
* FileName: initBoard.c
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
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date             Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould       14 January 2021   v1.0.0     Setup for PIC32.
* Serge Hould       27 April   2021   v1.0.1     Set PBCLK to 80MHz to facilitate simulation.  
*                                                Both sysclk and pbclk are the same.
* Leonardo Fusser   24 August  2021   v1.0.2     Added initT2 and initCN9 functions and comments.
* Leonardo Fusser   5 September 2021  v1.0.3     Initialized LEDs on EXPLORER to be off upon startup.
* Leonardo Fusser   7 September 2021  v1.0.4     Disabled JTAG header to use all LEDs on EXPLORER.
* Leonardo Fusser   14 September 2021 v1.0.5     Added description.
* Leonardo Fusser   19 September 2021 v1.0.6     Added comments and function prologs.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#include "initBoard.h"
#include <stdint.h>
#include <xc.h>
#include <sys/attribs.h>

// Configuration Bit settings
// SYSCLK = 80 MHz 
//(8MHz Crystal/ FPLLIDIV * FPLLMUL / FPLLODIV)
// PBCLK = 40 MHz
// Primary Osc w/PLL (HS+PLL)
// WDT OFF, Peripheral Bus is CPU clock÷8
// Other options are default as per datasheet
// see file: C:\Program Files (x86)\Microchip\xc32\v1.40\docs\config_docs\32mx795f512l.html
 
#pragma config FPLLMUL = MUL_20
#pragma config FPLLIDIV = DIV_2
#pragma config FPLLODIV = DIV_1 
#pragma config POSCMOD = HS, FNOSC = PRIPLL
#pragma config FPBDIV = DIV_1                   //PBCLK = SYSCLK/DIV_1.
#pragma config FWDTEN =  OFF                    //Disable.

/**********************************************************************************************
* Name: void initIO(void) 
* Description: Configures and initializes all LEDs on Explorer 16/32 board.
*              Configures and initializes all pushbuttons on Explorer 16/32 board. 
*              Configures and initializes external waveform generator.
*              Configures and initializes motor.  
* 
***********************************************************************************************/
void initIO(void)
{
    
    DDPCONbits.JTAGEN = 0;      //Disables JTAG programming header.
    
    /* LEDs */
    TRISAbits.TRISA7 = 0;       //LED10 on Explorer 16/32 board.
    TRISAbits.TRISA5 = 0;       //LED8 on Explorer 16/32 board.
    TRISAbits.TRISA4 = 0;       //LED7 on Explorer 16/32 board.
    TRISAbits.TRISA3 = 0;       //LED6 on Explorer 16/32 board.
    TRISAbits.TRISA2 = 0;       //LED5 on Explorer 16/32 board.
    TRISAbits.TRISA1 = 0;       //LED4 on Explorer 16/32 board.
    TRISAbits.TRISA0 = 0;       //LED3 on Explorer 16/32 board.
    
    LATAbits.LATA7 = 0;         //Initializes LED10 on Explorer 16/32 board to turn off.
    LATAbits.LATA5 = 0;         //Initializes LED8 on Explorer 16/32 board to turn off.
    LATAbits.LATA4 = 0;         //Initializes LED7 on Explorer 16/32 board to turn off.
    LATAbits.LATA3 = 0;         //Initializes LED6 on Explorer 16/32 board to turn off.
    LATAbits.LATA2 = 0;         //Initializes LED5 on Explorer 16/32 board to turn off.
    LATAbits.LATA1 = 0;         //Initializes LED4 on Explorer 16/32 board to turn off.
    LATAbits.LATA0 = 0;         //Initializes LED3 on Explorer 16/32 board to turn off.
    
    TRISGbits.TRISG8 = 0;       //Motor enable pin (pin 12 on PIC32).
    TRISGbits.TRISG13 = 0;      //External generator pin (pin 97 on PIC32).
    
    TRISDbits.TRISD6 =1;        //S3 on Explorer 16/32 board.
    TRISDbits.TRISD7 =1;        //S6 on Explorer 16/32 board.
    TRISDbits.TRISD13 =1;       //S4 on Explorer 16/32 board.
    TRISAbits.TRISA6 =1;        //S5 on Explorer 16/32 board.
       
}

/**********************************************************************************************
* Name: void initT2(void) 
* Description: Configures Timer2 module on PIC32.
*              Configured Timer2 for 1:4 prescale. 
*              Configured Timer2 for maximum timeout period (interrupt every 65'537 ticks). 
* 
***********************************************************************************************/
void initT2(void)
{

	T2CONbits.TON = 0;                  //Stop Timer2 module.
	T2CONbits.TCS = 0;                  //Select internal instruction cycle clock.
	T2CONbits.TGATE = 0;                //Disable Gated Timer mode.
    T2CONbits.TCKPS = 0b010;            //Sets Timer2 module to use 1:4 prescale value.
	TMR2 = 0x00;                        //Clear Timer2 register.
	PR2=0xFFFF;                         //Sets the maximum period value (2^16).
    INTCONbits.MVEC = 1;                //SystemMultiVectored.
    __builtin_disable_interrupts();     //Disable interrupts.
	IPC2bits.T2IP = 0x01;               //Set Timer2 Interrupt Priority. 
	IFS0bits.T2IF = 0;                  //Clear Timer2 Interrupt Flag.
	IEC0bits.T2IE = 1;                  //Enable Timer2 interrupt.
    __builtin_enable_interrupts();      //Enable interrupts.
	T2CONbits.TON = 1;                  //Start Timer2 module.            

}

/**********************************************************************************************
* Name: void initCN9(void)
* Description: Configures PIC32 to handle CN interrupts.
*              Configures CN9 (pin 11) to handle interrupts on PIC32. 
* 
***********************************************************************************************/
void initCN9(void){
    
    TRISGbits.TRISG7 =1;                //Input CN9/RG7 pin 11 on PIC32.
    CNENbits.CNEN9 = 1;                 //CN9.
    __builtin_disable_interrupts();     //Disable interrupts.
    CNCONbits.ON = 1;                   //Start CN.
    IPC6bits.CNIP=2;    
    IFS1bits.CNIF=0;       
    INTCONbits.MVEC=1;
    IEC1bits.CNIE=1;
    __builtin_enable_interrupts();      //Enable interrupts.
    
}