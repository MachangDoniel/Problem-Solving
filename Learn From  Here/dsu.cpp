#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

class DisjointSet {
private:
    int parent[N];
    int size[N];

public:
    DisjointSet() {
        for (int i = 0; i < N; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]); // Path compression
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            // Union by size
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    DisjointSet ds;
    while (k--) {
            int u, v;
            cin >> u >> v;
            ds.union_sets(u, v);
        }
        int connected_component = 0;
        for (int i = 1; i <= n; ++i) {
            if (ds.find_set(i) == i) connected_component++;
        }
    return 0;
}
