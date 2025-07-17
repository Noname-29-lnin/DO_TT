#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <fstream>
#include <chrono>

template<typename Func>
long long measureTime(Func func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

// Function to check if a subarray is sorted, reversely sorted, or contains similar elements
int checkSortStatus(const std::vector<int>& arr) {
    if (arr.empty()) return 3; // Treat empty arrays as "similar"
    bool isSorted = true, isReverseSorted = true, isSimilar = true;
    int first = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i-1]) isSorted = false;
        if (arr[i] > arr[i-1]) isReverseSorted = false;
        if (arr[i] != first) isSimilar = false;
    }
    if (isSorted) return 2; // Sorted
    if (isReverseSorted) return 1; // Reverse sorted
    if (isSimilar) return 3; // Similar elements
    return 0; // Unsorted
}

// Function to compute the mean of a vector
double computeMean(const std::vector<int>& arr) {
    if (arr.empty()) return 0.0;
    return std::accumulate(arr.begin(), arr.end(), 0.0) / arr.size();
}

// Function to partition array based on mean value
void partitionByMean(const std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right) {
    if (arr.size() <= 1) {
        left = arr;
        return;
    }
    double mean = computeMean(arr);
    // std::cout << "Partitioning array of size " << arr.size() << " with mean " << mean << "\n";
    for (int val : arr) {
        if (val < mean) left.push_back(val);
        else right.push_back(val);
    }
    // Handle case where one subarray is empty
    if (left.empty() && !right.empty()) {
        left.push_back(right.back());
        right.pop_back();
    } else if (right.empty() && !left.empty()) {
        right.push_back(left.back());
        left.pop_back();
    }
}

// Recursive function to create 2^M subarrays
void createSubarrays(const std::vector<int>& arr, int level, int maxLevel, 
                    std::vector<std::vector<int>>& subarrays, std::vector<int>& status) {
    if (level > maxLevel || arr.empty()) {
        if (!arr.empty()) {
            subarrays.push_back(arr);
            status.push_back(checkSortStatus(arr));
        }
        return;
    }

    int sortStatus = checkSortStatus(arr);
    // std::cout << "Level " << level << ": Array size " << arr.size() << ", Status " << sortStatus << "\n";
    if (sortStatus == 2 || sortStatus == 3) {
        subarrays.push_back(arr);
        status.push_back(sortStatus);
        return;
    }
    if (sortStatus == 1) {
        std::vector<int> reversed(arr.rbegin(), arr.rend());
        subarrays.push_back(reversed);
        status.push_back(2);
        return;
    }

    std::vector<int> left, right;
    partitionByMean(arr, left, right);
    createSubarrays(left, level + 1, maxLevel, subarrays, status);
    createSubarrays(right, level + 1, maxLevel, subarrays, status);
}

// Function to sort a subarray
void sortSubarray(std::vector<int>& subarray, int status) {
    if (status == 2 || status == 3) return;
    std::sort(subarray.begin(), subarray.end());
}

// Main function to perform parallel sorting
void parallelSort(std::vector<int>& data) {
    const int maxLevel = 3; // For 2^3 = 8 subarrays
    std::vector<std::vector<int>> subarrays;
    std::vector<int> status;

    // Step 1: Create subarrays
    createSubarrays(data, 0, maxLevel, subarrays, status);

    if (subarrays.empty()) {
        // std::cerr << "Error: No subarrays generated\n";
        return;
    }

    // std::cout << "Number of subarrays created: " << subarrays.size() << "\n";
    // for (size_t i = 0; i < subarrays.size(); ++i) {
    //     std::cout << "Subarray " << i << " (status " << status[i] << "): ";
    //     for (int x : subarrays[i]) std::cout << x << " ";
    //     std::cout << "\n";
    // }

    // Step 2: Sort subarrays in parallel
    std::vector<std::thread> threads;
    for (size_t i = 0; i < subarrays.size() && i < 8; ++i) {
        threads.emplace_back(sortSubarray, std::ref(subarrays[i]), status[i]);
    }

    // Step 3: Wait for all threads to complete
    for (auto& t : threads) {
        if (t.joinable()) t.join();
    }

    // Step 4: Merge sorted subarrays
    std::vector<int> result;
    for (const auto& subarray : subarrays) {
        result.insert(result.end(), subarray.begin(), subarray.end());
    }
    if (result.empty()) {
        // std::cerr << "Error: Result array is empty\n";
        return;
    }
    std::sort(result.begin(), result.end());
    data = result;
}

int main() {
    // Read input from file
    std::ifstream file("unsorted.txt");
    std::vector<int> data;
    int number;

    if (file.is_open()) {
        while (file >> number) {
            data.push_back(number);
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open unsorted.txt\n";
        return 1;
    }

    if (data.empty()) {
        std::cerr << "Error: No data read from unsorted.txt\n";
        return 1;
    }

    std::cout << "Original array: ";
    for (int x : data) std::cout << x << " ";
    std::cout << "\n";

    // Measure and perform parallel sort
    std::vector<int> originalData = data; // Keep original data for comparison
    long long sortTime = measureTime([&originalData]() {
        parallelSort(originalData);
    });
    std::cout << "Parallel sort completed in " << sortTime << " ns\n";

    // try {
    //     parallelSort(data);
    //     std::cout << "Sorted array: ";
    //     for (int x : data) std::cout << x << " ";
    //     std::cout << "\n";
    // } catch (const std::exception& e) {
    //     std::cerr << "Error: " << e.what() << "\n";
    //     return 1;
    // }

    if(is_sorted(originalData.begin(), originalData.end())) { 
        std::cout << "Array is sorted successfully.\n";
    } else {
        std::cout << "Error: Array is not sorted correctly.\n";
    }
    return 0;
}