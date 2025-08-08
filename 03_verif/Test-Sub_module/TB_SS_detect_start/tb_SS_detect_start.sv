`timescale 1ns/1ps

module tb_SS_detect_start;

logic                         i_clk;
logic                         i_rst_n;
logic                         i_start;
logic                         i_done;
logic                         o_w_start;

SS_detect_start DUT (
    .i_clk       (i_clk),
    .i_rst_n     (i_rst_n),
    .i_start     (i_start),
    .i_done      (i_done),
    .o_w_start   (o_w_start)
);

initial begin
    i_clk = 1'b0;
    forever begin
        #10 i_clk = ~i_clk;
    end
end

initial begin
    $dumpfile("./tb_SS_detect_start.vcd");
    $dumpvars(0, tb_SS_detect_start);
end

initial begin
    i_rst_n = 1'b0;

    #30;

    i_rst_n = 1'b1;

    #10;

    @(posedge i_clk);
    i_start = 1'b1;
    i_done  = 1'b1;
    @(posedge i_clk);
    i_start = 1'b1;
    i_done  = 1'b0;

    #40;

    @(posedge i_clk);
    i_start = 0;
    i_done = 1;
    @(posedge i_clk);
    i_start = 1;
    i_done = 0;

    #40;

    @(posedge i_clk);
    i_start = 1;
    i_done = 1;

    #40;

    @(posedge i_clk);
    i_done = 0;

    @(posedge i_clk);
    i_start = 0;

    #40;

    @(posedge i_clk);
    i_done = 1;

    @(posedge i_clk);
    i_done = 0;
    @(posedge i_clk);
    i_start = 1;
    #100;
    $finish;
end

endmodule
