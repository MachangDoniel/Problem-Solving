#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

// Function to compute the weighted median
int weightedMedian(vector<int>& coordinates, vector<int>& weights) {
    vector<pair<int, int>> weighted_coords;
    
    // Populate the weighted coordinates vector
    for (size_t i = 0; i < coordinates.size(); ++i) {
        weighted_coords.push_back({coordinates[i], weights[i]});
    }
    
    // Sort by coordinates
    sort(weighted_coords.begin(), weighted_coords.end());
    
    int total_weight = 0;
    for (int weight : weights) {
        total_weight += weight;
    }
    
    int half_weight = total_weight / 2;
    int current_weight = 0;
    
    // Find the median
    for (const auto& p : weighted_coords) {
        current_weight += p.second;
        if (current_weight >= half_weight) {
            return p.first;
        }
    }
    
    return -1; // should never reach here if the input is valid
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    cin.ignore(); // to skip the newline after the number of test cases

    for (int case_number = 1; case_number <= T; ++case_number) {
        cin.ignore(); // to skip the blank line
        
        int m, n, q;
        cin >> m >> n >> q;

        vector<int> x_coords;
        vector<int> y_coords;
        vector<int> weights;

        for (int i = 0; i < q; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            x_coords.push_back(u);
            y_coords.push_back(v);
            weights.push_back(w);
        }

        int optimal_x = weightedMedian(x_coords, weights);
        int optimal_y = weightedMedian(y_coords, weights);

        cout << "Case " << case_number << ": " << optimal_x << " " << optimal_y << '\n';
    }

    return 0;
}
