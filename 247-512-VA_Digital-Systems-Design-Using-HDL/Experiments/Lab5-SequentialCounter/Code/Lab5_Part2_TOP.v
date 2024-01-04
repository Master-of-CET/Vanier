`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: Lab5_Part2_TOP.v
*	Description: Verilog top module for Lab5-Part 2. All needed modules are instantiated
*					 below. Inputs are Baysys2 MCLK and a reset switch on Baysys2 board.
*					 Outputs are a 7sd digit, AN select (for selecting 7sd on Baysys2 board)
*					 and a decimal point. 
*
*	Author				Date						Revision		Comments	
************************************************************************************
*	Leonardo Fusser	15 November 2021		v1.0.0		Created Lab5_Part2_TOP.v file.
*	Leonardo Fusser	27 November 2021		v1.0.1		Completed Lab5_Part2_TOP.v file.
************************************************************************************/

/*Lab5_Part2_TOP module*/
module Lab5_Part2_TOP(
	 input MCLK, RESET,	//MCLCK and RESET inputs.
	 output [6:0] seg,	//7sd digit output.
	 output [3:0] an,		//Selected 7sd AN output.
	 output dp				//7sd decimal point output.
    );
	 
	 /*Internal wire declarations*/
	 wire hz1, hz200;
	 wire [3:0] digit_mux;

	 /*pulse_gen module instantiation*/
	 pulse_gen U1(
		.PulseGen_CLK(MCLK),		//Provides MCLK as input to module.
		.PulseGen_RST(RESET),	//Provides RESET as input to module.
		.Hz_1_pulse(hz1),			//Takes 1Hz pulse as output from module.
		.Hz_200_pulse(hz200)		//Takes 200Hz pulse as output from module.
	 );
	
	 /*Mux module instantiation*/
	 Mux U2(
		.MUX_CLK(MCLK),			//Provides MCLK as input to module.
		.MUX_RST(RESET),			//Provides RESET as input to module.
		.MUX_1Hz(hz1),				//Provides 1Hz pulse as input to module.
		.MUX_200Hz(hz200),		//Provides 200Hz pulse as input to module.
		.MUX_digit(digit_mux),	//Takes selected 7sd digit as output from module.
		.MUX_an(an),				//Takes selected 7sd AN as output from module.
		.MUX_dp(dp)					//Takes selected 7sd decimal point as output from module.
	 );
	
	 /*bin2seg module instantiation*/
	 bin2seg U3(
		.bin2seg_CLK(MCLK),		//Provides MCLK as input to module.
		.IN_bin2seg(digit_mux),	//Provides selected 7sd digit as input to module.
		.CA_to_CG(seg)				//Takes selected 7sd digit as output from module.
	 );

endmodule
