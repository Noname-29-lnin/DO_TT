//#pragma once
#ifndef FUNCTION_COMPARE_H
#define FUNCTION_COMPARE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric> // std::accumulate
#include <atomic>
#include <future>

void PrintArray(std::string name, const std::vector<int>& arr);
void F_SelectionSort(std::vector<int>& arr, int& count_swap, int& count_compare);
void F_InsertionSort(std::vector<int>& arr, int& count_compare);
void F_BubbleSort(std::vector<int>& arr, int& count_swap, int& count_compare);
void F_HeapSort(std::vector<int>& arr, int& count_swap, int& count_compare);
void F_QuickSort(std::vector<int>& arr, int low, int high, int& count_swap, int& count_compare);
void F_MergeSort(std::vector<int>& arr, int left, int right, int& count_compare);

// Using Independent subarray sorting
enum class CheckArrayStatus{
    SIMILAR     = 0 ,
    INCREASING      ,
    DECREASING      ,
    SORTED          ,
    UNSORTED
};

void S_Sort(std::vector<int>& arr, int M, int& count_swap, int& count_compare, int& count_similar, int& count_increasing, int& count_decreasing);
void P_Sort(std::vector<int>& arr, int M, int& count_swap, int& count_compare);

#endif
