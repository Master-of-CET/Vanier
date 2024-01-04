`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: PulseGen.v
*	Description: Verilog module that produces a 1Hz pulse. Inputs 
*					 are Baysys2 MCLK and a reset switch on Baysys2 board. Output is a
*					 1-second pulse.
*
*	Author				Date					Revision		Comments	
************************************************************************************
*	Leonardo Fusser	6 December 2021	v1.0.0		Created pulse_gen.v file.
*																	Completed pulse_gen.v file.
*
************************************************************************************/

/*pulse generator module*/
module PulseGen(
	 input PulseGen_CLK, PulseGen_RST,		//MCLK and RESET inputs.
	 output Hz_1_pulse							//1Hz output.
    );
	 
	 localparam CONSTANT_NUM1 = 50000000;	//1S pulse (1Hz).

	 /*DFFs declarations and internal wire declarations*/
	 reg [26:0] count_reg1, count_next1;
	 
	 /*Data register*/
	 always @(posedge PulseGen_CLK, posedge PulseGen_RST)
		begin
			if (PulseGen_RST == 1)				//If RESET...
				begin
				count_reg1 <= 0;					//1Hz pulse reset to 0.
				end
			else										//Else...
				begin
				count_reg1 <= count_next1;		//Continue.
				end
		end
		 
	 /*Next data logic*/
	 always @(*)
		begin
			if (count_reg1 == CONSTANT_NUM1-1)	//If 1Hz pulse counter reached CONSTANT_NUM1...
				count_next1 <= 0;						//1Hz pulse counter is reset to 0.
			else											//Else...
				count_next1 <= count_reg1 + 1;	//Counter keeps counting.
		end
		
	 /*Output logic*/
	 assign Hz_1_pulse = (count_reg1 == 0) ? 1'b1 : 1'b0;			//If 1Hz pulse counter is reset to 0, toggle 1Hz pulse output.

endmodule
