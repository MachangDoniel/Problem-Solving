#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 1e9+7;

LL c[55][55];  // Binomial coefficients
LL Dp[410][55]; // DP table

// Precompute binomial coefficients and DP transitions
void Init() {
    memset(c, 0, sizeof(c));
    for (int i = 0; i < 55; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
        }
    }

    for (int i = 1; i < 410; i++) {
        Dp[i][1] = 1;
        for (int j = 2; j < 55; j++) {
            Dp[i][j] = (Dp[i-1][j-1] * j + Dp[i-1][j] * j) % MOD;
        }
    }
}

int main() {
    Init();
    int t;
    cin >> t;
    int cas = 0;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        n++, m++;

        LL ans = 0;

        if (n == 1 && m == 1) {
            ans = k;
        } else 
        {
            int sum1 = 0, sum2 = 0;
            sum1 = ((n+1)/2) * ((m+1)/2) + (n/2) * (m/2);
            sum2 = n * m - sum1;

            for (int i = 1; i < k; i++) {
                for (int j = 1; i + j <= k; j++) {
                    ans = (ans + c[k][i] * c[k-i][j] % MOD * Dp[sum1][i] % MOD * Dp[sum2][j] % MOD) % MOD;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}