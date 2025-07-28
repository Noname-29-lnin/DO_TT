module partition(xin, xout, i, j, loc_in, loc_out, clk, init, complete, read, write);
  parameter N = 8;
  input clk, init, read, write;
  input [31:0] xin;
  input [31:0] i, j;
  input [31:0] loc_in;
  output reg [31:0] loc_out, xout;
  output reg complete;
  reg [31:0] vec[0:N-1];
  reg [31:0] right, left, loc;
  reg set;
  reg [31:0] temp, count;
  reg [3:0] state;
  parameter S0=4'b0000, S1=4'b0001, S2=4'b0010, S3=4'b0011, S4=4'b0100,
            S5=4'b0101, S6=4'b0110, S7=4'b0111, S8=4'b1000;

  always @(posedge clk) begin
    // Read and write operations
    if (read && count != N) begin
      vec[count] <= xin;
      count <= count + 1;
    end
    else if (write && count != N) begin
      xout <= vec[count];
      count <= count + 1;
    end
    else if (~read && ~write) begin
      count <= 0;
    end

    // State machine
    case (state)
      S0: begin
        state <= init ? S1 : S0;
        complete <= 0;
        loc <= loc_in;
        left <= i;
        right <= j;
      end
      S1: begin
        complete <= 0;
        if (vec[loc] <= vec[right] && loc != right)
          state <= S2;
        else if (vec[loc] > vec[right]) begin
          state <= S4;
          // Swap vec[loc] and vec[right]
          temp <= vec[loc];
          vec[loc] <= vec[right];
          vec[right] <= temp;
          loc <= right;
        end
        else if (loc == right)
          state <= S3;
      end
      S2: begin
        if (vec[loc] <= vec[right] && loc != right) begin
          state <= S2;
          right <= right - 1;
        end
        else if (vec[loc] > vec[right]) begin
          state <= S4;
          // Swap vec[loc] and vec[right]
          temp <= vec[loc];
          vec[loc] <= vec[right];
          vec[right] <= temp;
          loc <= right;
        end
        else if (loc == right)
          state <= S3;
      end
      S3: begin
        state <= S0;
        set <= 1;
        complete <= 1;
        loc_out <= loc;
      end
      S4: begin
        if (vec[loc] >= vec[left] && left != loc)
          state <= S5;
        else if (vec[loc] < vec[left]) begin
          state <= S7;
          // Swap vec[loc] and vec[left]
          temp <= vec[loc];
          vec[loc] <= vec[left];
          vec[left] <= temp;
          loc <= left;
        end
        else if (loc == left)
          state <= S6;
      end
      S5: begin
        if (vec[loc] >= vec[left] && left != loc) begin
          state <= S5;
          left <= left + 1;
        end
        else if (vec[loc] < vec[left]) begin
          state <= S7;
          // Swap vec[loc] and vec[left]
          temp <= vec[loc];
          vec[loc] <= vec[left];
          vec[left] <= temp;
          loc <= left;
        end
        else if (loc == left)
          state <= S6;
      end
      S6: begin
        state <= init ? S0 : S6;
        set <= 1;
        complete <= 1;
        loc_out <= loc;
      end
      S7: begin
        state <= S1;
      end
      default: state <= S0; // Added for robustness
    endcase
  end
endmodule
