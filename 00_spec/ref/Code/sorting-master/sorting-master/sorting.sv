module sorting(input [15:0] a[9:0],
			   input clk);
			   
	reg [15:0]a_in[9:0];
	reg [15:0]array[99:0];
	reg [15:0]array_new[99:0];
	
	always @(posedge clk)
	begin
		a_in<=a;
		//array<=array_new;
	end
	always @(negedge clk)
	begin
		array<=array_new;
	end
	sort_10_to_100 #(16) m_sort(.a(a_in),
								.array(array),
								.array_new(array_new));
	
	
endmodule