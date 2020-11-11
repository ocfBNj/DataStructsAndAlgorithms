#include <iostream>

void __insertion_sort(int arr[], int i, int interval) {
    int key = arr[i];
    int j = i - interval;

    while (j >= 0 && arr[j] > key) {
        arr[j + interval] = arr[j];
        j -= interval;
    }

    arr[j + interval] = key;
}

void shell_sort(int arr[], int length) {
    for (int interval = length / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < length; i++) {
            __insertion_sort(arr, i, interval);
        }
    }
}

int main() {
    int arr[] = {56, 32, 45, 12, 52, 32, 61, 8, 5, 4, 2, 1};
    shell_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (auto num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}
