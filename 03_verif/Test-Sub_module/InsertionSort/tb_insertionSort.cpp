#include <verilated.h>
#include "VinsertionSort.h"
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    VinsertionSort* top = new VinsertionSort;

    // Reset
    top->i_clk = 0;
    top->i_rst_n = 0;
    top->i_start = 0;
    for (int i = 0; i < 10; ++i) {
        top->i_clk ^= 1;
        top->eval();
    }
    top->i_rst_n = 1;

    // Cấu hình mảng đầu vào
    std::vector<uint8_t> input_data = {42, 10, 30, 20, 5, 88, 2, 70};
    for (int i = 0; i < 8; i++) {
        top->i_data[i] = input_data[i];
    }

    // Start sorting
    top->i_start = 1;
    while (1){
        top->i_clk ^= 1;

        top->eval();
        if(top->o_done == 1){
            std::cout << "Sort done" << std::endl;
            top->i_start = 0;
            break;
        }
    }
    delete top;
    return 0;
}
