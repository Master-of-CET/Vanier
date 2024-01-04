`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: Down_counter.v
*	Description: Verilog module for a down counter (from 9 to 0 and 4 to 0). Inputs 
*					 are Baysys2 MCLK, two control signals for down counters (feedback from
*					 Lock module), a reset switch on Baysys2 board, a 1-second pulse and 
*					 8 LEDs (feedback from Lock module). Outputs are the down counter value 
*					 and 7sd anode select.
*
*	Author				Date					Revision		Comments	
************************************************************************************
*	Leonardo Fusser	11 December 2021	v1.0.0		Created Down_counter.v file.
*																	Completed Down_counter.v file.
*
************************************************************************************/

/*Down_counter module*/
module Down_counter(
	 input DownCnt_PULSE, DownCnt_CLK, DownCnt_RST, //1-second pulse, MCLK and RESET.
	 input DownCnt_Timeout1, DownCnt_Timeout2,		//4-second and 9-second down count control signal (feedback from Lock.v).
	 input [7:0] LED_graph,									//LED bargraph input (feedback from Lock.v).
	 output [3:0] DownCnt,									//Down count result output.
	 output [3:0] an											//7sd anode select.
    );

	/*DFFs and internal wire delcarations*/
	reg [3:0] CntDown_reg, CntDown_next;
	reg [3:0] AN_reg, AN_next;

	/*Data register*/
	always @(posedge DownCnt_CLK, posedge DownCnt_RST)
		begin
			if(DownCnt_RST)								//If RESET...
				begin	
					AN_reg <= 4'b1111;					//Turn off all 7sd.
					CntDown_reg <= 5;						//Reset down counter to 5 (4+1).
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
			AN_next <= AN_reg;																//Implied else.
			CntDown_next <= CntDown_reg;													//" ".
			if(LED_graph == 8'd128 && DownCnt_PULSE)									//If RESET or incorrect combination entered...		
				begin
					CntDown_next <= (CntDown_reg == 0) ? 0 : CntDown_reg - 1;	//Count down from 4.
					AN_next <= (CntDown_reg == 0) ? 4'b1111: 4'b1110;				//Keep 7sd ON until down count reached 0.
				end
			else if(LED_graph == 8'd15 && DownCnt_PULSE)								//If correct combination entered...
				begin
					CntDown_next <= (CntDown_reg == 0) ? 0 : CntDown_reg - 1;	//Count down from 9.
					AN_next <= (CntDown_reg == 0) ? 4'b1111 : 4'b1110;				//Keep 7sd ON until down count reached 0.
				end
			else if(LED_graph == 8'd255 && DownCnt_PULSE)							
					AN_next <= (CntDown_reg == 0) ? 4'b1111 : 4'b1110;				//Keep 7sd ON until down count reached 0.
			else if(DownCnt_Timeout1)														//If control signal to load 4-second down count...
				begin
					AN_next <= 4'b1111;														//Keep 7sd off.
					CntDown_next <= 5;														//Load 4-second down count value.
				end
			else if(DownCnt_Timeout2)														//If control signal to load 9-second down count...
				begin
					AN_next <= 4'b1111;														//Keep 7sd off.
					CntDown_next <= 10;														//Load 9-second down count value.
				end
		end
		
	/*Output logic*/
	assign an = AN_reg;					//Assign 7sd anode select value to output.
	assign DownCnt = CntDown_reg;		//Assign down count value to output.

endmodule
