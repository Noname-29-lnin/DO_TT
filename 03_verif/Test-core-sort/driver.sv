module driver #(
    parameter SIZE_DATA = 8,
    parameter NUM_VALS  = 8
)(
    output logic [NUM_VALS-1:0][SIZE_DATA-1:0] o_data
);

    logic [SIZE_DATA-1:0] mem [NUM_VALS-1:0]; // Unpacked array

    initial begin
        $readmemh("./unsorted.txt", mem);
        for (int i = 0; i < NUM_VALS; i++) begin
            o_data[i] = mem[i];
        end
    end

endmodule