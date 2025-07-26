#include "function_non_compare.hpp"

void PrintArray(std::string name, const std::vector<int>& arr){
    std::cout << name << ": " << std::endl;
    for(const auto& elem : arr){
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

void CountingSort(std::vector<int>& arr){
    int n = arr.size();
}