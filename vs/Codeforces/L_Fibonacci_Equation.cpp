#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to check number of real roots
int checkRoots(ll A, ll B, ll C) {
    ll discriminant = B * B - 4 * A * C;
    
    if (discriminant > 0) return 2; // Two distinct real roots
    if (discriminant == 0) return 1; // One real root (double root)
    return 0; // No real roots (complex roots)
}

int main() {
    ll i, j, k;
    cin >> i >> j >> k;

    // Sort i, j, k
    ll indices[3] = {i, j, k};
    sort(indices, indices + 3);

    // Generalized A, B, C for Fibonacci relation
    ll A = 1, B = 1, C = 2; // This holds for consecutive Fibonacci indices (can be computed easily)

    cout << checkRoots(A, B, C) << endl;

    return 0;
}
