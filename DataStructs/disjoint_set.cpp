int n;                    // we have n elements.
int disjoint_set[500000]; // index starts from 0.

void make_set() {
    for (int i = 0; i != n; i++) {
        disjoint_set[i] = i;
    }
}

int find_set(int i) {
    if (disjoint_set[i] != i) {
        disjoint_set[i] = find_set(disjoint_set[i]);
    }

    return disjoint_set[i];
}

void union_set(int lhs, int rhs) {
    disjoint_set[find_set(lhs)] = find_set(rhs);
}
