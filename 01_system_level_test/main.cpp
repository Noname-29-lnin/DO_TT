#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>


#include "./comparison-based/function_compare.hpp"
#include "./Verification/Verif.hpp"

int main(int argc, char** argv){
    
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
    int S_M = std::stoi(argv[1]);
    std::cout << "Input S_M: " << S_M << std::endl;
    std::vector<int> serialRealizationData = data;
    long long serialRealizationTime = V_CAL_MeasureTime([&serialRealizationData, S_M, &serialRealizationSwap, &serialRealizationCompare, &serialRealizationSimilar, &serialRealizationIncreasing, &serialRealizationDecreasing]() {
        S_Sort(serialRealizationData, S_M, serialRealizationSwap, serialRealizationCompare, serialRealizationSimilar, serialRealizationIncreasing, serialRealizationDecreasing);
    });
    
    int parallelRealizationCompare = 0;
    int parallelRealizationSwap = 0;
    int P_M = std::stoi(argv[2]);
    std::cout << "Input P_M: " << P_M << std::endl;
    std::vector<int> paralleData = data;
    long long parallelTime = V_CAL_MeasureTime([&paralleData, &P_M, &parallelRealizationCompare, &parallelRealizationSwap]() {
        P_Sort(paralleData, P_M, parallelRealizationSwap, parallelRealizationCompare);
    });

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
    results.push_back({"ParallelRealizationSort", CheckSortedString(paralleData), parallelTime, parallelRealizationSwap, parallelRealizationCompare});
    
    Print_Table_Result(results);
    
    std::cout << "- SerialRealizationSort" << std::endl;
    std::cout << "Number Similar: " << serialRealizationSimilar << std::endl;
    std::cout << "Number Increasing: " << serialRealizationIncreasing << std::endl;
    std::cout << "Number Decreasing: " << serialRealizationDecreasing << std::endl;
    return 0;
}
