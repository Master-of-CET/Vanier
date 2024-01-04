`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: pulse_gen.v
*	Description: Verilog module that produces a 1Hz pulse and a 200Hz pulse. Inputs 
*					 are Baysys2 MCLK and a reset switch on Baysys2 board.
*
*	Author				Date						Revision		Comments	
************************************************************************************
*	Leonardo Fusser	15 November 2021		v1.0.0		Created pulse_gen.v file.
*	Leonardo Fusser	27 November 2021		v1.0.1		Completed pulse_gen.v file.
*
************************************************************************************/

/*pulse generator module*/
module pulse_gen(
	 input PulseGen_CLK, PulseGen_RST,		//MCLK and RESET inputs.
	 output Hz_1_pulse, Hz_200_pulse			//1Hz and 200Hz pulse outputs.
    );
	 
	 localparam CONSTANT_NUM1 = 50000000;	//1S pulse (1Hz).
	 localparam CONSTANT_NUM2 = 250000;		//5mS pulse (200Hz). 

	 /*DFFs declarations and internal wire declarations*/
	 reg [26:0] count_reg1, count_next1, count_reg2, count_next2;
	 
	 /*Data register*/
	 always @(posedge PulseGen_CLK, posedge PulseGen_RST)
		begin
			if (PulseGen_RST == 1)				//If RESET...
				begin
				count_reg1 <= 0;					//1Hz pulse reset to 0.
				count_reg2 <= 0;					//200Hz pulse reset to 0.
				end
			else										//Else...
				begin
				count_reg1 <= count_next1;		//Continue.
				count_reg2 <= count_next2;		//" ".
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
		
	always @(*)
		begin
			if (count_reg2 == CONSTANT_NUM2-1)	//If 200Hz pulse counter reached CONSTANT_NUM2...
				count_next2 <= 0;						//200Hz pulse counter is reset to 0.
			else											//Else...
				count_next2 <= count_reg2 + 1;	//Counter keeps counting.
		end
		
	 /*Output logic*/
	 assign Hz_1_pulse = (count_reg1 == 0) ? 1'b1 : 1'b0;			//If 1Hz pulse counter is reset to 0, toggle 1Hz pulse output.
	 assign Hz_200_pulse = (count_reg2 == 0) ? 1'b1 : 1'b0;		//If 200Hz pulse counter is reset to 0, toggle 200Hz pulse output.

endmodule
