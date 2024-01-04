/***********************************************************************************************
*
*
* FileName:  initBoard.c      
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date            Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould      14 Jan. 2021		v1.0.0      Setup for PIC32    
* 
*
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#include "initBoard.h"

 // Configuration Bit settings
// SYSCLK = 80 MHz 
//(8MHz Crystal/ FPLLIDIV * FPLLMUL / FPLLODIV)
// PBCLK = 40 MHz
// Primary Osc w/PLL (HS+PLL)
// WDT OFF, Peripheral Bus is CPU clock÷8
// Other options are default as per datasheet
// see file:C:\Program Files (x86)\Microchip\xc32\v1.40\docs\config_docs\32mx795f512l.html
 

#pragma config FPLLMUL = MUL_20
#pragma config FPLLIDIV = DIV_2
#pragma config FPLLODIV = DIV_1 
#pragma config POSCMOD = HS, FNOSC = PRIPLL
#pragma config FPBDIV = DIV_2   // PBCLK = SYSCLK/DIV_2
//#pragma config WDTPS =  PS4096 // Post Scaler  32kHz/32/4096  target
#pragma config WDTPS =  PS256 // Post Scaler  32kHz/32/8  simulation
#pragma config FWDTEN =  OFF // 

/* Sets up the IOs */
void initIO(void)
{
    /* LEDs */
    TRISAbits.TRISA6= 0;    //Led9
    TRISAbits.TRISA5 = 0;    //Led8
    
         /*PMOD I/Os tris*/
    TRISGbits.TRISG9 = 0;    //Dir P14
    TRISGbits.TRISG8 = 0;    //EN P12
    TRISGbits.TRISG7 = 1;    //SA channel P11
    TRISGbits.TRISG6 = 1;    //SB channel P10
 
     /*PMOD I/Os setting*/
    LATGbits.LATG9 =1;  //dir
    LATGbits.LATG8 =1;  //EN
       
}

