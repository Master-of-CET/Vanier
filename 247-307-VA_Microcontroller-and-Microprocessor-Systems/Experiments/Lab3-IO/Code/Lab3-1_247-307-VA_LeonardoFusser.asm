;***********************************************************************
;*Leonardo Fusser (1946995)					       *
;*Microcontroller & Microprocessor systems, Lab3 Part A, Day Yann Fong *
;*Program to turn on a LED from pin 2 of PIC16F887 microcontroller.    *
;***********************************************************************


; [PIC config]

#include "p16f887.inc"

; CONFIG1
; __config 0x23F5
 __CONFIG _CONFIG1, _FOSC_INTRC_CLKOUT & _WDTE_OFF & _PWRTE_OFF & _MCLRE_ON & _CP_OFF & _CPD_OFF & _BOREN_ON & _IESO_OFF & _FCMEN_OFF & _LVP_OFF
; CONFIG2
; __config 0x3FFF
 __CONFIG _CONFIG2, _BOR4V_BOR40V & _WRT_OFF


; [Start of program]
 
    org	    0
    goto    Main
	
Main
    
    ;*******************************************************************************************************************
    ;[Config for PORTA]

    ;TRISA0-TRISA7
    banksel TRISA	    ; (Register that determines if pin(s) are configured as Input or Output)
    clrf    TRISA	    ; Sets RA0 to be an output.
    
    ;ANS0-ANS7
    banksel ANSEL	    ; (Register that determines if pin(s) are configured as Anolog or Digital I/O)
    clrf    ANSEL	    ; Sets RA0 to be a digital I/O.
	
    ;RA0-RA7
    banksel PORTA	    ; (Register that determines if pin(s) are configured to produce an active LOW or active HIGH)
    movlw   b'00000001'	    ; Turns on LED from RA0.
    movwf   PORTA	    ; " "
    ;********************************************************************************************************************
	
    goto $		    ; Loops forever.
	
    End
    
; [End of program]