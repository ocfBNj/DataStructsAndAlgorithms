#include <cstddef>
#include <iostream>

void __merge(int arr[], int begin, int mid, int end) {
    int n1 = mid - begin;
    int n2 = end - mid;

    int* A = new int[n1 + 1]{};
    int* B = new int[n2 + 1]{};
    A[n1] = INT_MAX;
    B[n2] = INT_MAX;

    int i = 0;
    for (; i < n1; i++)
        A[i] = arr[i + begin];

    int j = 0;
    for (; j < n2; j++)
        B[j] = arr[j + mid];

    i = j = 0;
    int k = begin;
    for (; k < end; k++) {
        if (A[i] <= B[j])
            arr[k] = A[i++];
        else
            arr[k] = B[j++];
    }

    delete[] A;
    delete[] B;
}

void merge_sort(int arr[], int length) {
    if (length > 1) {
        int mid = length / 2;
        merge_sort(arr, mid);
        merge_sort(arr + mid, length - mid);
        __merge(arr, 0, mid, length);
    }
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 34, 13, 453, 12, 53};
    merge_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (auto num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}
