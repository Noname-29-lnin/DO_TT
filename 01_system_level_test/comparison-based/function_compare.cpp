#include "function_compare.hpp"
#include "./../Verification/Verif.hpp"
#include <thread>

void PrintArray(std::string name, const std::vector<int>& arr){
    std::cout << name << ": ";
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

////////////////////////////////////////////////////////////////

int F_Cal_mean(const std::vector<int>& arr, int si, int ei){
    int sum = 0;
    for(int i = si; i <= ei; i++){ sum += arr[i]; }
    return (int) sum / (ei - si + 1);
}

CheckArrayStatus SS_Check(std::vector<int>& arr, int si, int ei){
    if(arr.empty() || arr.size() == 1) return CheckArrayStatus::SIMILAR;
    bool isAsc = true, isDesc = true, isEqual = true;
    for(int i = si + 1; i <= ei; ++i){
        if(arr[i] != arr[i - 1]) isEqual = false;
        if(arr[i] < arr[i - 1]) isAsc = false;
        if(arr[i] > arr[i - 1]) isDesc = false;
    }
    if(isEqual)     return CheckArrayStatus::SIMILAR;
    else if(isAsc)  return CheckArrayStatus::INCREASING;
    else if(isDesc) return CheckArrayStatus::DECREASING;
    else            return CheckArrayStatus::UNSORTED;
}

void F_Reverse_Array(std::vector<int>& arr, int si, int ei){
    while(si < ei){ std::swap(arr[si++], arr[ei--]); }
}

int S_Partition(std::vector<int>& arr, int si, int ei, int& count_swap, int& count_compare){
    int bi = si - 1;
    int mean = F_Cal_mean(arr, si, ei);
    std::cout << "Mean = " << mean << std::endl;
    for(int i = si; i <= ei; i++){
        count_compare++;
        if(arr[i] <= mean){
            ++bi;
            std::swap(arr[bi], arr[i]);
            count_swap++;
        }
    }
    std::cout << "Bi = " << bi << std::endl;
    return bi;
}
void S_Division(std::vector<int>& arr, int si, int ei, int M, int& S_cnt, int& count_swap, int& count_compare, int& count_similar, int& count_increasing, int& count_decreasing){
    if(si < ei){
        std::cout << "si = " << si << " ei = " << ei << " Scnt = " << S_cnt << std::endl;
        CheckArrayStatus status = SS_Check(arr, si, ei);
        if(status == CheckArrayStatus::SIMILAR) {
            // std::cout <<"Status = " << "SIMILAR" << std::endl;
            count_similar++;
            return;
        }
        else if(status == CheckArrayStatus::INCREASING) {
            // std::cout <<"Status = " << "INCREASING" << std::endl;
            count_increasing++;    
            return;
        }
        else if(status == CheckArrayStatus::DECREASING){
            // std::cout <<"Status = " << "DECREASING" << std::endl;
            count_decreasing++;
            F_Reverse_Array(arr, si, ei);
            return;
        }
        else {
            if(S_cnt < (1 << (M))){
                int bi = S_Partition(arr, si, ei, count_swap, count_compare);
                S_cnt++;
                // PrintArray("D0", arr);
                S_Division(arr, si, bi, M, S_cnt, count_swap, count_compare, count_similar, count_increasing, count_decreasing);
                if((si == 0) || (ei == static_cast<int>(arr.size()) - 1)) {
                    S_cnt = 1;
                }
                // PrintArray("D1", arr);
                S_Division(arr, bi+1, ei, M, S_cnt, count_swap, count_compare, count_similar, count_increasing, count_decreasing);
                // PrintArray("D2", arr);
            } else { // core-sort
                // std::cout <<"F_subarray: si = " << si << " ei = " << ei << std::endl;
                F_QuickSort(arr, si, ei, count_swap, count_compare);
                // F_MergeSort(arr, si, ei, count_compare);
            }
        }
    }
}

void S_Sort(std::vector<int>& arr, int M, int& count_swap, int& count_compare, int& count_similar, int& count_increasing, int& count_decreasing){
    if(arr.empty() || arr.size() <= 1) return;
    int cnt = 0;
    S_Division(arr, 0, arr.size() - 1, M, cnt, count_swap, count_compare, count_similar, count_increasing, count_decreasing);
}

//////////////////////////////////////////////////

// 1 thread process: 
//  + check status
//  + cal sum

bool P_CoreChecker(std::vector<int>& arr, int si, int ei){
    CheckArrayStatus status = SS_Check(arr, si, ei);
    switch(status){
        case CheckArrayStatus::SIMILAR:
            return false;
        case CheckArrayStatus::INCREASING:
            return false;
        case CheckArrayStatus::DECREASING:
            F_Reverse_Array(arr, si, ei);
            return false;
        default:
            return true;
    }
}

int P_Cal_Sum(std::vector<int>& arr, int si, int ei){
    int sum = 0;
    for(int i = si; i <= ei; ++i){
        sum += arr[i];
    }
    return sum;
}

void P_A_Thread(std::vector<int>& arr, int si, int ei, bool& status, int &sum){
    status = P_CoreChecker(arr, si, ei);
    sum = P_Cal_Sum(arr, si, ei);
}

void P_Division(std::vector<int>& arr, int si, int ei, int M, int& S_cnt){
    std::vector<std::thread> Number_thread;
    
}


bool P_CoreSSChecker(std::vector<int>& arr, int si, int ei) {
    CheckArrayStatus status = SS_Check(arr, si, ei);
    if (status == CheckArrayStatus::DECREASING) {
        F_Reverse_Array(arr, si, ei);
        return true;
    }
    return (status != CheckArrayStatus::UNSORTED);
}

int P_Partition(std::vector<int>& arr, int si, int ei, double mean) {
    int bi = si;
    for (int i = si; i <= ei; ++i) {
        if (arr[i] <= mean) {
            ++bi;
            std::swap(arr[i], arr[bi]);
        }
    }
    return bi;
}

void P_Division(std::vector<int>& arr, int si, int ei, int M, int level) {
    if (level >= (1 << M) - 1) {
        if (!P_CoreSSChecker(arr, si, ei)) {
            std::sort(arr.begin() + si, arr.begin() + ei + 1);
        }
        return;
    }

    int parts = 1 << level;
    int len = (ei - si + 1) / parts;

    std::vector<int> partSI(parts), partEI(parts);
    for (int i = 0; i < parts; ++i) {
        partSI[i] = si + i * len;
        partEI[i] = (i == parts - 1) ? ei : (si + (i + 1) * len - 1);
    }

    // Song song P_CoreSSChecker
    std::vector<std::thread> check_threads;
    std::vector<bool> valid_parts(parts, false);

    for (int i = 0; i < parts; ++i) {
        check_threads.emplace_back([&, i]() {
            valid_parts[i] = P_CoreSSChecker(arr, partSI[i], partEI[i]);
        });
    }
    for (auto& t : check_threads) t.join();

    if (!std::all_of(valid_parts.begin(), valid_parts.end(), [](bool v) { return v; })) {
        return;
    }
    
    // Song song tính tổng để lấy mean
    std::vector<int> part_sums(parts, 0);
    std::vector<std::thread> sum_threads;

    for (int i = 0; i < parts; ++i) {
        sum_threads.emplace_back([&, i]() {
            part_sums[i] = std::accumulate(arr.begin() + partSI[i], arr.begin() + partEI[i] + 1, 0);
        });
    }
    for (auto& t : sum_threads) t.join();

    int total_sum = std::accumulate(part_sums.begin(), part_sums.end(), 0);
    double mean = static_cast<double>(total_sum) / (ei - si + 1);

    // Partition toàn mảng theo mean
    int mid = P_Partition(arr, si, ei, mean); // arr[si..mid-1] < mean, arr[mid..ei] >= mean

    // Đệ quy song song 2 phần
    std::thread t1(P_Division, std::ref(arr), si, mid - 1, M, level + 1);
    std::thread t2(P_Division, std::ref(arr), mid, ei, M, level + 1);
    t1.join();
    t2.join();
}

void P_Sort(std::vector<int>& arr, int M) {
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
