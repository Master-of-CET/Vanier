`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: Lock_TB.v
*	Description: Verilog testbench for CombinationLock module. Inputs are simulated 
*					 by appling a stimulus and outputs are generated automatically.
*
*	Author	   	   	Date					Revision		Comments	
************************************************************************************
*	Leonardo Fusser	   29 November 2021	v1.0.0		Created Lock_TB.v file.
*																		Completed Lock_TB.v file.
*
************************************************************************************/

module Lock_TB;

	/*Inputs*/
	reg Lock_CLK;			//Input for CombinationLock module (simulated below).
	reg Lock_RST;			//" ".
	reg [3:0] Key_IN;		//" ".

	/*Outputs*/
	wire [7:0] LED_graph;	//Output from CombinationLock module.

	/*Instantiate the Unit Under Test (UUT)*/
	CombinationLock uut (
		.Lock_CLK(Lock_CLK), 	//Connect segments together.
		.Lock_RST(Lock_RST), 	//" ".
		.Key_IN(Key_IN), 			//" ".
		.LED_graph(LED_graph)	//" ".
	);

	/*Initialize inputs*/
	initial
		begin
			Lock_CLK = 0;
			Lock_RST = 1;	//Disables lock.
			Key_IN = 0;
			
			#10;				//Wait 10nS for global reset to finish.
			
			Lock_RST = 0;	//Enables lock.
		end
		  
	/*Stimulus*/
	always
		begin
			Key_IN = 0;					//Keypad input: 0.
			#10;
			
			Lock_CLK = ~Lock_CLK;	//Toggle MCLK.
			#10;							//Simulates 50MHz MCLK.
			Lock_CLK = ~Lock_CLK;	//Toggle MCLK.
			#10;							//Simulates 50MHz MCLK.
			
			Key_IN = 2;					//Keypad input: 2.
			#10;
			
			Lock_CLK = ~Lock_CLK;	//Toggle MCLK.
			#10;							//Simulates 50MHz MCLK.
			Lock_CLK = ~Lock_CLK;	//Toggle MCLK.
			#10;							//Simulates 50MHz MCLK.
			
			Key_IN = 8;					//Keypad input: 8.
			#10;
			
			Lock_CLK = ~Lock_CLK;	//Toggle MCLK.
			#10;							//Simulates 50MHz MCLK.
			Lock_CLK = ~Lock_CLK;	//Toggle MCLK.
			#10;							//Simulates 50MHz MCLK.
			
			Key_IN = 1;					//Keypad input: 1.
			#10;
			
			Lock_CLK = ~Lock_CLK;	//Toggle MCLK.
			#10;							//Simulates 50MHz MCLK.
			Lock_CLK = ~Lock_CLK;	//Toggle MCLK.
			#10;							//Simulates 50MHz MCLK.
			
			Key_IN = 4;					//Keypad input: 4.
			#10;
			
			Lock_CLK = ~Lock_CLK;	//Toggle MCLK.
			#10;							//Simulates 50MHz MCLK.
			Lock_CLK = ~Lock_CLK;	//Toggle MCLK.
			#10;							//Simulates 50MHz MCLK.
			
			Key_IN = 0;					//Keypad input: 0.
			#10
			
			Lock_RST = ~Lock_RST;	//Resets lock.
			Lock_CLK = ~Lock_CLK;	//Toggle MCLK.
			#10;							//Simulates 50MHz MCLK.
			Lock_RST = ~Lock_RST;	//Resets lock.
			Lock_CLK = ~Lock_CLK;	//Toggle MCLK.
			#10;							//Simulates 50MHz MCLK.
		end
endmodule
