#include "parallel_realization.hpp"

int P_Cal_mean(const std::vector<int>& arr, int si, int ei) {
    int sum = 0;
    for (int i = si; i <= ei; ++i)
        sum += arr[i];
    return sum / (ei - si + 1);
}

int P_Cal_sign(int x) {
    return (x > 0) - (x < 0);
}

// bool P_CoreSSChecker(std::vector<int>& arr, int si, int ei) {
//     int signCnt = 0;
//     for (int i = si + 1; i <= ei; ++i) {
//         signCnt += P_Cal_sign(arr[i] - arr[i - 1]);
//     }

//     if (signCnt == ei - si || signCnt == -(ei - si)) {
//         if (arr[si] > arr[si + 1]) {
//             std::reverse(arr.begin() + si, arr.begin() + ei + 1);
//         }
//         return true;
//     }

//     if (signCnt == 0) return true;
//     return false;
// }
bool P_CoreSSChecker(std::vector<int>& arr, int si, int ei) {
    int signCnt = 0;
    for (int i = si + 1; i <= ei; ++i) {
        signCnt += P_Cal_sign(arr[i] - arr[i - 1]);
    }

    if (signCnt == ei - si) return true; // increasing
    if (signCnt == -(ei - si)) {
        std::reverse(arr.begin() + si, arr.begin() + ei + 1);
        return true;
    }
    return false;
}


int P_Partition(std::vector<int>& arr, int si, int ei) {
    int bi = si - 1;
    int mean = P_Cal_mean(arr, si, ei);

    for (int i = si; i <= ei; ++i) {
        if (arr[i] < mean) {
            std::swap(arr[++bi], arr[i]);
        }
    }
    return bi;
}

void P_Division(std::vector<int>& arr, int si, int ei, int M, int level) {
    if (level < (1 << M)) {
        int segmentCount = 1 << level;
        int segmentSize = (ei - si + 1) / segmentCount;
        int remainder = (ei - si + 1) % segmentCount;

        std::vector<int> partStart(segmentCount);
        std::vector<int> partEnd(segmentCount);

        int idx = si;
        for (int i = 0; i < segmentCount; ++i) {
            partStart[i] = idx;
            int len = segmentSize + (i < remainder ? 1 : 0);
            idx += len;
            partEnd[i] = idx - 1;
        }

        // Step 2: Check each segment with CoreSSChecker
        bool allSorted = true;
        for (int i = 0; i < segmentCount; ++i) {
            if (!P_CoreSSChecker(arr, partStart[i], partEnd[i])) {
                allSorted = false;
            }
        }

        if (allSorted) return;

        // Step 3: Calculate mean from si to ei
        int mean = P_Cal_mean(arr, si, ei);

        // Step 4–5: Classify to < mean and >= mean
        std::vector<int> lessThanMean;
        std::vector<int> greaterThanMean;

        for (int i = si; i <= ei; ++i) {
            if (arr[i] < mean) lessThanMean.push_back(arr[i]);
            else greaterThanMean.push_back(arr[i]);
        }

        // Step 6: Replace data
        int index = si;
        for (int v : lessThanMean) arr[index++] = v;
        for (int v : greaterThanMean) arr[index++] = v;

        // Step 7: Recursive Division
        int boundary = si + lessThanMean.size() - 1;
        if (si <= boundary)
            P_Division(arr, si, boundary, M, level + 1);
        if (boundary + 1 <= ei)
            P_Division(arr, boundary + 1, ei, M, level + 1);
    } else {
        // Fallback Core Sort
        if (!P_CoreSSChecker(arr, si, ei)) {
            std::sort(arr.begin() + si, arr.begin() + ei + 1);
        }
    }
}

void ParallelSort(std::vector<int>& arr, int M) {
    if (arr.empty()) return;
    P_Division(arr, 0, arr.size() - 1, M, 0);
}
