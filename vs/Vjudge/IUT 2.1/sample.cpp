#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp;

int getAns(vector<int>& v, vector<int>& digit, int index, int sum) {
    if (index >= v.size()) {
        return 0;
    }

    if (dp[index][sum] != -1) {
        return dp[index][sum];
    }

    // Recurse without taking v[index]
    int res = getAns(v, digit, index + 1, sum);

    // Recurse by taking v[index] if possible
    vector<int> count = digit;
    int num = v[index];
    while (num > 0) {
        count[num % 10]++;
        if (count[num % 10] > 2) {
            // Prune this branch if digit frequency exceeds 2
            dp[index][sum] = res;
            return res;
        }
        num /= 10;
    }
    int newSum = sum + v[index];
    if (newSum <= 1000) {
        res = max(res, newSum + getAns(v, count, index + 1, newSum));
    }

    // Memoize the result
    dp[index][sum] = res;
    return res;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<int> digit(10, 0);
        dp.assign(n + 1, vector<vector<int>>(1001, vector<int>(1001, -1))); // Initialize dp table
        cout << getAns(v, digit, 0, 0) << endl;
    }

}
