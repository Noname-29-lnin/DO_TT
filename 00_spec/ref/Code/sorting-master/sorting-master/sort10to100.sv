module sort10to100 #(parameter WIDTH = 16)
					(input [WIDTH-1:0] a[9:0],
					 input [WIDTH-1:0] array[99:0],
					 output [WIDTH-1:0] result[99:0]);
	
	/*a and array are all sorted*/
	
	//FLAG:
	//00----INITIAL
	//01----LESS
	//10----FIT
	//11----LARGER
	localparam init=2'b00, less=2'b01, fit=2'b10, larger=2'b11;
	wire[109:0]notempty = 110'b0;
	reg [9:0] notempty_index = 10'b0;
	reg signed[7:0] index[9:0];	//0~109
	wire [WIDTH-1:0] newarray [109:0];
	
	//output of stage_0
	wire [1:0]flag0[9:0];
	wire [WIDTH-1:0]a_out_0[9:0];
	wire [3:0] a_id_out_0[9:0];
	wire signed[7:0]index0[9:0];
	wire [9:0] use_out_0;
	/* wire [1:0]flag_up_1[8:0];wire [1:0]flag_down_1[8:0];
	wire [1:0]flag_up_2[7:0];wire [1:0]flag_down_2[7:0];
	wire [1:0]flag_up_3[6:0];wire [1:0]flag_down_3[6:0];
	wire [1:0]flag_up_4[5:0];wire [1:0]flag_down_4[5:0];
	wire [1:0]flag_up_5[4:0];wire [1:0]flag_down_5[4:0];
	wire [1:0]flag_up_6[3:0];wire [1:0]flag_down_6[3:0];
	wire [1:0]flag_up_7[2:0];wire [1:0]flag_down_7[2:0];
	wire [1:0]flag_up_8[1:0];wire [1:0]flag_down_8[1:0];
	wire [1:0]flag_up_9[0:0];wire [1:0]flag_down_9[0:0]; */
	
	//PORT for stage_0~9
	//DATA: a
	//ID: a_id
	//INDEX: index
	//FLAG: flag
	//USE FLAG: use
	wire [1:0]flag_up[9:0][9:0];
	wire [1:0]flag_down[9:0][9:0];
	wire signed[7:0]index_up[9:0][9:0];
	wire signed[7:0]index_down[9:0][9:0];
	wire [WIDTH-1:0]a_up[9:0][9:0];
	wire [WIDTH-1:0]a_down[9:0][9:0];
	wire [WIDTH-1:0]a_up_id[9:0][9:0];
	wire [WIDTH-1:0]a_down_id[9:0][9:0];
	wire [WIDTH-1:0]use_up[9:0][9:0];
	wire [WIDTH-1:0]use_down[9:0][9:0];
	
	
	
	
	singleStage_0 #(WIDTH) m_stage_0(.a(a),
									 .array(array),
									 .flag(flag0),
									 .index(index0),
									 .a_out(a_out_0),
									 .a_id_out(a_id_out_0),
									 .use_out(use_out_0));
	
	singleStage_1 #(WIDTH) m_stage_1(.a(a_out_0),
									 .a_id(a_id_out_0),
									 .array(array),
									 .flag(flag0),
									 .use_in(use_out_0),
									 .a_up_out(a_up[1][8:0]),
									 .a_down_out(a_down[1][8:0]),
									 .index_up(index_up[1][8:0]),
									 .index_down(index_down[1][8:0]),
									 .flag_up_out(flag_up[1][8:0]),
									 .flag_down_out(flag_down[1][8:0]),
									 .a_up_id_out(a_up_id[1][8:0]),
									 .a_down_id_out(a_down_id[1][8:0]),
									 .use_up_out(use_up[1][8:0]),
									 .use_down_out(use_down[1][8:0]));	
	generate
	genvar i;
	for(i=2;i<10;i++)
	begin: generate_stages
	singleStage_i #(.WIDTH(WIDTH),.numofblock(10-i)) 
		   m_stage_2(.a_up(a_up[i-1][10-i:0]),
					.a_down(a_down[i-1][10-i:0]),
					.a_up_id(a_up_id[i-1][10-i:0]),
					.a_down_id(a_down_id[i-1][10-i:0]),
					.array(array),
					.use_up(use_up[i-1][10-i:0]),
					.use_down(use_down[i-1][10-i:0]),
					.flag_up_in(flag_up[i-1][10-i:0]),
					.flag_down_in(flag_down[i-1][10-i:0]),
					.a_up_out(a_up[i][9-i:0]),
					.a_down_out(a_down[i][9-i:0]),
					.a_up_id_out(a_up_id[i][9-i:0]),
					.a_down_id_out(a_down_id[i][9-i:0]),
					.index_up(index_up[i][9-i:0]),
					.index_down(index_down[i][9-i:0]),
					.flag_up_out(flag_up[i][9-i:0]),
					.flag_down_out(flag_down[i][9-i:0]),
					.use_up_out(use_up[i][9-i:0]),
					.use_down_out(use_down[i][9-i:0]));
	end
	endgenerate	

	generate 
		genvar j;
		genvar k;
		for(j=0;j<10;j++)		//stage
		begin: get_final_index
			for(k=0;k<10;k++)	//block
			begin: get_index
				always @(*)
				begin
					if(j==0)
						begin
						if(flag0[k]==fit)
							begin
							index[a_id_out_0[k]]<=index0[k];
							notempty_index[a_id_out_0[k]]<=1'b1;
							end
						end
					else
						begin
						if(flag_up[j]==fit)
							begin
							index[a_up_id[k]]<=index[j][k];
							notempty_index[a_up_id[k]]<=1'b1;
							end
						else if(flag_down==fit)
							begin
							index[a_down_id[k]]<=index[j][k];
							notempty_index[a_down_id[k]]<=1'b1;	
							end
						end	
				end
			end
		end
	endgenerate
	
	combine #(WIDTH) m_combine(.a(a),.array(array),.index(index),.array_new(result));
	
