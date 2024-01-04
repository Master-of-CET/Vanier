`timescale 1ns / 1ps
/* *********************************************************************************
*	Module name: Mux.v
*	Description: Verilog module for a 1-second counter/timer up to 1-hour. Inputs are
*					 Baysys2 MCLK, a reset switch on Baysys2 board, 1Hz pulse and 200Hz
*					 pulse from pulse_gen module. Outputs are a 4-bit BCD value (for 7sd 
*				    digit), AN select (for selecting 7sd on Baysys2 board) and a 
*               decimal point.
*
*	Author				Date						Revision		Comments	
************************************************************************************
*	Leonardo Fusser	15 November 2021		v1.0.0		Created Mux.v file.
*	Leonardo Fusser	27 November 2021		v1.0.1		Completed Mux.v file.
*
************************************************************************************/

/*Mux module*/
module Mux(
	 input MUX_1Hz, MUX_200Hz, MUX_CLK, MUX_RST,	//1Hz pulse, 200Hz pulse, MLCK and RESET inputs.
    output [3:0] MUX_digit, MUX_an,					//7sd digit and selected AN (for Baysys2 four 7sd) outputs.
	 output MUX_dp											//7sd decimal point output.
    );
	 
	/*DFFs declarations*/
	reg [3:0] Sec_TenCount_reg, Sec_UnitCount_reg, Min_TenCount_reg, Min_UnitCount_reg;
	reg [1:0] MUX_cnt_reg;
	
	/*Internal wire declarations*/
	reg [3:0] Sec_TenCount_next, Sec_UnitCount_next, Min_TenCount_next, Min_UnitCount_next;
	wire [1:0] MUX_cnt_nxt;
	
	/*Initial block*/
	initial
		begin
		Sec_TenCount_reg = 4'b0; Sec_UnitCount_reg = 4'b0; Min_TenCount_reg = 4'b0; Min_UnitCount_reg = 4'b0;
		MUX_cnt_reg = 2'b0;
		end
	 
	/*Data register*/
	always @(posedge MUX_CLK, posedge MUX_RST)
		if(MUX_RST)								//If RESET...
			begin
				Sec_TenCount_reg <= 4'b0;	//Second Ten's counter is reset to 0.
				Sec_UnitCount_reg <= 4'b0;	//Second Unit's counter is reset to 0.
				Min_TenCount_reg <= 4'b0;	//Minute Ten's counter is reset to 0.
				Min_UnitCount_reg <= 4'b0;	//Minute Unit's counter is reset to 0.
				MUX_cnt_reg <= 2'b0;			//MUX's counter is reset to 0.
			end
		else												 				//Else...
			begin
				Sec_TenCount_reg <= Sec_TenCount_next;	    	//Continue.
				Sec_UnitCount_reg <= Sec_UnitCount_next;	 	//" ".
				Min_TenCount_reg <= Min_TenCount_next;			//" ".
				Min_UnitCount_reg <= Min_UnitCount_next;		//" ".
				MUX_cnt_reg <= MUX_cnt_nxt;		 		 		//" ".
			end
			
	/*Next state logic*/
	always @(*)
		begin
			Sec_UnitCount_next <= Sec_UnitCount_reg;	//Implied else.
			Sec_TenCount_next <= Sec_TenCount_reg;		//" ".
			Min_UnitCount_next <= Min_UnitCount_reg;	//" ".
			Min_TenCount_next <= Min_TenCount_reg;		//" ".
			
			/*1-second mm:ss counter logic block*/
			if(MUX_1Hz)
				begin
					if(Sec_UnitCount_reg == 4'd9)
						begin
							Sec_UnitCount_next <= 4'd0;
							if(Sec_TenCount_reg == 4'd5)
								begin
									Sec_TenCount_next <= 4'd0;
									if(Min_UnitCount_reg == 4'd9)
										begin
											Min_UnitCount_next <= 4'd0;
											if(Min_TenCount_reg == 4'd5)
												Min_TenCount_next <= 4'd0;
											else
												Min_TenCount_next <= Min_TenCount_reg + 1;
										end
									else
										Min_UnitCount_next <= Min_UnitCount_reg + 1;
								end
							else
								Sec_TenCount_next <= Sec_TenCount_reg + 1;
						end
					else
						Sec_UnitCount_next <= Sec_UnitCount_reg + 1;
				end
		end
		
	/*MUX counter logic block (for toggling between all four 7sd on Baysys2 board*/
	assign MUX_cnt_nxt = (MUX_200Hz) ? MUX_cnt_reg + 1 : MUX_cnt_reg;
	
	/*Output logic*/ 	
	assign MUX_an = (MUX_RST) ? 4'b0000 : (MUX_cnt_reg == 2'b00 ? 4'b1110 : (MUX_cnt_reg == 2'b01 ? 4'b1101 : (MUX_cnt_reg == 2'b10 ? 4'b1011 : 4'b0111)));
	assign MUX_digit = (MUX_cnt_reg == 2'b00) ? Sec_UnitCount_reg : (MUX_cnt_reg == 2'b01 ? Sec_TenCount_reg : (MUX_cnt_reg == 2'b10 ? Min_UnitCount_reg : Min_TenCount_reg));
	assign MUX_dp = (MUX_cnt_reg == 2'b00) ? 1'b1: (MUX_cnt_reg == 2'b01 ? 1'b1 : (MUX_cnt_reg == 2'b10 ? 1'b0: 1'b1));
		
endmodule
