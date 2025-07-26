#include "function_compare.hpp"

void PrintArray(std::string name, const std::vector<int>& arr){
    std::cout << name << ": " << std::endl;
    for(const auto& elem : arr){
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

void F_SelectionSort(std::vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n - 1; ++i){
        int minIndex = i;
        for(int j = i+1; j < n; ++j){
            if(arr[j] < arr[minIndex]) minIndex = j;
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

void F_InsertionSort(std::vector<int>& arr){
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

void F_BubbleSort(std::vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]) std::swap(arr[j], arr[j+1]);
        }
    }
}

void F_heapify(std::vector<int>& arr, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;

    if(largest != i){
        std::swap(arr[i], arr[largest]);
        F_heapify(arr, n, largest);
    }
}

void F_HeapSort(std::vector<int>& arr){
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0; i--){
        F_heapify(arr, n, i);
    }
    for(int i = n - 1; i > 0; i--){
        std::swap(arr[0], arr[i]);
        F_heapify(arr, i, 0);
    }
}

int F_Partition(std::vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j = low; j < high; ++j){
        if(arr[j] < pivot){
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[high]);
    return i + 1;
}

void F_QuickSort(std::vector<int>& arr, int low, int high){
    if(low < high){
        int pi = F_Partition(arr, low, high);
        F_QuickSort(arr, low, pi - 1);
        F_QuickSort(arr, pi + 1, high);
    }
}

void F_Merge(std::vector<int>& arr, int left, int mid, int right){
    std::vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    size_t i = 0, j = 0, k = left;
    while(i < L.size() && j < R.size()){
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while(i < L.size()) arr[k++] = L[i++];
    while(j < R.size()) arr[k++] = R[j++];
}

void F_MergeSort(std::vector<int>& arr, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        F_MergeSort(arr, left, mid);
        F_MergeSort(arr, mid + 1, right);
        F_Merge(arr, left, mid, right);
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

void S_Partition(std::vector<int>& arr, int si, int ei, int& left, int& right){
    int mean = F_Cal_mean(arr, si, ei);
    left = si - 1;
    right = ei + 1;
    int i = si;
    while(i < right){
        if(arr[i] < mean){ std::swap(arr[++left], arr[i++]); }
        else if(arr[i] > mean){ std::swap(arr[i], arr[--right]); }
        else { ++i; }
    }
}

void S_Division(std::vector<int>& arr, size_t si, size_t ei, int M, int& S_cnt){
    if(ei <= si) return;
    CheckArrayStatus status = SS_Check(arr, si, ei);
    if(status == CheckArrayStatus::INCREASING || status == CheckArrayStatus::SIMILAR) return;
    if(status == CheckArrayStatus::DECREASING){
        F_Reverse_Array(arr, si, ei);
        return;
    }
    if(S_cnt < (1 << (M - 1))){
        int left, right;
        S_Partition(arr, si, ei, left, right);
        S_cnt++;
        S_Division(arr, si, left, M, S_cnt);
        if(si == 0 || ei == arr.size() - 1) S_cnt = 1;
        S_Division(arr, right, ei, M, S_cnt);
    } else {
        F_MergeSort(arr, si, ei);
    }
}


void S_Sort(std::vector<int>& arr, int M){
    if(arr.empty() || arr.size() <= 1) return;
    int cnt = 0;
    S_Division(arr, 0, arr.size() - 1, M, cnt);
}


bool P_SS_CoreCheck(std::vector<int>& arr, size_t si, size_t ei){
    if(ei <= si) return true;
    CheckArrayStatus status = SS_Check(arr, si, ei);
    if(status == CheckArrayStatus::INCREASING || status == CheckArrayStatus::SIMILAR) return false;
    if(status == CheckArrayStatus::DECREASING){
        F_Reverse_Array(arr, si, ei);
        return false;
    }
    return true;
}

void P_PartitionByMean(const std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right){
    if(arr.size() <= 1){
        left = arr;
        return;
    }
    int mean = F_Cal_mean(arr, 0, arr.size() - 1);
    for(int val : arr){
        if(val < mean) left.push_back(val);
        else right.push_back(val);
    }
    if(left.empty() && !right.empty()){ left.push_back(right.back()); right.pop_back(); }
    else if(right.empty() && !left.empty()){ right.push_back(left.back()); left.pop_back(); }
}

void P_Create_Subarry(std::vector<int>& arr, size_t si, size_t ei, int M, int level, std::vector<std::vector<int>>& subarrays){
    if(ei <= si) return;
    int num_subarrays = 1 << (M - level);
    size_t total_len = ei - si + 1;
    size_t sub_len = total_len / num_subarrays;
    size_t remain = total_len % num_subarrays;
    size_t start = si;
    for(int i = 0; i < num_subarrays; ++i){
        size_t len = sub_len + (static_cast<size_t>(i) < remain ? 1 : 0);
        size_t end = start + len;
        if(end > arr.size()) break;
        subarrays.push_back(std::vector<int>(arr.begin() + start, arr.begin() + end));
        start = end;
    }
}

void P_Division(std::vector<int>& arr, size_t si, size_t ei, int M, int level){
    if(ei <= si) return;
    std::vector<std::vector<int>> subarrays;
    if(level < (1 << (M - 1))){
        P_Create_Subarry(arr, si, ei, M, level, subarrays);
        if(subarrays.empty()) return;
        std::vector<std::thread> threads;
        for(size_t i = 0; i < subarrays.size(); ++i){
            if(!P_SS_CoreCheck(subarrays[i], 0, subarrays[i].size() - 1)) continue;
            std::vector<int> left, right;
            P_PartitionByMean(subarrays[i], left, right);
            left.insert(left.end(), right.begin(), right.end());
            subarrays[i] = left;
            threads.emplace_back([&subarrays, i, level, M](){
                P_Division(subarrays[i], 0, subarrays[i].size() - 1, M, level + 1);
            });
        }
        for(auto& thread : threads){
            if(thread.joinable()) thread.join();
        }
        std::vector<int> result;
        for(const auto& sub : subarrays){
            result.insert(result.end(), sub.begin(), sub.end());
        }
        arr = result;
    } else {
        F_MergeSort(arr, si, ei);
    }
}

void P_Sort(std::vector<int>& arr, int M){
    if(arr.empty() || arr.size() <= 1) return;
    if(!P_SS_CoreCheck(arr, 0, arr.size() - 1)) return;
    P_Division(arr, 0, arr.size() - 1, M, 0);
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