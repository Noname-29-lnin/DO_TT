#include "function_compare.hpp"
#include "./../Verification/Verif.hpp"

void PrintArray(std::string name, const std::vector<int>& arr){
    std::cout << name << ": " << std::endl;
    for(const auto& elem : arr){
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

void F_SelectionSort(std::vector<int>& arr, int& count_swap, int& count_compare){
    int n = arr.size();
    for(int i = 0; i < n - 1; ++i){
        int minIndex = i;
        for(int j = i+1; j < n; ++j){
            count_compare++;
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
        count_swap++;
    }
}

void F_InsertionSort(std::vector<int>& arr, int& count_compare){
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && (++count_compare && arr[j] > key)){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

void F_BubbleSort(std::vector<int>& arr, int& count_swap, int& count_compare){
    int n = arr.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            count_compare++;
            if(arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
                count_swap ++;
            }
        }
    }
}

void F_heapify(std::vector<int>& arr, int n, int i, int& count_swap, int& count_compare) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && (++count_compare && arr[left] > arr[largest])) {
        largest = left;
    }
    if(right < n && (++count_compare && arr[right] > arr[largest])) {
        largest = right;
    }

    if(largest != i){
        std::swap(arr[i], arr[largest]);
        count_swap++;
        F_heapify(arr, n, largest, count_swap, count_compare);
    }
}

void F_HeapSort(std::vector<int>& arr, int& count_swap, int& count_compare) {
    int n = arr.size();
    count_swap = 0;

    for(int i = n/2 - 1; i >= 0; i--){
        F_heapify(arr, n, i, count_swap, count_compare);
    }

    for(int i = n - 1; i > 0; i--){
        std::swap(arr[0], arr[i]);
        count_swap++;
        F_heapify(arr, i, 0, count_swap, count_compare);
    }
}

int F_Partition(std::vector<int>& arr, int low, int high, int& count_swap, int& count_compare){
    int pivot = arr[high];
    int i = low-1;
    for(int j = low; j < high; ++j){
        count_compare++;
        if(arr[j] < pivot){
            ++i;
            std::swap(arr[i], arr[j]);
            count_swap ++;
        }
    }
    std::swap(arr[i+1], arr[high]);
    count_swap++;
    return i + 1;
}

void F_QuickSort(std::vector<int>& arr, int low, int high, int& count_swap, int& count_compare){
    if(low < high){
        int pi = F_Partition(arr, low, high, count_swap, count_compare);
        F_QuickSort(arr, low, pi - 1, count_swap, count_compare);
        F_QuickSort(arr, pi + 1, high, count_swap, count_compare);
    }
}

void F_Merge(std::vector<int>& arr, int left, int mid, int right, int& count_compare){
    std::vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    size_t i = 0, j = 0, k = left;
    while(i < L.size() && j < R.size()){
        count_compare++;
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }
    while(i < L.size()) arr[k++] = L[i++];
    while(j < R.size()) arr[k++] = R[j++];
}

void F_MergeSort(std::vector<int>& arr, int left, int right, int& count_compare){
    if(left < right){
        int mid = (left + right) / 2;
        F_MergeSort(arr, left, mid, count_compare);
        F_MergeSort(arr, mid + 1, right, count_compare);
        F_Merge(arr, left, mid, right, count_compare);
    }
}

int F_Cal_mean(const std::vector<int>& arr, int si, int ei){
    int sum = 0;
    for(int i = si; i <= ei; ++i){ sum += arr[i]; }
    return sum / (ei - si + 1);
}

CheckArrayStatus SS_Check(std::vector<int>& arr, int si, int ei){
    if(arr.empty() || arr.size() == 1) return CheckArrayStatus::SIMILAR;
    bool isAsc = true, isDesc = true, isEqual = true;
    for(int i = si + 1; i <= ei; ++i){
        if(arr[i] != arr[i - 1]) isEqual = false;
        if(arr[i] < arr[i - 1]) isAsc = false;
        if(arr[i] > arr[i - 1]) isDesc = false;
    }
    if(isEqual) return CheckArrayStatus::SIMILAR;
    if(isAsc) return CheckArrayStatus::INCREASING;
    if(isDesc) return CheckArrayStatus::DECREASING;
    return CheckArrayStatus::UNSORTED;
}

void F_Reverse_Array(std::vector<int>& arr, int si, int ei){
    while(si < ei){ std::swap(arr[si++], arr[ei--]); }
}

// void S_Partition(std::vector<int>& arr, int si, int ei, int& left, int& right, int &count_swap){
//     int mean = F_Cal_mean(arr, si, ei);
//     left = si - 1;
//     right = ei + 1;
//     int i = si;
//     while(i < right){
//         if(arr[i] < mean){ 
//             std::swap(arr[++left], arr[i++]); 
//             count_swap++;
//         }
//         else if(arr[i] > mean){ 
//             std::swap(arr[i], arr[--right]); 
//             count_swap++;
//         }
//         else { ++i; }
//     }
// }

int S_Partition(std::vector<int>& arr, int si, int ei, int& count_swap, int& count_compare){
    int bi = si - 1;
    int mean = F_Cal_mean(arr, si, ei);
    for(int i = si; i < ei; i++){
        count_compare++;
        if(arr[i] >= mean){
            bi = bi + 1;
            std::swap(arr[bi], arr[i]);
            count_swap++;
        }
    }
    return bi;
}

