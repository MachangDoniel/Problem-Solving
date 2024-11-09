#include <bits/stdc++.h>
using namespace std;

#define int long long
constexpr int N = 10005;
constexpr int mod = 1e9 + 7;

vector<int> fact(N), invFact(N);
int comb[N][N];

// Compute bigmoder with modulo for Fermat’s inverse
int bigmod(int a,int p,int m){
    if(p == 0) return 1;
    int q = bigmod(a, p/2, m);
    if(p % 2 == 0) return (q*q) % m;
    return (q*((q*a) % m)) % m;
}

// Precompute factorials and modular inverses for the modular inverse method
void precomputeFactorials() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    invFact[N - 1] = bigmod(fact[N - 1], mod - 2, mod); // Fermat’s inverse for the last factorial
    for (int i = N - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }
}

// Traditional method to calculate combinations with modular inverse (nCr = fact[n] / (fact[r] * fact[n - r]))
int traditionalCombinationWithModInv(int n, int r) {
    if (r > n) return 0;
    return fact[n] % mod * invFact[r] % mod * invFact[n - r] % mod;
}

// Traditional method without modular inverses (only for smainter values of n to avoid overflow)
int traditionalCombinationWithoutMod(int n, int r) {
    if (r > n) return 0;
    return fact[n] / (fact[r] * fact[n - r]);
}

// DP Combination table setup, calculated on-demand with memoization
void precomputeDP() {
    
    for (int i = 0; i < N; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
        }
    }
}

// DP method to retrieve precomputed combination
int dpCombination(int n, int r) {
    if (n < 0 || r < 0 || n < r) return 0;
    return comb[n][r];
}

main() {
    precomputeFactorials();  // For factorial-based methods
    precomputeDP();          // For DP-based method

    int n, r;
    cin >> n >> r;

    // Using the DP-based method
    cout << "DP Method: " << dpCombination(n, r) << endl;

    // Using the traditional method with modular inverse
    cout << "Traditional Method with Modular Inverse: " << traditionalCombinationWithModInv(n, r) << endl;

    // Using the traditional method without modular inverse (no mod, for smaint n)
    cout << "Traditional Method without Modular Inverse: " << traditionalCombinationWithoutMod(n, r) << endl;
}
