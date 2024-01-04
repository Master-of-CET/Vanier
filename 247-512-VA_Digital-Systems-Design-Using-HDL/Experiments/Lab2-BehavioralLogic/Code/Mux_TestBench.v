`timescale 1ns / 1ps

/* ***********************************************************************************
*	Module name: Mux_TestBench.v
*	Description: HDL project that implements a 2-bit 2x1 MUX using a behavioural 
*					 approach instead of a structural approach (like in previous lab).
*
*	Author				Date						Revision		Comments	
***************************************************************
*	Leonardo Fusser	13 September 2021		v1.0.0		Created Mux_TestBench.v file.
*																		Added stimuli to test all output
*																		possibilities for 2-bit 2x1 MUX.
*
**************************************************************************************/


	//[2-bit 2x1 MUX module]
	module Mux_TestBench;
		reg [1:0] A;		//2-bit input.
		reg [1:0] B;		//" ".
		reg S;				//1-bit input.
		wire [1:0] Y;		//2-bit output.

	//[Instantiate the Unit Under Test (UUT)]
	Mux_IMPROVED uut (
		.A(A), 
		.B(B), 
		.S(S), 
		.Y(Y)
	);

	integer i;	//Loop variable.

	//[Simualtion initialization]
	initial begin
		A = 0;	//Initialize to 0.
		B = 0;	//" ".
		S = 0;	//" ".

		#10;		//Wait 10 ns for global reset to finish.
		
		for(i=0; i<32; i=i+1)
			begin
				{S,A,B} = i;	//Contactenation.
				#10;				//Wait 10 ns for global reset to finish.	
			end

	end
      
endmodule
