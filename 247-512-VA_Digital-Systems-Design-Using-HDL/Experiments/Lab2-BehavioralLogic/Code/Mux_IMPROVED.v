`timescale 1ns / 1ps

/* *********************************************************************************
*	Module name: Mux_IMPROVED.v
*	Description: HDL project that implements a 2-bit 2x1 MUX using a behavioural 
*					 approach instead of a structural approach (like in previous lab).
*
*	Author				Date						Revision		Comments	
***************************************************************
*	Leonardo Fusser	13 September 2021		v1.0.0		Created Mux_IMPROVED.v file.
*																		Implemented 2-bit 2x1 MUX using
*																		behavioural approach.
*
*************************************************************************************/


/*[2-bit 2x1 MUX module]*/
module Mux_IMPROVED(
    input [1:0] A,		//2-bit input.
    input [1:0] B,		//" ".
    input S,				//1-bit input.
    output reg [1:0] Y	//2-bit output.
    );

/*[2-bit 2x1 MUX implemented using behavioural method]*/
////////////////////////////////////////////////////////
always @(*)

if(S == 0)		//If select bit = 0...
	begin 
		Y = A;	//Output = value stored in A.
	end	

else				//If select bit = 1...
	begin
		Y = B;	//Output = value stored in B.
	end
////////////////////////////////////////////////////////


endmodule
