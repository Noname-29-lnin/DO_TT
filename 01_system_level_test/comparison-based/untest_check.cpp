#include <iostream>
#include <vector>
#include <string>

enum class ArrayStatus {
    ALL_EQUAL,
    SORTED_ASC,
    SORTED_DESC,
    UNSORTED
};

std::string statusToString(ArrayStatus status) {
    switch(status) {
        case ArrayStatus::ALL_EQUAL:  return "All elements are equal";
        case ArrayStatus::SORTED_ASC: return "Sorted in ascending order";
        case ArrayStatus::SORTED_DESC:return "Sorted in descending order";
        case ArrayStatus::UNSORTED:   return "Not sorted";
    }
    return "Unknown";
}

ArrayStatus checkArray(const std::vector<int>& arr) {
    if (arr.empty() || arr.size() == 1)
        return ArrayStatus::ALL_EQUAL;

    bool isAsc = true, isDesc = true, isEqual = true;

    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] != arr[i - 1]) isEqual = false;
        if (arr[i] < arr[i - 1]) isAsc = false;
        if (arr[i] > arr[i - 1]) isDesc = false;
    }

    if (isEqual) return ArrayStatus::ALL_EQUAL;
    if (isAsc)   return ArrayStatus::SORTED_ASC;
    if (isDesc)  return ArrayStatus::SORTED_DESC;

    return ArrayStatus::UNSORTED;
}

// =========================
// Ví dụ minh họa:
int main() {
    std::vector<std::vector<int>> testArrays = {
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {7, 7, 7, 7, 8},
        {1, 3, 2, 4, 2},
        {}
    };

    for (const auto& arr : testArrays) {
        std::cout << "Array: ";
        for (int x : arr) std::cout << x << " ";
        std::cout << "\n=> " << statusToString(checkArray(arr)) << "\n\n";
    }

    return 0;
}
