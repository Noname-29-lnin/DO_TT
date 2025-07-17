// #include "function.hpp"

// void PrintArray(std::string name, const std::vector<int>& arr){
//     // int n = arr.size();
//     std::cout << name << ": " << std::endl;
//     // for(int i = 0; i < n; i++){
//     //     std::cout << arr[i] << " ";
//     // }
//     for(const auto& elem : arr){
//         std::cout << elem << " ";
//     }
//     std::cout << "\n";
// }

// void F_SelectionSort(std::vector<int>& arr){
//     int n = arr.size();
//     for(int i = 0; i < n - 1; ++i){
//         int minIndex = i;
//         for(int j = i+1; j < n; ++j){
//             if(arr[j] < arr[minIndex]) { minIndex = j; }
//         }
//         std::swap(arr[i], arr[minIndex]);
//     }
// }

// void F_InsertionSort(std::vector<int>& arr){
//     int n = arr.size();

//     for(int i = 1; i < n; i++){
//         int key = arr[i];
//         int j = i - 1;
//         while(j >= 0 && arr[j] > key){
//             arr[j+1] = arr[j];
//             --j;
//         }
//         arr[j+1] = key;
//     }
// }

// void F_BubbleSort(std::vector<int>& arr){
//     int n = arr.size();

//     for(int i = 0; i < n - 1; i++){
//         for(int j = 0; j < n - i - 1; j++){
//             if(arr[j] > arr[j+1]) { std::swap(arr[j], arr[j+1]); }
//         }
//     }
// }

// void F_heapify(std::vector<int>& arr, int n, int i){
//     int largest = i;
//     int left = 2*i + 1;
//     int right = 2*i + 2;

//     // Check if Left or Right child is larger than root
//     if(left < n && arr[left] > arr[largest]) { largest = left; }
//     if(right < n && arr[right] > arr[largest]) { largest = right; }

//     // If largest is not root, swap and continue heapifying
//     if(largest != i){
//         std::swap(arr[i], arr[largest]);
//         F_heapify(arr, n, largest);
//     }
// }
// void F_HeapSort(std::vector<int>& arr){
//     int n = arr.size();
    
//     // Build heap
//     for(int i = n/2 - 1; i >= 0; i--){
//         F_heapify(arr, n, i);
//     }
    
//     // One by one extract elements from heap
//     for(int i = n - 1; i > 0; i--){
//         std::swap(arr[0], arr[i]); // Move current root to end
//         F_heapify(arr, i, 0); // Call heapify on reduced heap
//     }
// }

// int F_Partition(std::vector<int>& arr, int low, int high){
//     int pivot = arr[high];
//     int i = low-1;

//     // Partitioning the array around the pivot
//     for(int j = low; j < high; ++j){
//         if(arr[j] < pivot){
//             ++i;
//             std::swap(arr[i], arr[j]);
//         }
//     }
//     std::swap(arr[i+1], arr[high]);
//     return i + 1;
// }
// void F_QuickSort(std::vector<int>& arr, int low, int high){
//     if(low < high){
//         int pi = F_Partition(arr, low, high);
//         // for( int i : arr){
//         //     std::cout << i << " ";
//         // }
//         // std::cout << "QuickSort - 1: low = " << low << ", high = " << high << ", pi = " << pi << std::endl;
//         F_QuickSort(arr, low, pi - 1);
//         // for( int i : arr){
//         //     std::cout << i << " ";
//         // }
//         // std::cout << "QuickSort - 2: low = " << low << ", high = " << high << ", pi = " << pi << std::endl;
//         F_QuickSort(arr, pi + 1, high);
//         // for( int i : arr){
//         //     std::cout << i << " ";
//         // }
//         // std::cout << "QuickSort - 3: low = " << low << ", high = " << high << ", pi = " << pi << std::endl;
//     }
// }

// void F_Merge(std::vector<int>& arr, int left, int mid, int right){
//     std::vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
//     std::vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

//     size_t i = 0, j = 0, k = left;

