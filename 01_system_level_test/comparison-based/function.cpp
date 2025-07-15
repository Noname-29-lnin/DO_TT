#include "function.hpp"

void PrintArray(std::string name, const std::vector<int>& arr){
    // int n = arr.size();
    std::cout << name << ": " << std::endl;
    // for(int i = 0; i < n; i++){
    //     std::cout << arr[i] << " ";
    // }
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
            if(arr[j] < arr[minIndex]) { minIndex = j; }
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
            if(arr[j] > arr[j+1]) { std::swap(arr[j], arr[j+1]); }
        }
    }
}

void F_heapify(std::vector<int>& arr, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    // Check if Left or Right child is larger than root
    if(left < n && arr[left] > arr[largest]) { largest = left; }
    if(right < n && arr[right] > arr[largest]) { largest = right; }

    // If largest is not root, swap and continue heapifying
    if(largest != i){
        std::swap(arr[i], arr[largest]);
        F_heapify(arr, n, largest);
    }
}
void F_HeapSort(std::vector<int>& arr){
    int n = arr.size();
    
    // Build heap
    for(int i = n/2 - 1; i >= 0; i--){
        F_heapify(arr, n, i);
    }
    
    // One by one extract elements from heap
    for(int i = n - 1; i > 0; i--){
        std::swap(arr[0], arr[i]); // Move current root to end
        F_heapify(arr, i, 0); // Call heapify on reduced heap
    }
}

int F_Partition(std::vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;

    // Partitioning the array around the pivot
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
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }
    while(i < L.size()) { arr[k++] = L[i++]; }
    while(j < R.size()) { arr[k++] = R[j++]; }
}
void F_MergeSort(std::vector<int>& arr, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        F_MergeSort(arr, left, mid);
        F_MergeSort(arr, mid + 1, right);
        F_Merge(arr, left, mid, right);
    }
}
////////////////////////////////////////////////////////////////
int S_cnt = 0;
int S_iCnt = 0;
std::vector<int> S_status;
int F_Cal_mean(std::vector<int>& arr, int si, int ei){
    int sum = 0;
    for(int i = si; i <= ei; ++i){
        sum += arr[i];
    }
    return sum / (ei - si + 1);
}
int F_Cal_sign(int n){
    return (n > 0) - (n < 0);
}
void F_Reverse_Array(std::vector<int>& arr, int si, int ei){
    while(si < ei){
        std::swap(arr[si++], arr[ei--]);
    }
}
// Serial realization
int S_Partition(std::vector<int>& arr, int si, int ei){
    int bi = si - 1;
    int mean = F_Cal_mean(arr, si, ei);

    for(int i = si; i <= ei; ++i){
        if(arr[i] < mean){
            std::swap(arr[++bi], arr[i]);
        }
    }

    if(bi < si || bi >= ei)
        return si + (ei - si) / 2;
    
    return bi;
}
void S_Division(std::vector<int>& arr, int si, int ei, int M){
    int S_signCnt = 0;
    for(int i = si + 1; i <= ei; ++i){
        S_signCnt += F_Cal_sign(arr[i] - arr[i - 1]);
    }
    if(S_signCnt == (ei - si)){
        S_status[S_iCnt++] = 1; // Increasing
        return;
    }
    else if(S_signCnt == -(ei - si)){
        S_status[S_iCnt++] = 2; // Decreasing
        F_Reverse_Array(arr, si, ei);
        return;
    }
    else if(S_signCnt == 0){
        S_status[S_iCnt++] = 3; // Similar
        return;
    } else {
        S_status[S_iCnt++] = 0; // Unsorted
    }

    if(S_cnt < (1 << M) && S_status[S_iCnt - 1] == 0){
        int bi = S_Partition(arr, si, ei);
        S_cnt++;
        if(si != bi && ei != bi){
            S_Division(arr, si, bi - 1, M);
            S_Division(arr, bi + 1, ei, M);
        }
    } else {
        // std::sort(arr.begin() + si, arr.begin() + ei + 1); // Sort the segment
        // F_InsertionSort(arr); // Use Insertion Sort as a fallback 92ns
        F_QuickSort(arr, si, ei); // Use Quick Sort as a fallback
    }
}

void S_Sort(std::vector<int>& arr, int M){
    if ((arr.empty()) || (arr.size() <= 1)) return;
    S_cnt = 0;
    S_iCnt = 0;
    S_status.resize((1<<M), 0);
    S_Division(arr, 0, arr.size() - 1, M);
    if (!std::is_sorted(arr.begin(), arr.end()))
        std::sort(arr.begin(), arr.end());
}
