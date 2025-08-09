module PA_division_algo #(
    parameter SIZE_DATA = 32
)(
  input  logic                      i_clk,
  input  logic                      i_rst_n,
  input  logic                      i_en_division,
  input  logic [SIZE_DATA-1:0]      i_dividend,  // unsigned
  input  logic [SIZE_DATA-1:0]      i_divisor,   // unsigned
  output logic [SIZE_DATA-1:0]      o_quotient,  // unsigned
  output logic [SIZE_DATA-1:0]      o_remainder, // unsigned
  output logic                      o_valid
);

  typedef enum logic [2:0] {
    IDLE,
    SHIFT,
    SUBTRACT,
    RESTORE
  } State;

  State state;

  logic [SIZE_DATA-1:0] quotient_reg;
  logic [SIZE_DATA-1:0] remainder_reg;
  logic [SIZE_DATA-1:0] dividend_reg;
  logic [SIZE_DATA-1:0] divisor_reg;
  logic [SIZE_DATA:0]   remainder_tmp; // 1 bit wider
  logic [SIZE_DATA-1:0] quotient_tmp;

  always_ff @(posedge i_clk or negedge i_rst_n) begin
    if (!i_rst_n) begin
      state         <= IDLE;
      quotient_reg  <= 0;
      remainder_reg <= 0;
      dividend_reg  <= 0;
      divisor_reg   <= 0;
      o_valid       <= 0;
    end else begin
      case (state)
        IDLE: begin
          o_valid <= 0;
          if (i_en_division && i_divisor != 0) begin
            dividend_reg <= i_dividend;
            divisor_reg  <= i_divisor;
            quotient_tmp <= 0;
            remainder_tmp <= 0;
            state <= SHIFT;
          end
        end

        SHIFT: begin
          quotient_tmp  <= quotient_tmp << 1;
          remainder_tmp <= (remainder_tmp << 1) | dividend_reg[SIZE_DATA-1];
          state <= SUBTRACT;
        end

        SUBTRACT: begin
          remainder_tmp <= remainder_tmp - divisor_reg;
          state <= RESTORE;
        end

        RESTORE: begin
          if (!remainder_tmp[SIZE_DATA] && remainder_tmp >= divisor_reg) begin
            quotient_tmp  <= quotient_tmp | 1;
            remainder_tmp <= remainder_tmp - divisor_reg;
          end
          if (/* finish condition here */ 1) begin
            quotient_reg  <= quotient_tmp;
            remainder_reg <= remainder_tmp[SIZE_DATA-1:0];
            o_valid       <= 1;
            state         <= IDLE;
          end else begin
            state <= SHIFT;
          end
        end
      endcase
    end
  end

  always_comb begin
    o_quotient  = quotient_reg;
    o_remainder = remainder_reg;
  end

endmodule
