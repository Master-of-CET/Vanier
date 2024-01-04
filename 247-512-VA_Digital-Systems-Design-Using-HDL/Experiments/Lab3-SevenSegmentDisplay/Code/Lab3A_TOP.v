`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: Lab3A_TOP.v
*	Description: This code implements the logic for a typical 7sd to display '0' to
*					 'F' on the 7sd, based on select inputs.
*
*	Author				Date						Revision		Comments	
***************************************************************
*	Leonardo Fusser	20 September 2021		v1.0.0		Created Lab3A_TOP.v file.
*																		Completed Lab3A_TOP.v file.
*
*************************************************************************************/

module Lab3A_TOP(
	input [3:0] sw,	//4-bit select input.
	output [6:0] seg,	//7-bit select output.
	output [3:0] an	//4-bit select output.
   );

	assign an = 4'b0000;	//Initializes all 4 7sd to be off.
	
	/*Instantiation for simple 7sd*/
	Lab3A U1(
		.B(sw),			//Connects 4 inputs (in Lab3A.v) to 4 select inputs.
		.CA_to_CG(seg)	//Connects 7 outputs (in Lab3A.v) to 7 select outputs.
	);

endmodule
