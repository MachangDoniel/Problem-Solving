#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long  // Use long long for large inputs

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];

        vector<int> dp[2];  // dp[0]: selected, dp[1]: not selected
        dp[0].resize(n + 1, 0);
        dp[1].resize(n + 1, 0);

        // Traverse the problems in reverse order
        for (int i = n; i >= 1; --i) {
            // If we select this problem
            dp[0][i] = a[i] + dp[1][b[i]];  // Select the current problem, can choose from the last acceptable problem
            
            // If we do not select this problem
            dp[1][i] = max(dp[0][i + 1], dp[1][i + 1]);  // Max of selecting or not selecting the next problems

            // Ensure dp[1] also accounts for the previous state
            dp[1][i] = max(dp[1][i], dp[1][i + 1]);
        }

        // The result will be the maximum of selecting or not selecting the first problem
        int max_points = max(dp[0][1], dp[1][1]);
        cout << max_points << "\n";
    }

    return 0;
}
