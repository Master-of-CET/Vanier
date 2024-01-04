`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: Lab3B.v
*	Description: This code implements the logic for a typical 7sd to display '0' to
*					 'F' on multiple 7sd, based on select input switches and pushbuttons.
*
*	Author				Date						Revision		Comments	
***************************************************************
*	Leonardo Fusser	27 September 2021		v1.0.0		Created Lab3B.v file.
*																		Completed Lab3B.v file.
*
*************************************************************************************/

module Lab3B(
    input [3:0] SW,				//4-bit input.
    output reg [6:0] CA_to_CG	//7-bit output.
    );

always @(*)
	begin
		case(SW)
			0: CA_to_CG = 7'b0000001; //Displays '0'.
			1: CA_to_CG = 7'b1001111; //Displays '1'.
			2: CA_to_CG = 7'b0010010; //Displays '2'.
			3: CA_to_CG = 7'b0000110; //Displays '3'.
			4: CA_to_CG = 7'b1001100; //Displays '4'.
			5: CA_to_CG = 7'b0100100; //Displays '5'.
			6: CA_to_CG = 7'b0100000; //Displays '6'.
			7: CA_to_CG = 7'b0001111; //Displays '7'.
			8: CA_to_CG = 7'b0000000; //Displays '8'.
			9: CA_to_CG = 7'b0000100; //Displays '9'.
			10: CA_to_CG = 7'b0001000; //Displays 'A'.
			11: CA_to_CG = 7'b1100000; //Displays 'b'.
			12: CA_to_CG = 7'b0110001; //Displays 'C'.
			13: CA_to_CG = 7'b1000010; //Displays 'd'.
			14: CA_to_CG = 7'b0110000; //Displays 'E'.
			15: CA_to_CG = 7'b0111000; //Displays 'F'.
			default: CA_to_CG = 7'b0000001; //Displays '0'.
		endcase
	end
	
endmodule
