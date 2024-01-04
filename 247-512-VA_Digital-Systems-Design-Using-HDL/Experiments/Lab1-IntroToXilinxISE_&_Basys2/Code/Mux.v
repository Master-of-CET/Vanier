`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:11:08 08/30/2021 
// Design Name: 
// Module Name:    Mux 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////


module Mux(
	 input I0,I1,X,					//Inputs.
	 output f,f_bar					//Outputs.
    );
	 
	 wire Out_1,Out_2,X_bar;		//Nets.
	 
	 assign Out_1 = I0 & X;			//AND of I0 and X.
	 assign X_bar = ~X;				//NOT of X.
	 assign Out_2 = X_bar & I1;	//AND of X' and I1.
	 assign f = Out_1 | Out_2;		//OR of Out_1 and Out_2.
	 assign f_bar = ~f;				//NOT of f.
	 
endmodule