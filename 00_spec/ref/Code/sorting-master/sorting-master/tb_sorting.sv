`define PERIOD 20
module tb_sorting();
	
	reg [15:0] a[9:0];
	reg clk;
	integer i;
	
	sorting test(.a(a),.clk(clk));
	
	always #(`PERIOD/2) clk=~clk;
	
	initial
	begin
		clk = 1;
		$readmemb("arrayData_binary.dat",test.array);
		for(i=0;i<10;i++)
		begin	
			a[i] = $random%500 + 500;
			$display("a%d=%d\n",i,a[i]);
		end
		#`PERIOD
		for(i=0;i<10;i++)
		begin	
			a[i] = $random%500 + 500;
			$display("a%d=%d\n",i,a[i]);
		end
		#`PERIOD
		for(i=0;i<10;i++)
		begin	
			a[i] = $random%500 + 500;
			$display("a%d=%d\n",i,a[i]);
		end	
	end
	
	
	
	
endmodule