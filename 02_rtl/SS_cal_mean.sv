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

logic [DATA_WIDTH:0] w_addr_divisor, w_data_dividend, w_quotient;
assign w_addr_divisor = {{(DATA_WIDTH+1-ADDR_WIDTH){1'b0}}, (i_addr_ei - i_addr_si)};

logic w_done_read_data;

SS_read_data #(
    .SIZE_ADDR (ADDR_WIDTH)
) Read_data_unit (
    .i_clk              (i_clk),
    .i_rst_n            (i_rst_n),

    .i_start_read_data  (i_en_mean),
    .i_en_read_data     (w_en_next_value_cal_sum),
    .i_si_ram           (i_addr_si),
    .i_ei_ram           (i_addr_ei),
    .o_re_ram           (o_re_ram),
    .o_addr_ram         (o_addr_ram),
    .o_done_read_data   (w_done_read_data)
);

logic w_done_cal_sum, w_en_next_value_cal_sum;
SS_cal_sum #(
    .SIZE_DATA (DATA_WIDTH)
) Cal_sum_unit (
    .i_clk          (i_clk),
    .i_rst_n        (i_rst_n),
    
    .i_start_cal_sum(i_en_mean),
    .i_en_cal_sum   (o_re_ram),
    .i_en_out_sum   (w_done_read_data),
    
    .i_data         (i_data_ram),

    .o_sum          (w_data_dividend),
    .o_en_next_value(w_en_next_value_cal_sum),
    .o_done         (w_done_cal_sum)
);

SS_Division #(
    .SIZE_DATA  (DATA_WIDTH+1)
) Division_unit (
  .i_clk        (i_clk),
  .i_rst_n      (i_rst_n),
  .i_en_division(w_done_cal_sum),
  .i_dividend   (w_data_dividend),
  .i_divisor    (w_addr_divisor),
  .o_quotient   (w_quotient),
  .o_remainder  (),
  .o_valid      (o_done)
);
assign o_mean = w_quotient[DATA_WIDTH-1:0];

endmodule