endmodule

module singleStage_0 #(parameter WIDTH = 16)
					  (input [WIDTH-1:0] a[9:0],
					   input [WIDTH-1:0] array[99:0],
					   output [1:0] flag[9:0],
					   output signed[7:0]index[9:0],
					   output [WIDTH-1:0] a_out[9:0],
					   output [3:0] a_id_out[9:0],
					   output [9:0]use_out);
	
	localparam init=2'b00, less=2'b01, fit=2'b10, larger=2'b11;
	wire [1:0] flag_init[9:0];
	generate
		genvar i;
		for(i=0;i<10;i++)
		begin :loop
			assign flag_init[i] = init;
		end
	endgenerate
	
	generate
		genvar j;
		for(j=0;j<10;j++)
		begin: blocks
			sort_1_to_10_new #(WIDTH,j) 
			m_block(.a(a[j]),
					.a_id(j),
					.flag(flag_init[j]),
					.index(index[j]),
					.flag_new(flag),
					.a_out(a_out[j]),
					.a_id_out(a_id_out[j]));
			assign use_out[j] = (flag[j]==fit)?0:1;
		end
	endgenerate
	
	
endmodule

module singleStage_1 #(parameter WIDTH = 16)
					(input [WIDTH-1:0]a[9:0],
					 input [3:0]a_id[9:0],
					 input [WIDTH-1:0]array[99:0],
					 input [1:0]flag[9:0],
					 input [9:0]use_in,
					 output [WIDTH-1:0]a_up_out[8:0],
					 output [WIDTH-1:0]a_down_out[8:0],
					 output signed[7:0]index_up[8:0],
					 output signed[7:0]index_down[8:0],
					 output [1:0]flag_up_out[8:0],
					 output [1:0]flag_down_out[8:0],
					 output [3:0]a_up_id_out[8:0],
					 output [3:0]a_down_id_out[8:0],
					 output [8:0] use_up_out, use_down_out);
	
	localparam init=2'b00, less=2'b01, fit=2'b10, larger=2'b11;
	generate
		genvar i;
		for(i=0;i<9;i++)
		begin: blocks_up
			sort_1_to_10_new #(.WIDTH(WIDTH),.BLOCK(i))
				sort_up(.a(a[i+1]),
						.a_id(a_id[i+1]),
						.array(array[9+10*i:10*i]),
						.flag(flag[i+1]),
						.index(index_up[i]),
						.a_out(a_up_out[i]),
						.a_id_out(a_up_id_out[i]),
						.flag_new(flag_up_out[i]));
			assign use_up_out[i] = (~use_in[i+1])?0:
								   (flag_up_out[i]==fit)?0:1;
			
		end
	endgenerate
	
	//integer dis = 10-numofblock;
	generate	
		genvar j;
		for(j=1;j<10;j++)
		begin: blocks_down
			sort_1_to_10_new #(.WIDTH(WIDTH),.BLOCK(j))
				sort_down(.a(a[j-1]),
						  .a_id(a_id[j-1]),
						  .array(array[9+10*j:10*j]),
						  .flag(flag[j-1]),
						  .index(index_down[j-1]),
						  .a_out(a_down_out[j-1]),
						  .a_id_out(a_down_id_out[j-1]),
						  .flag_new(flag_down_out[j-1]));
			assign use_down_out[j-1] = (~use_in[j-1])?0:
										 (flag_down_out[j-1]==fit)?0:1;
		
		end
	endgenerate
	
	
					 

endmodule

