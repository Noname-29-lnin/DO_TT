#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "function.hpp"

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
    // PrintArray(mergedata);
    std::cout << "Time: " << timeMerge << "ms\n\n";

    return 0;
}