//     while(i < L.size() && j < R.size()){
//         if(L[i] <= R[j]) {
//             arr[k++] = L[i++];
//         }
//         else {
//             arr[k++] = R[j++];
//         }
//     }
//     while(i < L.size()) { arr[k++] = L[i++]; }
//     while(j < R.size()) { arr[k++] = R[j++]; }
// }
// void F_MergeSort(std::vector<int>& arr, int left, int right){
//     if(left < right){
//         int mid = (left + right) / 2;
//         F_MergeSort(arr, left, mid);
//         F_MergeSort(arr, mid + 1, right);
//         F_Merge(arr, left, mid, right);
//     }
// }
// ////////////////////////////////////////////////////////////////
// int S_cnt = 0;
// int S_iCnt = 0;
// std::vector<int> S_status;
// int F_Cal_mean(const std::vector<int>& arr, int si, int ei){
//     int sum = 0;
//     for(int i = si; i <= ei; ++i){
//         sum += arr[i];
//     }
//     return (int)sum / (ei - si + 1);
// }
// int F_Cal_sign(int n){
//     if( n < 0) return -1;
//     else if( n > 0) return 1;
//     else return 0;
// }
// void F_Reverse_Array(std::vector<int>& arr, int si, int ei){
//     while(si < ei){
//         std::swap(arr[si++], arr[ei--]);
//     }
// }

// CheckArrayStatus SS_Check(std::vector<int>& arr, int si, int ei){
//     if(arr.empty() || arr.size() == 1) return CheckArrayStatus::SIMILAR;

//     bool isAsc = true, isDesc = true, isEqual = true;

//     // for(size_t i = si + 1; i <= ei; ++i){ // 3O(N)
//     for(size_t i = si + 1; i <= ei; ++i){
//         if(arr[i] != arr[i - 1])    isEqual = false;
//         if(arr[i] < arr[i - 1])     isAsc   = false;
//         if(arr[i] > arr[i - 1])     isDesc  = false;
//     }

//     if(isEqual) return CheckArrayStatus::SIMILAR;
//     if(isAsc)   return CheckArrayStatus::INCREASING;
//     if(isDesc)  return CheckArrayStatus::DECREASING;
//     return CheckArrayStatus::UNSORTED;
// }
// void S_Partition(std::vector<int>& arr, int si, int ei, int& left, int& right) {
//     int mean = F_Cal_mean(arr, si, ei);
//     left = si - 1;
//     right = ei + 1;
//     int i = si;
//     while (i < right) {
//         if (arr[i] < mean) {
//             std::swap(arr[++left], arr[i++]);
//         } else if (arr[i] > mean) {
//             std::swap(arr[i], arr[--right]);
//         } else {
//             i++;
//         }
//     }
// }
// void S_Division(std::vector<int>& arr, size_t si, size_t ei, int M, int& S_cnt){
//     if(ei <= si) return; // Stop if the subarray is empty or has one element

//     CheckArrayStatus status = SS_Check(arr, si, ei);
    
//     if(status == CheckArrayStatus::INCREASING) {
//         return; // Already sorted in increasing order
//     } else if(status == CheckArrayStatus::DECREASING) {
//         F_Reverse_Array(arr, si, ei); // Reverse if sorted in decreasing order
//         return;
//     } else if(status == CheckArrayStatus::SIMILAR) {
//         return; // All elements are equal
//     }

//     if(S_cnt < (1 << (M - 1))) {
//         int left, right;
//         S_Partition(arr, si, ei, left, right); // Use three-way partitioning
//         S_cnt++;
//         S_Division(arr, si, left, M, S_cnt);
//         // std::cout << "1: S_cnt: " << S_cnt << std::endl;
//         if(si == 0 || ei == arr.size() - 1) {
//             S_cnt = 1; // Reset count for the next full array
//         }
//         S_Division(arr, right, ei, M, S_cnt);
//         // std::cout << "2: S_cnt: " << S_cnt << std::endl;
//     } else {
//         // F_QuickSort(arr, si, ei); // Fallback to QuickSort
//         F_MergeSort(arr, si, ei); // Fallback to Merge Sort
//     }
// }
// // Serial realization
// // int S_Partition(std::vector<int>& arr, int si, int ei){
// //     int bi = si - 1;
// //     int mean = F_Cal_mean(arr, si, ei);

