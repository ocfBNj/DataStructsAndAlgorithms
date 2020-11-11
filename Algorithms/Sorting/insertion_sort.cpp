#include <iostream>

void insertion_sort(int arr[], int length) {
    for (int i = 1; i < length; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {56, 32, 45, 12, 52, 32, 61, 8, 5, 4, 2, 1};
    insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (auto num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}
