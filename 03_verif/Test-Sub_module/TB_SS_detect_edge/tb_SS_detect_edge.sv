`timescale 1ns/1ps
module tb_SS_detect_edge();

logic i_clk, i_rst_n, i_pos_edge;
logic i_signal, o_signal;

// i_pos_edge = 0 -> detect negedge edge
// i_pos_edge = 1 -> detect posedge edge
SS_detect_edge DUT (
    .i_clk       (i_clk),
    .i_rst_n     (i_rst_n),
    .i_pos_edge  (i_pos_edge),
    .i_signal    (i_signal),
    .o_signal    (o_signal)
);

initial begin
    $dumpfile("./tb_SS_detect_edge.vcd");
    $dumpvars(0, tb_SS_detect_edge);
end

initial begin
    i_clk = 1'b0;
    forever begin
        #10 i_clk = ~i_clk;
    end 
end 

initial begin
    i_rst_n = 1'b0;
    #30;
    i_rst_n = 1'b1;
    #10;
    i_pos_edge = 1'b1;
    i_signal = 1'b0;
    #20;
    i_signal = 1'b1;
    #40;
    @(posedge i_clk);
    i_signal = 1'b1;
    @(posedge i_clk);
    i_signal = 1'b0;

    #10;
    i_pos_edge = 1'b1;
    i_signal = 1'b0;
    #20;
    i_signal = 1'b1;
    #10;
    i_signal = 1'b0;
    #20;
    @(posedge i_clk);
    i_signal = 1'b1;
    @(posedge i_clk);
    i_signal = 1'b0;

    #100;
    $finish;
end 

endmodule
