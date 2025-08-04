#include "Verif.hpp"

void PrintTime(const std::string& name, long long time){
    std::cout << name << " took " << time << " ns." << std::endl;
}

void writeVectorToFile(const std::vector<int>& vec, const std::string& filename) {
    std::ofstream outFile(filename); // Mở file để ghi

    if (!outFile.is_open()) {
        std::cerr << "Error: Can't open file '" << filename << std::endl;
        return;
    }

    for (const int& val : vec) {
        outFile << val << " "; // Mỗi phần tử ghi trên một dòng
    }

    outFile.close();
    std::cout << "Finish write file '" << filename << "'.\n";
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

std::string CheckSortedString(const std::vector<int>& arr) {
    return std::is_sorted(arr.begin(), arr.end()) ? "PASS" : "FAIL";
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

void Print_Table_Result(const std::vector<SortResult>& results) {
    // Title
    std::cout << std::endl;
    std::cout << std::left << std::setw(30) << "Sort algorithm "
              << std::setw(15) << "Check sorted"
              << std::setw(20) << "Time (ns)"
              << std::setw(20) << "Number Swap" 
              << std::setw(20) << "Number Compare" << std::endl;

    std::cout << std::string(120, '-') << std::endl;

    // Display value in struct
    for (const auto& res : results) {
        std::cout << std::left << std::setw(30) << res.algorithm_name
                  << std::setw(15) << res.check_sorted
                  << std::setw(20) << res.time_run
                  << std::setw(20) << res.count_swap 
                  << std::setw(20) << res.count_compare << std::endl;
        std::cout << std::string(120, '-') << std::endl;
    }
}

