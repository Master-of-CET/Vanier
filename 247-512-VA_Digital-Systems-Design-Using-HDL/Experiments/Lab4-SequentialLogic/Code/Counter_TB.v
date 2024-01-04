`timescale 1ns / 1ps
/* **********************************************************************************
*	Module name: Counter_TB.v
*	Description: Test bench file for Counter module in Lab 4. Used to test Counter
*					 module logic.
*
*	Author				Date						Revision		Comments	
*************************************************************************************
*	Leonardo Fusser	25 October 2021		v1.0.0		Created Counter_TB.v file.
*	Leonardo Fusser	8 November 2021		v1.0.1		Completed Counter_TB.v file.
*
*************************************************************************************/


module Counter_TB;

	//Inputs.
	reg clk;
	reg rst;

	//Outputs.
	wire _Hz11_92;
	wire Hz5_96;
	wire Hz2_98;
	wire Hz1_49;

	//Instantiate the Unit Under Test (UUT).
	Counter uut (
		.clk(clk), 
		.rst(rst), 
		._Hz11_92(_Hz11_92), 
		.Hz5_96(Hz5_96), 
		.Hz2_98(Hz2_98), 
		.Hz1_49(Hz1_49)
	);

	initial begin
	
		//Initialize Inputs.
		clk = 0;
		rst = 1;

		#10;		//Wait for 10nS.
        
		rst = 0;
		
	end
		  
		//Stimulus.
		always
			begin
			#10;				//Wait for 10nS.
			clk = ~clk;		//Toggle the clock.
			end
      
endmodule
