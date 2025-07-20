// module insertionSort #(
//     parameter SIZE_DATA     = 8,
//     parameter NUMBER_ARR    = 8
// )(
//     input  logic                     i_clk,
//     input  logic                     i_rst_n,
//     input  logic                     i_start,
//     input  logic [SIZE_DATA-1:0]     i_data [NUMBER_ARR],
//     output logic [SIZE_DATA-1:0]     o_data [NUMBER_ARR],
//     output logic                     o_done
// );
//     // Block update i
//     logic [$clog2(SIZE_DATA)-1:0] i, i_n;
//     logic w_init_i, w_update_i;
//     always_comb begin
//         i = (w_init_i) ? 1 : i_n;
//     end
//     always_ff @(posedge i_clk or negedge i_rst_n) begin
//         if(~i_rst_n)
//             i_n     <= '0;
//         else
//             i_n     <= (w_update_i) ? i + 1'b1 : i;
//     end

//     // Block update j
//     logic [$clog2(SIZE_DATA)-1:0] j, j_n;
//     logic w_init_j, w_update_j;
//     always_comb begin
//         j = (w_init_j) ? i - 1 : j_n;
//     end
//     always_ff @(posedge i_clk or negedge i_rst_n) begin
//         if(~i_rst_n)
//             j_n     <= '0;
//         else
//             j_n     <= (w_update_j) ? j - 1 : j;
//     end

//     // Block FSM
//     typedef enum logic [1:0] {
//         IDLE,
//         LOAD,
//         COMPARE,
//         DONE
//     } state_e;
//     state_e state, n_state;

//     logic [SIZE_DATA-1:0] arr [0:NUMBER_ARR-1];
//     always_comb begin
//         for(int i = 0; i < NUMBER_ARR; i++) begin
//             arr[i] = (i_start) ? i_data[i] : '0;
//         end
//     end

//     logic [SIZE_DATA-1:0] key;
//     assign key = (state == LOAD) ? arr[i] : key;
//     assign arr[j+1] = (state == DONE) ? key : arr[j+1];

//     logic w_update_load, w_update_compare;

//     assign w_update_load = (i < NUMBER_ARR);
//     assign w_update_compare = (arr[j] > key);

//     always_comb begin : proc_next_state_FSM
//         case(state)
//             IDLE: 
//                 n_state = (i_start) ? LOAD : IDLE;
//             LOAD:
//                 n_state = (w_update_load) ? COMPARE : DONE;
//             COMPARE:
//                 n_state = (w_update_compare) ? COMPARE : DONE;
//             DONE:
//                 n_state = (w_update_load) ? LOAD : IDLE;
//         endcase
//     end
//     always_ff @(posedge i_clk or negedge i_rst_n) begin : proc_next_state_FSM
//         if(~i_rst_n)
//             state <= IDLE;
//         else
//             state <= n_state;
//     end
//     always_comb begin : proc_output_FSM
//         case(state)
//             IDLE: begin
//                 w_init_i = 1'b1;
//                 w_init_j = 1'b1;
//                 w_update_i = 1'b0;
//                 w_update_j = 1'b0;
//             end
//             LOAD: begin
//                 w_init_i = 1'b0;
//                 w_init_j = 1'b1;
//                 w_update_i = 1'b0;
//                 w_update_j = 1'b0;
//             end
//             COMPARE: begin
//                 w_init_i = 1'b0;
//                 w_init_j = 1'b0;
//                 w_update_i = 1'b0;
//                 w_update_j = 1'b1;
//             end 
//             DONE: begin
//                 w_init_i = 1'b0;
//                 w_init_j = 1'b0;
//                 w_update_i = 1'b1;
//                 w_update_j = 1'b0;
//             end
//             default: begin
//                 w_init_i = 1'b1;
//                 w_init_j = 1'b1;
//                 w_update_i = 1'b0;
//                 w_update_j = 1'b0;
//             end
//         endcase
//     end

//     always_ff @(posedge i_clk or negedge i_rst_n or negedge w_update_load) begin
//         if(~i_rst_n)
//             o_done <= 1'b0;
//         else if(~w_update_load)
//             o_done <= 1'b1;
//         else
//             o_done <= 1'b0;
//     end

// endmodule

