;******************************************************************************************************
;*Leonardo Fusser (1946995)									      *
;*Microcontroller & Microprocessor systems, Lab4 - Part B Q10, Day Yann Fong			      *
;*Program to flash 4 LEDs from pins 2-5 at 50% duty cycle with longer delay on PIC16F887.             *
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


;****************************************************
;[Constant declarations]
 
LEDs_HIGH   equ b'00001111'  ;Value when LEDs are ON.
LEDs_LOW    equ b'00000000'  ;Value when LEDs are OFF.
;*****************************************************
 
    ;****************************************************************************************************************
    ;[Variable declarations]
   
    cblock   0x20	      ;Stores variables at address 0x20 in GPR.
    Counter1		      ;Variable for software delay (in subroutine "Delay") - inner loop counter.
    Counter2		      ;Variable for software delay (in subroutine "Delay") - outer loop counter (nested loop).
    endc
    ;****************************************************************************************************************
   
    org	    0		      ;Reset vector.
    goto    Main	      ;Goto "Main".
    
Main
    
    ;***************************************************************************************************************
    ;[Config for internal oscillator]
    
    banksel OSCCON	    ;(Oscillator control register)
    movlw   b'00000111'	    ;Sets internal clock rate to 31 kHz (IRCF<2:0> = 000) Fosc = 31 kHz.
			    ;(SCS is set for internal oscillator for system clock, LTS is stable, HTS is stable, OSTS
			    ; is set for internal oscillator HFINTOSC or LFINTOSC)
    movwf   OSCCON
    ;****************************************************************************************************************
    
    ;****************************************************************************************************************
    ;[Config for PORTA]
    
    ;TRISA0-TRISA7
    banksel TRISA	    ;(Register that determines if pin(s) are configured as Input or Output)
    clrf    TRISA	    ;Sets RA0, RA1, RA2, RA3 to be an output.
    
    ;ANS0-ANS7
    banksel ANSEL	    ;(Register that determines if pin(s) are configured as Anolog or Digital I/O)
    clrf    ANSEL	    ;Sets RA0, RA1, RA2, RA3 to be a digital I/O.
    ;*****************************************************************************************************************
    
    
;********************************************************************************************************************** 
;(Begin LED ON/OFF procedure)    
Start	
    
    ;RA0 - RA7
    banksel PORTA	    ;(Register that determines if pin(s) are configured to produce an active LOW or active HIGH)
    movlw   LEDs_HIGH	    ;Sets RA0, RA1, RA2 and RA3 to turn ON.
    movwf   PORTA	    ;" "
    
    call    Delay	    ;Goto subroutine (software delay) - to keep LEDs ON for a certain amount of time - 50% ON**!
    
    banksel PORTA	    ;(Register that determines if pin(s) are configured to produce an active LOW or active HIGH)
    movlw   LEDs_LOW	    ;Sets RA0, RA1, RA2 and RA3 to turn OFF.
    movwf   PORTA	    ;" "
    
    call    Delay	    ;Goto subroutine (software delay) - to keep LEDs OFF for a certain amount of time - 50% OFF**!
    
    goto    Start	    ;Repeat LED ON/OFF procedure (go back to "Start" and start procedure over).
    
    
;(Subroutine - software delay)    
Delay
    
    movlw   h'02'	    ;2 in hex.
    movwf   Counter2	    ;Load 2 into outer loop counter (used for outer loop below).

;(Loop that creates 2nd extended delay for LEDs - nested loop)  
Loop2
    
    movlw   h'FF'	    ;255 in hex.
    movwf   Counter1	    ;Load 255 into inner loop counter (used for inner loop below).
    
;(Loop that creates 1st delay for LEDs)  
Loop1    
    
    decfsz  Counter1	    ;Decrement "Counter1" until value is 0.
    goto    Loop1	    ;Goto "Loop1" in order to keep decrementing "Counter1".
			    ;(Note: this instruction is SKIPPED if "Counter1" is 0, creating a NOP instruction)
			    
    decfsz  Counter2	    ;Decrement "Counter2" until value is 0.
    goto    Loop2	    ;Goto "Loop2" in order to keep decrementing "Counter2".
			    ;(Note: this instruction is SKIPPED if "Counter2" is 0, creating a NOP instruction)
    
    return		    ;Return to point where subroutine was originally called from.
;*********************************************************************************************************************
    
    End			    ;End
    
    ;[End of program]
    
;**Subroutine "Delay" creates a software delay for LEDs to remain ON or OFF. The time it takes to keep the LEDs on or
; OFF is dependent on what Fosc is set at. For example, if Fosc is set for 31 kHz, the delay generated will keep the LEDs ON or OFF
; for 197.80 mS. If Fosc is set to another value other than 31 kHz, calculations will need to be done in order to determine how
; long the subroutine "Delay" will generate a delay for the LEDs to remain ON or OFF. This software delay is based of off the
; nested loop technique.