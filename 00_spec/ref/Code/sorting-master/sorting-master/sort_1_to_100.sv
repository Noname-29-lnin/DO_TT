module sort_1_to_x #(parameter WIDTH = 16, LENGTH = 109)
					  (input [WIDTH-1:0] a,
					   input [WIDTH-1:0] array[LENGTH-1:0],
					   output [7:0] index);
	localparam 
	init=2'b00, 
	less=2'b01, 
	fit=2'b10, 
	larger=2'b11;
	wire [LENGTH-1:0] state;
	//integer num_of_1 = 0;
	generate
		genvar i;
		for(i=0;i<LENGTH;i++)
		begin: loop
			compare #(WIDTH)m_cmp
							(.x(a),
							 .y(array[i]),
							 .out(state[i]));
		end
	endgenerate
	
	sumArray #(.LENGTH(LENGTH),.WIDTH(8))
			m_sum (.array(state),.sum(index));
	
	//assign index = num_of_1;	   
endmodule

module sumArray #(parameter LENGTH, WIDTH)
			(input [LENGTH-1:0]array,
			 output [WIDTH-1:0] sum);
	
	wire [WIDTH-1:0]count[LENGTH-2:0];
	generate
		genvar i;
		for(i=0;i<LENGTH-1;i++)
		begin: sum_up
			if(i==0)
				assign count[i] = array[i]+array[i+1];
			else
				assign count[i] = count[i-1]+array[i+1];
		end
	endgenerate
	assign sum = count[LENGTH-2];
	
endmodule

module sort_10_to_100 #(parameter WIDTH = 16)
					   (input [WIDTH-1:0] a[9:0],
						input [WIDTH-1:0] array[99:0],
						output [WIDTH-1:0] array_new[99:0]);
						
	wire [WIDTH-1:0]tmparray_new[109:0];
	wire [7:0] index[9:0];
	
	wire [WIDTH-1:0] array0[108:0];
	wire [WIDTH-1:0] array1[108:0];
	wire [WIDTH-1:0] array2[108:0];
	wire [WIDTH-1:0] array3[108:0];
	wire [WIDTH-1:0] array4[108:0];
	wire [WIDTH-1:0] array5[108:0];
	wire [WIDTH-1:0] array6[108:0];
	wire [WIDTH-1:0] array7[108:0];
	wire [WIDTH-1:0] array8[108:0];
	wire [WIDTH-1:0] array9[108:0];
	wire [WIDTH-1:0] tmparray[1090-1:0];
	assign array0[108:100] = a[9:1]; assign array0[99:0] = array;
	assign array1[108:101] = a[9:2]; assign array1[100] = a[0]; assign array1[99:0] = array;
	assign array2[108:102] = a[9:3]; assign array2[101:100] = a[1:0]; assign array2[99:0] = array;
	assign array3[108:103] = a[9:4]; assign array3[102:100] = a[2:0]; assign array3[99:0] = array;
	assign array4[108:104] = a[9:5]; assign array4[103:100] = a[3:0]; assign array4[99:0] = array;
	assign array5[108:105] = a[9:6]; assign array5[104:100] = a[4:0]; assign array5[99:0] = array;
	assign array6[108:106] = a[9:7]; assign array6[105:100] = a[5:0]; assign array6[99:0] = array;
	assign array7[108:107] = a[9:8]; assign array7[106:100] = a[6:0]; assign array7[99:0] = array;
	assign array8[108] = a[9]; assign array8[107:100] = a[7:0]; assign array8[99:0] = array;
	assign array9[108:100] = a[8:0]; assign array9[99:0] = array;
	
	assign tmparray[109*1-1:109*0] = array0;
	assign tmparray[109*2-1:109*1] = array1;
	assign tmparray[109*3-1:109*2] = array2;
	assign tmparray[109*4-1:109*3] = array3;
	assign tmparray[109*5-1:109*4] = array4;
	assign tmparray[109*6-1:109*5] = array5;
	assign tmparray[109*7-1:109*6] = array6;
	assign tmparray[109*8-1:109*7] = array7;
	assign tmparray[109*9-1:109*8] = array8;
	assign tmparray[109*10-1:109*9] = array9;
	
	/* wire [WIDTH-1:0]array0[108:0] = {{array},{a[9:1]}};
	wire [WIDTH-1:0]array1[108:0] = {array,a[9:2],a[0]};
	wire [WIDTH-1:0]array2[108:0] = {array,a[9:3],a[1:0]};
	wire [WIDTH-1:0]array3[108:0] = {array,a[9:4],a[2:0]};
	wire [WIDTH-1:0]array4[108:0] = {array,a[9:5],a[3:0]};
	wire [WIDTH-1:0]array5[108:0] = {array,a[9:6],a[4:0]};
	wire [WIDTH-1:0]array6[108:0] = {array,a[9:7],a[5:0]};
	wire [WIDTH-1:0]array7[108:0] = {array,a[9:8],a[6:0]};
	wire [WIDTH-1:0]array8[108:0] = {array,a[9],a[7:0]};
	wire [WIDTH-1:0]array9[108:0]= {array,a[8:0]};
	wire [WIDTH-1:0]tmparray[109*10-1:0] = {array9,array8,array7,
											array6,array5,array4,
											array3,array2,array1,array0}; */
	generate
		genvar i;
		for(i=0;i<10;i++)
		begin: sort
			sort_1_to_x #(WIDTH, 109) sort
						(.a(a[i]),
						 .array(tmparray[109*(i+1)-1:109*i]),
						 .index(index[i]));
		end
	endgenerate
	
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
	
		
	/* combine #(WIDTH) m_combine(.array(array),
							   .a(a),
							   .index(index),
							   .array_new(tmparray_new)); */
	assign array_new = tmparray_new[99:0];						   
	
