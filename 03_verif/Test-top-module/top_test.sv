`include "tlib.svh"

module top_test;

    logic i_clk, i_rst_n;

    logic i_start, o_done;

    initial i_start = 1'b1;

    initial tsk_clock_gen(i_clk, 10);
    initial tsk_reset(i_rst_n, 10);
    initial print_wate();
    initial begin
        bit sorted;
        sorted = check_sorted(w_odata);
        // Optionally, display result or use 'sorted' as needed
    end

    logic [`NUM_VALS-1:0][`SIZE_DATA-1:0] w_idata, w_odata;
    driver #(
        .SIZE_DATA (`SIZE_DATA),
        .NUM_VALS  (`NUM_VALS)
    ) driver_unit (
        .o_data     (w_idata)
    );

    bubbleSort #(
        .SIZE_DATA (`SIZE_DATA),
        .NUM_VALS  (`NUM_VALS)
    ) DUT (
        .i_clk      (i_clk),
        .i_rst_n    (i_rst_n),
        .i_start    (i_start),
        .i_data     (w_idata),
        .o_data     (w_odata),
        .o_done     (o_done)
    );

    scoreboard scoreboard_unit(
        .i_check_sorted (check_sorted)
    );

endmodule
