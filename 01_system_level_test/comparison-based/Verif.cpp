#include "Verif.hpp"

void PrintTime(const std::string& name, long long time){
    std::cout << name << " took " << time << " ns." << std::endl;
}

void CheckSorted(const std::string NameSort ,const std::vector<int>& normalarr, std::vector<int>& arr) {
    // std::vector<int> CheckArray = normalarr;
    // std::sort(CheckArray.begin(), CheckArray.end());
    // // if (!std::is_sorted(arr.begin(), arr.end()))
    // //     std::sort(arr.begin(), arr.end());
    // if(CheckArray == arr){
    //     std::cout << NameSort << " -> PASS" << std::endl;
    // } else {
    //     std::cout << NameSort << " -> FAIL" << std::endl;
    // }
    if(std::is_sorted(arr.begin(), arr.end())){
        std::cout << NameSort << " -> PASS" << std::endl;
    } else {
        std::cout << NameSort << " -> FAIL" << std::endl;
    }
}