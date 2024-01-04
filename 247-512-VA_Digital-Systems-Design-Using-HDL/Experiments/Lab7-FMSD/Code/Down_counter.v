`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: Down_counter.v
*	Description: Verilog module for a down counter (from 9 to 0). Inputs are Baysys2
*					 MCLK, a reset switch on Baysys2 board, a 1-second pulse and 8 LEDs
*					 (feedback from Lock module). Outputs are the down counter value and
*					 7sd anode select.
*
*	Author				Date					Revision		Comments	
************************************************************************************
*	Leonardo Fusser	6 December 2021	v1.0.0		Created Down_counter.v file.
*																	Completed Down_counter.v file.
*
************************************************************************************/

/*Down_counter module*/
module Down_counter(
	 input DownCnt_PULSE, DownCnt_CLK, DownCnt_RST,	//MCLK, RESET and 1-second pulse.
	 input [7:0] LED_graph,									//8 LED input (feedback from Lock module).
	 output [3:0] DownCnt,									//Down count result output.
	 output [3:0] an											//7sd anode select.
    );

	/*DFFs and internal wire delcarations*/
	reg [3:0] CntDown_reg, CntDown_next, AN_reg, AN_next;

	/*Data register*/
	always @(posedge DownCnt_CLK, posedge DownCnt_RST)
		begin
			if(DownCnt_RST)								//If RESET...
				begin	
					AN_reg <= 4'b1111;					//Turn off all 7sd.
					CntDown_reg <= 10;					//Reset down counter to 10.
				end
			else												//Else...
				begin
					AN_reg <= AN_next;					//Continue.
					CntDown_reg <= CntDown_next;		//" ".
				end
		end

	/*Next state logic*/
	always @(*)
		begin
			AN_next <= AN_reg;				//Implied else.
			CntDown_next <= CntDown_reg;	//" ".
			if(DownCnt_PULSE)											//If 1-second pulse detected.
				begin
					AN_next <= AN_reg;					//Implied else.
					CntDown_next <= CntDown_reg;		//" ".
					if(LED_graph == 8'd15)							//If keypad input succesfull (all four LEDs on).
						begin
							AN_next <= 4'b1110;						//Turn on first 7sd.
							CntDown_next <= CntDown_reg - 1;		//Decrement count by 1.
						end
				end
		end

	/*Output logic*/
	assign an = AN_reg;					//Assign 7sd anode select value to output.
	assign DownCnt = CntDown_reg;		//Assign down count value to output.

endmodule
