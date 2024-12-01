#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

// Function to compute x^y % p using iterative binary exponentiation
long long mod_pow(long long x, long long y, long long p) {
    long long res = 1; // Initialize result
    x = x % p; // Update x if it is more than or equal to p
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) {
            res = (res * x) % p;
        }
        // y must be even now
        y = y >> 1; // y = y / 2
        x = (x * x) % p; // Change x to x^2
    }
    return res;
}

// Function to calculate expected coins spent by Oli
long long expected_coins(int n, int k, int a, int b) {
    // If Oli is first in line, he spends 0 coins.
    if (k == 1) return 0;

    // Calculate p and q for the expected coins formula
    long long p = (n - k + 1) * (b - a) % MOD; // (n - k + 1)(b - a)
    long long q = b; // q = b

    // Compute the inverse of q modulo MOD
    long long inverse_q = mod_pow(q, MOD - 2, MOD); // q^-1 mod MOD

    // Final expected coins calculation
    long long expected = (p * inverse_q) % MOD;

    return expected;
}

int main() {
    int n, k, a, b;
    cin >> n >> k; // Read number of students and Oli's position
    cin >> a >> b; // Read the probability parameters

    // Calculate and print the expected coins spent by Oli
    long long result = expected_coins(n, k, a, b);
    cout << result << endl;

    return 0;
}
