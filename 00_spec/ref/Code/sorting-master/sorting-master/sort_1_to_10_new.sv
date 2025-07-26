module sort_1_to_10_new #(parameter WIDTH = 16, BLOCK = 0)
					 (input [WIDTH-1:0] a,
					  input [3:0] a_id,
					  input [WIDTH-1:0] array[9:0],
					  input [1:0] flag,
					  //input [3:0] layer,i,
					  //input [1:0] flag[9:0],
					  //input [3:0] i,layer,
					  output reg signed[7:0] index,
					  output [WIDTH-1:0] a_out,
					  output [3:0] a_id_out,
					  output reg [1:0] flag_new);
	
	localparam 
	init=2'b00, 
	less=2'b01, 
	fit=2'b10, 
	larger=2'b11;
	wire signed [7:0] tmpindex;
	
	findIndex #(.WIDTH(WIDTH)) m_findIndex
			   (.array10(array),
			    .tmpa(a),
				.LOW(10*BLOCK),
				.index(tmpindex));
				
	setFlagIndex #(.BLOCK(BLOCK)) m_setting
				  (.flag_old(flag),
				   .flag_new(flag_new),
				   .index(tmpindex),
				   .index_new(index));
	
	assign a_out = a;
	assign a_id_out = a_id;
	
endmodule


module setFlagIndex #(parameter BLOCK = 0)
					 (input [1:0]flag_old,
					  input signed[7:0] index,
					  output reg[1:0] flag_new,
					  output reg signed[7:0] index_new);
					  
	localparam 
	init=2'b00, 
	less=2'b01, 
	fit=2'b10, 
	larger=2'b11;
	integer low = BLOCK*10;
	integer high = BLOCK*10 + 1;
	always @(*)
	begin
		case(flag_old)
		init:
		begin
			flag_new = (index==8'b11111111)?less:
							  (index>high)?larger:fit;
			index_new = index;
		end
		less:
		begin
			flag_new = (BLOCK==0)?fit:
							  (index==8'b11111111)?less:fit;
			index_new = (BLOCK==0)?0:index;
		end
		larger:
		begin
			flag_new = (BLOCK==9)?fit:
							  (index==8'b11111111)?fit:
							  (index>high)?larger:fit;
			index_new = (BLOCK==9)?100:
							  (index==8'b11111111)?low:index;
		end
		fit:
		begin
			flag_new = flag_old;
			index_new = index;
		end
		endcase
	end
endmodule
	