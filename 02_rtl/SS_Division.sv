// Using division two number (start when i_en_division is hight)
// o_quotient = i_dividend/i_divisor
// o_remainder = i_dividend%i_divisor
// o_valid perform data valid
module SS_Division #(
    parameter SIZE_DATA = 32
)(
  input  logic                        i_clk,
  input  logic                        i_rst_n,
  input  logic                        i_en_division,
  input  logic signed [SIZE_DATA-1:0] i_dividend,
  input  logic signed [SIZE_DATA-1:0] i_divisor,
  output logic signed [SIZE_DATA-1:0] o_quotient,
  output logic signed [SIZE_DATA-1:0] o_remainder,
  output logic                        o_valid
);

  typedef enum logic [2:0] {
    IDLE,
    SHIFT,
    SUBTRACT,
    RESTORE
  } State;

  State state;

  logic signed [SIZE_DATA-1:0] quotient_reg;
  logic signed [SIZE_DATA-1:0] remainder_reg;
  logic signed [SIZE_DATA-1:0] dividend_reg;
  logic signed [SIZE_DATA-1:0] divisor_reg;
  logic signed_divisor;
  logic [SIZE_DATA:0] remainder_tmp;
  logic [SIZE_DATA-1:0] quotient_tmp;
  logic sign_quotient;
  logic sign_remainder;

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
          quotient_tmp <= quotient_tmp << 1;
          remainder_tmp <= (remainder_tmp << 1) | dividend_reg[SIZE_DATA-1];
          state <= SUBTRACT;
        end

        SUBTRACT: begin
          remainder_tmp <= remainder_tmp - (signed_divisor ? -divisor_reg : divisor_reg);
          state <= RESTORE;
        end

        RESTORE: begin
          if (remainder_tmp[SIZE_DATA] || remainder_tmp[SIZE_DATA:1] >= (signed_divisor ? -divisor_reg : divisor_reg)) begin
            quotient_tmp <= quotient_tmp | 1;
            remainder_tmp <= remainder_tmp + (signed_divisor ? -divisor_reg : divisor_reg);
            state <= SHIFT;
          end else begin
            quotient_reg  <= quotient_tmp;
            remainder_reg <= remainder_tmp[SIZE_DATA-1:0];
            o_valid       <= 1;
            state         <= IDLE;
          end
        end
      endcase
    end
  end

  always_comb begin
    signed_divisor  = (divisor_reg < 0);
    sign_quotient   = (dividend_reg < 0) ^ (divisor_reg < 0);
    sign_remainder  = (dividend_reg < 0);

    o_quotient  = sign_quotient  ? -quotient_reg  : quotient_reg;
    o_remainder = sign_remainder ? -remainder_reg : remainder_reg;
  end

endmodule
