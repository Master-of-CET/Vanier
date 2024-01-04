`timescale 1ns / 1ps
/* **********************************************************************************
*	Module name: Counter.v
*	Description: Code that allows Basys2 MCLK to be divided by certain values. These 
*					 divided clocks are used as input to the Mux module.
*
*	Author				Date						Revision		Comments	
*************************************************************************************
*	Leonardo Fusser	25 October 2021		v1.0.0		Created Counter.v file.
*	Leonardo Fusser	8 November 2021		v1.0.1		Completed Counter.v file.
*
*************************************************************************************/


/*Counter module*/
module Counter(
    input COUNTER_CLK, COUNTER_RST,				//CLK(MCLK) and RST inputs.
	 output Hz11_92, Hz5_96, Hz2_98, Hz1_49	//CLK-divide outputs.
	 );
	 
	 reg [24:0] Q;			//Register to store all the possible present-state CLK outputs.
	 wire [24:0] Q_next;	//Wire to store all the possible next-state CLK outputs.
	 
	 /*Data register*/
	 always @(posedge COUNTER_CLK or posedge COUNTER_RST)
			begin
				if(COUNTER_RST == 1) Q <= 0;
				else Q <= Q_next;
			end
		
			/*Next state logic*/
			assign	Q_next = Q+1;
				
			/*Output logic*/
			assign	Hz11_92 = Q[21];	//clk/2^(22+1).
			assign	Hz5_96 = Q[22];	//clk/2^(23+1).
			assign 	Hz2_98 = Q[23];	//clk/2^(24+1).
			assign	Hz1_49 = Q[24];	//clk/2^(25+1).
			
endmodule
