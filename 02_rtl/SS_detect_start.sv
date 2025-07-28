module SS_detect_start(
    input logic                         i_clk       ,
    input logic                         i_rst_n     ,
    input logic                         i_start     ,
    input logic                         i_done      ,
    output logic                        o_w_start   
);

logic w_next_start;
assign o_w_start = (i_done) ? 1'b0 : w_next_start;

always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n)
        w_next_start <= 1'b0;
    else
        w_next_start <= ((~o_w_start) & (i_start)) ? (~o_w_start) : (o_w_start);
end

endmodule
