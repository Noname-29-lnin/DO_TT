module compare_block_reg #(
    parameter SIZE_DATA = 8
)(
    input  logic                     i_clk,
    input  logic                     i_rst_n,
    input  logic [SIZE_DATA-1:0]     i_data_1,
    input  logic [SIZE_DATA-1:0]     i_data_2,
    output logic [SIZE_DATA-1:0]     o_less_data,
    output logic [SIZE_DATA-1:0]     o_greater_data
);

    logic w_compare_less;
    assign w_compare_less = (i_data_1 < i_data_2);

    logic [SIZE_DATA-1:0] w_data_less, w_data_greater;
    assign w_data_less    = w_compare_less ? i_data_1 : i_data_2;
    assign w_data_greater = w_compare_less ? i_data_2 : i_data_1;

    always_ff @(posedge i_clk or negedge i_rst_n) begin
        if (!i_rst_n) begin
            o_less_data    <= '0;
            o_greater_data <= '0;
        end else begin
            o_less_data    <= w_data_less;
            o_greater_data <= w_data_greater;
        end
    end

endmodule
