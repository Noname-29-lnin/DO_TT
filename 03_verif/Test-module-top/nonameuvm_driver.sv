function automatic logic [SIZE_NUMBER*NUM_VALS-1:0] random_value;
    input int SIZE_NUMBER;
    input int NUM_VALS;

    logic [SIZE_NUMBER*NUM_VALS-1:0] frv_o_data;
    logic [SIZE_NUMBER-1:0] rand_val;

    begin
        frv_o_data = '0;
        for (int i = 0; i < NUM_VALS; i++) begin
            rand_val = $urandom_range(0, (1 << SIZE_NUMBER) - 1);
            frv_o_data[i*SIZE_NUMBER +: SIZE_NUMBER] = rand_val;
        end
        return frv_o_data;
    end
endfunction
