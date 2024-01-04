`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: bin2seg.v
*	Description: Verilog module to decode a 4-bit BCD input to a 7sd 7-bit digit output 
*		     		 (for patterns from 0 to F). Inputs are 4-bit BCD value from Mux module
*		     		 and Baysys2 MCLK. Output is a 7sd digit.
*
*	Author				Date					Revision		Comments	
************************************************************************************
*	Leonardo Fusser	11 December 2021	v1.0.0		Created bin2seg.v file.
*																	Completed bin2seg.v file.
*
************************************************************************************/

/*bin2seg module*/
module bin2seg(
    input [3:0] IN_bin2seg,	 //bin2seg (BCD) input.
    input bin2seg_CLK,	 	 	 //MCLK input.
    output reg [6:0] CA_to_CG	 //bin2seg (BCD to 7sd) output.	
    );

	/*bin2seg logic*/
	always @(posedge bin2seg_CLK)			
		begin
			case(IN_bin2seg)
				0: CA_to_CG <= 7'b0000001; 			//If bin2seg input is 0, output displays "0".
				1: CA_to_CG <= 7'b1001111; 			//Else if bin2seg input is 1, output displays "1".
				2: CA_to_CG <= 7'b0010010; 			//Else if bin2seg input is 2, output displays "2".
				3: CA_to_CG <= 7'b0000110; 			//Else if bin2seg input is 3, output displays "3".
				4: CA_to_CG <= 7'b1001100; 			//Else if bin2seg input is 4, output displays "4".
				5: CA_to_CG <= 7'b0100100; 			//Else if bin2seg input is 5, output displays "5".
				6: CA_to_CG <= 7'b0100000; 			//Else if bin2seg input is 6, output displays "6".
				7: CA_to_CG <= 7'b0001111; 			//Else if bin2seg input is 7, output displays "7".
				8: CA_to_CG <= 7'b0000000; 			//Else if bin2seg input is 8, output displays "8".
				9: CA_to_CG <= 7'b0000100; 			//Else if bin2seg input is 9, output displays "9".
				10: CA_to_CG <= 7'b0001000; 			//Else if bin2seg input is 10, output displays "A".
				11: CA_to_CG <= 7'b1100000; 			//Else if bin2seg input is 11, output displays "b".
				12: CA_to_CG <= 7'b0110001; 			//Else if bin2seg input is 12, output displays "C".
				13: CA_to_CG <= 7'b1000010; 			//Else if bin2seg input is 13, output displays "d".
				14: CA_to_CG <= 7'b0110000; 			//Else if bin2seg input is 14, output displays "E".
				15: CA_to_CG <= 7'b0111000; 			//Else if bin2seg input is 15, output displays "F".
				default: CA_to_CG <= 7'b0000001;		//Else, output displays "0".
			endcase
		end
endmodule
