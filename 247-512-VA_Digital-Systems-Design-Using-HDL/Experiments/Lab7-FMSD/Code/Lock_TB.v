`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: Lock_TB.v
*	Description: Verilog testbench for Lock module. Inputs are simulated by appling 
*					 a stimulus and outputs are generated automatically.
*
*	Author	   	   	Date					Revision		Comments	
************************************************************************************
*	Leonardo Fusser	   12 December 2021	v1.0.0		Created Lock_TB.v file.
*																		Completed Lock_TB.v file.
*
************************************************************************************/

/*Lock_TB module*/
module Lock_TB;

	/*Inputs*/
	reg Lock_CLK;			//Input for CombinationLock module (simulated below).
	reg Lock_RST;			//" ".
	reg [3:0] DownCnt;	//" ".
	reg [3:0] Key_IN;		//" ".

	/*Outputs*/
	wire [7:0] LED_graph;	//Output from Lock module.

	/*Instantiate the Unit Under Test (UUT)*/
	Lock uut (
		.Lock_CLK(Lock_CLK),		//Connect segments together.
		.Lock_RST(Lock_RST), 	//" ".
		.DownCnt(DownCnt), 		//" ".
		.Key_IN(Key_IN), 			//" ".
		.LED_graph(LED_graph)	//" ".
	);

	/*Initialize inputs*/
	initial 
		begin
			Lock_CLK = 0;
			Lock_RST = 1;	//Disables lock.
			DownCnt = 9;
			Key_IN = 0;
			#10;				//Wait 10nS for global reset to finish.
			Lock_RST = 0;	//Enables lock.
		end
		
	/*Stimulus*/
	always
		begin
			Lock_CLK = ~Lock_CLK;	//Toggle MCLK.
			#10;							//Small delay.
			Lock_CLK = ~Lock_CLK;	//Toggle MCLK again.
			#10;							//Simulates 50MHz MCLK.
		end
		
	always
		begin
			Key_IN = 0;		//Keypad input: 0.
			#30;				//Small delay.
			
			Key_IN = 2;		//Keypad input: 2.
			#30;				//Small delay.
			
			Key_IN = 8;		//Keypad input: 8.
			#30;				//Small delay.
			
			Key_IN = 1;		//Keypad input: 1.
			#30;				//Small delay.
			
			Key_IN = 4;		//Keypad input: 4.
			#30;				//Small delay.
		
			Key_IN = 0;		//Resets keypad input to 0.
			#5500;			//Long delay.
		end
	
	always
		begin
			DownCnt = 9;	//Count down value: 9.
			#500;				//Small delay.
			
			DownCnt = 8;	//Count down value: 8.
			#500;				//Small delay.
			
			DownCnt = 7;	//Count down value: 7.
			#500;				//Small delay.
			
			DownCnt = 6;	//Count down value: 6.
			#500;				//Small delay.
			
			DownCnt = 5;	//Count down value: 5.
			#500;				//Small delay.
			
			DownCnt = 4;	//Count down value: 4.
			#500;				//Small delay.
			
			DownCnt = 3;	//Count down value: 3.
			#500;				//Small delay.
			
			DownCnt = 2;	//Count down value: 2.
			#500;				//Small delay.
			
			DownCnt = 1;	//Count down value: 1.
			#500;				//Small delay.
			
			DownCnt = 0;	//Count down value: 0.
			#500;				//Small delay.
			
			Lock_RST = ~Lock_RST;	//Resets lock.
			#10;							//Small delay.
			Lock_RST = ~Lock_RST;	//Resets lock.
			
			DownCnt = 9;	//Resets count down value to 9.
			#5500;			//Long delay.
		end
		
endmodule
