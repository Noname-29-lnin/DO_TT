`timescale 1ns/1ps
module tb_SS_cal_sum();

SS_cal_sum #(
    .SIZE_DATA (8)
) DUT (
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

endmodule

