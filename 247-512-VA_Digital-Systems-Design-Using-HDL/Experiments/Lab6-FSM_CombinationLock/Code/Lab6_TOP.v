`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: Lab6_TOP.v
*	Description: Verilog top module for Lab6. All needed modules are instantiated
*					 below. Inputs are Baysys2 MCLK and a reset switch on Baysys2 board.
*					 Outputs are 8 LEDs (bargraph) for combination lock.
*
*	Author				Date						Revision		Comments	
************************************************************************************
*	Leonardo Fusser	29 November 2021		v1.0.0		Created Lab6_TOP.v file.
*																		Completed Lab6_TOP.v file.
*
************************************************************************************/

/*Lab6_TOP module*/
module Lab6_TOP(
	 input MCLK, RESET,	//MCLCK and RESET inputs.
	 input [3:0] btn,		//Pushbutton inputs.
	 output [7:0] LED		//LED bargraph output.
    );

	 /*CombinationLock module instantiation*/
	 CombinationLock U1(
		.Lock_CLK(MCLK),	//Provides MCLK as input to module.
		.Lock_RST(RESET),	//Provides RESET as input to module.
		.Key_IN(btn),		//Provides pushbuttons as input to module.
		.LED_graph(LED)	//Takes LED bargraph as output from module.
	 );

endmodule
