#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<double> calculateRatings(int N, int B, int Q, vector<int>& a, vector<pair<int, int>>& queries) {
    vector<double> results;
    long long cumulativeSum = 0;
    bool ratingFixed = false; // This flag will stop further updates when rating reaches or exceeds B
    double finalRating = 0.0;

    // Calculate initial cumulative sum of the array a
    for (int value : a) {
        cumulativeSum += value;
    }

    // Process each query
    for (auto& query : queries) {
        if (!ratingFixed) {
            int c = query.first;
            int x = query.second;

            // Adjust cumulative sum with the new performance value
            cumulativeSum += x - a[c - 1];
            a[c - 1] = x;

            // Calculate the rating
            double currentRating = static_cast<double>(cumulativeSum) / N;

            // Check if the rating meets or exceeds threshold B
            if (currentRating >= B) {
                finalRating = static_cast<double>(B); // Fix rating at B
                ratingFixed = true; // No further updates to rating will occur
            } else {
                finalRating = currentRating;
            }
        }
        
        // Append the final or current rating to results
        results.push_back(finalRating);
    }

    return results;
}

int main() {
    int N, B, Q;
    cin >> N >> B >> Q;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        int c, x;
        cin >> c >> x;
        queries[i] = {c, x};
    }

    // Calculate and print the ratings for each query
    vector<double> results = calculateRatings(N, B, Q, a, queries);
    cout << fixed << setprecision(12);
    for (double rating : results) {
        cout << rating << endl;
    }

    return 0;
}
