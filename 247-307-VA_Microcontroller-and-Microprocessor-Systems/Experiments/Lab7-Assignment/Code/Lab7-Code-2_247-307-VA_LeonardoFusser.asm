;************************************************************************************************
;*Leonardo Fusser (1946995)									*
;*Microcontroller & Microprocessor systems, Lab Assignment - Part B, Day Yann Fong		*
;*This program is a 1 second 4-bit binary up-counter that displays a count from 0 to 9 on a 7-  *
;*segment display driven by a 7448 7-segment display driver on a PIC16F887.                     *
;************************************************************************************************


;[PIC config]

#include "p16F887.inc"

; CONFIG1
; __config 0x23F5
 __CONFIG _CONFIG1, _FOSC_INTRC_CLKOUT & _WDTE_OFF & _PWRTE_OFF & _MCLRE_ON & _CP_OFF & _CPD_OFF & _BOREN_ON & _IESO_OFF & _FCMEN_OFF & _LVP_OFF
; CONFIG2
; __config 0x3FFF
 __CONFIG _CONFIG2, _BOR4V_BOR40V & _WRT_OFF


;[Start of program]

    ;********************************************************************************
    ;[Variable delcarations]

    cblock	    0x70	; (Stores variables below at address 70)			
    STATUS_TEMP			; STATUS register variable (for context saving).
    W_TEMP			; Wreg variable (for context saving).
    endc
    ;********************************************************************************

    org		    0x0000      ; Address of the first program instruction.
    goto	    Main        ; Go to "Main".
       
;********************************************************************************************************************************************
;[Interrupt routine]

    ;GIE bit in INTCON is cleared upon entering this interrupt routine.

    org			0x0004			; Interrupt vector.

    movwf		W_TEMP			; Move Wreg to W_TEMP register.
    swapf		STATUS,w		; Swap STATUS register to be placed in Wreg.
    movwf		STATUS_TEMP		; Move STATUS (in Wreg) to STATUS_TEMP register.
    
    ;for UP-counter:
    ;*Note: counter (PORTA) will display 0 and count UP to 9 again if the conditions yield TRUE in Loop below.
    banksel		PORTA			; (Register that determines if pin(s) are configured to produce an active LOW or active HIGH)
    incf		PORTA,f			; Increments counter (PORTA) by 1, then result is stored in PORTA register.
    
    banksel		INTCON			; (Register that contains various interrupt controls)
    bcf			INTCON,T0IF		; Clear TMR0 overflow flag bit before returning to normal operation.
		
    swapf		STATUS_TEMP,w		; Swap STATUS_TEMP value to be placed in Wreg.
    movwf		STATUS			; Move STATUS_TEMP (in Wreg) to STATUS register.
    swapf		W_TEMP,f		; Swap W_TEMP.
    swapf		W_TEMP,w		; Swap W_TEMP value to be placed in Wreg.

    ;GIE bit in INTCON is set upon leaving this interrupt routine.

    retfie					; Return from interrupt routine.
    
;*********************************************************************************************************************************************
       
    
;******************************************************************************************************************************
;[Initialization]

Main  
    
    ;**************************************************************************************************************************
    ;[Fosc, Timer0, Interrupt control initialization]
    
    banksel	OSCCON		    ; (Oscillator control register)
    clrf	OSCCON		    ; Clear register, start from scratch.
    bsf		OSCCON,IRCF0	    ; Sets PIC's internal clock to 125 kHz (Fosc). Instruction clock is set to 31.250 kHz (Fcy).
    bsf		OSCCON,HTS	    ; HFINTOSC is set stable.
    bsf		OSCCON,LTS	    ; LFINTOSC is set stable.
    bsf		OSCCON,SCS	    ; Sets PIC to use internal oscillator for system clock.
    
    banksel     OPTION_REG	    ; (Register that sets certain parameters for Timer0 module)
    clrf	OPTION_REG	    ; Clear register, start from scratch (other parameters not mentioned below are not used).
    bcf         OPTION_REG,T0CS	    ; Sets Timer0 to count pulses from internal instruction clock cycle.      
    bcf         OPTION_REG,PSA	    ; Assigns prescale to Timer0.
    bsf		OPTION_REG,PS2	    ; Sets prescale rate to 1:128. Calculations were done in order to verify which Fosc and 
				    ; prescale was to be used in order to get 1-second delay for UP/DOWN-counter. Calculations
				    ; can be found in report attached to this Lab Assignmnet submission.
    bsf		OPTION_REG,PS1	    ; " "
    bcf		OPTION_REG,PS0	    ; " "

    banksel     INTCON		    ; (Register that contains various interrupt controls)
    clrf	INTCON		    ; Clear register, start from scratch (other parameters not mentioned below are not used).
    bsf		INTCON,GIE	    ; Enables all unmasked interrupts.
    bsf		INTCON,T0IE	    ; Enables Timer0 interrupt (used for TMR0 overflow).
    ;***************************************************************************************************************************
    
    ;***************************************************************************************************************************
    ;[Port A initialization]
    
    banksel	ANSEL		    ; (Register that determines if pin(s) are configured as Anolog or Digital I/O)
    clrf	ANSEL		    ; Sets all PORTA pins as digital.
		
    banksel	TRISA		    ; (Register that determines if pin(s) are configured as Input or Output)
    clrf	TRISA		    ; Sets all PORTA pins as output.
    
    banksel	PORTA		    ; (Register that determines if pin(s) are configured to produce an active LOW or active HIGH)
    clrf	PORTA		    ; Clears PORTA to output logical LOW. This is also where the value of the counter is stored.
    ;***************************************************************************************************************************

    ;***************************************************************************************************************************
    ;[TMR0 initialization]
    
    banksel	TMR0		    ; (Selecting 8-bit timer/counter register)
    clrf	TMR0		    ; Clear TMR0 register, start from scratch (initialization).
    ;***************************************************************************************************************************
    
;*******************************************************************************************************************************
	
    
;*********************************************************************************************************************************************
;[Main program]    
    
; Loop for checking if counter (PORTA) has reached 9.    
Loop
    
    movlw	b'00001010'	    ; 10 in binary (placed in Wreg).
    xorwf	PORTA,w		    ; Performs XOR operation between Wreg (value of 10) and value stored in PORTA (value of counter).
    btfsc	STATUS,Z	    ; Checks to see if zero flag is set (from XOR operation above), otherwise next instruction is SKIPPED.
    clrf	PORTA		    ; Clears counter back down to zero if the previous instruction yields TRUE.
    clrw			    ; Clears Wreg.
    
    ;*Note: counter (PORTA) will display 0 and count UP to 9 again if the conditions set above yield TRUE.

    goto	Loop		    ; Keep on checking to see if counter (PORTA) has reached 10.
    
;*********************************************************************************************************************************************

    End				    ; End.

;[End of program]