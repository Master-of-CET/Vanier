;******************************************************************************************************
;*Leonardo Fusser (1946995)									      *
;*Microcontroller & Microprocessor systems, Lab5, Day Yann Fong					      *
;*Program that uses PIC's Timer0 as counter for 4-bit binary counter using push-button and 4 LEDs.    *										              *
;******************************************************************************************************


;[PIC config]

#include "p16f887.inc"

; CONFIG1
; __config 0x23F5
 __CONFIG _CONFIG1, _FOSC_INTRC_CLKOUT & _WDTE_OFF & _PWRTE_OFF & _MCLRE_ON & _CP_OFF & _CPD_OFF & _BOREN_ON & _IESO_OFF & _FCMEN_OFF & _LVP_OFF
; CONFIG2
; __config 0x3FFF
 __CONFIG _CONFIG2, _BOR4V_BOR40V & _WRT_OFF
 
 
;[Start of program]
   
    org	    0		      ;Reset vector.
    goto    Main	      ;Goto "Main".
    
Main
    
    ;****************************************************************************************************************
    ;[Config for OPTION]
    
    banksel OPTION_REG	    ;(Register that sets certain parameters for TMR0)
    movlw   b'00111000'	    ;Sets TMR0 as counter (T0CS = 1), no prescaler (PSA = 1), increments counter on high-to-low
			    ;transition from push-button (TOSE = 1) and remaining parameters are not used.
    movwf   OPTION_REG	    ;" "
    ;****************************************************************************************************************
    
    ;****************************************************************************************************************
    ;[Config for PORTA]
    
    ;TRISA0-TRISA7
    banksel TRISA	    ;(Register that determines if pin(s) are configured as Input or Output)
    bcf	    TRISA,0	    ;Sets RA0 to output.
    bcf	    TRISA,1	    ;Sets RA1 to output.
    bcf	    TRISA,2	    ;Sets RA2 to output.
    bcf	    TRISA,3	    ;Sets RA3 to output.
    
    ;ANS0-ANS7
    banksel ANSEL	    ;(Register that determines if pin(s) are configured as Anolog or Digital I/O)
    bcf	    ANSEL,0	    ;Sets RA0 to digital.
    bcf	    ANSEL,1	    ;Sets RA1 to digital.
    bcf	    ANSEL,2	    ;Sets RA2 to digital.
    bcf	    ANSEL,3	    ;Sets RA3 to digital.
    ;*****************************************************************************************************************
    
    banksel TMR0	    ;(Selecting 8-bit timer/counter register)
    clrf    TMR0	    ;Clears TMR0 upon reset - initialization.
    
;*********************************************************************************************************************    
;(Loop for displaying LEDs based on counter - TMR0)    
Loop
    
    banksel TMR0	    ;(Selecting 8-bit timer/counter register)
    movf    TMR0,0	    ;Moves value stored in TMR0 to working register.
    
    ;RA0 - RA7
    banksel PORTA	    ;(Selects PORTA register)
    movwf   PORTA	    ;Move value from TMR0 (placed in wreg) to PORTA.
    
    banksel TMR0	    ;(Selecting 8-bit timer/counter register)
    btfsc   TMR0,4	    ;Checks to see if bit 4 in TMR0 register is set to 1 (otherwise next instruction is SKIPPED)...
    clrf    TMR0	    ;Clears TMR0 if previous result yields TRUE.
    
    goto    Loop	    ;Repeat process forever.
;**********************************************************************************************************************
    
    End			    ;End
    
    ;[End of program]