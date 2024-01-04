`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: CombinationLock.v
*	Description: Verilog module that creates a combination lock with a unique input
*					 sequence. Inputs are Baysys2 MCLK, a reset switch on Baysys2 board
*					 and 4 pushbutton inputs. Outputs are 8 LEDs (bargraph) for combination
*					 lock input sequence illustration.
*
*	Author				Date						Revision		Comments	
************************************************************************************
*	Leonardo Fusser	29 November 2021		v1.0.0		Created CombinationLock.v file.
*																		Completed CombinationLock.v file.
*
************************************************************************************/

/*CombinationLock module*/
module CombinationLock(
	 input Lock_CLK, Lock_RST,		//MCLK and RESET inputs.
	 input wire [3:0] Key_IN,		//Keypad input.
	 output reg [7:0] LED_graph	//LED bargraph output.
    );
	 
	 localparam S0 = 3'd0, S1 = 3'd1, S2 = 3'd2, S3 = 3'd3, S4 = 3'd4;	//All 5 states needed for combination lock FSM.

	 /*DFFs and internal wire declaration*/
	 reg [2:0] State, State_nxt;
	 
	 /*State register*/
	 always @(posedge Lock_CLK, posedge Lock_RST)
	 	begin
	 		if(Lock_RST)				//If RESET...
				State <= S0;			//Reset lock.
	 		else							//Else...
	 			State <= State_nxt;	//Continue.
	 	end
	 	
	 /*Next data logic and output logic*/
	 always @(*)
		begin
			case(State)								//FSM for combination lock.
				S0:									//For state 0...
					begin
						LED_graph <= 8'd128;		//Only turn on far left LED.
						if(Key_IN == 4'b0010)	//If keypad input is 2...
							State_nxt <= S1;		//Move on to next state.
						else							//Else...
							State_nxt <= S0;		//Stay in this state.
					end
				
				S1:															//For state 1...
					begin
						LED_graph <= 8'd1;								//Only turn on far right LED.
						if(Key_IN == 4'b0010 || Key_IN == 4'b0)	//If keypad input is 2 or 0...
							State_nxt <= S1;								//Stay in this state.
						else if(Key_IN == 4'b1000)						//Otherwise, if keypad input is 8.
							State_nxt <= S2;								//Move on to next state.
						else													//Else...
							State_nxt <= S0;								//Go back to state 0.
					end
									
				S2:															//For state 2...
					begin
						LED_graph <= 8'd3;								//Only turn on two LEDs.
						if(Key_IN == 4'b1000 || Key_IN == 4'b0)	//If keypad input is 8 or 0...
							State_nxt <= S2;								//Stay in this state.
						else if(Key_IN == 4'b0001)						//Otherwise, if keypad input is 1.
							State_nxt <= S3;								//Move on to next state.
						else													//Else...
							State_nxt <= S0;								//Go back to state 0.
					end
				
				S3:															//For state 3...
					begin
						LED_graph <= 8'd7;								//Only turn on three LEDs.
						if(Key_IN == 4'b0001 || Key_IN == 4'b0)	//If keypad input is 1 or 0...
							State_nxt <= S3;								//Stay in this state.
						else if(Key_IN == 4'b0100)						//Otherwise, if keypad input is 4.
							State_nxt <= S4;								//Move on to next state.
						else													//Else...
							State_nxt <= S0;								//Go back to state 0.
					end
					
				S4:															//For state 4...
					begin
						LED_graph <= 8'd15;								//Turn on all four LEDs (correct keypad input sequence entered).
						State_nxt <= S4;									//Stay in this state UNTIL RESET HAS OCCURED.
					end
					
				default: State_nxt <= S0;								//For all other cases, move on to state 0.
			endcase
		end
endmodule
