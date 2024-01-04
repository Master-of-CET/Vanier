/******************************************************************************
*   Description: Generates square waves at 3kHz or 100Hz at pin RG13
*		
******************************************************************************/

#include "generator.h"
#include <stdint.h>
#include <xc.h>
#include <sys/attribs.h>
/*
 *  Generator output
 * 
*/
void __ISR( _TIMER_3_VECTOR, IPL1SOFT) T3InterruptHandler( void){
    IFS0bits.T3IF=0; 
    LATGbits.LATG13 ^=1; // square wave at RG13 (pin 97)
} // T3 Interrupt Handler
/*
 *  Function that sets timer3 at 3kHz
 * 
*/


void initT3_3kHz( void)
{
    T3CONbits.ON = 0; // turn off Timer3
    T3CONbits.TGATE = 0; // not gated input (the default)
    T3CONbits.TCS = 0; // PCBLK input (the default)
    T3CONbits.TCKPS = 0b000; // set prescaler 1:1
    TMR3 = 0x00; // Clear timer register
    PR3 = 13333; // 80 000 000/(3000Hz*2) = 13333  for two toggles per cycle
    INTCONbits.MVEC=1; //SystemMultiVectored
    __builtin_disable_interrupts();   // disable interrupts 
    IPC3bits.T3IP=1;  
    IFS0bits.T3IF=0;  
    IEC0bits.T3IE=1;
    __builtin_enable_interrupts();   // enable interrupts	
    T3CONbits.ON = 1; // turn on Timer3
}

/*
 *  Function that sets timer3 at 100Hz
 * 
*/
void initT3_100Hz( void)
{
    T3CONbits.ON = 0; // turn off Timer3
    T3CONbits.TGATE = 0; // not gated input (the default)
    T3CONbits.TCS = 0; // PCBLK input (the default)
    T3CONbits.TCKPS = 0b011; // set prescaler 8:1
    TMR3 = 0x00; // Clear timer register
    PR3=50000; // (80M/8)/(100Hz*2) = 50000
    INTCONbits.MVEC=1; //SystemMultiVectored
    __builtin_disable_interrupts();   // disable interrupts 
    IPC3bits.T3IP=1;  
    IFS0bits.T3IF=0;  
    IEC0bits.T3IE=1;
    __builtin_enable_interrupts();   // enable interrupts	
    T3CONbits.ON = 1; // turn on Timer3
}
