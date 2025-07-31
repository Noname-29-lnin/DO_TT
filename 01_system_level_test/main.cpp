#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

#include "./comparison-based/function_compare.hpp"
#include "./Verification/Verif.hpp"

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

    std::cout << "Size of array: " << data.size() << std::endl;

    // PrintArray("Original Array", data);

    // std::vector<int> normalSortData = data;
    // long long normalSortTime = V_CAL_MeasureTime([&normalSortData]() {
    //     std::sort(normalSortData.begin(), normalSortData.end());
    // });
    // CheckSorted("Normal Sort", data, normalSortData);
    // PrintTime("Normal Sort", normalSortTime);
    // std::cout << "Starting sorting algorithms..." << std::endl;
    
    // std::vector<int> insertionSortData = data;
    // // long long insertionSortTime = V_MeasureSortTime(insertionSortData, F_InsertionSort);
    // // F_InsertionSort(insertionSortData);
    // long long insertionSortTime = V_CAL_MeasureTime([&insertionSortData]() {
    //     F_InsertionSort(insertionSortData);
    // });
    // // PrintArray("Insertion Sort", insertionSortData);
    // CheckSorted("Insertion Sort", data, insertionSortData);
    // PrintTime("Insertion Sort", insertionSortTime);

    // std::vector<int> selectionSortData = data;
    // // long long selectionSortTime = V_MeasureSortTime(selectionSortData, F_SelectionSort);
    // // F_SelectionSort(selectionSortData);
    // long long selectionSortTime = V_CAL_MeasureTime([&selectionSortData]() {
    //     F_SelectionSort(selectionSortData);
    // });
    // // PrintArray("Selection Sort", selectionSortData);
    // CheckSorted("Selection Sort", data, selectionSortData);
    // PrintTime("Selection Sort", selectionSortTime);

    // std::vector<int> bubbleSortData = data;
    // // long long bubbleSortTime = V_MeasureSortTime(bubbleSortData, F_BubbleSort);
    // // F_BubbleSort(bubbleSortData);
    // long long bubbleSortTime = V_CAL_MeasureTime([&bubbleSortData]() {
    //     F_BubbleSort(bubbleSortData);
    // });
    // // PrintArray("Bubble Sort", bubbleSortData);
    // CheckSorted("Bubble Sort", data, bubbleSortData);
    // PrintTime("Bubble Sort", bubbleSortTime);

    // std::vector<int> heapSortData = data;
    // // long long heapSortTime = V_MeasureSortTime(heapSortData, F_HeapSort);
    // // F_HeapSort(heapSortData);
    // long long heapSortTime = V_CAL_MeasureTime([&heapSortData]() {
    //     F_HeapSort(heapSortData);
    // });
    // // PrintArray("Heap Sort", heapSortData);
    // CheckSorted("Heap Sort", data, heapSortData);
    // PrintTime("Heap Sort", heapSortTime);

    // std::vector<int> quickSortData = data;
    // // long long quickSortTime = V_MeasureSortTime(quickSortData, [](std::vector<int>& arr) {
    // //     F_QuickSort(arr, 0, arr.size() - 1);
    // // });
    // // F_QuickSort(quickSortData, 0, quickSortData.size() - 1);
    // long long quickSortTime = V_CAL_MeasureTime([&quickSortData]() {
    //     F_QuickSort(quickSortData, 0, quickSortData.size() - 1);
    // });
    // // PrintArray("Quick Sort", quickSortData);
    // CheckSorted("Quick Sort", data, quickSortData);
    // PrintTime("Quick Sort", quickSortTime);

    // std::vector<int> mergeSortData = data;
    // // long long mergeSortTime = V_MeasureSortTime(mergeSortData, [](std::vector<int>& arr) {
    // //     F_MergeSort(arr, 0, arr.size() - 1);
    // // });
    // // F_MergeSort(mergeSortData, 0, mergeSortData.size() - 1);
    // long long mergeSortTime = V_CAL_MeasureTime([&mergeSortData]() {
    //     F_MergeSort(mergeSortData, 0, mergeSortData.size() - 1);
    // });
    // // PrintArray("Merge Sort", mergeSortData);
    // CheckSorted("Merge Sort", data, mergeSortData);
    // PrintTime("Merge Sort", mergeSortTime);

    // int S_M;
    // std::cout << "Input S_M: ";
    // std::cin >> S_M;
    // std::vector<int> serialRealizationData = data;
    // // long long serialRealizationTime = V_MeasureSortTime(serialRealizationData, [](std::vector<int>& arr) {
    // //     S_Sort(arr, S_M);
    // // });
    // // S_Sort(serialRealizationData, S_M);
    // long long serialRealizationTime = V_CAL_MeasureTime([&serialRealizationData, S_M]() {
    //     S_Sort(serialRealizationData, S_M);
    // });
    // // PrintArray("Serial Realization Sort", serialRealizationData);
    // CheckSorted("Serial Realization Sort", data, serialRealizationData);
    // PrintTime("Serial Realization Sort", serialRealizationTime);


    // const int P_M = 2;
    // std::vector<int> parallelRealizationData = data;
    // long long parallelRealizationTime = V_CAL_MeasureTime([&parallelRealizationData, P_M]() {
    //     P_Sort(parallelRealizationData, P_M);
    // });
    // // PrintArray("Parallel Realization Sort", parallelRealizationData);
    // CheckSorted("Parallel Realization Sort", data, parallelRealizationData);
    // PrintTime("Parallel Realization Sort", parallelRealizationTime);

    // std::vector<int> bitonicSortData = data;
    // long long bitonicSortTime = V_CAL_MeasureTime([&bitonicSortData]() {
    //     bitonicSort(bitonicSortData, 0, bitonicSortData.size(), true);
    // });
    // CheckSorted("Bitonic Sort", data, bitonicSortData);
    // PrintTime("Bitonic Sort", bitonicSortTime);

    // std::cout << "Sorting completed." << std::endl;
    // std::cout << "All sorting algorithms executed successfully." << std::endl;

    std::vector<int> normalSortData = data;
    long long normalSortTime = V_CAL_MeasureTime([&normalSortData]() {
        std::sort(normalSortData.begin(), normalSortData.end());
    });
    writeVectorToFile(normalSortData, "sorted.txt");

    int selectionSortCompare = 0;
    int selectionSortSwap = 0;
    std::vector<int> selectionSortData = data;
    long long selectionSortTime = V_CAL_MeasureTime([&selectionSortData, &selectionSortSwap, &selectionSortCompare]() {
        F_SelectionSort(selectionSortData, selectionSortSwap, selectionSortCompare);
    });
    
    int insertionSortCompare = 0;
    std::vector<int> insertionSortData = data;
    long long insertionSortTime = V_CAL_MeasureTime([&insertionSortData, &insertionSortCompare]() {
        F_InsertionSort(insertionSortData, insertionSortCompare);
    });

    int bubbleSortCompare = 0;
    int bubbleSortSwap = 0;
    std::vector<int> bubbleSortData = data;
    long long bubbleSortTime = V_CAL_MeasureTime([&bubbleSortData, &bubbleSortSwap, &bubbleSortCompare]() {
        F_BubbleSort(bubbleSortData, bubbleSortSwap, bubbleSortCompare);
    });

    int heapSortCompare = 0;
    int heapSortSwap = 0;
    std::vector<int> heapSortData = data;
    long long heapSortTime = V_CAL_MeasureTime([&heapSortData, &heapSortSwap, &heapSortCompare]() {
        F_HeapSort(heapSortData, heapSortSwap, heapSortCompare);
    });

    int quickSortCompare = 0;
    int quickSortSwap = 0;
    std::vector<int> quickSortData = data;
    long long quickSortTime = V_CAL_MeasureTime([&quickSortData, &quickSortSwap, &quickSortCompare]() {
        F_QuickSort(quickSortData, 0, quickSortData.size() - 1, quickSortSwap, quickSortCompare);
    });

    int mergeSortCompare = 0;
    std::vector<int> mergeSortData = data;
    long long mergeSortTime = V_CAL_MeasureTime([&mergeSortData, &mergeSortCompare]() {
        F_MergeSort(mergeSortData, 0, mergeSortData.size() - 1, mergeSortCompare);
    });

    int serialRealizationCompare = 0;
    int serialRealizationSwap = 0;
    int serialRealizationSimilar = 0;
    int serialRealizationIncreasing = 0;
    int serialRealizationDecreasing = 0;
    int S_M;
    std::cout << "Input S_M: ";
    std::cin >> S_M;
    std::vector<int> serialRealizationData = data;
    long long serialRealizationTime = V_CAL_MeasureTime([&serialRealizationData, S_M, &serialRealizationSwap, &serialRealizationCompare, &serialRealizationSimilar, &serialRealizationIncreasing, &serialRealizationDecreasing]() {
        S_Sort(serialRealizationData, S_M, serialRealizationSwap, serialRealizationCompare, serialRealizationSimilar, serialRealizationIncreasing, serialRealizationDecreasing);
    });

    // std::vector<int> paralleData = data;
    // long long parallelTime = V_CAL_MeasureTime([&paralleData]() {
    //     P_Sort(paralleData, 2);
    // });

    std::vector<SortResult> results;
    results.push_back({"NormalData", CheckSortedString(data), 0, 0, 0});
    results.push_back({"NormalSort", CheckSortedString(normalSortData), normalSortTime, 0, 0});
    results.push_back({"SelectionSort", CheckSortedString(selectionSortData), selectionSortTime, selectionSortSwap, selectionSortCompare});
    results.push_back({"InsertionSort", CheckSortedString(insertionSortData), insertionSortTime, 0, insertionSortCompare});
    results.push_back({"BubbleSort", CheckSortedString(bubbleSortData), bubbleSortTime, bubbleSortSwap, bubbleSortCompare});
    results.push_back({"HeapSort", CheckSortedString(heapSortData), heapSortTime, heapSortSwap, heapSortCompare});
    results.push_back({"QuickSort", CheckSortedString(quickSortData), quickSortTime, quickSortSwap, quickSortCompare});
    results.push_back({"MergeSort", CheckSortedString(mergeSortData), mergeSortTime, 0, mergeSortCompare});
    results.push_back({"SerialRealizationSort", CheckSortedString(serialRealizationData), serialRealizationTime, serialRealizationSwap, serialRealizationCompare});
    // results.push_back({"ParallelRealizationSort", CheckSortedString(paralleData), parallelTime, 0, 0});
    
    Print_Table_Result(results);
    
    std::cout << "- SerialRealizationSort" << std::endl;
    std::cout << "Number Similar: " << serialRealizationSimilar << std::endl;
    std::cout << "Number Increasing: " << serialRealizationIncreasing << std::endl;
    std::cout << "Number Decreasing: " << serialRealizationDecreasing << std::endl;
    return 0;
}
