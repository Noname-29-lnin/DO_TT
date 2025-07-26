`define SIZE_DATA 8
`define NUM_VALS 8

task automatic tsk_clock_gen(ref logic i_clk, input int PERIOD);
  begin
    i_clk = 1'b1;
    forever #PERIOD i_clk = !i_clk;
  end
endtask

task automatic tsk_reset(ref logic i_reset, input int RESETPERIOD);
  begin
    i_reset = 1'b0;
    #RESETPERIOD i_reset = 1'b1;
  end
endtask

function bit check_sorted(input logic [`NUM_VALS-1:0][`SIZE_DATA-1:0] data);
    for (int i = 0; i < `NUM_VALS - 1; i++) begin
        if (data[i+1] < data[i]) return 0;
    end
    return 1;
endfunction

task print_wate;
    begin
        $dumpfile("tb_top_test.vcd");
        $dumpvars(0, tb_top_test);
    end
endtask 