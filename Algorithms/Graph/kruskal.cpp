#include <algorithm>
#include <iterator>
#include <vector>

struct edge_t {
    int u, v;
    int w;
};

int n;                     // we have n vertices.
int disjoint_set[500000];  // index starts from 0.
int res;                   // the result.
std::vector<edge_t> edges; // all edges.

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

void kruskal() {
    make_set();

    std::sort(edges.begin(), edges.end(),
              [](const edge_t& lhs, const edge_t& rhs) { return lhs.w < rhs.w; });

    int count = n - 1; // at most n - 1 edges are required.

    auto it = edges.cbegin();

    while (count) {
        if (find_set(it->u) != find_set(it->v)) {
            union_set(it->u, it->v);

            res += it->w;
            count--;
        }

        ++it;
    }
}
