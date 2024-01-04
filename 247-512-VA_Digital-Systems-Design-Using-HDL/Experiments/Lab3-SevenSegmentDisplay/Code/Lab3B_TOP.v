`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: Lab3B_TOP.v
*	Description: This code implements the logic for a typical 7sd to display '0' to
*					 'F' on multiple 7sd, based on select input switches and pushbuttons.
*
*	Author				Date						Revision		Comments	
***************************************************************
*	Leonardo Fusser	20 September 2021		v1.0.0		Created Lab3B_TOP.v file.
*																		Completed Lab3B_TOP.v file.
*
*************************************************************************************/

module Lab3B_TOP(
	input [3:0] sw,		//4-bit select input.
	input [3:0] btn,		//4-bit select input.
	output [6:0] seg,		//7-bit select output.
	output [3:0] an		//4-bit select output.
   );
	
	assign an = ~btn;		//7sd select logic.
	
	/*Instantiation for simple 7sd*/
	Lab3B U1(
		.SW(sw),			//Connects 4 inputs (in Lab3B.v) to 4 select inputs.
		.CA_to_CG(seg)	//Connects 7 outputs (in Lab3B.v) to 7 select outputs.
	);	

endmodule
