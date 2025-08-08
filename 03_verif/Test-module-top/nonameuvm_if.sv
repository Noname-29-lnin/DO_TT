interface nonameuvm_if;
    logic if_clk, if_rst_n;
    logic if_i_start;
    logic if_o_done;

    modport DUT (
        input input_ports,
        output output_ports
    );

endinterface //nonameuvm_if