// void S_Division(std::vector<int>& arr, size_t si, size_t ei, int M, int& S_cnt, int& count_swap){
//     if(ei <= si) return;
//     CheckArrayStatus status = SS_Check(arr, si, ei);
//     // const char* statusStr = "";
//     // switch(status) {
//     //     case CheckArrayStatus::SIMILAR: statusStr = "SIMILAR"; break;
//     //     case CheckArrayStatus::INCREASING: statusStr = "INCREASING"; break;
//     //     case CheckArrayStatus::DECREASING: statusStr = "DECREASING"; break;
//     //     case CheckArrayStatus::UNSORTED: statusStr = "UNSORTED"; break;
//     //     default: statusStr = "UNKNOWN"; break;
//     // }
//     // std::cout << "SS_Check = " << statusStr << std::endl;
//     if(status == CheckArrayStatus::INCREASING || status == CheckArrayStatus::SIMILAR) return;
//     if(status == CheckArrayStatus::DECREASING){
//         F_Reverse_Array(arr, si, ei);
//         return;
//     }
//     if(S_cnt < (1 << (M - 1))){
//         int left, right;
//         S_Partition(arr, si, ei, left, right, count_swap);
//         S_cnt++;
//         S_Division(arr, si, left, M, S_cnt, count_swap);
//         // std::cout << "D1: Si = " << si << " left = " << left << std::endl;
//         if(si == 0 || ei == arr.size() - 1) S_cnt = 1;
//         S_Division(arr, right, ei, M, S_cnt, count_swap);
//         // std::cout << "D2: Right = " << right << " ei = " << ei << std::endl;
//     } else {
//         // std::cout <<"F_subarray: si = " << si << " ei = " << ei << std::endl;
//         F_QuickSort(arr, si, ei, count_swap);
//         // F_MergeSort(arr, si, ei);
//     }
// }
void S_Division(std::vector<int>& arr, size_t si, size_t ei, int M, int& S_cnt, int& count_swap, int& count_compare, int& count_similar, int& count_increasing, int& count_decreasing){
    if(ei <= si) return;
    CheckArrayStatus status = SS_Check(arr, si, ei);
    //     // const char* statusStr = "";
    //     // switch(status) {
    //     //     case CheckArrayStatus::SIMILAR: statusStr = "SIMILAR"; break;
    //     //     case CheckArrayStatus::INCREASING: statusStr = "INCREASING"; break;
    //     //     case CheckArrayStatus::DECREASING: statusStr = "DECREASING"; break;
    //     //     case CheckArrayStatus::UNSORTED: statusStr = "UNSORTED"; break;
    //     //     default: statusStr = "UNKNOWN"; break;
    //     // }
    //     // std::cout << "SS_Check = " << statusStr << std::endl;
    if(status == CheckArrayStatus::SIMILAR) {
        count_similar++;
        return;
    }
    if(status == CheckArrayStatus::INCREASING) {
        count_increasing++;    
        return;
    }
    if(status == CheckArrayStatus::DECREASING){
        count_decreasing++;
        F_Reverse_Array(arr, si, ei);
        return;
    }
    if(S_cnt < (1 << (M - 1))){
        int bi = F_Partition(arr, si, ei, count_swap, count_compare);
        S_cnt++;
        // writeVectorToFile(arr, "test.txt");
        S_Division(arr, si, bi, M, S_cnt, count_swap, count_compare, count_similar, count_increasing, count_decreasing);
        if((si == 0) || (ei == arr.size() - 1)) {
            S_cnt = 1;
        }
        S_Division(arr, bi+1, ei, M, S_cnt, count_swap, count_compare, count_similar, count_increasing, count_decreasing);
    } else {
        // std::cout <<"F_subarray: si = " << si << " ei = " << ei << std::endl;
        // F_QuickSort(arr, si, ei, count_swap);
        F_MergeSort(arr, si, ei, count_compare);
    }
}

void S_Sort(std::vector<int>& arr, int M, int& count_swap, int& count_compare, int& count_similar, int& count_increasing, int& count_decreasing){
    if(arr.empty() || arr.size() <= 1) return;
    int cnt = 0;
    S_Division(arr, 0, arr.size() - 1, M, cnt, count_swap, count_compare, count_similar, count_increasing, count_decreasing);
}

//////////////////// Bitonic Sort //////////////////
void compareAndSwap(std::vector<int>& arr, int i, int j, bool ascending) {
    if (ascending == (arr[i] > arr[j])) {
        std::swap(arr[i], arr[j]);
    }
}

void bitonicMerge(std::vector<int>& arr, int low, int cnt, bool ascending) {
    if (cnt > 1) {
        int k = cnt / 2;
        for (int i = low; i < low + k; ++i) {
            compareAndSwap(arr, i, i + k, ascending);
        }
        bitonicMerge(arr, low, k, ascending);
        bitonicMerge(arr, low + k, k, ascending);
    }
}

void bitonicSort(std::vector<int>& arr, int low, int cnt, bool ascending) {
    if (cnt > 1) {
        int k = cnt / 2;
        bitonicSort(arr, low, k, true);         // nửa đầu tăng
        bitonicSort(arr, low + k, k, false);    // nửa sau giảm
        bitonicMerge(arr, low, cnt, ascending); // trộn bitonic
    }
}
