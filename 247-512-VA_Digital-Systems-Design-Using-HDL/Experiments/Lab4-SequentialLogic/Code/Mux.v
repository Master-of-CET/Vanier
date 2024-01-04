`timescale 1ns / 1ps
/* **********************************************************************************
*	Module name: Mux.v
*	Description: Code that selects which divided MCLK should be used for ShiftRegister
*					 module. Takes multiple inputs from Counter module.
*
*	Author				Date						Revision		Comments	
*************************************************************************************
*	Leonardo Fusser	25 October 2021		v1.0.0		Created Mux.v file.
*	Leonardo Fusser	8 November 2021		v1.0.1		Completed Mux.v file.
*
*************************************************************************************/


/*Mux module*/
module Mux(
	 input A, B, C, D, MUX_CLK,	//CLK-divide (F1, F2, F3, F4) and CLK(MCLK) inputs.
	 input [1:0] MUX_SEL,			//2 MUX select inputs.
    output reg Y						//MUX output.
    );

always @(posedge MUX_CLK)
	begin
		case (MUX_SEL)
			0: Y <= A; 			//If MUX select = 0, MUX output = F1 (connected to A).
			1: Y <= B;			//If MUX select = 1, MUX output = F2 (connected to B).
			2: Y <= C;			//If MUX select = 2, MUX output = F3 (connected to C).
			3: Y <= D;			//If MUX select = 3, MUX output = F4 (connected to D).
			default: Y <= A;	//Otherwise, MUX output = F1 (connected to A).
			endcase
	end
endmodule
