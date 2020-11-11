#include <iostream>

int __partition(int arr[], int length) {
    int i = -1;
    int j = 0;
    int mid = arr[length - 1];

    for (; j < length - 1; j++) {
        if (arr[j] <= mid) {
            i += 1;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    i += 1;
    arr[length - 1] = arr[i];
    arr[i] = mid;

    return i;
}

void qucik_sort(int arr[], int length) {
    while (length > 1) {
        int mid = __partition(arr, length);
        qucik_sort(arr, mid);
        arr += mid + 1;
        length -= mid + 1;
    }
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 34, 13, 453, 12, 53};
    qucik_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (auto num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}
