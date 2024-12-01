#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

vector<vector<int>> Adj(25);
vector<pair<int, int>> edges; // List of edges
vector<bool> deleted; // Tracks deleted edges
int min_cost = 0;

int count_non_deleted_neighbors(int edge_index) {
    int u = edges[edge_index].first;
    int v = edges[edge_index].second;
    int count = 0;

    for (int i = 0; i < edges.size(); i++) {
        if (!deleted[i]) {
            int neighbor_u = edges[i].first;
            int neighbor_v = edges[i].second;
            // Check if edge i shares a vertex with edge_index
            if (neighbor_u == u || neighbor_u == v || neighbor_v == u || neighbor_v == v) {
                count++;
            }
        }
    }

    return count;
}

void paint_edge_and_delete_neighbors(int edge_index) {
    // Paint the current edge blue (costs 1)
    min_cost += 1;

    // Get the vertices of the current edge
    int u = edges[edge_index].first;
    int v = edges[edge_index].second;

    // Mark all neighbor edges as deleted (white)
    for (int i = 0; i < edges.size(); i++) {
        if (i != edge_index && !deleted[i]) {
            int neighbor_u = edges[i].first;
            int neighbor_v = edges[i].second;
            // Check if edge i shares a vertex with edge_index
            if (neighbor_u == u || neighbor_u == v || neighbor_v == u || neighbor_v == v) {
                deleted[i] = true; // Mark neighbor edge as deleted
            }
        }
    }
}

void solve() {
    int n, m; 
    cin >> n >> m;
    
    edges.resize(m);
    deleted.resize(m, false); // Initialize deleted edges

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    // Main loop to paint edges
    while (true) {
        int max_neighbors = -1;
        int edge_to_paint = -1;

        // Find the edge with the maximum non-deleted neighbors
        for (int i = 0; i < m; i++) {
            if (!deleted[i]) { // Edge not painted yet
                int count = count_non_deleted_neighbors(i);
                if (count > max_neighbors) {
                    max_neighbors = count;
                    edge_to_paint = i;
                }
            }
        }

        // If no edge can be painted, exit
        if (edge_to_paint == -1) break;

        // Paint the chosen edge and delete its neighbors
        paint_edge_and_delete_neighbors(edge_to_paint);
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1; 
    // cin >> T; // Uncomment if you want to handle multiple test cases
    for (int t = 1; t <= T; t++) {
        solve();
    }

    cout << min_cost << endl; // Output the minimal cost
}
