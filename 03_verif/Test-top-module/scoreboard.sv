module scoreboard(
    input logic i_done,
    input bit i_check_sorted
);

always_comb begin
    if(i_done == 1'b1 && i_check_sorted == 1'b1) begin
        $write("-> PASS");
    end
end

endmodule
