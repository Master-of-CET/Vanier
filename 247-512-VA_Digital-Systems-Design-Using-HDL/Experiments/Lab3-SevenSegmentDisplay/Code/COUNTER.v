`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: COUNTER.v
*	Description: This code implements the logic for a typical 7sd to display '0' to
*					 'F' on two 7sd, each indepently controlled and based on two groups
*					 of select input switches.
*
*	Author				Date						Revision		Comments	
***************************************************************
*	Leonardo Fusser	27 September 2021		v1.0.0		Created COUNTER.v file.
*	Leonardo Fusser	4 October 2021			v1.0.1		Complete COUNTER.v file.
*
*************************************************************************************/

module COUNTER(
    input [0:0] clk,			//1-bit clock input.
    output [0:0] div_out	//1-bit clock output.
    );
	 
reg [18:0] CNT;

	/*COUNTER logic*/
	always @(posedge clk)
		
		begin
			CNT <= CNT +1;
		end
		
		assign div_out=CNT[18]; 	//Clock output tapped for 96 Hz
		//assign div_out=CNT[23];	//Clock output tapped for 2.98Hz
      
endmodule
