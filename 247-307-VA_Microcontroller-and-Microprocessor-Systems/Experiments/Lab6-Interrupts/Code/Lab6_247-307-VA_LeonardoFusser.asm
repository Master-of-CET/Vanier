;************************************************************************************************
;*Leonardo Fusser (1946995)																		*
;*Microcontroller & Microprocessor systems, Lab6, Day Yann Fong									*
;*Program that uses interupts to increment a counter when TMR0 overflows.						*
;************************************************************************************************


;[PIC config]

#include "p16F887.inc"

; CONFIG1
; __config 0x3FF5
 __CONFIG _CONFIG1, _FOSC_INTRC_CLKOUT & _WDTE_OFF & _PWRTE_OFF & _MCLRE_ON & _CP_OFF & _CPD_OFF & _BOREN_ON & _IESO_OFF & _FCMEN_OFF & _LVP_ON
; CONFIG2
; __config 0x3FFF
 __CONFIG _CONFIG2, _BOR4V_BOR40V & _WRT_OFF


;[Start of program]

		;********************************************************************************
		;[Variable delcarations]

		cblock      0x70			; (Stores variables below at address 70)			
		counter                     ; Counter varibale (used in interrupt routine below).
		STATUS_TEMP					; STATUS register variable (for context saving).
		W_TEMP						; Wreg variable (for context saving).
		endc
		;********************************************************************************

       	org         0x0000          ; Address of the first program instruction.
       	goto        Main            ; Go to "Main".
       
		;*********************************************************************************************************
		;[Interrupt routine]

		;GIE bit in INTCON is cleared upon entering this interrupt routine.

		org         0x0004          ; Interrupt vector.

		movwf		W_TEMP			; Move Wreg to W_TEMP register.
		swapf		STATUS,w		; Swap STATUS register to be placed in Wreg.
		movwf		STATUS_TEMP		; Move STATUS (in Wreg) to STATUS_TEMP register.
		
		banksel		TMR0
		incf		counter			; Increment "counter" by one when TMR0 overflow flag bit has been set (T0IF).

		banksel		INTCON
		bcf			INTCON,T0IF		; Clear TMR0 overflow flag bit before returning to normal operation.
		
		swapf		STATUS_TEMP,w	; Swap STATUS_TEMP value to be placed in Wreg.
		movwf		STATUS			; Move STATUS_TEMP (in Wreg) to STATUS register.
		swapf		W_TEMP,f		; Swap W_TEMP.
		swapf		W_TEMP,w		; Swap W_TEMP value to be placed in Wreg.

		;GIE bit in INTCON is set upon leaving this interrupt routine.

       	retfie                      ; Return from interrupt routine.
		;*********************************************************************************************************
       
;****************************************************************************************************************************
;[Main program]

Main                               	
		banksel     OPTION_REG      ; (Register that sets certain parameters for Timer0 module)
		clrf		OPTION_REG		; Clear register, start from scratch (other parameters not mentioned below are not used).
		bcf         OPTION_REG,T0CS	; Sets Timer0 to count pulses from internal instruction clock cycle.      
		bsf         OPTION_REG,PSA	; Sets prescaler to WDT, not needed for this Lab.
		
		banksel		TMR0
		clrf		TMR0			; Clear TMR0 register, start from scratch (initialization).
		clrf		counter			; Clear "counter" variable, start from scratch (initialization).

		banksel     INTCON          ; (Register that contains various interrupt controls)
		clrf		INTCON			; Clear INTCON register, strat from scracth (initialization).
		bsf			INTCON,T0IE		; Enables Timer0 interrupt (used for TMR0 overflow).
		bsf			INTCON,GIE		; Enables all unmasked interrupts.
	
Loop							

		; Waits for TMR0 to overflow. Once overflowed, T0IF bit in INTCON is set and interrupt above is executed.		

		goto		Loop			;Keep waiting for TMR0 to overflow forever.
;***************************************************************************************************************************

		End                         ; End.

;[End of program]