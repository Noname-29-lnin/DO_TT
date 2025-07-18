`timescale 1ns/1ps

module tb_insertionSort();

`define TIME_SIMULATION 10

// Clock
logic i_clk;
initial begin
    i_clk = 0;
    forever #(`TIME_SIMULATION/2) i_clk = ~i_clk;
end

// Parameters
parameter SIZE_DATA  = 8;
parameter NUMBER_ARR = 8;

// DUT Signals
logic                     i_rst_n;
logic                     i_start;
logic [SIZE_DATA-1:0]     i_data [NUMBER_ARR];
logic [SIZE_DATA-1:0]     o_data [NUMBER_ARR];
logic                     o_done;

// DUT Instantiation
insertionSort #(
    .SIZE_DATA     (SIZE_DATA),
    .NUMBER_ARR    (NUMBER_ARR)
) DUT (
    .i_clk     (i_clk),
    .i_rst_n   (i_rst_n),
    .i_start   (i_start),
    .i_data    (i_data),
    .o_data    (o_data),
    .o_done    (o_done)
);

// Testbench Process
initial begin
    i_rst_n = 0;
    i_start = 0;

    // Cố định mảng đầu vào
    i_data[0] = 8'd55;
    i_data[1] = 8'd12;
    i_data[2] = 8'd99;
    i_data[3] = 8'd18;
    i_data[4] = 8'd67;
    i_data[5] = 8'd3;
    i_data[6] = 8'd45;
    i_data[7] = 8'd21;

    // Reset
    #(`TIME_SIMULATION * 2);
    i_rst_n = 1;

    // Chờ vài chu kỳ trước khi bắt đầu
    #(`TIME_SIMULATION * 2);
    i_start = 1;

    // Chờ hoàn thành
    wait (o_done == 1);

    // Hiển thị kết quả
    $display("Sorted Output:");
    for (int i = 0; i < NUMBER_ARR; i++) begin
        $display("o_data[%0d] = %0d", i, o_data[i]);
    end

    $finish;
end

endmodule
