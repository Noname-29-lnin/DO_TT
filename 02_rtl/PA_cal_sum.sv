module SS_cal_sum #(
    parameter SIZE_DATA = 8
)(
    input logic                     i_clk   ,
    input logic                     i_rst_n ,
    
    input logic                     i_start_cal_sum ,
    input logic                     i_en_cal_sum    ,
    input logic                     i_en_out_sum    ,
    
    input logic [SIZE_DATA-1:0]     i_data          ,

    output logic [SIZE_DATA:0]      o_sum           ,
    output logic                    o_en_next_value ,
    output logic                    o_done          
);

logic w_update_start;
SS_detect_edge detect_edge_unit(
    .i_clk       (i_clk),
    .i_rst_n     (i_rst_n),
    .i_pos_edge  (1'b1),
    .i_signal    (i_start_cal_sum),
    .o_signal    (w_update_start)
);

logic w_reset_value_temp_sum;
assign w_reset_value_temp_sum = w_update_start | o_done;

logic w_update_cal_sum;
assign w_update_cal_sum = i_en_cal_sum;
logic [SIZE_DATA:0] w_temp_sum, w_next_sum;
assign w_next_sum = w_temp_sum + {1'b0, i_data};
always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n)
        w_temp_sum <= '0;
    else
        w_temp_sum <= w_reset_value_temp_sum ? '0 : ((w_update_cal_sum) ? w_next_sum : w_temp_sum);
end

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_out_sum
    if(~i_rst_n)
        o_sum <= '0;
    else
        o_sum <= (i_en_out_sum) ? w_temp_sum : o_sum;
end
always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_o_en_next_value
    if(~i_rst_n)
        o_en_next_value <= '0;
    else
        o_en_next_value <= w_update_cal_sum & (~o_done);
end

SS_detect_edge detect_edge_unit_2(
    .i_clk       (i_clk),
    .i_rst_n     (i_rst_n),
    .i_pos_edge  (1'b1),
    .i_signal    (i_en_out_sum),
    .o_signal    (o_done)
);

endmodule
