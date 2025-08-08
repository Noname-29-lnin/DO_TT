// Using read data by address in BRAM
module SS_read_data #(
    parameter SIZE_ADDR = 6
)(
    input logic                     i_clk       ,
    input logic                     i_rst_n     ,

    input logic                     i_start_read_data,
    input logic                     i_en_read_data,

    input logic [SIZE_ADDR-1:0]     i_si_ram    ,
    input logic [SIZE_ADDR-1:0]     i_ei_ram    ,

    output logic                    o_re_ram    ,
    output logic [SIZE_ADDR-1:0]    o_addr_ram  ,
    output logic                    o_done_raad_data
);

logic [SIZE_ADDR-1:0] w_next_addr_ram;
assign w_next_addr_ram = o_addr_ram + 1'b1;

logic w_update_start;
SS_detect_edge detect_edge_unit(
    .i_clk       (i_clk),
    .i_rst_n     (i_rst_n),
    .i_pos_edge  (1'b1),
    .i_signal    (i_start_read_data),
    .o_signal    (w_update_start)
);

logic w_compare_ei, w_compare_ei_p;
assign w_compare_ei_p = ~|(i_ei_ram^o_addr_ram);
always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        w_compare_ei  <= '0; 
    end else begin
        w_compare_ei  <= w_compare_ei_p; 
    end
end

logic w_update_en;
assign w_update_en = i_en_read_data & (~w_compare_ei);


always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_o_addr_ram
    if(~i_rst_n) begin
        o_addr_ram  <= '0; 
    end else begin
        o_addr_ram  <= (w_update_start) ? i_si_ram : ((w_update_en) ? w_next_addr_ram : o_addr_ram); 
    end
end

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_o_re_ram
    if(~i_rst_n)
        o_re_ram <= 1'b0;
    else
        o_re_ram <= w_update_en;
end

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_o_done_read_data
    if(~i_rst_n)
        o_done_raad_data <= 1'b0;
    else
        o_done_raad_data <= w_compare_ei;
end

endmodule
