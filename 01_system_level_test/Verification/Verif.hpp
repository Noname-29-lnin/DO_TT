#ifndef VERIF_H
#define VERIF_H

#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <algorithm>
#include <iomanip> // using std::setw
#include <fstream>

template<typename Func>
long long V_MeasureSortTime(std::vector<int> arr, Func sortFunction){
    auto start = std::chrono::high_resolution_clock::now();
    sortFunction(arr);
    auto end = std::chrono::high_resolution_clock::now();

    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    return duration.count();
}

template<typename Func>
long long V_CAL_MeasureTime(Func func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

void PrintTime(const std::string& name, long long time);
void CheckSorted(const std::string NameSort ,const std::vector<int>& normalarr, std::vector<int>& arr);

struct SortResult {
    std::string algorithm_name;
    std::string check_sorted;
    long long time_run;
    int count_swap;
    int count_compare;
};
std::string CheckSortedString(const std::vector<int>& arr);
void Print_Table_Result(const std::vector<SortResult>& results);

void writeVectorToFile(const std::vector<int>& vec, const std::string& filename);

#endif // VERIF_H
