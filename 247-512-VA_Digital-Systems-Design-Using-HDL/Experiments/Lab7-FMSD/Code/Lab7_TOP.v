`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: Lab7_TOP.v
*	Description: Verilog top module for Lab7. All needed modules are instantiated
*		     		 below. Inputs are Baysys2 MCLK, a reset switch on Baysys2 board and
*					 four pushbuttons. Outputs are a 7sd digit, AN select (for selecting 
*					 7sd on Baysys2 board) and 8 LEDs. 
*
*	Author	       	Date		     		Revision		Comments	
************************************************************************************
*	Leonardo Fusser   6 December 2021   v1.0.0		Created Lab7_TOP.v file.
*																	Completed Lab7_TOP.v file.
*
************************************************************************************/

/*Lab7_TOP module*/
module Lab7_TOP(
    input MCLK, RESET,	//MCLK and RESET inputs.
	 input [3:0] btn,		//Pushbutton inputs.
	 output [7:0] LED,	//LED outputs.
	 output [6:0] seg,	//7sd digit output.
	 output [3:0] AN		//7sd anode select output.
	 );

/*Internal wire declarations*/
wire pulse;					//1-second pulse.
wire [3:0] down_cnt;		//Down count value.
wire [7:0] led_graph;	//Pushbutton input sequence illustration.

assign LED = led_graph;	//Connects led_graph to LED outputs.

/*PulseGen module instantiation*/
PulseGen U1(
	.PulseGen_CLK(MCLK),		//Provides MCLK as input to module.
	.PulseGen_RST(RESET),	//Provides RESET as input to module.
	.Hz_1_pulse(pulse)		//Takes 1-second pulse as output from module.
);

/*Down_counter module instatiation*/
Down_counter U2(
	.DownCnt_CLK(MCLK),		//Provides MCLK as input to module.
	.DownCnt_RST(RESET),		//Provides RESET as input to module.
	.DownCnt_PULSE(pulse),	//Provides 1-second pulse as input to module.
	.LED_graph(led_graph),	//Provides led_graph as input to module.
	.DownCnt(down_cnt),		//Takes down count value as output from module.
	.an(AN)						//Takes 7sd anode select as output from module.
);

/*Lock module instantiation*/
Lock U3(
	.Lock_CLK(MCLK),			//Provides MCLK as input to module.
	.Lock_RST(RESET),			//Provides RESET as input to module.
	.DownCnt(down_cnt),		//Provides down count value as input to module.
	.Key_IN(btn),				//Provides pushbuttons as input to module.
	.LED_graph(led_graph)	//Takes led_graph as output from module.
);

/*bin2seg module instantiation*/
bin2seg U4(
	.bin2seg_CLK(MCLK),		//Provides MCLK as input to module.
	.IN_bin2seg(down_cnt),	//Provides down count value as input to module.
	.CA_to_CG(seg)				//Takes 7sd digit value as output from module.
);

endmodule
