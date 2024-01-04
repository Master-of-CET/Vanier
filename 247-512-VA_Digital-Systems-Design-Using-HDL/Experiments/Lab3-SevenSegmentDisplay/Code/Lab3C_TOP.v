`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: Lab3C_TOP.v
*	Description: This code implements the logic for a typical 7sd to display '0' to
*					 'F' on two 7sd, each indepently controlled and based on two groups
*					 of select input switches.
*
*	Author				Date						Revision		Comments	
***************************************************************
*	Leonardo Fusser	20 September 2021		v1.0.0		Created Lab3C_TOP.v file.
*																		Completed Lab3C_TOP.v file.
*
*************************************************************************************/

module Lab3C_TOP(
	input [3:0] swA,	//4-bit select input (A sw group).
	input [3:0] swB,	//4-bit select input (B sw group).
	input [0:0] mclk,	//1-bit select input (Basys2 clock).
	output [6:0] seg,	//7-bit select output (for 7sd).
	output [3:0] an	//4-bit select output (for 7sd select).
   );
	
	wire a,b;		//Wire.
	wire [3:0] z;	//Wire.
	
	assign an[0] = 1'b1;	//Turns off first 7sd.
	assign an[1] = 1'b1;	//Turns off second 7sd.
	assign an[2] = b;		//Interface between "INVERTER" to third 7sd.
	assign an[3] = a;		//Interace between "INVERTER", "MUX" and "COUNTER" to fourth 7sd.
		
	/*Instantiation for 2x1 MUX*/
	MUX U1(
		.A(swA),	//Connects MUX input 'A' to input sw group 'A'.
		.B(swB),	//Connects MUX input 'B' to input sw group 'B'.
		.S(a),	//Connects MUX select input 'S' to wire 'a'.
		.Y(z)		//Connects MUX output 'Y' to wire 'z'.
	);
	
	/*Instantiation for clock*/
	COUNTER U2(
		.clk(mclk),	//Connects COUNTER input 'clk' to input 'mclk'.
		.div_out(a)	//Connects COUNTER output 'div_out' to wire 'a'.
	);
	
	/*Instantiation for binary-segment decoder*/
	bin2seg U3(
		.IN_bin2seg(z),	//Connects bin2seg input 'IN_bin2seg' to wire 'z'.
		.CA_to_CG(seg)		//Connects bin2seg output 'CA_to_CG' to output 'seg'.
	);
	
	/*Instantiation for inverter*/
	INVERTER U4(
		.IN(a),		//Connects INVERTER input 'IN' to wire 'a'.
		.IN_INV(b)	//Connects INVERTER output 'IN_INV' to wire 'b'.
	);

endmodule
