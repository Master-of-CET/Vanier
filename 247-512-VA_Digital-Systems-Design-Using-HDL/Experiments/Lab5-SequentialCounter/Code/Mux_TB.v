`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: MUX_TB.v
*	Description: Verilog testbench for Mux module. Inputs are simulated by appling a
*					 stimulus and outputs are generated automatically.
*
*	Author				Date						Revision		Comments	
************************************************************************************
*	Leonardo Fusser	22 November 2021		v1.0.0		Created MUX_TB.v file.
*																		Completed MUX_TB.v file.
*
************************************************************************************/

module Mux_TB;

	/*Inputs*/
	reg MUX_1Hz;   //Input for Mux module (simulated below).
	reg MUX_200Hz;	//" ".
	reg MUX_CLK;   //" ".
	reg MUX_RST;   //" ".

	/*Outputs*/
	wire [3:0] MUX_digit; //Output from Mux module (generated automatically).
	wire [3:0] MUX_an;	 //" ".
	wire MUX_dp;			 //" ".

	/*Instantiate the Unit Under Test (UUT)*/
	Mux uut (
		.MUX_1Hz(MUX_1Hz), 		//Connect segments together.
		.MUX_200Hz(MUX_200Hz),  //" ".
		.MUX_CLK(MUX_CLK),		//" ". 
		.MUX_RST(MUX_RST), 		//" ".
		.MUX_digit(MUX_digit),  //" ".
		.MUX_an(MUX_an), 			//" ".
		.MUX_dp(MUX_dp)			//" ".
	);
	
	initial 
		begin
		
		/*Initialize Inputs*/
		MUX_1Hz = 0;
		MUX_200Hz = 0;
		MUX_CLK = 0;
		MUX_RST = 1;	//Disable timer.

		#10;				//Wait 10 ns for global reset to finish.
		
		MUX_RST = 0;	//Enable timer.
      
		end
		
		/*Stimulus*/
		always
			begin
				#10;									//MCLK period of 20nS.
				MUX_CLK = ~MUX_CLK;				//Toggles MCLK.	
			end
			
		always
			begin
				#1000000000							//Counter period of 1S (1Hz) for mm:ss timer.
				MUX_1Hz = ~MUX_1Hz;				
				#20									//Creates 1S pulse for 20nS (pulse width of 1 MCLK cycle).
				MUX_1Hz = 0;						//Resets counter.
			end
			
		always
			begin
				#5000000								//MUX counter period of 5mS (200Hz) to toggle between all four 7sd on Baysys2 board.
				MUX_200Hz = ~MUX_200Hz;
				#20									//Creates 5mS pulse for 20nS (pulse width of 1 MCLK cycle).
				MUX_200Hz = 0;						//Resets MUX counter pulse.
			end
      
endmodule