// //     for(int i = si; i <= ei; ++i){
// //         if(arr[i] < mean){
// //             std::swap(arr[++bi], arr[i]);
// //         }
// //     }
// //     return bi;
// // }
// // void S_Partition(std::vector<int>& arr, int si, int ei, int& left, int& right) {
// //     int mean = F_Cal_mean(arr, si, ei);
// //     left = si - 1;
// //     right = ei + 1;
// //     int i = si;
// //     while (i < right) {
// //         if (arr[i] < mean) {
// //             std::swap(arr[++left], arr[i++]);
// //         } else if (arr[i] > mean) {
// //             std::swap(arr[i], arr[--right]);
// //         } else {
// //             i++;
// //         }
// //     }
// // }
// // void S_Division(std::vector<int>& arr, size_t si, size_t ei, int M, int &S_cnt) {
// //     if (ei <= si) return; // Dừng nếu mảng con rỗng hoặc có 1 phần tử

// //     // // Sử dụng InsertionSort cho mảng con nhỏ
// //     // if (ei - si + 1 <= 10) {
// //     //     // F_InsertionSort(arr, si, ei);
// //     //     F_QuickSort(arr, si, ei); // Sử dụng QuickSort làm phương pháp thay thế
// //     //     return;
// //     // }

// //     int SignCnt = 0;
// //     for (size_t i = si + 1; i <= ei; ++i) {
// //         SignCnt += F_Cal_sign(arr[i] - arr[i - 1]);
// //     }

// //     if (SignCnt == (ei - si)) {
// //         if (arr[si] < arr[si + 1]) {
// //             return; // Đã sắp xếp tăng dần
// //         } else {
// //             F_Reverse_Array(arr, si, ei); // Đảo ngược nếu giảm dần
// //             return;
// //         }
// //     } else if (SignCnt == 0) {
// //         // Kiểm tra xem mảng con có thực sự được sắp xếp không
// //         bool sorted = true;
// //         for (size_t i = si + 1; i <= ei; ++i) {
// //             if (arr[i] < arr[i - 1]) {
// //                 sorted = false;
// //                 break;
// //             }
// //         }
// //         if (sorted) {
// //             return;
// //         } else {
// //             // F_InsertionSort(arr, si, ei); // Sắp xếp mảng con nhỏ
// //             // F_QuickSort(arr, si, ei); // Sử dụng QuickSort làm phương pháp thay thế
// //             return;
// //         }
// //     } else {
// //         if (S_cnt < (1 << (M - 1))) {
// //             int left, right;
// //             S_Partition(arr, si, ei, left, right); // Sử dụng phân vùng ba phần
// //             S_cnt++;
// //             S_Division(arr, si, left, M, S_cnt);
// //             if (si == 0 || ei == arr.size() - 1) {
// //                 S_cnt = 1;
// //             }
// //             S_Division(arr, right, ei, M, S_cnt);
// //         } else {
// //             F_QuickSort(arr, si, ei); // Fallback to QuickSort
// //         }
// //     }
// // }
// // void S_Division(std::vector<int>& arr, size_t si, size_t ei, int M, int &S_cnt) {
// //     int SignCnt = 0;
// //     for (int i = si + 1; i <= ei; ++i){
// //         SignCnt += F_Cal_sign(arr[i] - arr[i - 1]);
// //     }
    
// //     if(SignCnt == (ei - si)) {
// //         if(arr[si] < arr[si + 1]){
// //             return;
// //         } else {
// //             F_Reverse_Array(arr, si, ei);
// //             return;
// //         }
// //     } else if(SignCnt == 0){
// //         return;
// //     } else {
// //         if(S_cnt < (1 << (M-1))) {
// //             int bi = S_Partition(arr, si, ei);
// //             S_cnt ++;