endmodule

/* module combine #(parameter WIDTH = 16)
				(input [WIDTH-1:0] array[99:0],
				 input [WIDTH-1:0] a[9:0],
				 input [7:0] index [9:0],
				 output [WIDTH-1:0] array_new[109:0]);
	
	wire [109:0] notempty = 110'b0;
	wire [3:0] minus[109:0];
	wire [WIDTH-1:0] tmp_array_new [109:0];
	assign minus[0] = 1'b0;
	/* generate
		genvar i;
		for(i=0;i<10;i++) 
		begin: insert_a
			//assign array_new[index[i]]=a[i];
			always@(*)
			begin
				array_new[index[i]] = a[i];
				notempty[index[i]] = 1'b1;
			end
		end
	endgenerate */
	
	/* insert_a #(WIDTH) m_insert_a(.a(a),
								 .index(index),
								 .notempty(notempty),
								 .array_new(tmp_array_new));
	
	generate
		genvar j;
		for(j=1;j<110;j++)
		begin: count_minus
			sumArray #(.LENGTH(j+1), .WIDTH(4))
					sum_notempty(.array(notempty[j:0]),
								 .sum(minus[j]));
		end
	endgenerate
	
	generate
		genvar k;
		for(k=0;k<110;k++)
		begin: insert_array
			/* always @(*)
			begin
				if(~notempty[k])
					array_new[k] = array[k-minus[k]];
			end */
			/* assign tmp_array_new[k] = (~notempty[k])?array[k-minus[k]]:tmp_array_new[k];
		end
	endgenerate
	
	assign array_new = tmp_array_new;
	
endmodule */

/* module insert_a #(parameter WIDTH = 16)
				(input [WIDTH-1:0] a[9:0],
				 input [7:0] index[9:0],
				 output [109:0] notempty,
				 output [WIDTH-1:0] array_new[109:0]);
	
	reg [109:0] tmp_notempty = 110'b0;
	reg [WIDTH-1:0] tmp_array_new[109:0];
	generate
		genvar i;
		for(i=0;i<10;i++) 
		begin: insert_a
			//assign array_new[index[i]]=a[i];
			//always@(*)
			//begin
			assign array_new[index[i]] = a[i];
			assign notempty[index[i]] = 1'b1;
			//end
		end
	endgenerate
	assign notempty = tmp_notempty;
	assign array_new = tmp_array_new;
endmodule */

module compare #(parameter WIDTH = 16)
				(input [WIDTH-1:0] x, y,
				 output out);
	assign out = (x>=y)?1'b1:1'b0;
	/* always @(*)
	begin
		if(x >= y)
			out = 1'b1;
		else
			out = 1'b0;
	end
 */	
endmodule


