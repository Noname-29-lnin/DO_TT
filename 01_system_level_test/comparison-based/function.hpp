//#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <vector>
#include <chrono>
#include <cstddef>

template<typename T>
void PrintArray(const std::vector<T>& arr){
    int n = arr.size();

    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

template<typename T>
void SelectionSort(std::vector<T>& arr){
    int n = arr.size();
    for(int i = 0; i < n-1; ++i){
        int minIndex = i;
        for(int j = i+1; j < n; ++j){
            if(arr[j] < arr[minIndex]) { minIndex = j; }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

template<typename T>
void InsertionSort(std::vector<T>& arr){
    std::size_t n = arr.size();

    for(int i = 1; i < n; i++){
        T key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

template<typename T>
void BubbleSort(std::vector<T>& arr){
    int n = arr.size();

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]) { std::swap(arr[j], arr[j+1]); }
        }
    }
}

void heapify(std::vector<int>& arr, int n, int i){

    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if( left < n &&  arr[left] > arr[largest]) { largest = left; }
    if(right < n && arr[right] > arr[largest]) { largest = right; }

    if(largest != i){
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void HeapSort(std::vector<int>& arr){
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    for(int i = n-1; i > 0; i--){
        std::swap(arr[0], arr[i]);
        heapify(arr, i , 0);
    }
}

int partition(std::vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; ++j){
        if(arr[j] < pivot){
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[high]);
    return i+1;
}

void QuickSort(std::vector<int>& arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

template<typename T>
void merge(std::vector<T>& arr, int left, int mid, int right){
    std::vector<T> L(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<T> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0;
    int j = 0;
    int k = left;

    while(i < static_cast<int>(L.size()) && j < R.size()){
        if(L[i] <= R[j]) { 
            arr[k++] = L[i++];
            // arr[k] = L[i]
            // ++k, ++i;
        }
        else { 
            arr[k++] = R[j++];
            // arr[k] = R[j];
            // ++k, ++j;
        }
    }

    while(i < static_cast<int>(L.size())) { arr[k++] = L[i++]; }
    while(j < static_cast<int>(R.size())) { arr[k++] = R[j++]; }
}

template<typename T> 
void MergeSort(std::vector<T>& arr, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

template<typename Func>
long long MeasureSortTime(std::vector<int> arr, Func sortFunction){
    auto start = std::chrono::high_resolution_clock::now();
    sortFunction(arr);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    return duration.count();
}

#endif
