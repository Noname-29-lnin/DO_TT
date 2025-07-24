`timescale 1ns / 1ps

module tb_insertionSort;

    parameter SIZE_DATA = 8;
    parameter NUM_VALS  = 8;

    // Clock and reset
    logic i_clk;
    logic i_rst_n;
    logic i_start;
    logic [NUM_VALS*SIZE_DATA-1:0] i_data;
    logic o_done;
    logic [NUM_VALS*SIZE_DATA-1:0] o_data;

    // Clock generation
    initial begin
        i_clk = 0;
        forever #5 i_clk = ~i_clk; // 10ns period
    end

    // Instantiate DUT
    insertionSort #(
        .NUM_VALS(NUM_VALS),
        .SIZE_DATA(SIZE_DATA)
    ) dut (
        .i_clk(i_clk),
        .i_rst_n(i_rst_n),
        .i_start(i_start),
        .i_data(i_data),
        .o_done(o_done),
        .o_data(o_data)
    );

    // Task to print output array
    task automatic print_array(input [NUM_VALS*SIZE_DATA-1:0] arr);
        for (int i = 0; i < NUM_VALS; i++) begin
            $write("%0d ", arr[i*SIZE_DATA +: SIZE_DATA]);
        end
        $write("\n");
    endtask

    // Stimulus
    initial begin
        $display("=== Testbench: Insertion Sort ===");
        i_rst_n = 0;
        i_start = 0;
        i_data = 0;

        #20;
        i_rst_n = 1;

        // Test case 1: unsorted input
        #10;
        i_data = {
            8'd12,  // MSB
            8'd5,
            8'd1, 
            8'd20,
            8'd3,
            8'd15,
            8'd29,
            8'd1   // LSB
        };
        $display("Input data: ");
        print_array(i_data);

        #10;
        i_start = 1;
        #10;
        i_start = 0;

        // Wait for done signal
        wait (o_done == 1);
        $display("Sorted output: ");
        print_array(o_data);

        #10;
        $finish;
    end

endmodule
