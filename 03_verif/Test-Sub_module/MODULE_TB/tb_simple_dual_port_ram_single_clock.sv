module tb_simple_dual_port_ram_single_clock#(
    parameter DATA_WIDTH = 8,
    parameter ADDR_WIDTH = 6,
    parameter MEM_INIT_FILE = "./mem_init.hex"
)(
    input  logic                     clk,
    input  logic                     we,
    input  logic [DATA_WIDTH-1:0]    data,
    input  logic [ADDR_WIDTH-1:0]    read_addr,
    input  logic [ADDR_WIDTH-1:0]    write_addr,
    output logic [DATA_WIDTH-1:0]    q
);

    logic [DATA_WIDTH-1:0] ram [0:(2**ADDR_WIDTH)-1];

    // Load toàn bộ file vào RAM ban đầu
    initial begin
        if (MEM_INIT_FILE != "") begin
            $display("Initial load memory contents from %s", MEM_INIT_FILE);
            $readmemh(MEM_INIT_FILE, ram);
        end
    end

    // Đọc và ghi
    always_ff @(posedge clk) begin
        // Đọc giá trị tại read_addr
        q <= ram[read_addr];

        // Nếu ghi thì ghi vào RAM
        if (we)
            ram[write_addr] <= data;
    end

endmodule
