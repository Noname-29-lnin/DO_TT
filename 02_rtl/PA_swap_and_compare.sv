module PA_swap_and_compare #(
    parameter SIZE_DATA = 8
)(
    input logic [SIZE_DATA-1:0]     i_data_a        ,
    input logic [SIZE_DATA-1:0]     i_data_b        ,
    input logic                     i_mode          ,
    output logic [SIZE_DATA-1:0]    o_less_data     ,
    output logic [SIZE_DATA-1:0]    o_greater_data  
);

logic w_compare_result;
assign w_compare_result = (i_data_a < i_data_b);

logic w_after_compare_result;
assign w_after_compare_result = w_compare_result ^ i_mode;

always_comb begin
    o_less_data = (w_after_compare_result) ? i_data_a : i_data_b;
    o_greater_data = (w_after_compare_result) ? i_data_b : i_data_a;
end

endmodule
