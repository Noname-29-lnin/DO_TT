#include "Verif.hpp"

void PrintTime(const std::string& name, long long time){
    std::cout << name << " took " << time << " ns." << std::endl;
}

void CheckSorted(const std::string NameSort ,const std::vector<int>& normalarr, std::vector<int>& arr) {
    // std::vector<int> CheckArray = normalarr;
    // std::sort(CheckArray.begin(), CheckArray.end());
    // // if (!std::is_sorted(arr.begin(), arr.end()))
    // //     std::sort(arr.begin(), arr.end());
    // if(CheckArray == arr){
    //     std::cout << NameSort << " -> PASS" << std::endl;
    // } else {
    //     std::cout << NameSort << " -> FAIL" << std::endl;
    // }
    if(std::is_sorted(arr.begin(), arr.end())){
        std::cout << NameSort << " -> PASS" << std::endl;
    } else {
        std::cout << NameSort << " -> FAIL" << std::endl;
    }
}

int BinarySearch(const std::vector<int>& arr, int target){
    int left = 0;
    int right = arr.size() - 1;

    while( left <= right ){ // use <= fix error off-by-one (OBOE), when searching for the last element
         // in the array, it was not found because the condition was left < right
        int mid = (left + (right - left)) / 2; // avoid to prevent overflow int

        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // Target not found in the array
}