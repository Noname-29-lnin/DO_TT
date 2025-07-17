#include "rtl_based.hpp"

void RTL_Cal_Mean(std::vector<int>& i_arr, int i_si, int i_ei, int& o_mean){
    if(i_arr.empty() || i_si > i_ei) {
        o_mean = 0; // Handle empty or invalid range
        return;
    }
    int w_sum = 0;
    for(int i = i_si; i <= i_ei; ++i){
        w_sum += i_arr[i];
    }
    o_mean = (int)(w_sum / (i_ei - i_si + 1));
}

void RTL_Compare_Arr(std::vector<int>& i_arr, int i_mean, 
                    std::vector<int>& o_less_arr, std::vector<int>& o_greater_arr){
    if(i_arr.empty()) {
        o_less_arr.clear();
        o_greater_arr.clear();
        return;
    }

    o_less_arr.clear();
    o_greater_arr.clear();
    
    for(int i : i_arr){
        if(i < i_mean) {
            o_less_arr.push_back(i);
        } else if(i > i_mean) {
            o_greater_arr.push_back(i);
        }
    }
}

//////////////////////////////////////////////////////////////