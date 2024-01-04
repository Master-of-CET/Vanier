`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: INVERTER.v
*	Description: This code implements the logic for a typical 7sd to display '0' to
*					 'F' on two 7sd, each indepently controlled and based on two groups
*					 of select input switches.
*
*	Author				Date						Revision		Comments	
***************************************************************
*	Leonardo Fusser	27 September 2021		v1.0.0		Created INVERTER.v file.
*	Leonardo Fusser	4 October 2021			v1.0.1		Completed INVERTER.v file.
*
*************************************************************************************/

module INVERTER(
		input [0:0] IN,		//1-bit inverter input.
		output [0:0] IN_INV	//1-bit inverter output.
    );

	/*INVERTER logic*/
	assign IN_INV = ~IN;

endmodule
