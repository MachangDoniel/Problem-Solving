#include <iostream>
using namespace std;

const int MOD = 1000000007;

// Define a matrix structure
struct Matrix {
    long long mat[4][4];

    Matrix() {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                mat[i][j] = 0;
            }
        }
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                    result.mat[i][j] %= MOD;
                }
            }
        }
        return result;
    }
};

// Function to perform matrix exponentiation
Matrix power(Matrix base, long long exp) {
    Matrix result;
    for (int i = 0; i < 4; ++i) {
        result.mat[i][i] = 1;
    }

    while (exp > 0) {
        if (exp & 1) {
            result = result * base;
        }
        base = base * base;
        exp >>= 1;
    }
    return result;
}

// Function to calculate Trinacci sequence for given K
long long trinacci(long long K) {
    if (K == 0) return 1;
    else if (K == 1) return 2;
    else if (K == 2) return 3;

    // Initialize the base matrix
    Matrix base;
    base.mat[0][0] = 3;
    base.mat[0][2] = 2;
    base.mat[0][3] = 1;
    base.mat[1][0] = 1;
    base.mat[2][1] = 1;
    base.mat[3][3] = 1;

    // Raise the base matrix to the power of K - 2
    Matrix result = power(base, K - 2);

    // Calculate the K-th term
    return (3 * result.mat[0][0] + 2 * result.mat[0][1] + result.mat[0][2] + 3) % MOD;
}

int main() {
    long long K;
    cin >> K;
    cout << trinacci(K) << endl;
    return 0;
}
