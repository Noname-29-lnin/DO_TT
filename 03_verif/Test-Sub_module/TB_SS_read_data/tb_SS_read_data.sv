`timescale 1ns/1ps
`
module tb_SS_read_data();

SS_read_data #(
    .SIZE_ADDR  (6)
) DUT (
    .i_clk              (),
    .i_rst_n            (),
    .i_start_read_data  (),
    .i_en_read_data     (),
    .i_si_ram           (),
    .i_ei_ram           (),
    .o_re_ram           (),
    .o_addr_ram         (),
    .o_done_read_data   ()
);

endmodule

