module compare_block #(
    parameter SIZE_DATA = 8
)(
    input logic [SIZE_DATA-1:0]     i_data_a        ,
    input logic [SIZE_DATA-1:0]     i_data_b        ,
    output logic [SIZE_DATA-1:0]    o_less_data     ,
    output logic [SIZE_DATA-1:0]    o_greater_data  
);

logic w_compare_result;
assign w_compare_result = (i_data_a < i_data_b);

always_comb begin
    o_less_data = (w_compare_result) ? i_data_a : i_data_b;
    o_greater_data = (w_compare_result) ? i_data_b : i_data_a;
end

endmodule
