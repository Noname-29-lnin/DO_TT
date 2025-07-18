#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

#include "function.hpp"
#include "Verif.hpp"

int main(){
    
    std::ifstream file("unsorted.txt");
    std::vector<int> data;
    int number;

    if(file.is_open()){
        while(file >> number){
            data.push_back(number);
        }
        file.close();
    }

    PrintArray("Original Array", data);

    std::vector<int> normalSortData = data;
    // long long normalSortTime = V_MeasureSortTime(normalSortData, [](std::vector<int>& arr) {
    //     std::sort(arr.begin(), arr.end());
    // });
    // std::sort(normalSortData.begin(), normalSortData.end());
    long long normalSortTime = V_CAL_MeasureTime([&normalSortData]() {
        std::sort(normalSortData.begin(), normalSortData.end());
    });
    CheckSorted("Normal Sort", data, normalSortData);
    PrintTime("Normal Sort", normalSortTime);
    std::cout << "Starting sorting algorithms..." << std::endl;
    
    std::vector<int> insertionSortData = data;
    // long long insertionSortTime = V_MeasureSortTime(insertionSortData, F_InsertionSort);
    // F_InsertionSort(insertionSortData);
    long long insertionSortTime = V_CAL_MeasureTime([&insertionSortData]() {
        F_InsertionSort(insertionSortData);
    });
    // PrintArray("Insertion Sort", insertionSortData);
    CheckSorted("Insertion Sort", data, insertionSortData);
    PrintTime("Insertion Sort", insertionSortTime);

    std::vector<int> selectionSortData = data;
    // long long selectionSortTime = V_MeasureSortTime(selectionSortData, F_SelectionSort);
    // F_SelectionSort(selectionSortData);
    long long selectionSortTime = V_CAL_MeasureTime([&selectionSortData]() {
        F_SelectionSort(selectionSortData);
    });
    // PrintArray("Selection Sort", selectionSortData);
    CheckSorted("Selection Sort", data, selectionSortData);
    PrintTime("Selection Sort", selectionSortTime);

    std::vector<int> bubbleSortData = data;
    // long long bubbleSortTime = V_MeasureSortTime(bubbleSortData, F_BubbleSort);
    // F_BubbleSort(bubbleSortData);
    long long bubbleSortTime = V_CAL_MeasureTime([&bubbleSortData]() {
        F_BubbleSort(bubbleSortData);
    });
    // PrintArray("Bubble Sort", bubbleSortData);
    CheckSorted("Bubble Sort", data, bubbleSortData);
    PrintTime("Bubble Sort", bubbleSortTime);

    std::vector<int> heapSortData = data;
    // long long heapSortTime = V_MeasureSortTime(heapSortData, F_HeapSort);
    // F_HeapSort(heapSortData);
    long long heapSortTime = V_CAL_MeasureTime([&heapSortData]() {
        F_HeapSort(heapSortData);
    });
    // PrintArray("Heap Sort", heapSortData);
    CheckSorted("Heap Sort", data, heapSortData);
    PrintTime("Heap Sort", heapSortTime);

    std::vector<int> quickSortData = data;
    // long long quickSortTime = V_MeasureSortTime(quickSortData, [](std::vector<int>& arr) {
    //     F_QuickSort(arr, 0, arr.size() - 1);
    // });
    // F_QuickSort(quickSortData, 0, quickSortData.size() - 1);
    long long quickSortTime = V_CAL_MeasureTime([&quickSortData]() {
        F_QuickSort(quickSortData, 0, quickSortData.size() - 1);
    });
    // PrintArray("Quick Sort", quickSortData);
    CheckSorted("Quick Sort", data, quickSortData);
    PrintTime("Quick Sort", quickSortTime);

    std::vector<int> mergeSortData = data;
    // long long mergeSortTime = V_MeasureSortTime(mergeSortData, [](std::vector<int>& arr) {
    //     F_MergeSort(arr, 0, arr.size() - 1);
    // });
    // F_MergeSort(mergeSortData, 0, mergeSortData.size() - 1);
    long long mergeSortTime = V_CAL_MeasureTime([&mergeSortData]() {
        F_MergeSort(mergeSortData, 0, mergeSortData.size() - 1);
    });
    // PrintArray("Merge Sort", mergeSortData);
    CheckSorted("Merge Sort", data, mergeSortData);
    PrintTime("Merge Sort", mergeSortTime);

    const int S_M = 2;
    std::vector<int> serialRealizationData = data;
    // long long serialRealizationTime = V_MeasureSortTime(serialRealizationData, [](std::vector<int>& arr) {
    //     S_Sort(arr, S_M);
    // });
    // S_Sort(serialRealizationData, S_M);
    long long serialRealizationTime = V_CAL_MeasureTime([&serialRealizationData]() {
        S_Sort(serialRealizationData, S_M);
    });
    // PrintArray("Serial Realization Sort", serialRealizationData);
    CheckSorted("Serial Realization Sort", data, serialRealizationData);
    PrintTime("Serial Realization Sort", serialRealizationTime);


    const int P_M = 2;
    std::vector<int> parallelRealizationData = data;
    long long parallelRealizationTime = V_CAL_MeasureTime([&parallelRealizationData, P_M]() {
        P_Sort(parallelRealizationData, P_M);
    });
    // PrintArray("Parallel Realization Sort", parallelRealizationData);
    CheckSorted("Parallel Realization Sort", data, parallelRealizationData);
    PrintTime("Parallel Realization Sort", parallelRealizationTime);

    std::vector<int> bitonicSortData = data;
    long long bitonicSortTime = V_CAL_MeasureTime([&bitonicSortData]() {
        bitonicSort(bitonicSortData, 0, bitonicSortData.size(), true);
    });
    CheckSorted("Bitonic Sort", data, bitonicSortData);
    PrintTime("Bitonic Sort", bitonicSortTime);

    std::cout << "Sorting completed." << std::endl;
    std::cout << "All sorting algorithms executed successfully." << std::endl;

    return 0;
}

