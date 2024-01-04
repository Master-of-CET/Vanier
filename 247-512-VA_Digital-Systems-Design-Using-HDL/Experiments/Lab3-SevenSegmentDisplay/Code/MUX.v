`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: MUX.v
*	Description: This code implements the logic for a typical 7sd to display '0' to
*					 'F' on two 7sd, each indepently controlled and based on two groups
*					 of select input switches.
*
*	Author				Date						Revision		Comments	
***************************************************************
*	Leonardo Fusser	27 September 2021		v1.0.0		Created MUX.v file.
*	Leonardo Fusser	4 October 2021			v1.0.1		Completed MUX.v file.
*
*************************************************************************************/

module MUX(
	 input [3:0] A,		//4-bit mux input.
    input [3:0] B,		//4-bit mux input.
    input [0:0] S,		//1-bit mux select input.
    output reg [3:0] Y	//4-bit mux output.
    );
	 
	/*MUX logic*/
	always @(*)
		if(S == 0)		//If mux select bit = 0...
			begin 
				Y = A;	//Mux output = value stored in A.
			end	
		else				//If mux select bit = 1...
			begin
				Y = B;	//Mux output = value stored in B.
			end
			
endmodule