// //             S_Division(arr, si, bi, M, S_cnt);
// //             if(si == 0 || (ei == (arr.size() - 1))){
// //                 S_cnt = 1;
// //             }
// //             S_Division(arr, bi + 1, ei, M, S_cnt);
// //         } else {
// //             F_QuickSort(arr, si, ei); // Use Quick Sort as a fallback
// //             // F_InsertionSort(arr); // Use Insertion Sort as a fallback
// //         }
// //     }
// //     return;
// // }
// // void S_Division(std::vector<int>& arr, int si, int ei, int M){
// //     int S_signCnt = 0;
// //     for(int i = si + 1; i <= ei; ++i){
// //         S_signCnt += F_Cal_sign(arr[i] - arr[i - 1]);
// //     }
// //     if(S_signCnt == (ei - si)){
// //         S_status[S_iCnt++] = 1; // Increasing
// //     }
// //     else if(S_signCnt == -(ei - si)){
// //         S_status[S_iCnt++] = 2; // Decreasing
// //         F_Reverse_Array(arr, si, ei);
// //     }
// //     else if(S_signCnt == 0){
// //         S_status[S_iCnt++] = 3; // Similar
// //     } else {
// //         S_status[S_iCnt++] = 0; // Unsorted
// //     }

// //         if(S_cnt < (1<<M) && S_status[S_iCnt - 1] == 0){
// //             int bi = S_Partition(arr, si, ei);
// //             S_cnt++;
// //             // for(int i : arr){
// //             //     std::cout << i << " ";
// //             // }
// //             // std::cout << "1: " << "S_cnt: " << S_cnt << ", S_iCnt: " << S_iCnt << ", Bi: " << bi << " Si: " << si << " Ei: " << ei << std::endl;
// //             S_Division(arr, si, bi, M);
// //             if(si == 0 || (ei == (arr.size() - 1))){
// //                 S_cnt = 1;
// //             }
// //             // for(int i : arr){
// //             //     std::cout << i << " ";
// //             // }
// //             // std::cout << "2: " << "S_cnt: " << S_cnt << ", S_iCnt: " << S_iCnt << ", Bi: " << bi << " Si: " << si << " Ei: " << ei << std::endl;
// //             S_Division(arr, bi + 1, ei, M);
// //             // for(int i : arr){
// //             //     std::cout << i << " ";
// //             // }
// //             // std::cout << "3: " << "S_cnt: " << S_cnt << ", S_iCnt: " << S_iCnt << ", Bi: " << bi << " Si: " << si << " Ei: " << ei << std::endl;
// //         } else {
// //             // std::sort(arr.begin() + si, arr.begin() + ei + 1); // Sort the segment
// //             // F_InsertionSort(arr); // Use Insertion Sort as a fallback 92ns
// //             F_QuickSort(arr, si, ei); // Use Quick Sort as a fallback
// //         }

// //     // if(S_cnt < (1 << M) && S_status[S_iCnt - 1] == 0){
// //     //     int bi = S_Partition(arr, si, ei);
// //     //     S_cnt++;
// //     //     // std::cout << "S_cnt: " << S_cnt << ", S_iCnt: " << S_iCnt << ", Bi: " << bi << std::endl;
// //     //     if(si != bi && ei != bi){
// //     //         S_Division(arr, si, bi - 1, M);
// //     //         S_Division(arr, bi + 1, ei, M);
// //     //     }
// //     //     if(si == 0 || ei == arr.size() - 1){
// //     //         S_cnt = 1;  
// //     //     }
// //     //     // std::cout << "------------------" << std::endl;
// //     //     // std::cout << "S_cnt: " << S_cnt << ", S_iCnt: " << S_iCnt << std::endl;
// //     //     // std::cout << "S_Division_Array: " << si << " to " << ei << std::endl;
// //     //     // std::cout << "-------------------" << std::endl;
// //     // } else {
// //     //     // std::sort(arr.begin() + si, arr.begin() + ei + 1); // Sort the segment
// //     //     // F_InsertionSort(arr); // Use Insertion Sort as a fallback 92ns
// //     //     // F_QuickSort(arr, si, ei); // Use Quick Sort as a fallback
// //     //     return;
// //     // }
// // }

// void S_Sort(std::vector<int>& arr, int M){
//     if ((arr.empty()) || (arr.size() <= 1)) return;
//     int cnt = 0;
//     // S_iCnt = 0;
//     // S_status.resize((1<<M), 0);
//     S_Division(arr, 0, arr.size() - 1, M, cnt);
// }

// ////////////// Parallel realization //////////////

