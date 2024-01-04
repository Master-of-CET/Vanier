`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: PulseGen_TB.v
*	Description: Verilog testbench for pulse_gen module. Inputs are simulated by 
*               appling a stimulus and outputs are generated automatically.
*
*	Author				Date						Revision		Comments	
************************************************************************************
*	Leonardo Fusser	15 November 2021		v1.0.0		Created PulseGen_TB.v file.
*																		Completed PulseGen_TB.v file.
*
************************************************************************************/

module PulseGen_TB;

	/*Inputs*/
	reg PulseGen_CLK;	//Input for PulseGen module (simulated below).
	reg PulseGen_RST;	//" ".

	/*Outputs*/
	wire Hz_1_pulse;	 //Output from PulseGen module (generated automatically).
	wire Hz_200_pulse; //" ".

	/*Instantiate the Unit Under Test (UUT)*/
	pulse_gen uut (
		.PulseGen_CLK(PulseGen_CLK),	//Connect segments together.
		.PulseGen_RST(PulseGen_RST),	//" ".
		.Hz_1_pulse(Hz_1_pulse),		//" ".
		.Hz_200_pulse(Hz_200_pulse)	//" ".
	);

	initial 
		begin
		
		/*Initialize Inputs*/
		PulseGen_CLK = 0;
		PulseGen_RST = 1;	//Disables pulse generator.

		#10; 					//Wait 10ns for global reset to finish.
		
		PulseGen_RST = 0;	//Enables pule generator.
		  
		end
		  
		/*Stimulus*/
		always
			begin
				#10;									//MCLK period of 20nS.
				PulseGen_CLK = ~PulseGen_CLK;	//Toggles MCLK.
			end
			
endmodule
