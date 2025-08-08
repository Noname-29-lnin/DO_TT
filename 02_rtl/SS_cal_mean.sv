// Using Cal mean of all address begin si from ei
// 
module SS_cal_mean #(
    parameter DATA_WIDTH=8	,
	parameter ADDR_WIDTH=6	
)(
    input logic                         i_clk       ,
    input logic                         i_rst_n     ,
    
    input logic                         i_en_mean   ,

    input logic [ADDR_WIDTH-1:0]        i_addr_si   ,
    input logic [ADDR_WIDTH-1:0]        i_addr_ei   ,
    input logic [DATA_WIDTH-1:0]        i_data_ram  ,
    
    output logic                        o_re_ram    ,
    output logic [ADDR_WIDTH-1:0]       o_addr_ram  ,
    output logic [DATA_WIDTH-1:0]       o_mean      ,
    output logic                        o_done      
);

logic [DATA_WIDTH:0] w_addr_divisor, w_data_dividend;
assign w_addr_divisor = {{(DATA_WIDTH+1-ADDR_WIDTH){1'b0}}, (i_addr_ei - i_addr_si)};

SS_Division #(
    .SIZE_DATA  (32)
) Division_unit (
  .i_clk        (i_clk),
  .i_rst_n      (i_rst_n),
  input  logic                          i_en_division,
  input logic signed [SIZE_DATA-1:0]    i_dividend,
  input logic signed [SIZE_DATA-1:0]    i_divisor,
  output logic signed [SIZE_DATA-1:0]   o_quotient,
  output logic signed [SIZE_DATA-1:0]   o_remainder,
  output logic                          o_valid
);

endmodule
