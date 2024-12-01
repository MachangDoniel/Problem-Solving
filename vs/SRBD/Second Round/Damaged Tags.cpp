#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define Good_Luck ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MOD = 1000000007;

bool isMatch(const string& p, const string& n) {
    for (int i = 0; i < 4; ++i) {
        if (p[i] != '?' && p[i] != n[i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int p; cin >> p; 
    vector<string> purchased(p);
    
    for(int i = 0; i < p; i++){
        cin >> purchased[i];
    }
    
    int n; 
    cin >> n; 
    vector<string> nearby(n);
    
    for(int i = 0; i < n; i++){
        cin >> nearby[i];
    }
    
    vector<vector<int>> matches(p);
    for(int i = 0; i < p; i++) {
        for (int j = 0; j < n; j++) {
            if (isMatch(purchased[i], nearby[j])) {
                matches[i].push_back(j);
            }
        }
    }

    // dp[i] stores the number of ways to match purchased items represented by i
    vector<int> dp(1 << n, 0);
    dp[0] = 1; 
    for(int i = 0; i < (1 << n); i++){
        int matchedCount = 0;

        for(int j = 0; j < n; j++){
            if (i & (1 << j)) {
                matchedCount++;
            }
        }

        if(matchedCount < p){
            for (int j : matches[matchedCount]){ 
                if (!(i & (1 << j))) { 
                    dp[i | (1 << j)] = (dp[i | (1 << j)] + dp[i]) % MOD; 
                }
            }
        }
    }

    int totalWays=0;
    for (int i=0;i<(1<<n);i++) {
        if (__builtin_popcount(i)==p) {
            totalWays=(totalWays+dp[i])%MOD; 
        }
    }
    cout<<totalWays<<endl;
}

int main() {
    Good_Luck; 
    int T; 
    cin >> T; 
    while (T--) {
        solve();
    }
    return 0;
}