//stage_i, num of block=10-i, i=2~9
// [i]	numofblock	input	output up_block  down_block
//  2	  8			[8:0]	[7:0]	[0:7]		[2:9]
//	3	  7			[7:0]	[6:0]
//	4	  6			[6:0]	[5:0]
//	5	  5			[5:0]	[4:0]
//	6	  4			[4:0]	[3:0]
//	7	  3			[3:0]	[2:0]
//	8	  2			[2:0]	[1:0]
//	9	  1			[1:0]	 [0]
module singleStage_i #(parameter WIDTH = 16, numofblock = 8)
					  (input [WIDTH-1:0] a_up[numofblock:0], 
					   input [WIDTH-1:0] a_down[numofblock:0],
					   input [3:0] a_up_id[numofblock:0],
					   input [3:0] a_down_id[numofblock:0],
					   input [WIDTH-1:0] array[99:0],
					   input [numofblock:0] use_up, use_down,
					   input [1:0] flag_up_in[numofblock:0],
					   input [1:0] flag_down_in[numofblock:0],
					   output[WIDTH-1:0] a_up_out[numofblock-1:0],
					   output[WIDTH-1:0] a_down_out[numofblock-1:0],
					   output[3:0] a_up_id_out[numofblock-1:0],
					   output[3:0] a_down_id_out[numofblock-1:0],
					   output signed[7:0] index_up[numofblock-1:0],
					   output signed[7:0] index_down[numofblock-1:0],
					   output[1:0] flag_up_out[numofblock-1:0],
					   output[1:0] flag_down_out[numofblock-1:0],
					   output [numofblock-1:0] use_up_out, use_down_out);

	localparam init=2'b00, less=2'b01, fit=2'b10, larger=2'b11;
	generate
		genvar i;
		for(i=0;i<numofblock;i++)
		begin: blocks_up
			sort_1_to_10_new #(.WIDTH(WIDTH),.BLOCK(i))
				sort_up(.a(a_up[i+1]),
						.a_id(a_up_id[i+1]),
						.array(array[9+10*i:10*i]),
						.flag(flag_up_in[i+1]),
						.index(index_up[i]),
						.a_out(a_up_out[i]),
						.a_id_out(a_up_id_out[i]),
						.flag_new(flag_up_out[i]));
			assign use_up_out[i] = (~use_up[i+1])?0:
								   (flag_up_out[i]==fit)?0:1;
			
		end
	endgenerate
	
	//integer dis = 10-numofblock;
	generate	
		genvar j;
		//for(j=dis;j<10;j++)
		for(j=0;j<numofblock;j++)
		begin: blocks_down
			sort_1_to_10_new #(.WIDTH(WIDTH),.BLOCK(j+10-numofblock))
				sort_down(.a(a_down[j]),
						  .a_id(a_down_id[j]),
						  .array(array[9+10*(j+10-numofblock):10*(j+10-numofblock)]),
						  .flag(flag_down_in[j]),
						  .index(index_down[j]),
						  .a_out(a_down_out[j]),
						  .a_id_out(a_down_id_out[j]),
						  .flag_new(flag_down_out[j]));
			assign use_down_out[j] = (~use_down[j])?0:
										 (flag_down_out[j]==fit)?0:1;
		
		end
	endgenerate
	
endmodule


module combine #(WIDTH = 16)
				(input [WIDTH-1:0]a[9:0],
				 input signed[7:0]index[9:0],
				 input [WIDTH-1:0]array[99:0],
				 output [WIDTH-1:0]array_new[99:0]);
	
	wire [WIDTH-1:0] tmparray_new[109:0];
	wire [3:0]is_index[109:0];
	wire [109:0] notempty;
	generate 
		genvar j;
		for(j=0;j<110;j++)
		begin: if_in_index
			assign is_index[j] = (index[0]==j)?1:
								 (index[1]==j)?2:
								 (index[2]==j)?3:
								 (index[3]==j)?4:
								 (index[4]==j)?5:
								 (index[5]==j)?6:
								 (index[6]==j)?7:
								 (index[7]==j)?8:
								 (index[8]==j)?9:
								 (index[9]==j)?10:4'b0;
			assign notempty[j] = (index[0]!=j)&(index[1]!=j)&(index[2]!=j)&
								 (index[3]!=j)&(index[4]!=j)&(index[5]!=j)&
								 (index[6]!=j)&(index[7]!=j)&(index[8]!=j)&
								 (index[9]!=j)?0:1;
		end
	endgenerate
	
	wire [3:0] minus[109:0];
	assign minus[0] = 1'b0;
	
	generate
		genvar k;
		for(k=1;k<110;k++)
		begin: count_minus
			sumArray #(.LENGTH(k+1), .WIDTH(4))
					sum_notempty(.array(notempty[k:0]),
								 .sum(minus[k]));
		end
	endgenerate
	
	generate
		genvar ii;
		for(ii=0;ii<110;ii++)
		begin: insert_new_array
			assign tmparray_new[ii] = (~notempty[ii])?array[ii-minus[ii]]:
														a[is_index[ii]-1];
		end
	endgenerate	
	
	assign array_new = tmparray_new[99:0];
				 
endmodule