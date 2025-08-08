`timescale 1ns / 1ps

module tb_insertionSort;

    parameter SIZE_DATA = 8;
    parameter NUM_VALS  = 8;

    // Clock and reset
    logic i_clk;
    logic i_rst_n;
    logic i_start;
    logic [SIZE_DATA-1:0] i_data [NUM_VALS];
    logic o_done;
    logic [SIZE_DATA-1:0] o_data [NUM_VALS];

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
        // .i_mode(1'b0),        // ascending
        .i_data(i_data),
        .o_done(o_done),
        .o_data(o_data)
    );

    // Task to print output array
    task automatic print_array(input [SIZE_DATA-1:0] arr [NUM_VALS]);
        for (int i = 0; i < NUM_VALS; i++) begin
            $write("%0d ", arr[i]);
        end
        $write("\n");
    endtask

    initial begin
        $dumpfile("tb_insertionSort.vcd");
        $dumpvars(0, tb_insertionSort);
    end

    // Stimulus
        int execution_cycles;
    initial begin
        $display("=== Testbench: Insertion Sort ===");
        i_rst_n = 0;
        i_start = 0;
        #20;
        i_rst_n = 1;
        #10;

        // Test case 1: unsorted input
        i_data[0] = 8'd12;
        i_data[1] = 8'd1;
        i_data[2] = 8'd1;
        i_data[3] = 8'd20;
        i_data[4] = 8'd0;
        i_data[5] = 8'd15;
        i_data[6] = 8'd29;
        i_data[7] = 8'd1;

        $display("Input data: ");
        print_array(i_data);

        // Start sorting
        #10;
        i_start = 1;

        execution_cycles = 0;

            // Đếm chu kỳ cho đến khi i_done == 1
        while (o_done == 1'b0) begin
            @(posedge i_clk);
            execution_cycles++;
        end
        // Wait for done signal
        // @(posedge o_done);
        // #10000;
        $display("Sorted output: ");
        print_array(o_data);
        $display("Insertion sort took %0d clock cycles", execution_cycles);
        #10;
        $finish;
    end

endmodule
