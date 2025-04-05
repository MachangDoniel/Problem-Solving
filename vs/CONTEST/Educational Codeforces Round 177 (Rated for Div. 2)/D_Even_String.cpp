#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;
const int MAX_N = 500000;

vector<long long> fact(MAX_N + 1), inv_fact(MAX_N + 1);

// Function to compute modular exponentiation
long long mod_exp(long long base, long long exp, int mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Precompute factorials and their modular inverses
void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[MAX_N] = mod_exp(fact[MAX_N], MOD - 2, MOD);
    for (int i = MAX_N - 1; i >= 0; --i) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

// Function to calculate nCr % MOD
long long nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return (fact[n] * inv_fact[r] % MOD) * inv_fact[n - r] % MOD;
}

// Function to solve each test case
void solve() {
    vector<int> c(26);
    for (int i = 0; i < 26; ++i) {
        cin >> c[i];
    }
    
    long long result = 1;
    int total_chars = 0;
    
    // Check if all counts are even, and calculate the total number of characters
    for (int i = 0; i < 26; ++i) {
        if (c[i] % 2 != 0) {
            cout << 0 << endl;
            return;
        }
        total_chars += c[i];
    }

    // We will place characters in pairs
    int half_chars = total_chars / 2;

    // Calculate the number of ways to distribute the characters in the string
    for (int i = 0; i < 26; ++i) {
        if (c[i] > 0) {
            // We need to place c[i] / 2 characters at half_chars positions
            result = (result * nCr(half_chars, c[i] / 2)) % MOD;
            half_chars -= c[i] / 2;
        }
    }
    
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute factorials and inverses
    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
