module subarray_splitter #(
    parameter SIZE_DATA         = 8     , // 1 element = 8bit
    parameter ADDR_ROM          = 16    , // 64K = 65536 element
    parameter SIZE_SUBARRAY     = 32      // 1 score-sort = 32 element
    // parameter ADDR_SUBARRAY     = 11      // 2048 subarray
)(
    input logic                                     i_clk           ,
    input logic                                     i_rst_n         ,
    input logic                                     i_start         ,

    input logic [SIZE_DATA-1:0]                     i_rom_data      ,
    output logic [ADDR_ROM-1:0]                     o_rom_addr      ,

    output logic                                    o_fifo_wr_en    ,
    output logic [SIZE_DATA*SIZE_SUBARRAY-1:0]      o_fifo_data     ,

    output logic                                    o_done          
);

logic [SIZE_DATA-1:0] w_rom_data;
logic [ADDR_ROM-1:0] w_rom_adrr_rd;
simple_dual_port_ram_single_clock #(
	.DATA_WIDTH     (SIZE_DATA)	,
	.ADDR_WIDTH     (ADDR_ROM)	
) arr_temp (
    .clk        (i_clk),
	.we         (i_start), 
	.data       (i_rom_data),
    .write_addr (o_rom_addr),
	.read_addr  (w_rom_adrr_rd), 
	.q          (w_rom_data)
);



endmodule