// void P_PartitionByMean(const std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right) {
//     if (arr.size() <= 1) {
//         left = arr;
//         return;
//     }
//     int mean = F_Cal_mean(arr, 0, arr.size() - 1);
//     // std::cout << "Partitioning array of size " << arr.size() << " with mean " << mean << "\n";
//     for (int val : arr) {
//         if (val < mean) left.push_back(val);
//         else right.push_back(val);
//     }
//     // Handle case where one subarray is empty
//     if (left.empty() && !right.empty()) {
//         left.push_back(right.back());
//         right.pop_back();
//     } else if (right.empty() && !left.empty()) {
//         right.push_back(left.back());
//         left.pop_back();
//     }
// }

// bool P_SS_CoreCheck(std::vector<int>& arr, size_t si, size_t ei){
//     if(ei <= si) return true;

//     CheckArrayStatus status = SS_Check(arr, si, ei);

//     if(status == CheckArrayStatus::INCREASING) {
//         return false;
//     } else if(status == CheckArrayStatus::DECREASING) {
//         F_Reverse_Array(arr, si, ei);
//         return false;
//     } else if(status == CheckArrayStatus::SIMILAR) {
//         return false;
//     } else{
//         return true;
//     }
// }

// int P_Cal_Sum_Subarray(std::vector<int>& arr, size_t si, size_t ei){
//     int sum = 0;
//     for(size_t i = si; i <= ei; ++i){
//         sum += arr[i];
//     }
//     return sum;
// }

// void P_Create_Subarry(std::vector<int>& arr, size_t si, size_t ei, int M, int level,
//                     std::vector<std::vector<int>>& subarrays) {
//     if (ei <= si) return; // Subarray quá nhỏ để chia

//     int num_subarrays = 1 << (M - level); // 2^(M - level)
//     size_t total_len = ei - si + 1;
//     size_t sub_len = total_len / num_subarrays;
//     size_t remain = total_len % num_subarrays; // phần dư nếu không chia đều được

//     size_t start = si;
//     for (int i = 0; i < num_subarrays; ++i) {
//         size_t len = sub_len + (i < remain ? 1 : 0); // chia đều dư vào các mảng đầu tiên
//         size_t end = start + len;

//         if (end > arr.size()) break; // kiểm tra tràn

//         subarrays.push_back(std::vector<int>(arr.begin() + start, arr.begin() + end));
//         start = end;
//     }
// }    

// void P_Division(std::vector<int>& arr, size_t si, size_t ei, int M, int level){
//     if (ei <= si) return;

//     std::vector<std::vector<int>> subarrays;

//     if(level < (1 << (M-1))){
//     P_Create_Subarry(arr, si, ei, M, level, subarrays);

//     if(subarrays.empty()) {
//         return;
//     }

//     std::vector<std::thread> threads;
//     for (size_t i = 0; i < subarrays.size(); ++i){
//         if(!P_SS_CoreCheck(subarrays[i], 0, subarrays[i].size() - 1)) {
//             return; // any subarray false (similar, increasing, decreasing) return
//         }
         
//         int mean = F_Cal_mean(arr, si, ei);

//         P_PartitionByMean(subarrays[i], subarrays[i], subarrays[i]);

//         threads.emplace_back([&subarrays, i, level, M]() {
//             P_Division(subarrays[i], 0, subarrays[i].size() - 1, M, level + 1);
//         });
//     }

//     for (auto& thread : threads) {
//         if (thread.joinable()) {
//             thread.join();
//         }
//     }

//     // Gộp các mảng con đã sắp xếp
//     std::vector<int> result;
//     for (const auto& subarray : subarrays) {
//         result.insert(result.end(), subarray.begin(), subarray.end());
//     }
//     if (result.empty()) {
//         return; // Không có kết quả
//     }
//     arr = result; // Cập nhật mảng gốc với kết quả đã sắp xếp
//     } else {
//         // Nếu không chia được nữa, sắp xếp mảng con
//         F_MergeSort(arr, si, ei);
//     }
// }
// void P_Sort(std::vector<int>& arr, int M) {
//     if (arr.empty() || arr.size() <= 1) return;

//     // Kiểm tra mảng đã sắp xếp hay chưa
//     if (!P_SS_CoreCheck(arr, 0, arr.size() - 1)) {
//         return; // Mảng đã sắp xếp
//     }

//     P_Division(arr, 0, arr.size() - 1, M, 0);
// }   








#include "function.hpp"
#include <thread>

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