;******************************************************************************************************
;*Leonardo Fusser (1946995)									      *
;*Microcontroller & Microprocessor systems, Lab3 Part B, Day Yann Fong				      *
;*Program to turn off a LED from pin 2 of PIC16F887 microcontroller if push-button is pressed.        *
;******************************************************************************************************


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
    
    ;******************************************************************************************************
    ;[Config for PORTA]
    
    ;TRISA0-TRISA7
    banksel TRISA	    ; (Register that determines if pin(s) are configured as Input or Output)
    clrf    TRISA	    ; Sets RA0 to be an output.
    
    ;ANS0-ANS7
    banksel ANSEL	    ; (Register that determines if pin(s) are configured as Anolog or Digital I/O)
    clrf    ANSEL	    ; Sets RA0 to be a digital I/O.
    ;******************************************************************************************************
    
    ;******************************************************************************************************
    ;[Config for PORTB]
    
    ;TRISB0-TRISB7
    banksel TRISB	    ; (Register that determines if pin(s) are configured as Input or Output)
    movlw   b'00000001'	    ; Sets RB0 to be an input.
    movwf   TRISB	    ; " "
    
    ;ANS8-ANS13
    banksel ANSELH	    ; (Register that determines if pin(s) are configured as Anolog or Digital I/O)
    clrf    ANSELH	    ; Sets RB0 to be a digital I/O.
    ;******************************************************************************************************

;**********************************************************************************************************
    ;[Do...]
    
    ;RA0-RA7
    banksel PORTA	    ; (Register that determines if pin(s) are configured to produce an active LOW or active HIGH)
    movlw   b'00000001'	    ; Initially turns on LED from RA0 (Assuming that push-button is not initially pressed).
    movwf   PORTA	    ; " "

;[While...]
Loop

    btfss   PORTB,0	    ; If push-button is pressed (TRUE/FALSE)...(checks PORTB bit 0 status)
    bcf	    PORTA,0	    ; Turns off LED (sets RA0 to active LOW) (Note: this instruction is SKIPPED if the result from previous one yields FALSE).
    
    btfsc   PORTB,0	    ; If push-button isn't pressed (TRUE/FALSE)...(checks PORTB bit 0 status)
    bsf	    PORTA,0	    ; Turns on LED (sets RA0 to active HIGH) (Note: this instruction is EXECUTED if the result from previous one yields TRUE).
    
    goto Loop		    ; Loops forever.
    
    End
;**********************************************************************************************************

; [End of program]