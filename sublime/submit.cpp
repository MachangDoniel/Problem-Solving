#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Sort the array in increasing order
        sort(a.begin(), a.end());

        // Calculate the maximum score
        long long score = 0;
        for (int i = 1; i < n; i++) {
            score += a[i] - a[0];
        }

        cout << score << '\n';
    }
    return 0;
}
