#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "function.hpp"
#include "serial_realization.hpp"
#include "parallel_realization.hpp"

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

    std::cout << "Cac so doc duoc: \n";
    for(int x : data) std::cout << x << " ";
    std::cout << "\n\n";

    std::vector<int> insertiondata = data;
    InsertionSort(insertiondata);
    long long timeIns = MeasureSortTime(insertiondata, [](std::vector<int>& v){ InsertionSort(v); });
    std::cout << "InsertionSort: ";
    // PrintArray(insertiondata);
    std::cout << "Time: " << timeIns << " ms\n\n";

    std::vector<int> selectiondata = data;
    long long timeSel = MeasureSortTime(selectiondata, [](std::vector<int>& v){ SelectionSort(v); });
    SelectionSort(selectiondata);
    std::cout << "SelectionSort: ";
    // PrintArray(selectiondata);
    std::cout << "Time: " << timeSel << " ms\n\n";

    std::vector<int> bubbledata = data;
    BubbleSort(bubbledata);
    long long timeBubb = MeasureSortTime(bubbledata, [](std::vector<int>& v){ BubbleSort(v); });
    std::cout << "BubbleSort: ";
    // PrintArray(bubbledata);
    std::cout << "Time: " << timeBubb << " ms\n\n";

    std::vector<int> mergedata = data;
    MergeSort(mergedata, 0, mergedata.size() - 1);
    long long timeMerge = MeasureSortTime(mergedata, [](std::vector<int>& v){ MergeSort(v, 0, v.size() - 1); });
    std::cout << "MergeSort: ";
    PrintArray(mergedata);
    std::cout << "Time: " << timeMerge << "ms\n\n";


    std::vector<int> serialdata = data;
    int M = 16; // Example value for M, can be adjusted
    // Division(serialdata, 0, serialdata.size() - 1, M);
    Sort(serialdata, M);
    // long long timeSerial = MeasureSortTime(serialdata, [&serialdata, M](){ Sort(serialdata, M); });
    long long timeSerial = MeasureSortTime(serialdata, [](std::vector<int>& v){ Sort(v, 16); });
    std::cout << "Serial Division Sort: ";
    std::cout << "Time: " << timeSerial << " ms\n";
    PrintArray(serialdata);

    std::vector<int> parallelData = data;
    ParallelSort( parallelData ,M);
    // long long timeParallel = MeasureSortTime(parallelData, [](std::vector<int>& v){ ParallelSort(v, 16); });
    std::cout << "Parallel Division Sort: ";
    // std::cout << "Time: " << timeParallel << " ms\n";
    PrintArray(parallelData);

    return 0;
}

