module SS_read_data #(
    parameter SIZE_ADDR = 6 ,
    parameter SIZE_DATA = 8
)(
    input logic                     i_clk               ,
    input logic                     i_rst_n             ,
    
    input logic                     i_start_read_data   ,
    input logic                     i_en_read_data      ,

    input logic [SIZE_ADDR-1:0]     i_si_ram            ,
    input logic [SIZE_ADDR-1:0]     i_ei_ram            ,

    input logic [SIZE_DATA-1:0]     i_data_ram          ,
    output logic [SIZE_ADDR-1:0]    o_addr_ram          ,
    output logic [SIZE_DATA-1:0]    o_data_ram          ,

    output logic                    o_data_valid        ,
    output logic                    o_done_read_data    
);

// processing the signal detecting i_start_read_data
logic w_update_start;
SS_detect_edge detect_edge_unit(
    .i_clk       (i_clk),
    .i_rst_n     (i_rst_n),
    .i_pos_edge  (1'b1),
    .i_signal    (i_start_read_data),
    .o_signal    (w_update_start)
);

// processing the signal detecting i_en_read_data
logic w_update_en;
logic w_update_en_start;
logic w_update_en_done;
always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_update_en_start
    if(~i_rst_n) begin
        w_update_en_start <= 1'b0; 
    end else begin
        w_update_en_start <= (w_update_start) ? 1'b1 : ((w_update_en_done) ? 1'b0 : w_update_en_start); 
    end
end
assign w_update_en = i_en_read_data & (w_update_en_start);
logic w_en_save;
always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_w_en_save
    if(~i_rst_n)
        w_en_save <= 1'b0;
    else
        w_en_save <= i_en_read_data;
end
// processing the compare of i_ei_ram and o_addr_ram
logic w_compare_ei;
assign w_compare_ei = (i_ei_ram == o_addr_ram) & w_update_en_start;
always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        w_update_en_done  <= '0; 
    end else begin
        w_update_en_done  <= w_compare_ei; 
    end
end

// processing o_addr_ram
logic [SIZE_ADDR-1:0] w_next_addr_ram;
assign w_next_addr_ram = o_addr_ram + 1'b1;
always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_o_addr_ram
    if(~i_rst_n) begin
        o_addr_ram  <= '0; 
    end else begin
        o_addr_ram  <= (w_update_start) ? i_si_ram : ((w_update_en) ? w_next_addr_ram :  o_addr_ram); 
    end
end

// processing o_data_ram and 0_data_valid
always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_o_data_valid
    if(~i_rst_n)
        o_data_valid    <= 1'b0;
    else
        o_data_valid    <= (w_en_save & w_update_en_start & ~w_update_en_done);
end
assign o_data_ram = (o_data_valid) ? i_data_ram : '0;

// processing o_done_read_data
always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_o_done
    if(~i_rst_n) 
        o_done_read_data <= 1'b0;
    else
        o_done_read_data <= w_update_en_done;
end

endmodule
