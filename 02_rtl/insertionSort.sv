module insertionSort #(
    parameter NUM_VALS = 5,
    parameter SIZE_DATA = 8
)(
    input  logic                         i_clk,
    input  logic                         i_rst_n,
    input  logic                         i_start,
    input  logic [NUM_VALS*SIZE_DATA-1:0] i_data,
    output logic                         o_done,
    output logic [NUM_VALS*SIZE_DATA-1:0] o_data
);

    // State encoding
    typedef enum logic [2:0] {
        b0, // Reset/init
        b1, // Load data into internal array
        b2, // Wait for start
        b3, // Use compare_block for first two elements
        b4, // Select key
        b5, // While loop condition
        b6, // Shift and insert
        b7  // Done
    } state_t;

    state_t state;

    // Internal array
    logic [SIZE_DATA-1:0] arr_temp [NUM_VALS-1:0];
    logic [SIZE_DATA-1:0] key;
    integer i_sign; // current index of insertion

    // Compare block outputs
    logic [SIZE_DATA-1:0] w_less_data;
    logic [SIZE_DATA-1:0] w_greater_data;

    // FSM & datapath
    always_ff @(posedge i_clk or negedge i_rst_n) begin
        if (!i_rst_n) begin
            state <= b0;
            o_done <= 1'b0;
            i_sign <= 0;
        end else begin
            case (state)
                b0: begin
                    o_done <= 1'b0;
                    state <= b1;
                end

                b1: begin
                    // Load input data to internal array
                    for (int i = 0; i < NUM_VALS; i++) begin
                        arr_temp[i] <= i_data[i*SIZE_DATA +: SIZE_DATA];
                    end
                    state <= b2;
                end

                b2: begin
                    // Wait for start signal
                    if (i_start)
                        state <= b3;
                end

                b3: begin
                    // Use compare_block to sort first 2 elements
                    arr_temp[0] <= w_less_data;
                    arr_temp[1] <= w_greater_data;
                    i_sign <= 2; // Start insertion from 3rd element
                    state <= b4;
                end

                b4: begin
                    if (i_sign < NUM_VALS) begin
                        key <= arr_temp[i_sign];
                        i_sign <= i_sign - 1;
                        state <= b5;
                    end else begin
                        state <= b7;
                    end
                end

                b5: begin
                    if ((i_sign >= 0) && (key < arr_temp[i_sign])) begin
                        arr_temp[i_sign + 1] <= arr_temp[i_sign];
                        i_sign <= i_sign - 1;
                        state <= b5; // Repeat
                    end else begin
                        state <= b6;
                    end
                end

                b6: begin
                    arr_temp[i_sign + 1] <= key;
                    i_sign <= i_sign + 2;
                    state <= b4;
                end

                b7: begin
                    // Sorting done
                    for (int i = 0; i < NUM_VALS; i++) begin
                        o_data[i*SIZE_DATA +: SIZE_DATA] <= arr_temp[i];
                    end
                    o_done <= 1'b1;
                    state <= b0; // reset for next run
                end

                default: state <= b0;
            endcase
        end
    end

    // === Compare block instantiation ===
    compare_block #(
        .SIZE_DATA(SIZE_DATA)
    ) u_compare_block (
        .i_data_a(arr_temp[0]),
        .i_data_b(arr_temp[1]),
        .o_less_data(w_less_data),
        .o_greater_data(w_greater_data)
    );

endmodule

//module insertionSort #(
//    parameter NUM_VALS = 5,
//    parameter SIZE     = 16
//)(  input  wire clk,
//    input  wire [NUM_VALS*SIZE-1:0] in,
//    output reg  [NUM_VALS*SIZE-1:0] out
//);
//    reg [NUM_VALS*SIZE-1:0] sorted_bus;
//    always @(posedge clk) begin
//        out <= sorted_bus;
//    end
//
//    integer i, j;
//    reg [SIZE-1:0] temp;
//    reg [SIZE-1:0] array [1:NUM_VALS-1];
//    always @* begin
//        for (i = 0; i < NUM_VALS; i = i + 1) begin
//            array[i+1] = in[i*SIZE +: SIZE];
//        end
//
//        for (j = 2; j < NUM_VALS + 1; j = j + 1) begin
//				i = j-1;
//				temp = array[j];
//            while((i > 0)&&(temp < array[i])) begin
//                    array[i+1] = array[i];
//						  i=i-1;
//						  end
//				array[i+1]=temp;
//            end    
//       for (i = 0; i < NUM_VALS; i = i + 1) begin
//            sorted_bus[i*SIZE +: SIZE] = array[i+1];
//       end
//    end
//endmodule
