# Module ROM

```SystemVerilog
    module single_port_rom #(
        parameter DATA_WIDTH=8  ,
        parameter ADDR_WIDTH=16  
    )(
        input clk                       ,
        input [(ADDR_WIDTH-1):0] addr   ,
        output reg [(DATA_WIDTH-1):0] q 
    );
```

| Signal | Type | Size | Func |
|--------|------|------|------|
| clk    | input | 1 | clock system |
| addr   | input | ADDR_WIDTH | Address |
| q      | output | DATA_WIDTH | Hex |

# Subarray_Slipitter 

```SystemVerilog
    module subarray_splitter #(
        parameter SIZE_DATA         = 8     , // 1 element = 8bit
        parameter ADDR_ROM          = 16    , // 64K = 65536 element
        parameter SIZE_SUBARRAY     = 32      // 1 score-sort = 32 element
        // parameter ADDR_SUBARRAY     = 11      // 2048 subarray
    )(
        input logic                                     i_clk           ,
        input logic                                     i_rst_n         ,
        input logic                                     i_start         ,

        input logic [SIZE_DATA-1:0]                     i_rom_data      ,
        output logic [ADDR_ROM-1:0]                     o_rom_addr      ,

        output logic                                    o_fifo_wr_en    ,
        output logic [SIZE_DATA*SIZE_SUBARRAY-1:0]      o_fifo_data     ,

        output logic                                    o_done          
    );
```

| Signal | Type | Size | Func ||--------|------|------|------|
| i_clk  | input | 1 | Clock system |
| i_rst_n | input | 1 | Reset active low |
| i_start | input | 1 | The signal allow module start |
| i_rom_data | input | SIZE_DATA | Data input |
| o_rom_addr | output | ADDR_ROM | Address using read value from ROM |
| o_fifo_wr_en | output | 1 | The signal write enable fifo |
| o_fifo_data | output | SIZE_DATA*SIZE_SUBARRAY | Data compress receive score-sort |
| o_done | output | 1 | The signal |