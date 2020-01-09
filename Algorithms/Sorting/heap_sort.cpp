#include <iostream>

void __max_heap(int arr[], int p, int legth) {
    int child = 0;

    while (p * 2 + 1 < legth) {
        child = p * 2 + 1;
        if (child + 1 < legth && arr[child] < arr[child + 1])
            child += 1;

        if (arr[child] > arr[p]) {
            int temp = arr[p];
            arr[p] = arr[child];
            arr[child] = temp;

            p = child;
        } else {
            break;
        }
    }
}

void __make_max_heap(int arr[], int length) {
    for (int p = (length - 2) / 2; p >= 0; p--)
        __max_heap(arr, p, length);
}

void __erase_max(int arr[], int length) {
    int max = arr[0];
    arr[0] = arr[length - 1];
    arr[length - 1] = max;

    __max_heap(arr, 0, length - 1);
}

void heap_sort(int arr[], int length) {
    __make_max_heap(arr, length);
    while (length > 1) {
        __erase_max(arr, length--);
    }
}

int main() {
    int arr[] = {10,9,8,7,6,5,4,3,2,1,100};
    heap_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (auto num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}