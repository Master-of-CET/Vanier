`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: Lock.v
*	Description: Verilog module that creates a combination lock with a unique input
*		     		 sequence. Inputs are Baysys2 MCLK, a reset switch on Baysys2 board,
*		     		 4 pushbutton inputs and a down count value (feedback from Down_counter
*					 module). Outputs are 8 LEDs (bargraph) for combination lock input 
*					 sequence illustration and 2 control signals for down counters (for
*					 Down_counter module).
*
*  Author				Date		   		Revision		Comments	
************************************************************************************
*  Leonardo Fusser	11 December 2021   v1.0.0		Created Lock.v file.
*																	Completed Lock.v file.
*
************************************************************************************/

/*Lock module*/
module Lock(
	 input Lock_CLK, Lock_RST,						//MCLK and RESET inputs.
	 input [3:0] DownCnt,							//Down count value input (feedback from Down_counter module).
	 input wire [3:0] Key_IN,						//Keypad input.
	 output reg Lock_Timeout1, Lock_Timeout2,	//Timeout signal output for 4-second and 9-second down counter.
	 output reg [7:0] LED_graph					//LED bargraph output.
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
				State <= State_nxt;	//Continue
		end
	 	
	 /*Next state logic and output logic*/
	 always @(*)
		begin
			Lock_Timeout1 <= 1'b0;	//Implied else.
			Lock_Timeout2 <= 1'b0;	//" ".
			State_nxt <= S0;			//" ".
			case(State)					//FSM for combination lock.
				S0:															//For state 0...
					begin
						LED_graph <= 8'd128;								//Only turn on far left LED.
						if(Key_IN == 4'b0010 && DownCnt == 4'b0)	//If keypad input is 2 or Timeout has elapsed...
							begin
								Lock_Timeout1 <= 1'b1;					//Tells down counter to load 4-second down count.
								State_nxt <= S1;							//Move on to next state.
							end
						else if(Key_IN == 4'b0000)						//Otherwise, if keypad input is 0...
								State_nxt <= S0;							//Stay in this state.
					end
				
				S1:															//For state 1...
					begin
						Lock_Timeout1 <= 1'b0;							//Tells down counter to not load 4-second down count.
						LED_graph <= 8'd1;								//Only turn on far right LED.
						if(Key_IN == 4'b0010 || Key_IN == 4'b0)	//If keypad input is 2 or 0...
							State_nxt <= S1;								//Stay in this state.
						else if(Key_IN == 4'b1000)						//Otherwise, if keypad input is 8.
							State_nxt <= S2;								//Move on to next state.
					end
									
				S2:															//For state 2...
					begin
						LED_graph <= 8'd3;								//Only turn on two LEDs.
						if(Key_IN == 4'b1000 || Key_IN == 4'b0)	//If keypad input is 8 or 0...
							State_nxt <= S2;								//Stay in this state.
						else if(Key_IN == 4'b0001)						//Otherwise, if keypad input is 1.
							State_nxt <= S3;								//Move on to next state.
					end
			
				S3:															//For state 3...
					begin
						LED_graph <= 8'd7;								//Only turn on three LEDs.
						if(Key_IN == 4'b0001 || Key_IN == 4'b0)	//If keypad input is 1 or 0...
							State_nxt <= S3;								//Stay in this state.
						else if(Key_IN == 4'b0100)						//Otherwise, if keypad input is 4.
							begin
								Lock_Timeout2 <= 1'b1;					//Tells down counter to load 9-second down count.
								State_nxt <= S4;							//Move on to next state.
							end
					end
					
				S4:															//For state 4...
					begin
						Lock_Timeout2 <= 1'b0;							//Tells down counter to not load 9-second down count.
						State_nxt <= S4;									//Stays in this state UNTIL RESET HAS OCCURED.
						LED_graph <= 8'd15;								//Turn on all four LEDs (correct keypad input sequence entered).
						if(DownCnt == 4'b0000)							//If 9-second down count has elapsed...
							LED_graph <= 8'd255;							//Turn on all 8 LEDs.
					end
					
				default: 
							begin
								Lock_Timeout1 <= 1'b0;					//Implied else.
								Lock_Timeout2 <= 1'b0;					//" ".
								State_nxt <= S0;							//" ".
							end
			endcase
		end
endmodule
