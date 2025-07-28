module SS_rom_addr #(
    parameter ADDR_ROM = 16
)(
    input logic                 i_clk       ,
    input logic                 i_rst_n     ,
    input logic                 i_we        , // arr_temp write enable
    output logic [ADDR_ROM-1:0] o_rom_addr  
);

logic [ADDR_ROM-1:0] w_pre_addr, w_next_addr;
assign w_next_addr = o_rom_addr + 1'b1;
assign w_pre_addr = (i_we) ? w_next_addr : '0;

always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n)
        o_rom_addr <= '0;
    else 
        o_rom_addr <= w_pre_addr;
end

endmodule
