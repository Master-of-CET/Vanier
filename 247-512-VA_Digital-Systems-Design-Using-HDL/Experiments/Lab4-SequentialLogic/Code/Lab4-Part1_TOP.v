`timescale 1ns / 1ps
/* **********************************************************************************
*	Module name: Lab4-Part1_TOP.v
*	Description: Top module for Part 1 of Lab 4. All connections and instantiations
*					 for all Verliog modules are performed here.
*
*	Author				Date						Revision		Comments	
*************************************************************************************
*	Leonardo Fusser	25 October 2021		v1.0.0		Created Lab4-Part1_TOP.v file.
*	Leonardo Fusser	8 November 2021		v1.0.1		Completed Lab4-Part1_TOP.v file.
*
*************************************************************************************/


/*Lab4 (Part1) TOP module*/
module Lab4Part1_TOP(
	 input MCLK,RST,		//RST and MCLK inputs.
	 output	F1,F2,F3,F4	//CLK-divide outputs.
    );

	 /*Counter module instantiation*/
	 Counter U1(
	 .COUNTER_CLK(MCLK),	//Connects to MCLK.
	 .COUNTER_RST(RST),	//Connects to RST.
	 .Hz11_92(F1),	//Connects to F1.
	 .Hz5_96(F2),	//Connects to F2.
	 .Hz2_98(F3),	//Connects to F3.
	 .Hz1_49(F4)	//Connects to F4.
	 );
	 
endmodule
