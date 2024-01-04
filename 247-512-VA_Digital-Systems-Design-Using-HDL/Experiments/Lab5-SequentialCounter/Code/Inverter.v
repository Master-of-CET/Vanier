`timescale 1ns / 1ps

module Inverter(
		input IN,		//1-bit inverter input.
		output IN_INV	//1-bit inverter output.
    );

	/*INVERTER logic*/
	assign IN_INV = ~IN;

endmodule
