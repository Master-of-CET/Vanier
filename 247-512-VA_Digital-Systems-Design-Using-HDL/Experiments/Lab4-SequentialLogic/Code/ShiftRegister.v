`timescale 1ns / 1ps
/* **********************************************************************************
*	Module name: ShiftRegister.v
*	Description: Code that performs an 8-bit shifting operation one way. Input is taken 
*					 from output of Mux module (selected clock divider) and is used to 
*					 determine shifting speed.
*
*	Author				Date						Revision		Comments	
*************************************************************************************
*	Leonardo Fusser	25 October 2021		v1.0.0		Created ShiftRegister.v file.
*	Leonardo Fusser	8 November 2021		v1.0.1		Completed ShiftRegister.v file.
*  Leonardo Fusser	14 November 2021		v1.0.2		Added shifting input.
*
*************************************************************************************/


/*Shift-register module*/
module ShiftRegister(
	 input SR_CLK, SR_CLR, 	//Selected CLK-divide and RST inputs. 
	 input sh_ld,				//Load enable input.
	 input [7:0] data_in,	//Shifting input.
	 output [7:0] Shift_OUT	//Shifting output.
    );

	reg [7:0] Present_8bits; //Register to store all the possible present-state shifted outputs.
	wire [7:0] Next_8bits;	 //Wire to store all the possible next-state shifted outputs.

	/*Data register*/
	always @(posedge SR_CLK or posedge SR_CLR or negedge sh_ld)
		begin
			if (SR_CLR == 1)
				Present_8bits <= 8'b00000001;
				
			else if (sh_ld == 0)
				Present_8bits <= data_in;
				
			else
				Present_8bits <= Next_8bits;
		end
	
		/*Next state logic*/
		assign Next_8bits = {Present_8bits[6:0], Shift_OUT[7]};	//1-bit shift operation.
		
		/*Output logic*/
		assign Shift_OUT = Present_8bits;	//Resulting shifted output.

endmodule
