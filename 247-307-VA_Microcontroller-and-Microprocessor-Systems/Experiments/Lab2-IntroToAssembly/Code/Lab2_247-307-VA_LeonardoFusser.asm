;LEONARDO FUSSER (1946995)
    

    
; PIC16F887 Configuration Bit Settings

; Assembly source line config statements

#include "p16f887.inc"

; CONFIG1
; __config 0x23F5
 __CONFIG _CONFIG1, _FOSC_INTRC_CLKOUT & _WDTE_OFF & _PWRTE_OFF & _MCLRE_ON & _CP_OFF & _CPD_OFF & _BOREN_ON & _IESO_OFF & _FCMEN_OFF & _LVP_OFF
; CONFIG2
; __config 0x3FFF
 __CONFIG _CONFIG2, _BOR4V_BOR40V & _WRT_OFF

;*************************************************************
;   declare constant
 
CONST1 equ	3ch
CONST2 equ b'00101001'

;*************************************************************
 
;*************************************************************
;   declare variables
 
    cblock  0x20
    var1
    
    endc
;*************************************************************
    
    org	    0
    
    movlw   .123
    clrw
    
    movlw   CONST1
    addlw   'F'
    xorlw   CONST2
    
    movwf   var1
    rlf	    var1,w
    
    goto $					; loop forever
    
    end