`timescale 1ns/1ps

module tb_SS_write_data;

    // Parameter
    localparam SIZE_ADDR = 6;
    localparam SIZE_DATA = 8;

    // Signals
    logic                     i_clk;
    logic                     i_rst_n;

    logic                     i_start_write_data;
    logic                     i_en_write_data;

    logic [SIZE_ADDR-1:0]     i_si_ram;
    logic [SIZE_ADDR-1:0]     i_ei_ram;

    logic [SIZE_DATA-1:0]     i_data_ram;

    logic                     o_we_ram;
    logic [SIZE_ADDR-1:0]     o_addr_ram;
    logic [SIZE_DATA-1:0]     o_data_ram;

    logic                     o_done_write_data;

    // Clock generation (10ns period)
    initial i_clk = 0;
    always #5 i_clk = ~i_clk;

    // DUT instantiation
    SS_write_data #(
        .SIZE_ADDR(SIZE_ADDR),
        .SIZE_DATA(SIZE_DATA)
    ) dut (
        .i_clk(i_clk),
        .i_rst_n(i_rst_n),
        .i_start_write_data(i_start_write_data),
        .i_en_write_data(i_en_write_data),
        .i_si_ram(i_si_ram),
        .i_ei_ram(i_ei_ram),
        .i_data_ram(i_data_ram),
        .o_we_ram(o_we_ram),
        .o_addr_ram(o_addr_ram),
        .o_data_ram(o_data_ram),
        .o_done_write_data(o_done_write_data)
    );

    initial begin
        $dumpfile("./tb_SS_write_data.vcd");
        $dumpvars(0, tb_SS_write_data);
    end

    // Testbench process
    initial begin
        i_rst_n = 1'b0;
        i_start_write_data = 1'b0;
        i_en_write_data = 1'b0;
        i_si_ram = 0;
        i_ei_ram = 0;
        i_data_ram = 0;

        #30;
        i_rst_n = 1'b1;

        #10;
        // --- Test 1: Ghi từ 5 -> 10 ---
        @(posedge i_clk);
        i_si_ram = 6'd5;
        i_ei_ram = 6'd10;
        i_start_write_data = 1'b1;
        @(posedge i_clk);
        i_start_write_data = 1'b0;

        i_en_write_data = 1'b1;

        // Ghi dữ liệu liên tiếp
        forever begin
            @(posedge i_clk);
            i_data_ram = {2'b00, o_addr_ram}; // Data = Addr
            if (o_done_write_data) break;
        end

        @(posedge i_clk);
        i_en_write_data = 1'b0;

        // --- Test 2: Ghi từ 0 -> 3 ---
        repeat (5) @(posedge i_clk);
        i_si_ram = 6'd0;
        i_ei_ram = 6'd3;
        i_start_write_data = 1'b1;
        @(posedge i_clk);
        i_start_write_data = 1'b0;
        i_en_write_data = 1'b1;

        forever begin
            @(posedge i_clk);
            i_data_ram = {2'b11, o_addr_ram}; // Data = Addr + pattern
            if (o_done_write_data) break;
        end

        @(posedge i_clk);
        i_en_write_data = 1'b0;

        // --- Test 3: Ngắt giữa chừng ---
        repeat (5) @(posedge i_clk);
        i_si_ram = 6'd8;
        i_ei_ram = 6'd12;
        i_start_write_data = 1'b1;
        @(posedge i_clk);
        i_start_write_data = 1'b0;
        i_en_write_data = 1'b1;

        // Ghi được 2 giá trị thì tắt enable
        repeat (2) @(posedge i_clk);
        i_data_ram = 8'hAA;
        i_en_write_data = 1'b0;

        // Đợi vài chu kỳ rồi bật lại enable
        repeat (3) @(posedge i_clk);
        i_en_write_data = 1'b1;

        forever begin
            @(posedge i_clk);
            i_data_ram = 8'hBB;
            if (o_done_write_data) break;
        end

        @(posedge i_clk);
        i_en_write_data = 1'b0;

        repeat (5) @(posedge i_clk);
        $finish;
    end

endmodule