// // version 2
module insertionSort #(
    parameter SIZE_DATA  = 8,
    parameter NUMBER_ARR = 8
)(
    input  logic                     i_clk,
    input  logic                     i_rst_n,
    input  logic                     i_start,
    input  logic [SIZE_DATA-1:0]     i_data [NUMBER_ARR],
    output logic [SIZE_DATA-1:0]     o_data [NUMBER_ARR],
    output logic                     o_done
);
    // Thanh ghi và biến
    logic [$clog2(NUMBER_ARR)-1:0] i, j;
    logic [SIZE_DATA-1:0] arr [0:NUMBER_ARR-1];
    logic [SIZE_DATA-1:0] key_reg;
    logic load_condition, compare_condition;

    // FSM
    typedef enum logic [2:0] {
        IDLE,
        LOAD,
        COMPARE,
        INSERT,
        CHECK
    } state_e;
    state_e state, n_state;

    // Consolidated arr updates in a single always_ff block
    always_ff @(posedge i_clk or negedge i_rst_n) begin
        if (~i_rst_n) begin
            for (int k = 0; k < NUMBER_ARR; k++) begin
                arr[k] <= '0;
            end
        end else if (i_start && state == IDLE) begin
            // Initialize arr with input data
            for (int k = 0; k < NUMBER_ARR; k++) begin
                arr[k] <= i_data[k];
            end
        end else if (state == COMPARE && compare_condition) begin
            // Shift: arr[j+1] = arr[j]
            arr[j+1] <= arr[j];
        end else if (state == INSERT) begin
            // Insert: arr[j+1] = key_reg
            arr[j+1] <= key_reg;
        end
    end

    // Pipeline: Lấy key
    always_ff @(posedge i_clk or negedge i_rst_n) begin
        if (~i_rst_n)
            key_reg <= '0;
        else if (state == LOAD)
            key_reg <= arr[i];
    end

    // Pipeline: So sánh
    always_ff @(posedge i_clk or negedge i_rst_n) begin
        if (~i_rst_n)
            compare_condition <= 1'b0;
        else if (state == COMPARE)
            compare_condition <= (j < NUMBER_ARR && arr[j] > key_reg); // Add j bounds check
    end

    // Cập nhật i, j
    always_ff @(posedge i_clk or negedge i_rst_n) begin
        if (~i_rst_n) begin
            i <= '0;
            j <= '0;
        end else begin
            case (state)
                IDLE: begin
                    i <= 1;
                    j <= '0;
                end
                LOAD: begin
                    j <= i - 1;
                end
                COMPARE: begin
                    if (compare_condition)
                        j <= j - 1;
                end
                CHECK: begin
                    i <= i + 1;
                end
            endcase
        end
    end

    // Điều kiện chuyển trạng thái
    always_ff @(posedge i_clk or negedge i_rst_n) begin
        if (~i_rst_n)
            load_condition <= 1'b0;
        else
            load_condition <= (i < NUMBER_ARR);
    end

    // FSM chuyển trạng thái
    always_comb begin
        case (state)
            IDLE:    n_state = (i_start) ? LOAD : IDLE;
            LOAD:    n_state = (load_condition) ? COMPARE : CHECK;
            COMPARE: n_state = (compare_condition) ? INSERT : CHECK;
            INSERT:  n_state = COMPARE;
            CHECK:   n_state = (load_condition) ? LOAD : IDLE;
            default: n_state = IDLE;
        endcase
    end

    always_ff @(posedge i_clk or negedge i_rst_n) begin
        if (~i_rst_n)
            state <= IDLE;
        else
            state <= n_state;
    end

    // Đầu ra
    always_ff @(posedge i_clk or negedge i_rst_n) begin
        if (~i_rst_n) begin
            for (int k = 0; k < NUMBER_ARR; k++)
                o_data[k] <= '0;
        end else if (state == CHECK && !load_condition) begin
            for (int k = 0; k < NUMBER_ARR; k++)
                o_data[k] <= arr[k];
        end
    end

    always_ff @(posedge i_clk or negedge i_rst_n) begin
        if (~i_rst_n)
            o_done <= 1'b0;
        else if (state == CHECK && !load_condition)
            o_done <= 1'b1;
        else
            o_done <= 1'b0;
    end
endmodule
