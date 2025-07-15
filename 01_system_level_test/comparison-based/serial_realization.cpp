#include "serial_realization.hpp"

// Hàm tính trung bình của 1 đoạn mảng
int Cal_mean(const std::vector<int>& arr, int si, int ei) {
    int sum = 0;
    for (int i = si; i <= ei; ++i) {
        sum += arr[i];
    }
    return sum / (ei - si + 1);
}

// Trả về -1, 0, +1 tùy theo dấu số
int Cal_sign(int n) {
    return (n > 0) - (n < 0);
}

// Đảo ngược đoạn từ si đến ei
void Reverse_Array(std::vector<int>& arr, int si, int ei) {
    while (si < ei) {
        std::swap(arr[si++], arr[ei--]);
    }
}

int Partition(std::vector<int>& arr, int si, int ei) {
    int bi = si - 1;
    int mean = Cal_mean(arr, si, ei);

    for (int i = si; i <= ei; ++i) {
        if (arr[i] < mean) { // dùng "<" thay vì ">="
            std::swap(arr[++bi], arr[i]);
        }
    }

    // Nếu không chia được thì chọn điểm chính giữa
    if (bi < si || bi >= ei)
        return si + (ei - si) / 2;

    return bi;
}


// Biến toàn cục theo đúng pseudo-code
int cnt = 0; // Đếm số lần chia
int iCnt = 0; // Chỉ số trạng thái
std::vector<int> status; // Trạng thái đoạn: 0-unsorted, 1-sorted, 2-reversed, 3-similar

// Chia đoạn và sắp xếp đệ quy theo pseudo-code
void Division(std::vector<int>& arr, int si, int ei, int M) {
    int signCnt = 0;
    for (int i = si + 1; i <= ei; ++i) {
        signCnt += Cal_sign(arr[i] - arr[i - 1]);
    }

    if (signCnt == (ei - si)) {
        status[iCnt++] = 1; // Increasing
        return;
    }
    else if (signCnt == -(ei - si)) {
        status[iCnt++] = 2; // Decreasing
        Reverse_Array(arr, si, ei);
        return;
    }
    else if (signCnt == 0) {
        status[iCnt++] = 3; // All equal
        return;
    }
    else {
        status[iCnt++] = 0; // Unsorted
    }

    if (cnt < (1 << M) && status[iCnt - 1] == 0) {
        int bi = Partition(arr, si, ei);
        cnt++;
        if (si != bi && bi != ei) {
            Division(arr, si, bi, M);
            Division(arr, bi + 1, ei, M);
        }
    } else {
        // Gọi sắp xếp cơ bản nếu không thể chia nữa
        std::sort(arr.begin() + si, arr.begin() + ei + 1);
    }
}

// Hàm chính: khởi động thuật toán
void Sort(std::vector<int>& arr, int M) {
    if (arr.empty()) return;
    cnt = 0;
    iCnt = 0;
    status.resize((1 << M), 0); // Kích thước mảng trạng thái
    Division(arr, 0, arr.size() - 1, M);
    // Sau khi chia xong
    if (!std::is_sorted(arr.begin(), arr.end()))
        std::sort(arr.begin(), arr.end());
}
