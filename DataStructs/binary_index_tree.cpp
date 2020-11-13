int n;           // we have n elements.
int arr[500001]; // index starts from 1.

inline int last_bit(int num) {
    return num & (-num);
}

// return the sum of [1, index]
int sum(int index) {
    int res = 0;
    while (index) {
        res += arr[index];
        index -= last_bit(index);
    }

    return res;
}

// plus value to the element of index of arr
void add(int index, int value) {
    while (index <= n) {
        arr[index] += value;
        index += last_bit(index);
    }
}
