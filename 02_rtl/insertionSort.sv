module insertionSort #(
    parameter SIZE_DATA     = 8,
    parameter NUMBER_ARR    = 8
)(
    input  logic                     i_clk,
    input  logic                     i_rst_n,
    input  logic                     i_start,
    input  logic [SIZE_DATA-1:0]     i_data [NUMBER_ARR],
    output logic [SIZE_DATA-1:0]     o_data [NUMBER_ARR],
    output logic                     o_done
);

    typedef enum logic [2:0] {
        IDLE,
        LOAD,
        CHECK,
        SHIFT,
        INSERT,
        DONE
    } state_e;

    state_e state, n_state;

    logic [SIZE_DATA-1:0] arr [NUMBER_ARR];
    logic [SIZE_DATA-1:0] key;
    logic [3:0] i, j;

    // FSM chuyển trạng thái
    always_comb begin
        case (state)
            IDLE:    n_state = (i_start) ? LOAD : IDLE;
            LOAD:    n_state = CHECK;
            CHECK:   n_state = (i < NUMBER_ARR) ? SHIFT : DONE;
            SHIFT:   n_state = (j < 4'd15 && arr[j] > key) ? SHIFT : INSERT; // j can't be negative, so j >= 0 replaced by valid logic
            INSERT:  n_state = CHECK;
            DONE:    n_state = IDLE;
            default: n_state = IDLE;
        endcase
    end

    always_ff @(posedge i_clk or negedge i_rst_n) begin
        if (!i_rst_n)
            state <= IDLE;
        else
            state <= n_state;
    end

    always_ff @(posedge i_clk or negedge i_rst_n) begin
        if (!i_rst_n) begin
            i <= 1;
            j <= 0;
            key <= 0;
            o_done <= 0;
            for (int k = 0; k < NUMBER_ARR; k++) begin
                arr[k] <= 0;
                o_data[k] <= 0;
            end
        end else begin
            case (state)
                LOAD: begin
                    for (int k = 0; k < NUMBER_ARR; k++)
                        arr[k] <= i_data[k];
                    i <= 1;
                end
                CHECK: begin
                    key <= arr[i];
                    j <= i - 1;
                end
                SHIFT: begin
                    if (arr[j] > key) begin
                        arr[j+1] <= arr[j];
                        j <= j - 1;
                    end
                end
                INSERT: begin
                    arr[j+1] <= key;
                    i <= i + 1;
                end
                DONE: begin
                    for (int k = 0; k < NUMBER_ARR; k++)
                        o_data[k] <= arr[k];
                    o_done <= 1;
                end
                default: begin
                    o_done <= 0;
                end
            endcase
        end
    end

endmodule
