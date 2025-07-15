#ifndef VERIF_H
#define VERIF_H

#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <algorithm>

template<typename Func>
long long V_MeasureSortTime(std::vector<int> arr, Func sortFunction){
    auto start = std::chrono::high_resolution_clock::now();
    sortFunction(arr);
    auto end = std::chrono::high_resolution_clock::now();

    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    return duration.count();
}

void PrintTime(const std::string& name, long long time);
void CheckSorted(const std::string NameSort ,const std::vector<int>& normalarr, std::vector<int>& arr);

#endif // VERIF_H
