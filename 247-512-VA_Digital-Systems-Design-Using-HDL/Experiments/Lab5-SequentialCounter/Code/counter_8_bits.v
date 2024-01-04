`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: counter_8_bits.v
*	Description: Verilog module to create an 8-bit counter (from 0 to 255). Inputs are
*					 a pulse for the counter (counts each time there is a pulse), a counter
*					 reset switch on Baysys2 board and MCLK from Baysys2 board. Output is
*					 8-bit result of the counter.
*
*	Author				Date						Revision		Comments	
************************************************************************************
*	Leonardo Fusser	15 November 2021		v1.0.0		Created counter_8_bits.v file.
*	Leonardo Fusser	22 November 2021		v1.0.1		Completed counter_8_bits.v file.
*
************************************************************************************/

/*8-bit counter module*/
module counter_8_bits(
    input Counter_PULSE, Counter_RST, Counter_CLK,	//Pulse, RESET and MCLK inputs.
	 output [7:0] Counter_OUT								//8-bit counter output.
	 );

	/*DFFs declarations and internal wire declarations*/
	reg [7:0] count_reg, count_next;
	
	/*Data register*/
	always @(posedge Counter_CLK, posedge Counter_RST)
		begin
			if(Counter_RST == 1)				//If RESET...
				count_reg <= 0;				//Reset counter to 0.
			else									//Else...
				count_reg <= count_next;	//Continue.
		end
		
	/*Next state logic*/
	always @(*)
		begin
			if(Counter_PULSE == 1)				//If pulse detected...
				count_next <= count_reg + 1;	//Counter counts up by 1.
			else										//Else...
				count_next <= count_reg;		//Continue.
		end
	
	/*Output logic*/
	assign Counter_OUT = count_reg;			//Assign 8-bit counter result to output.

endmodule
