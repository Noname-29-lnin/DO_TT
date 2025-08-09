// module bubbleSort #(
//     parameter NUM_VALS = 5,
//     parameter SIZE_DATA = 8
// )(
//     input  logic                         i_clk,
//     input  logic                         i_rst_n,
//     input  logic                         i_start,
//     input  logic [NUM_VALS*SIZE_DATA-1:0] i_data,
//     output logic                         o_done,
//     output logic [NUM_VALS*SIZE_DATA-1:0] o_data
// );

//     typedef enum logic [1:0] {
//         IDLE, LOAD, SORT, DONE
//     } state_t;

//     state_t current_state, next_state;

//     logic [SIZE_DATA-1:0] arr_temp [NUM_VALS-1:0];
//     logic [SIZE_DATA-1:0] cmp_less, cmp_greater;

//     logic [$clog2(NUM_VALS):0] i, j;

//     // FSM chuyển trạng thái
//     always_ff @(posedge i_clk or negedge i_rst_n) begin
//         if (!i_rst_n)
//             current_state <= IDLE;
//         else
//             current_state <= next_state;
//     end

//     always_comb begin
//         case (current_state)
//             IDLE:   next_state = i_start ? LOAD : IDLE;
//             LOAD:   next_state = SORT;
//             SORT:   next_state = (i == NUM_VALS - 1) ? DONE : SORT;
//             DONE:   next_state = IDLE;
//             default: next_state = IDLE;
//         endcase
//     end

//     // Tín hiệu done
//     always_ff @(posedge i_clk or negedge i_rst_n) begin
//         if (!i_rst_n)
//             o_done <= 0;
//         else if (current_state == DONE)
//             o_done <= 1;
//         else
//             o_done <= 0;
//     end

//     // Khởi tạo mảng
//     always_ff @(posedge i_clk or negedge i_rst_n) begin
//         if (!i_rst_n) begin
//             for (int k = 0; k < NUM_VALS; k++) begin
//                 arr_temp[k] <= '0;
//             end
//         end else if (current_state == LOAD) begin
//             for (int k = 0; k < NUM_VALS; k++) begin
//                 arr_temp[k] <= i_data[k*SIZE_DATA +: SIZE_DATA];
//             end
//             i <= 0;
//             j <= 0;
//         end
//     end

//     // Gọi compare_block
//     compare_block #(
//         .SIZE_DATA(SIZE_DATA)
//     ) cmp_unit (
//         .i_data_a(arr_temp[j]),
//         .i_data_b(arr_temp[j+1]),
//         .o_less_data(cmp_less),
//         .o_greater_data(cmp_greater)
//     );

//     // Vòng lặp bubble sort (dùng FSM)
//     always_ff @(posedge i_clk or negedge i_rst_n) begin
//         if (!i_rst_n) begin
//             i <= 0;
//             j <= 0;
//         end else if (current_state == SORT) begin
//             if (j < NUM_VALS - i - 1) begin
//                 // Cập nhật từ compare_block
//                 arr_temp[j]     <= cmp_less;
//                 arr_temp[j + 1] <= cmp_greater;
//                 j <= j + 1;
//             end else begin
//                 j <= 0;
//                 i <= i + 1;
//             end
//         end
//     end

//     // Gán dữ liệu đầu ra
//     always_ff @(posedge i_clk) begin
//         if (current_state == DONE) begin
//             for (int k = 0; k < NUM_VALS; k++) begin
//                 o_data[k*SIZE_DATA +: SIZE_DATA] <= arr_temp[k];
//             end
//         end
//     end

// endmodule
// Fixed and optimized version of parallel 8-input bubble sort in SystemVerilog

// Fixed and optimized version of parallel 8-input bubble sort in SystemVerilog

module bubbleSort #(
    parameter SIZE_DATA = 8,
    parameter NUM_VALS  = 8
)(
    input  logic                         i_clk,
    input  logic                         i_rst_n,
    input  logic                         i_start,
    input  logic [NUM_VALS-1:0][SIZE_DATA-1:0]    i_data,
    output logic [NUM_VALS-1:0][SIZE_DATA-1:0]    o_data,
    output logic                         o_done
);

    // Internal pipeline stages
    logic [7:0][SIZE_DATA-1:0] stage[0:7];

    // Stage 0: input load
    always_ff @(posedge i_clk or negedge i_rst_n) begin
        if (!i_rst_n)
            stage[0] <= '0;
        else if (i_start)
            stage[0] <= i_data;
    end

    // Instantiate each compare-and-swap unit statically
    generate
        genvar i;
        for (i = 0; i < 7; i++) begin : stage_gen
            // temp storage for current stage
            logic [7:0][SIZE_DATA-1:0] temp;

            always_comb begin : bubble_logic
                temp = stage[i];
                for (int j = 0; j < 7 - i; j++) begin
                    if (stage[i][j] > stage[i][j+1]) begin
                        temp[j]   = stage[i][j+1];
                        temp[j+1] = stage[i][j];
                    end else begin
                        temp[j]   = stage[i][j];
                        temp[j+1] = stage[i][j+1];
                    end
                end
                for (int j = 8 - i; j < 8; j++) begin
                    temp[j] = stage[i][j];
                end
            end

            always_ff @(posedge i_clk or negedge i_rst_n) begin
                if (!i_rst_n)
                    stage[i+1] <= '0;
                else
                    stage[i+1] <= temp;
            end
        end
    endgenerate

    // Output assignment
    always_ff @(posedge i_clk or negedge i_rst_n) begin
        if (!i_rst_n) begin
            o_data <= '0;
            o_done <= 1'b0;
        end else begin
            o_data <= stage[7];
            o_done <= 1'b1;
        end
    end

endmodule
