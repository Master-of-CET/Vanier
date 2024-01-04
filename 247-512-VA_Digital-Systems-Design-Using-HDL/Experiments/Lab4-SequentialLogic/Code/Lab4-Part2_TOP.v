`timescale 1ns / 1ps
/* **********************************************************************************
*	Module name: Lab4-Part2_TOP.v
*	Description: Top module for Part 2 of Lab 4. All connections and instantiations
*					 for all Verliog modules are performed here.
*
*	Author				Date						Revision		Comments	
*************************************************************************************
*	Leonardo Fusser	25 October 2021		v1.0.0		Created Lab4-Part2_TOP.v file.
*	Leonardo Fusser	8 November 2021		v1.0.1		Completed Lab4-Part2_TOP.v file.
*
*************************************************************************************/


/*Lab4 (Part2) TOP module*/
module Lab4Part2_TOP(
	 input [1:0] SW,		//CLK-divide select input switches.
	 input RST, MCLK,		//RST and MCLK inputs.
	 output [7:0] LED		//Shifting LED outputs.
    );
	 
	wire clk_sel, F1, F2, F3, F4;	//Selected CLK-divide output wire and CLK-divide input wires.

	/*Counter module instantiation*/
	Counter U1(
		.COUNTER_CLK(MCLK), //Connects to MCLK.
		.COUNTER_RST(RST),  //Connects to RST.
		.Hz11_92(F1),		  //Connects to F1.
		.Hz5_96(F2),		  //Connects to F2.
		.Hz2_98(F3),		  //Connects to F3.
		.Hz1_49(F4)			  //Connects to F4.
	);
	
	/*MUX module instantiation*/
	Mux U2(
		.MUX_CLK(MCLK),	  //Connects to MCLK.
		.MUX_SEL(SW),		  //Connects to CLK-divide select input switches.
		.A(F1),				  //Connects to F1.
		.B(F2),				  //Connects to F2.
		.C(F3),				  //Connects to F3.
		.D(F4),				  //Connects to F4.
		.Y(clk_sel)			  //Connects to clk_sel.
	);
	
	/*ShiftRegister module instantiation*/
	ShiftRegister U3(
		.SR_CLK(clk_sel),	  //Connects to clk_sel.
		.SR_CLR(RST),		  //Connects to RST.
		.Shift_OUT(LED)	  //Connects to shifting LED outputs.
	);

endmodule
