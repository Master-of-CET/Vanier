`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:05:32 08/30/2021
// Design Name:   Mux
// Module Name:   C:/Users/Leonardo Fusser/Documents/Xilinx/Projects/Vanier/HDL/Lab1/TestBench.v
// Project Name:  Lab1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Mux
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TestBench;

	// Inputs
	reg I0;
	reg I1;
	reg X;

	// Outputs
	wire f;
	wire f_bar;

	// Instantiate the Unit Under Test (UUT)
	Mux uut (
		.I0(I0), 
		.I1(I1), 
		.X(X), 
		.f(f), 
		.f_bar(f_bar)
	);

	initial begin
		// Initialize Inputs
		I0 = 0;
		I1 = 0;
		X = 0;

		// Wait 100 ns for global reset to finish
		//#100;
        
		// Add stimulus here
		#1; 	//Delay 1 nS. 
		I0=0;
		I1=0; 
		X=0; 
		#1; 
		I0=1; 
		I1=0; 
		X=0; 
		#1; 
		I0=0; 
		I1=1; 
		X=0; 
		#1; 
		I0=1; 
		I1=1; 
		X=0; 
		#1; 
		I0=0; 
		I1=0; 
		X=1; 
		#1; 
		I0=1; 
		I1=0; 
		X=1; 
		#1; 
		I0=0; 
		I1=1; 
		X=1; 
		#1; 
		I0=1; 
		I1=1; 
		X=1;

	end
      
endmodule