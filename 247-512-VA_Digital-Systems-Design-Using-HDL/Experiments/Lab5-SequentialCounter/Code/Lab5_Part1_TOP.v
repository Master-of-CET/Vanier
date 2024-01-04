`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: Lab5_Part1_TOP.v
*	Description: Verilog top module for Lab5-Part 1. All needed modules are instantiated
*					 below. Inputs are Baysys2 MCLK and a reset switch on Baysys2 board.
*					 Outputs are 8 LEDs. 
*
*	Author				Date						Revision		Comments	
************************************************************************************
*	Leonardo Fusser	15 November 2021		v1.0.0		Created Lab5_Part1_TOP.v file.
*	Leonardo Fusser	27 November 2021		v1.0.1		Completed Lab5_Part1_TOP.v file.
************************************************************************************/

module Lab5_Part1_TOP(
    input MCLK, RESET,	//MCLCK and RESET inputs.
	 output [7:0] LED		//8 LED outputs.
	 );
	 
	 /*Internal wire declarations*/
	 wire pulse;
	 
	 /*pulse_gen module instantiation*/
	 pulse_gen U1(
		.PulseGen_CLK(MCLK),		//Provides MCLK as input to module.
		.PulseGen_RST(RESET),	//Provides RESET as input to module.
		.Hz_1_pulse(pulse)		//Takes 1Hz pulse as output from module.
	 );

	/*counter_8_bits module instantiation*/
	counter_8_bits U2(
		.Counter_CLK(MCLK),		//Provides MCLK as input to module.
		.Counter_PULSE(pulse),	//Receives 1Hz pulse as input to module.
		.Counter_RST(RESET),		//Provides RESET as input to module.
		.Counter_OUT(LED)			//Takes counter output as output from module.
	);

endmodule
