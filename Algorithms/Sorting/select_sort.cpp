#include <iostream>

void select_sort(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            int min_index = i;
            if (arr[j] < arr[min_index])
                min_index = j;

            if (min_index != i) {
                int temp = arr[min_index];
                arr[min_index] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {56, 32, 45, 12, 52, 32, 61, 8, 5, 4, 2, 1};
    select_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (auto num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}
